# Laboratorio físico

## Componentes
- Raspberry Pi 4: gateway y servicios NetBox/LibreNMS documentados.
- MikroTik hEX lite: routing y firewall del laboratorio físico.
- TP-Link SG2210P: switching y PoE.
- EAP225: punto de acceso.
- Tres ESP32 Ethernet: servidor HTTP, cliente y monitor documentados; sketch servidor corregido publicado en GitHub, revalidación posterior pendiente.
- Arduino Yún: dispositivo Linux/microcontrolador para prácticas.
- Raspberry Pi 3: prácticas y pruebas de red, no monitorización principal.
- MEDION `netlab-ws01` conectado al puerto 6 del SG2210P mediante adaptador USB/Ethernet Realtek, con passthrough a OPNsense.
- **Lenovo L13: conectado físicamente al SG2210P mediante USB-Ethernet `enx00e04c6808a2` y bridge `br-pyme` (DHCP `192.168.88.236/24`, ping a MikroTik 4/4 el 15/10). Puerto físico del switch no identificado. Omada sigue en Lenovo; Windows 11, OMV y CUPS pendientes.**

Ficha de conexión física: [MEDION en el switch](portatil-switch/README.md).

Consultar [inventario](inventario/README.md) y [topología](topologia.md). La asignación de puertos actual requiere conciliación con NetBox y las tablas de equipos.


## Extensión PYME virtual Lenovo — bridge implementado, VMs pendientes (15/10/2026)

**La conexión física del anfitrión ya existe:** `br-pyme` integra USB-Ethernet en la LAN `192.168.88.0/24` y responde al MikroTik. No debe presentarse como futura ni aislada; **no hay máquinas virtuales conectadas** ni políticas VLAN adicionales acreditadas. El puerto exacto del SG2210P al que llega el Lenovo sigue pendiente de identificación, sin confundirlo con el puerto 6 del MEDION. Se prevén Windows 11, NAS OpenMediaVault y CUPS/IPP, previa verificación de direccionamiento, aislamiento y riesgos de conexión.
