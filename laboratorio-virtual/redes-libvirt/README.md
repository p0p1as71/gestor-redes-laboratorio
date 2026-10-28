# Redes libvirt — separación por anfitrión

## Lenovo L13: PYME virtual (actualización 28/10/2026)

- `default`: NAT/DHCP, `192.168.122.0/24` según informe Lenovo del 10/10.
- `LAB-NET`: **red operativa de Windows 11 Pro**; `virbr50`, host `192.168.50.1/24`, `192.168.50.0/24`, sin NAT ni DHCP de libvirt y sin NIC física en la definición consultada el 28/10.

No confundir estas redes con las definiciones independientes del MEDION.

## MEDION netlab-ws01: verificado el 10/10/2026

| Red | Bridge | Configuración / evidencia |
|---|---|---|
| `default` | `virbr0` | NAT; gateway `192.168.122.1`, utilizado por OPNsense WAN |
| `lab-isolated` | `virbr-lab` | XML sin `forward`, sin IP de bridge; dos interfaces conectadas |

Ambas estaban activas, persistentes y con autostart. OPNsense conecta ambas redes y tiene forwarding, reglas permisivas de LAN y NAT. Debian conectado a `lab-isolated` alcanzó `1.1.1.1`.

**Consecuencia:** `lab-isolated` carece de forwarding libvirt propio, pero no está aislada de Internet como sistema completo. Falta validar el bloqueo de otras redes privadas.

[Arquitectura MEDION](../medion-netlab-ws01/README.md) · [Pruebas](../../practicas/firewall-nat/PRAC-003-aislamiento-opnsense.md).

## Cambio de objetivo Lenovo — 15/10/2026 (histórico)

**Actualización 28/10:** `LAB-NET` fue asignada a `win11` y verificada directamente. La red `default` no se atribuye a Windows; se conserva como red preexistente. Se diseñará un switch virtual Linux Bridge para conectar Windows 11 y OpenMediaVault, con red inicial aislada del domicilio, MEDION y producción. La interconexión posterior con SG2210P mediante **adaptador USB 3.0–Ethernet del Lenovo** está supeditada a confirmar existencia/disponibilidad del hardware, puerto físico libre, VLAN, direccionamiento, DHCP y políticas. La Wi-Fi cliente del Lenovo permanece fuera del puente. CUPS/Docker deberá acceder a la red virtual por conexión explícita, sin alterar las redes Docker existentes.


## Lenovo — implementación física 15/10/2026

El bridge NetworkManager `br-pyme` **ya existe y enlaza** el adaptador USB-Ethernet `enx00e04c6808a2` con la red SG2210P/MikroTik `192.168.88.0/24`. DHCP: `192.168.88.236/24` (dinámica); STP activo, VLAN filtering apagado; ping al gateway `192.168.88.1` con 4/4 respuestas y 0 % pérdidas. El ajuste `ipv4.never-default yes` se reaplicó, conservando como única ruta default la Wi-Fi Starlink `192.168.1.1`.

Histórico 15/10: `default` y `LAB-NET` estaban activas/autostart y aún no existían VMs. **Estado 28/10: `win11` instalada, probada y apagada; Debian Server pendiente**. `br-pyme` es un bridge del host, **no una tercera red libvirt declarada**. Al estar conectado físicamente **no es una red aislada**; aún no existe segmentación VLAN adicional verificada. No confundir con interfaz MEDION VLAN20.


## Validación de LAB-NET — 28/10/2026

| Concepto | Estado documentado |
|---|---|
| Anfitrión | Lenovo Linux Mint, KVM/QEMU, libvirt `qemu:///system` |
| VM existente | `win11`, Windows 11 Pro, **4 vCPU, 4096 MiB, QCOW2 90 GiB** |
| NIC VM | Intel `e1000e`, conectada a `LAB-NET` |
| IPv4 VM | `192.168.50.20/24` **estática**, sin gateway ni DNS exterior |
| Bridge host | `virbr50`, `192.168.50.1/24` |
| NAT/DHCP libvirt | **No configurados** |
| Interfaz física asignada | **Ninguna** |
| ICMP Win11 → host | `192.168.50.1` 4/4 respuestas, 0 % pérdida |
| ICMP Win11 → 8.8.8.8 | 100 % pérdida; sin ruta por defecto en `route print -4` |
| Estado VM al cierre | **Apagada** |
| Debian Server | **No creada**, se propone `192.168.50.10/24` |

**Alcance:** aislamiento IPv4 inicial favorable, **no auditoría completa** de IPv6 ni de reglas de forwarding/firewall del host. La red física `br-pyme` (`192.168.88.0/24`) y `LAB-NET` (`192.168.50.0/24`) son **diferentes**, aunque ambas residen en el Lenovo. MEDION mantiene sus redes y VMs independientes.
