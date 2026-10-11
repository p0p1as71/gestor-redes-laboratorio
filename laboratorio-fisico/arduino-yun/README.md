# Arduino Yún — nodo de prácticas

Arduino Yún original (ATmega32U4 + Atheros AR933x) con Linino/OpenWrt histórico; acceso Linux recuperado por USB/serie en las primeras prácticas.

- IP de laboratorio documentada: `192.168.88.253` (histórica).
- En septiembre se comprobó conectividad desde MikroTik y presencia ARP.
- El CHANGELOG del 22/09 registra acceso SSH correcto desde Raspberry Pi 4 como root, con opciones de compatibilidad del cliente. Es evidencia histórica, no comprobación actual. El acceso directo MikroTik → Yún alcanzaba el servicio, pero no completó autenticación.
- LibreNMS realizaba supervisión ICMP, no SNMP.

**Pendiente:** estado de sistema, rutas, enlace Ethernet, credenciales de administración recuperables y condiciones de seguridad. Antes de cambiar firmware o configuración, conservar respaldo y acceso de rescate por USB.

## Conexión física

Ethernet hacia otro puerto LAN del MikroTik, según actualización del usuario del 10/10/2026. ether3 aparece en el CHANGELOG del 20 y 27/09; número actual pendiente. No situar el Yún detrás del SG2210P.

La consola USB/serie del Lenovo es un canal de recuperación/configuración, separado del enlace Ethernet de datos. Véase [mapa físico](../topologia.md).
