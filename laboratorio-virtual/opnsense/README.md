# OPNsense — router/firewall del MEDION

**VM:** `opnsense-lab` en `netlab-ws01`. **Versión observada:** 26.7 amd64 (10/10/2026).

## Actualización 12/10/2026 — interfaz física OPT1 y VLAN 20

**Evidencia:** informe de intervención facilitado por el usuario; no se ha efectuado comprobación remota independiente en esta actualización documental.

- Se instaló `firmware-realtek` (Debian 13 Trixie) en el MEDION tras errores por ausencia de `rtl_nic/rtl8153b-2.fw`. Tras reinicialización física del adaptador, desaparecieron los errores de carga observados.
- RTL8153, USB `0bda:8153`, MAC `00:e0:4c:68:31:b0`, pasado a OPNsense de forma persistente por vendor/product; apareció como `ue0`, enlace **1000baseT full-duplex, activo**.
- **Asignación reportada más reciente:** WAN `re1` (libvirt `default`), LAN `re0` (`lab-isolated`, `10.10.10.1/24`), OPT1 `ue0` (`10.20.20.1/24`, sin upstream gateway ni IPv6).
- SG2210P puerto 6: modo **Access VLAN 20**, `LAB-FISICO`. Es un enlace Ethernet sin etiquetado 802.1Q hacia `ue0`; OPNsense no necesita una subinterfaz VLAN para recibir las tramas *untagged* del puerto access.
- El asistente recibió rango DHCP `10.20.20.100–10.20.20.200`, pero **no está verificado que un servidor DHCP IPv4 de OPT1 esté activo**: no aparecieron procesos `kea`/`dhcpd` ni sección `<dhcpd>` en la comprobación descrita.
- **No se ha probado un cliente físico** ni la comunicación end-to-end, y siguen pendientes las reglas de firewall/routing entre LAN virtual, LAB-FISICO y salida exterior.

### Separación lógica de segmentos

| Segmento | Interfaz/gestión | Red | Alcance observado |
|---|---|---|---|
| WAN virtual | `re1`, libvirt `default` | Direccionamiento exacto no reconfirmado el 12/10 | Conservada |
| LAN virtual | `re0`, `lab-isolated` | `10.10.10.0/24` | Conservada, gateway `10.10.10.1` |
| LAB-FISICO | `OPT1` / `ue0` | `10.20.20.0/24` | `10.20.20.1/24`, enlace L1/L2 verificado |
| LAN MikroTik | Otro segmento del SG2210P | `192.168.88.0/24` | No migrada a VLAN 20 |

## Interfaces verificadas históricamente (10/10/2026)

| OPNsense | MAC | Backend | Función/IP |
|---|---|---|---|
| `em0` | `52:54:00:3B:36:21` | `vnet0` → libvirt `default` | WAN, `192.168.122.159/24` DHCP |
| `em1` | `52:54:00:06:81:71` | `vnet1` → `lab-isolated` | LAN, `10.10.10.1/24` |
| `ue0` | `00:E0:4C:68:31:B0` | Realtek RTL8153 vía passthrough USB, SG2210P puerto 6 | Enlace 1 Gbps activo, sin IP, sin flag UP |

**Corrección importante:** la antigua afirmación «passthrough no comprobado» era incorrecta a la luz del XML `hostdev` y `ifconfig ue0` vistos en la sesión. El dispositivo físico **sí está expuesto a la VM**; no se ha acreditado que intervenga en routing o NAT.

**Nota temporal:** el mapeo `em0`/`em1` y la falta de IPv4 en `ue0` descritos arriba corresponden a la sesión del **10/10**. El informe posterior del **12/10** identifica `re1`/`re0`, registra OPT1 sobre `ue0` y añade `10.20.20.1/24`. No trasladar las conclusiones anteriores al nuevo estado sin comprobación.

## Routing, firewall y NAT — observaciones del 10/10

- Reenvío IPv4: `net.inet.ip.forwarding: 1`.
- Ruta predeterminada: `192.168.122.1` por `em0`; rutas conectadas `192.168.122.0/24` y `10.10.10.0/24`. Sin ruta específica vía `ue0`.
- `pfctl -sr`: regla permisiva desde `em1:network` hacia cualquier destino y reglas WAN de filtrado.
- `pfctl -sn`: NAT de `em1:network` hacia `em0`.
- Pruebas desde Debian: ping a gateway LAN, gateway `default` y `1.1.1.1` con 0 % pérdida; resolución DNS mediante `10.10.10.1`.

**Hallazgo:** `lab-isolated` no está completamente aislada; la conectividad exterior funciona. No se ha verificado una política que bloquee las redes doméstica o física.

## Pendientes

Contrastar controles de acceso a redes privadas, perfiles NAT del anfitrión, comportamiento tras reinicio y administración remota del MEDION. No alterar firewall/rutas sin un diseño aprobado y copia de seguridad; `ue0` ya se configuró como OPT1 el 12/10.
