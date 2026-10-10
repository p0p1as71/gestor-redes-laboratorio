# Tres ESP32-S3-POE-ETH

**Modelo documentado:** Waveshare ESP32-S3-POE-ETH.
**Función:** nodos de prácticas Ethernet; funciones permanentes de diagnóstico aún por definir.

| Nodo | Puerto SG2210P (03/10) | IP DHCP reservada |
|---|---|---|
| ESP32-01 | Gi1/0/3 | 192.168.88.245 |
| ESP32-02 | Gi1/0/5 | 192.168.88.246 |
| ESP32-03 | Gi1/0/4 | 192.168.88.247 |

## Incidencia resuelta el 03/10

Las tres placas anunciaban inicialmente la misma MAC Ethernet `02:00:00:12:34:56`, causando desplazamiento del aprendizaje MAC entre puertos. Tras corrección del firmware y reservas DHCP, la tabla del switch mostró tres identidades independientes. El registro histórico no asegura que sigan ejecutando ese firmware hoy.

## Próximo diseño

Asignar a cada nodo una función mensurable y diferenciada (por ejemplo: comprobación ICMP de gateway, medición de disponibilidad de DNS y prueba de conectividad entre segmentos), sin instalar ni desplegar firmware antes de decidir el alcance de tráfico y el modo de observación.
