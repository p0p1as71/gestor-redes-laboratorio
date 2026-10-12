# TP-Link Omada SG2210P — switching y PoE

**Rol:** switch gestionable del laboratorio físico.
**Fecha de datos:** 02–03/10/2026 y seguimientos posteriores; contrastar antes de operar.

## Configuración documentada

- Dirección IPv4 de administración: `192.168.88.251`.
- Integrado en la LAN `192.168.88.0/24`.
- Adoptado en Omada Software Controller alojado en Lenovo L13.
- EAP225 conectado mediante Ethernet/PoE con enlace observado a 1 Gb/s.
- Tres ESP32 Ethernet con negociación a 100 Mb/s Full Duplex.

## Puertos comprobados para ESP32 (03/10)

| Puerto SG2210P | Nodo | IP reservada |
|---|---|---|
| Gi1/0/3 | ESP32-01 | 192.168.88.245 |
| Gi1/0/4 | ESP32-03 | 192.168.88.247 |
| Gi1/0/5 | ESP32-02 | 192.168.88.246 |

Las direcciones MAC particulares y su evidencia histórica constan en el [CHANGELOG](../../CHANGELOG.md). No se duplican aquí hasta revisar la exposición pública de identificadores.

**Causa y solución documentadas:** inicialmente los tres ESP32 compartían la MAC `02:00:00:12:34:56`; se corrigió firmware, se asignaron MAC diferentes y se revisó la tabla MAC y DHCP. Resultado verificado el 03/10, sin atribuirle estado actual permanente.

## Actualización de conexión ESP32 — 12/10/2026

El CHANGELOG del 12/10 registra corrección del cableado LAN4/LAN5 y presenta ESP32-01 en puerto 3, ESP32-02 en puerto 4 y ESP32-03 en puerto 5. Esto **contradice el mapeo histórico del 03/10** expuesto arriba para ESP32-02/03. Registrar ambas fechas y comprobar tabla MAC/LLDP o correspondencia física antes de declarar el mapa actual certificado.

Prueba HTTP funcional documentada entre las placas en [PRAC-004](../../practicas/switching/PRAC-004-http-esp32.md).

## Otras conexiones comprobadas el 10/10/2026

- Puerto 1: uplink MikroTik por LLDP (`bridge/ether4`; extremo físico a contrastar en el MikroTik).
- Puerto 2: EAP225 por LLDP, vecino `C0:3A:55:A9:6B:C2`.
- Puerto 6: MEDION `netlab-ws01`, Realtek USB/Ethernet, MAC `00:E0:4C:68:31:B0`, enlace 1 Gbps y passthrough a OPNsense como `ue0` sin IP.
- Puertos 3–5: enlaces a 100 Mbps observados; asociación ESP32 por historial del 03/10 pendiente de reconfirmación.

**Pendiente:** verificar de nuevo la asociación individual de ESP32 en puertos 3–5 y los extremos de cableado en MikroTik.

## Incidencias abiertas

Omada ha mostrado discrepancias en listados de clientes online/offline; esas vistas no demuestran ausencia de enlace. Diagnosticar correlacionando puerto, MAC, concesión DHCP, ARP y tráfico.

## Siguiente prueba segura

Reconciliar la tabla MAC y los puertos confirmados con NetBox. No deducir que una lista incompleta de clientes Omada indica puertos desconectados. No cambiar VLAN, PoE ni configuración del switch hasta tener la topología vigente.

Referencia vigente: [diagrama físico y mapa de conexiones](../topologia.md).
