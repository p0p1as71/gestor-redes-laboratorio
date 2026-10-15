# MikroTik hEX lite RB750r2

**Papel:** router y firewall de la LAN física del laboratorio.
**Estado actualizado:** intervención registrada el 12/10/2026 en el CHANGELOG; aquí se distinguen las comprobaciones de esa fecha del estado en tiempo real.

## Actualización de firmware — 12/10/2026

- **Equipo:** MikroTik hEX lite RB750r2, MIPSBE, almacenamiento 16 MiB (≈3,93 MiB libres antes de actualizar).
- **RouterOS:** 7.1.2 → 7.12.1 → **7.24.5**; **RouterBOOT:** 7.1.2 → 7.12.1 → **7.24.5**.
- Se realizaron copia binaria y exportación de configuración antes de intervenir, y otra copia tras la actualización; no guardar aquí ficheros de respaldo sin sanitizar.
- Se utilizó WinBox 4.4 en Linux, sin Netinstall ni restablecimiento de fábrica.
- Por SSH se confirmó RouterOS 7.24.5 y RouterBOOT `current-firmware`/`upgrade-firmware` en 7.24.5.
- Se mantuvieron WAN 192.168.100.2/30, LAN 192.168.88.1/24, DHCP, reservas y ruta predeterminada por 192.168.100.1. La regla `ALLOW Raspberry to LAB` seguía presente.
- Verificaciones desde MikroTik: ping a Pi 4 y a 1.1.1.1, ambos 4/4 respuestas; resolución DNS de `example.com` correcta.
- **Pendiente:** reconfirmar conectividad de clientes ESP32; sus tres reservas aparecían `waiting` durante una comprobación y eso, por sí solo, no acredita fallo de enlace.

## Recuperación de acceso SSH desde Raspberry — 15/10/2026

Desde Raspberry Pi 4 (`192.168.100.1/30`), una conexión SSH a la LAN MikroTik (`192.168.88.1`) expiraba porque la Raspberry elegía `192.168.1.1 dev wlan0` (Starlink). Se añadió en la Pi una ruta persistida en NetworkManager a `192.168.88.0/24 via 192.168.100.2 dev eth0`. La consulta de ruta resultó correcta y una captura de Termius mostró prompt `[admin@MikroTik] >` desde una sesión identificada por el usuario como acceso SSH desde la Raspberry a través de Tailscale. En los logs aparece también un **intento SSH fallido** desde `192.168.100.1` (no confundir con la sesión abierta). No se cambiaron las reglas MikroTik ni Tailscale. **Pendiente:** prueba después de reiniciar la Pi y, por separado, acceso directo Lenovo→MikroTik si se necesita.

## Topología y direccionamiento

| Elemento | Valor de referencia |
|---|---|
| WAN `ether1` | 192.168.100.2/30, hacia Raspberry Pi 4 (192.168.100.1) |
| LAN / bridge | 192.168.88.1/24 |
| LAN completa | 192.168.88.0/24 |
| Salida por defecto | 192.168.100.1 (según histórico) |
| DHCP | Activo históricamente; comprobar reservas vigentes |
| Zona horaria | Europe/Madrid |
| NTP | pool.ntp.org |

## Conexiones

En la topología del 27/09 se documentó `ether2` → Raspberry Pi 3 y `ether3` → Arduino Yún. Posteriormente se incorporó el SG2210P: **el puerto actual del switch requiere verificación**; no considerar libres puertos anotados en septiembre.

## Seguridad, routing y gestión

- NAT/firewall habilitados según histórico.
- Acceso administrativo WebFig/SSH/Winbox documentado; **revisar qué está habilitado y desde qué segmentos**.
- Existe una regla específica de permiso desde la Raspberry Pi para tráfico de laboratorio que debe situarse por encima de bloqueos genéricos de WAN, según objetivo de cada prueba.
- El 03/10 se documentó la configuración de DHCP Option 138 para descubrir el controlador Omada por la IP Tailscale del Lenovo. No exponer aquí contraseñas ni credenciales.

## DHCP / elementos documentados

| Equipo | Dirección histórica |
|---|---|
| SG2210P | 192.168.88.251 |
| EAP225 | 192.168.88.250 |
| ESP32-01 | 192.168.88.245 |
| ESP32-02 | 192.168.88.246 |
| ESP32-03 | 192.168.88.247 |
| Arduino Yún | 192.168.88.253 |
| Raspberry Pi 3 | 192.168.88.252 |

Las tres reservas ESP32 se verificaron `bound` con MAC independientes el 03/10. Son observaciones fechadas, no un chequeo actual.

## Copia y recuperación

El historial menciona una copia `lab-mikrotik-2026-09-27.backup`. El CHANGELOG del 12/10 también registra backups antes y después de actualizar, sin aportar en esta ficha ruta o verificación criptográfica. No dar por comprobada su disponibilidad actual. No almacenar backups binarios ni exportaciones brutas en GitHub público.

## Pendientes

- Exportación de configuración **sanitizada**, revisada por el usuario.
- Auditoría de puertos de switch conectados al MikroTik.
- Revisión de rutas, servicios administrativos y orden de firewall.
- Confirmación de DHCP/Option 138 y conectividad efectiva Omada.

## Actualización documental del 10/10/2026

Conexiones LAN: Pi 3 para prácticas, Yún en otro puerto y uplink al SG2210P. El portátil adicional se conecta al SG2210P. La actualización del usuario confirma las relaciones, no los números de puerto históricos.

Véase [mapa físico](../topologia.md), con evidencia y extremos pendientes.
