# Laboratorio físico

## Componentes
- Raspberry Pi 4: gateway y servicios NetBox/LibreNMS documentados.
- MikroTik hEX lite: routing y firewall del laboratorio físico.
- TP-Link SG2210P: switching y PoE.
- EAP225: punto de acceso.
- Tres ESP32 Ethernet: función de diagnóstico pendiente de consolidar.
- Arduino Yún: dispositivo Linux/microcontrolador para prácticas.
- Raspberry Pi 3: prácticas y pruebas de red, no monitorización principal.
- MEDION `netlab-ws01` conectado al puerto 6 del SG2210P mediante adaptador USB/Ethernet Realtek, con passthrough a OPNsense.
- Lenovo L13: controlador Omada según histórico y anfitrión previsto de la réplica virtual; no se identifica automáticamente con el portátil del switch.

Ficha de conexión física: [MEDION en el switch](portatil-switch/README.md).

Consultar [inventario](inventario/README.md) y [topología](topologia.md). La asignación de puertos actual requiere conciliación con NetBox y las tablas de equipos.

