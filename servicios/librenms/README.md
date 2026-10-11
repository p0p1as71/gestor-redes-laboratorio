# LibreNMS — observabilidad

**Instancia histórica:** Raspberry Pi 4 mediante Docker; puerto documentado 8000. Se registró monitorización SNMP de la propia Pi 4 y de la Pi 3, y seguimiento ICMP del Arduino Yún.

## Límite funcional

LibreNMS mide disponibilidad, métricas y eventos. No decide direccionamiento, identidad canónica ni políticas de cambio; esos datos deben revisarse en NetBox y GitHub.

## Datos históricos frente a estado actual

La Pi 3 fue empleada inicialmente como nodo supervisado, pero su función vigente del proyecto es **prácticas y pruebas**. Su posible permanencia como dispositivo supervisado debe comprobarse, sin alterar su nuevo papel.

## Pendientes

Revisar dispositivos realmente registrados, método de sondeo por equipo, estado de SNMP, retención y alertas, umbrales, visibilidad de SG2210P/EAP225/ESP32 y protección de credenciales SNMP. No copiar comunidades ni secretos al repositorio.
