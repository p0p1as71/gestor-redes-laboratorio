# Raspberry Pi 3 Model B v1.2 — prácticas y pruebas

**Rol vigente decidido para el proyecto:** estación de **prácticas y pruebas de red**, no nodo principal de monitorización.

## Contexto histórico

En septiembre se preparó una tarjeta microSD de 32 GB, se instaló Raspberry Pi OS y se utilizó temporalmente con función de monitorización y diagnóstico. Se registraron:

- Ethernet laboratorio `192.168.88.252`.
- Wi-Fi doméstica `192.168.1.94`.
- `snmpd`, consultas SNMP y descubrimiento en LibreNMS como `rpi3-monitor`.

**Estos datos son históricos**; la función de la Pi 3 cambió posteriormente a prácticas y pruebas. No asumir que continúen esas direcciones, SNMP o esa denominación.

## Uso objetivo

Cliente Linux de laboratorio, diagnóstico de conectividad, pruebas IP, DHCP, DNS, routing, capturas controladas y validación de segmentación. Mantener la separación respecto al entorno doméstico.

## Verificación pendiente

Sistema, interfaces, rutas, hostname, servicios todavía activos, ubicación física y acceso. Evaluar si procede mantener SNMP histórico o retirarlo mediante cambio autorizado, nunca automáticamente.

## Conexión física documentada

Ethernet hacia un puerto LAN del MikroTik, confirmado en la actualización del usuario del 10/10/2026. El CHANGELOG del 27/09 registra ether2; su vigencia requiere comprobación. No se conecta al SG2210P en la topología comunicada.

El CHANGELOG del 27/09 ya registra el cambio de función a prácticas y pruebas. Ser un equipo supervisado por LibreNMS no convierte a la Pi 3 en el anfitrión del servicio de monitorización. Véase [mapa físico](../topologia.md).
