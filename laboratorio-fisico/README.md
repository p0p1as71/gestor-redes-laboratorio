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


## Extensión planificada — PYME virtual Lenovo (15/10/2026)

Se estudia añadir **clientes y servidores virtuales** (Windows 11, NAS OpenMediaVault y CUPS/IPP) a la red física mediante un adaptador USB-Ethernet del Lenovo y Linux Bridge. **No está conectado ni aprobado ningún puerto del switch para este fin**. Comprobar primero coexistencia con el MEDION (puerto 6/VLAN 20), disponibilidad de adaptador distinto, puertos, VLAN, IPAM, DHCP y aislamiento. Este plan sustituye la intención de reproducir todos los dispositivos físicos como VMs.
