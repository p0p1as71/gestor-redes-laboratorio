# Omada Software Controller

**Anfitrión documentado:** Lenovo ThinkPad L13 Gen 3.
**Componentes documentados el 03/10:** Omada Network Application 6.3.0.45, Java 17, MongoDB 8.0.32, jsvc. Versiones históricas, no verificadas hoy.

- Equipos adoptados: SG2210P y EAP225.
- Interfaz web: puertos 8088/TCP y 8043/TCP según instalación.
- Para continuidad de adopción al cambiar el Lenovo de red, se documentó descubrimiento mediante DHCP Option 138 anunciando su dirección Tailscale.
- Se observaron conexiones al puerto 29814/TCP y eventos previos `Heartbeat Missed` / `Disconnected`.

## Incidencia de clientes

Los listados de clientes en Omada mostraron discrepancias frente a las conexiones esperadas. Antes de interpretar una ausencia en la interfaz, comparar:
1. Estado físico del puerto / enlace.
2. Tabla de MAC del switch.
3. Concesiones DHCP del MikroTik.
4. ARP y pruebas activas autorizadas.
5. Historia online/offline de Omada.

## Límites

No usar Tailscale como sustituto implícito de una LAN o de medidas de seguridad. No reconfigurar controlador, DHCP ni dispositivos adoptados sin verificar estado y posibilidad de reversión.
