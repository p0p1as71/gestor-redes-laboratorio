# MikroTik hEX lite RB750r2

**Papel:** router y firewall de la LAN física del laboratorio.
**Estado:** configuración histórica documentada; no auditada en vivo en esta revisión.

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

El historial menciona una copia `lab-mikrotik-2026-09-27.backup` transferida a la Raspberry Pi 4. **No se ha comprobado en esta fase su integridad ni disponibilidad actual.** No almacenar backups binarios ni exportaciones brutas en GitHub público.

## Pendientes

- Exportación de configuración **sanitizada**, revisada por el usuario.
- Auditoría de puertos de switch conectados al MikroTik.
- Revisión de rutas, servicios administrativos y orden de firewall.
- Confirmación de DHCP/Option 138 y conectividad efectiva Omada.
