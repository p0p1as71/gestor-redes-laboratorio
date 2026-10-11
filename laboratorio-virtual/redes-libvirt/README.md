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
