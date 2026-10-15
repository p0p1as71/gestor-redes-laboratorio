# Redes libvirt — separación por anfitrión

## Lenovo L13: réplica principal (estado documental previo)

- `default`: NAT/DHCP, `192.168.122.0/24` según informe Lenovo del 10/10.
- `LAB-NET`: `virbr50`, IP de host `192.168.50.1/24`; función final pendiente.

No confundir estas redes con las definiciones independientes del MEDION.

## MEDION netlab-ws01: verificado el 10/10/2026

| Red | Bridge | Configuración / evidencia |
|---|---|---|
| `default` | `virbr0` | NAT; gateway `192.168.122.1`, utilizado por OPNsense WAN |
| `lab-isolated` | `virbr-lab` | XML sin `forward`, sin IP de bridge; dos interfaces conectadas |

Ambas estaban activas, persistentes y con autostart. OPNsense conecta ambas redes y tiene forwarding, reglas permisivas de LAN y NAT. Debian conectado a `lab-isolated` alcanzó `1.1.1.1`.

**Consecuencia:** `lab-isolated` carece de forwarding libvirt propio, pero no está aislada de Internet como sistema completo. Falta validar el bloqueo de otras redes privadas.

[Arquitectura MEDION](../medion-netlab-ws01/README.md) · [Pruebas](../../practicas/firewall-nat/PRAC-003-aislamiento-opnsense.md).

## Cambio de objetivo Lenovo — 15/10/2026

`LAB-NET` y `default` son configuraciones históricas por contrastar; **no asignar automáticamente ninguna a la PYME virtual**. Se diseñará un switch virtual Linux Bridge para conectar Windows 11 y OpenMediaVault, con red inicial aislada del domicilio, MEDION y producción. La interconexión posterior con SG2210P mediante **adaptador USB 3.0–Ethernet del Lenovo** está supeditada a confirmar existencia/disponibilidad del hardware, puerto físico libre, VLAN, direccionamiento, DHCP y políticas. La Wi-Fi cliente del Lenovo permanece fuera del puente. CUPS/Docker deberá acceder a la red virtual por conexión explícita, sin alterar las redes Docker existentes.


## Lenovo — implementación física 15/10/2026

El bridge NetworkManager `br-pyme` **ya existe y enlaza** el adaptador USB-Ethernet `enx00e04c6808a2` con la red SG2210P/MikroTik `192.168.88.0/24`. DHCP: `192.168.88.236/24` (dinámica); STP activo, VLAN filtering apagado; ping al gateway `192.168.88.1` con 4/4 respuestas y 0 % pérdidas. El ajuste `ipv4.never-default yes` se reaplicó, conservando como única ruta default la Wi-Fi Starlink `192.168.1.1`.

Libvirt `default` y `LAB-NET` constaban activas/autostart y **no había VMs registradas**. `br-pyme` es un bridge del host, **no una tercera red libvirt declarada**. Al estar conectado físicamente **no es una red aislada**; aún no existe segmentación VLAN adicional verificada. No confundir con interfaz MEDION VLAN20.
