# Redes libvirt — separación por anfitrión

## Lenovo L13 — réplica principal

| Red | Estado documental |
|---|---|
| `default` | NAT/DHCP, 192.168.122.0/24 según informe 10/10 |
| `LAB-NET` | `virbr50` con IP del host 192.168.50.1/24, activa/autostart, sin NAT ni DHCP declarados; función definitiva pendiente |

No suponer que LAB-NET es absolutamente aislada del host: su bridge dispone de IP. Inspeccionar XML antes de cambiarla.

## MEDION netlab-ws01 — plataforma adicional

| Red | Estado histórico |
|---|---|
| `default` | NAT, activa/autostart según CHANGELOG |
| `lab-isolated` | Segmento interno, activa/autostart; aislamiento extremo a extremo no validado |

Una red `default` de un anfitrión no es la `default` del otro. Las pruebas OPNsense se documentan exclusivamente en MEDION.

## Principio de validación

Nombres como «isolated», estado activo o ausencia de NAT **no prueban aislamiento completo**. Registrar rutas, bridges, firewall y pruebas de comunicación permitida/bloqueada por anfitrión.
