# Raspberry Pi 4 — gateway y administración

**Tipo de dato:** consolidación del CHANGELOG (septiembre-octubre de 2026), no lectura en vivo.
**Rol:** puerta de entrada al laboratorio físico y anfitrión de herramientas de gestión.

## Interfaces y recorrido

| Interfaz / segmento | Dirección documentada | Función |
|---|---|---|
| Wi-Fi, red Starlink | 192.168.1.236 (observación histórica) | Conexión doméstica |
| Ethernet hacia MikroTik | 192.168.100.1/30 | Tránsito dedicado |
| Dirección adicional LAN laboratorio | 192.168.88.254 (histórica) | Administración del segmento físico |

Ruta histórica a la LAN del laboratorio: `192.168.88.0/24 via 192.168.100.2`. El 27/09 se registró pérdida de esta ruta tras un reinicio y recuperación temporal: **no asumir persistencia**.

## Responsabilidades documentadas

- Reenvío IPv4 y NAT/MASQUERADE para el laboratorio hacia la salida Wi-Fi.
- LibreNMS (Docker, puerto 8000 según histórico) para monitorización.
- NetBox (Docker Compose, puerto 8001 según histórico) para inventario/IPAM.
- Tailscale y herramientas de acceso remoto existentes.
- Ansible/AWX solo como objetivo futuro; instalación no confirmada.

## Riesgos y límites

La Pi tiene un pie en el entorno doméstico y otro en el laboratorio; no introducir reglas de tránsito, NAT, rutas o exposición de servicios sin revisar impacto y autorización. No inferir que Tailscale es una salida habilitada para equipos de pruebas.

## Pendientes de verificación

1. Configuración persistente de ruta hacia 192.168.88.0/24.
2. Reglas NAT/forward vigentes y orden de firewall.
3. Direcciones actuales por interfaz, servicios y puertos.
4. Estado y respaldo de NetBox, LibreNMS y dashboard.
5. Coincidencia entre NetBox y topología física.

**Evidencia fuente:** [CHANGELOG](../../CHANGELOG.md), entradas del 21 y 27 de septiembre y posteriores.
