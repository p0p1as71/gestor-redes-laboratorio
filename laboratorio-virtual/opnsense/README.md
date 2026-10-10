# OPNsense — router/firewall del MEDION

**VM:** `opnsense-lab` en `netlab-ws01`. **Versión observada:** 26.7 amd64 (10/10/2026).

## Interfaces verificadas

| OPNsense | MAC | Backend | Función/IP |
|---|---|---|---|
| `em0` | `52:54:00:3B:36:21` | `vnet0` → libvirt `default` | WAN, `192.168.122.159/24` DHCP |
| `em1` | `52:54:00:06:81:71` | `vnet1` → `lab-isolated` | LAN, `10.10.10.1/24` |
| `ue0` | `00:E0:4C:68:31:B0` | Realtek RTL8153 vía passthrough USB, SG2210P puerto 6 | Enlace 1 Gbps activo, sin IP, sin flag UP |

**Corrección importante:** la antigua afirmación «passthrough no comprobado» era incorrecta a la luz del XML `hostdev` y `ifconfig ue0` vistos en la sesión. El dispositivo físico **sí está expuesto a la VM**; no se ha acreditado que intervenga en routing o NAT.

## Routing, firewall y NAT

- Reenvío IPv4: `net.inet.ip.forwarding: 1`.
- Ruta predeterminada: `192.168.122.1` por `em0`; rutas conectadas `192.168.122.0/24` y `10.10.10.0/24`. Sin ruta específica vía `ue0`.
- `pfctl -sr`: regla permisiva desde `em1:network` hacia cualquier destino y reglas WAN de filtrado.
- `pfctl -sn`: NAT de `em1:network` hacia `em0`.
- Pruebas desde Debian: ping a gateway LAN, gateway `default` y `1.1.1.1` con 0 % pérdida; resolución DNS mediante `10.10.10.1`.

**Hallazgo:** `lab-isolated` no está completamente aislada; la conectividad exterior funciona. No se ha verificado una política que bloquee las redes doméstica o física.

## Pendientes

Contrastar controles de acceso a redes privadas, perfiles NAT del anfitrión, comportamiento tras reinicio y administración remota del MEDION. No habilitar `ue0` ni alterar firewall/rutas sin un diseño aprobado y copia de seguridad.
