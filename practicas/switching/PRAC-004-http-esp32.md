# PRAC-004 — HTTP Ethernet entre ESP32-S3 (W5500)

- **Fecha de las pruebas registradas:** 12/10/2026.
- **Entorno:** laboratorio físico, LAN `192.168.88.0/24`, switch SG2210P, MikroTik.
- **Estado:** PRUEBA FUNCIONAL DOCUMENTADA; falta repetición controlada con los tres equipos activos.

## Concepto y objetivo

HTTP utiliza un protocolo de aplicación sobre la conectividad IP. La respuesta `HTTP/1.1 200 OK` acredita que el cliente alcanzó un servidor HTTP capaz de procesar esa petición; no certifica por sí sola disponibilidad continua ni todas las funciones de la red.

## Nodos y roles

| Nodo | IPv4 reservada | Puerto indicado 12/10 | Rol |
|---|---|---|---|
| ESP32-01 | `192.168.88.245` | LAN3 | Servidor HTTP |
| ESP32-02 | `192.168.88.246` | LAN4 | Cliente HTTP (cada 10 s) |
| ESP32-03 | `192.168.88.247` | LAN5 | Monitor HTTP |

**Nota de evidencia:** el 03/10 se documentó ESP32-02 en puerto 5 y ESP32-03 en puerto 4. El 12/10 se registró una corrección de cables LAN4/LAN5 y el mapa anterior. Mantener ambos registros fechados hasta correlacionar físicamente MAC y puerto en Omada.

## Implementación registrada

1. Revisión y corrección del cableado LAN4/LAN5.
2. Comprobación de reservas DHCP por MAC en el MikroTik.
3. Carga de `ESP32_HTTP_CLIENT.ino` en ESP32-02.
4. Establecimiento de interfaces Ethernet W5500.
5. Peticiones HTTP de ESP32-02 a ESP32-01 cada 10 segundos.
6. Prueba del monitor ESP32-03.

## Resultados observados

- ESP32-02 obtuvo respuestas `HTTP/1.1 200 OK` de ESP32-01.
- ESP32-03 registró **4 respuestas satisfactorias**, sin errores en esa serie.
- Latencia registrada para el monitor: aproximadamente **19–20 ms**.
- Después de la actualización a RouterOS 7.24.5, las tres reservas DHCP seguían configuradas. En una consulta aparecieron `waiting`, lo que no acredita por sí solo un fallo.

## Limitaciones y pendientes

- Repetir prueba con los tres nodos activos, identificando MAC/puerto y estado DHCP.
- Registrar número de peticiones, errores, latencia, uptime y fecha de la nueva serie.
- Incorporar código fuente y versiones de firmware **solo después** de revisar que no incluyan credenciales o datos sensibles.
- No inferir persistencia del servicio ni mediciones continuadas de una serie de cuatro peticiones.

**Fuente:** entradas «Actualización de MikroTik hEX lite a RouterOS 7.24.5» e «Implementación y pruebas HTTP entre ESP32 del laboratorio físico», `CHANGELOG.md`, 12/10/2026.
