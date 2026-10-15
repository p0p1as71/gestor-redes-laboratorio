# Raspberry Pi 4 — gateway y administración

**Tipo de dato:** consolidación del CHANGELOG (septiembre-octubre de 2026), no lectura en vivo.
**Rol:** puerta de entrada al laboratorio físico y anfitrión de herramientas de gestión.

## Interfaces y recorrido

| Interfaz / segmento | Dirección documentada | Función |
|---|---|---|
| Wi-Fi, red Starlink | 192.168.1.236 (observación histórica) | Conexión doméstica |
| Ethernet hacia MikroTik | 192.168.100.1/30 | Tránsito dedicado |
| Dirección adicional LAN laboratorio | 192.168.88.254 (histórica) | Administración del segmento físico |

Ruta histórica a la LAN del laboratorio: `192.168.88.0/24 via 192.168.100.2`. El 27/09 se registró pérdida tras reiniciar. **Actualización 15/10/2026:** se configuró la ruta en NetworkManager por UUID del perfil Ethernet `ff200535-83ed-33eb-97c5-943b6f133bfc` mediante `+ipv4.routes "192.168.88.0/24 192.168.100.2"`. La consulta `ip route get 192.168.88.1` devolvió `via 192.168.100.2 dev eth0 src 192.168.100.1`. Ruta activa y guardada, **persistencia tras reinicio real aún no comprobada**. SSH Raspberry→consola MikroTik acreditado mediante sesión Termius aportada por el usuario; log de intento fallido desde `192.168.100.1` no equivale por sí mismo a login exitoso.

## Responsabilidades documentadas

- Reenvío IPv4 y NAT/MASQUERADE para el laboratorio hacia la salida Wi-Fi.
- LibreNMS (Docker, puerto 8000 según histórico) para monitorización.
- NetBox (Docker Compose, puerto 8001 según histórico) para inventario/IPAM.
- Tailscale y herramientas de acceso remoto existentes.
- Ansible/AWX solo como objetivo futuro; instalación no confirmada.

## Riesgos y límites

La Pi tiene un pie en el entorno doméstico y otro en el laboratorio; no introducir reglas de tránsito, NAT, rutas o exposición de servicios sin revisar impacto y autorización. No inferir que Tailscale es una salida habilitada para equipos de pruebas.

## Pendientes de verificación

1. Verificar tras un **reinicio real** que la ruta guardada el 15/10 sigue activa (no reiniciar sin autorización).
2. Reglas NAT/forward vigentes y orden de firewall.
3. Direcciones actuales por interfaz, servicios y puertos.
4. Estado y respaldo de NetBox, LibreNMS y dashboard.
5. Coincidencia entre NetBox y topología física.

**Evidencia fuente:** [CHANGELOG](../../CHANGELOG.md), entradas del 21 y 27 de septiembre y posteriores.
