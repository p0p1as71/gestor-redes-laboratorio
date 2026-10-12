# Laboratorio físico — Tres ESP32-S3-POE-ETH

**Hardware:** 3 placas Waveshare ESP32-S3-POE-ETH con controlador Ethernet W5500.
**Red:** 192.168.88.0/24.
**Fecha de actualización:** 12/10/2026.
**Estado:** arquitectura HTTP implementada y pruebas funcionales satisfactorias.

## 1. Objetivo

Utilizar tres microcontroladores ESP32 como nodos Ethernet independientes para estudiar y experimentar con:

- Comunicación SPI entre microcontrolador y controlador Ethernet.
- Direccionamiento MAC e identificación de dispositivos.
- Asignación IPv4 mediante DHCP.
- Funcionamiento de switches y aprendizaje de direcciones MAC.
- Establecimiento de conexiones TCP.
- Protocolo HTTP/1.1.
- Arquitectura cliente-servidor.
- Monitorización de disponibilidad y tiempos de respuesta.
- Diagnóstico de incidencias de red.

## 2. Arquitectura actual

| Nodo | IPv4 reservada | Puerto SG2210P (12/10) | Función |
|---|---|---|---|
| ESP32-01 | 192.168.88.245 | LAN3 | Servidor HTTP |
| ESP32-02 | 192.168.88.246 | LAN4 | Cliente HTTP |
| ESP32-03 | 192.168.88.247 | LAN5 | Monitor HTTP |

Las direcciones se asignan mediante DHCP del MikroTik, utilizando reservas por dirección MAC.

ESP32-01 escucha conexiones TCP en el puerto 80.

ESP32-02 y ESP32-03 realizan peticiones HTTP periódicas al servidor.

## 3. Antecedentes — 02 y 03 de octubre

Durante las primeras prácticas, las tres placas anunciaban la misma MAC Ethernet:

`02:00:00:12:34:56`

Esto provocaba desplazamientos del aprendizaje MAC entre los puertos del switch.

Se identificaron las placas por USB, se corrigieron sus identidades Ethernet y se actualizaron las reservas DHCP del MikroTik.

Esta incidencia está documentada en [PRAC-002 — Conflicto de MAC](../../practicas/switching/PRAC-002-conflicto-mac-esp32.md).

La distribución **histórica** del 03/10 situaba ESP32-02 en puerto 5 y ESP32-03 en puerto 4. El cableado se corrigió el 12/10 y la tabla anterior (01→3, 02→4, 03→5) es la referencia documental vigente. Una captura de Omada de ese día muestra enlaces activos en 3–5; falta comprobar individualmente la identidad de 02/03 mediante correlación MAC↔puerto.

## 4. Puesta en servicio y programación — 12 de octubre

ESP32-02 y ESP32-03 comenzaron esta intervención sin los firmwares HTTP correspondientes a sus funciones actuales.

Se trabajó con Arduino IDE y la librería `Ethernet_Generic` para desarrollar y cargar programas diferenciados.

La preparación incluyó la configuración de la comunicación con el controlador W5500, la inicialización Ethernet, la obtención de direcciones mediante DHCP y las pruebas de comunicación con ESP32-01.

Los tres programas originales se conservan en el entorno Arduino del Lenovo y se han copiado al repositorio.

### 4.1. Configuración W5500

| Señal | GPIO ESP32-S3 |
|---|---|
| CS | 14 |
| RST | 9 |
| INT | 10 (definido en el programa base; no utilizado en los clientes HTTP) |
| MISO | 12 |
| MOSI | 11 |
| SCK | 13 |

Los programas inicializan SPI con los pines correspondientes y realizan un reinicio físico del W5500 mediante GPIO 9.

La dirección MAC se obtiene con `esp_read_mac(mac, ESP_MAC_ETH)`.

La interfaz Ethernet se inicializa mediante `Ethernet.init(W5500_CS)` y `Ethernet.begin(mac)`.

El monitor serie utiliza 115200 baudios.

## 5. ESP32-01 — Servidor HTTP

**Firmware:** `ESP32-01/ETH_MAC_DHCP_StaticIP.ino`

Programa basado en el ejemplo de Waveshare y adaptado para funcionar como servidor HTTP del laboratorio.

Funciones implementadas:

1. Inicialización SPI y W5500.
2. Obtención de MAC Ethernet.
3. Configuración DHCP.
4. Creación de un servidor TCP mediante `EthernetServer(80)`.
5. Aceptación de conexiones entrantes.
6. Lectura de solicitudes HTTP.
7. Envío de `HTTP/1.1 200 OK`.
8. Entrega de una página HTML identificando al ESP32-01.
9. Cierre de la conexión TCP.

El nombre original del archivo menciona una IP estática de respaldo, pero el código conservado no implementa actualmente ese mecanismo.

## 6. ESP32-02 — Cliente HTTP

**Firmware:** `ESP32-02/ESP32_HTTP_CLIENT.ino`

Programa destinado a generar tráfico HTTP real contra ESP32-01.

Funciones implementadas:

1. Inicialización del hardware Ethernet.
2. Obtención de dirección IPv4 mediante DHCP.
3. Conexión TCP con `192.168.88.245:80`.
4. Envío de petición `GET / HTTP/1.1`.
5. Inclusión de cabecera `Host`.
6. Solicitud de cierre mediante `Connection: close`.
7. Recepción e impresión de la respuesta HTTP por el puerto serie.
8. Control de inactividad de tres segundos durante la lectura.
9. Cierre de la conexión TCP.
10. Repetición periódica de las consultas cada diez segundos.

### Resultado

Se observaron respuestas `HTTP/1.1 200 OK` procedentes de ESP32-01.

Este nodo permite estudiar la secuencia TCP/HTTP y observar el intercambio entre cliente y servidor.

## 7. ESP32-03 — Monitor HTTP

**Firmware:** `ESP32-03/ESP32_HTTP_MONITOR.ino`

Programa desarrollado para comprobar periódicamente la disponibilidad del servidor ESP32-01.

Funciones implementadas:

1. Inicialización Ethernet mediante W5500.
2. Obtención de IPv4 mediante DHCP.
3. Establecimiento de conexión TCP con ESP32-01.
4. Envío de solicitud HTTP GET.
5. Lectura de la primera línea de la respuesta.
6. Comprobación del estado `HTTP/1.1 200`.
7. Clasificación del resultado como ONLINE u OFFLINE.
8. Medición del tiempo transcurrido desde el inicio de la conexión.
9. Contadores acumulados de comprobaciones correctas y fallidas.
10. Repetición cada diez segundos.

### Resultado

En la serie observada:

- Cuatro comprobaciones satisfactorias.
- Cero fallos.
- Tiempos de respuesta aproximados de 19–20 ms.

El tiempo registrado incluye la conexión TCP y la recepción de la primera línea HTTP; no equivale exclusivamente a la latencia de red.

La evidencia se registra en [PRAC-004 — HTTP Ethernet entre ESP32](../../practicas/switching/PRAC-004-http-esp32.md).

## 8. Validación de comunicaciones

Las pruebas realizadas permiten confirmar:

- Funcionamiento del servidor HTTP del ESP32-01.
- Comunicación TCP desde ESP32-02.
- Respuestas HTTP 200.
- Comprobación HTTP desde ESP32-03.
- Medición de tiempos de respuesta.
- Funcionamiento de las funciones de cliente y monitor en las series observadas.

La revisión posterior a la actualización del MikroTik mostró las reservas DHCP de los ESP32 en estado `waiting`. Este dato no demuestra por sí solo una incidencia.

Queda pendiente repetir una validación conjunta con los tres dispositivos activos.

## 9. Limitaciones conocidas

- Los programas cliente y monitor no implementan recuperación completa ante fallos DHCP.
- El monitor HTTP comprueba el estado de respuesta, pero no analiza el contenido HTML.
- Los contadores del monitor son volátiles y se reinician al reiniciar la placa.
- No existe todavía almacenamiento histórico centralizado de resultados.
- No se ha implementado sincronización horaria ni registro persistente de mediciones.
- La comprobación HTTP no sustituye una monitorización integral de Ethernet, DHCP, DNS o routing.

## 10. Evolución prevista

Las siguientes prácticas podrán ampliar las funciones de los ESP32:

- Monitorización del gateway.
- Pruebas de resolución DNS.
- Comprobaciones entre segmentos de red.
- Registro de disponibilidad y latencia.
- Exportación de métricas.
- Observación del tráfico desde el switch y las herramientas de monitorización del laboratorio.

Las nuevas funciones deberán diseñarse y validarse antes de modificar los firmwares operativos.

## 11. Trazabilidad

- 02–03/10/2026: diagnóstico y corrección del conflicto MAC.
- 12/10/2026: implementación y validación de la arquitectura HTTP.
- Código fuente: carpetas `ESP32-01`, `ESP32-02` y `ESP32-03`.
- Historial de intervenciones: [CHANGELOG](../../CHANGELOG.md).
- Documento histórico conservado: `README.pre-20261012.md`.

**Estado documental:** se describen las funcionalidades comprobadas y las que se deducen directamente de los programas. Los pasos de preparación no respaldados por registros específicos no se presentan como verificaciones independientes.
