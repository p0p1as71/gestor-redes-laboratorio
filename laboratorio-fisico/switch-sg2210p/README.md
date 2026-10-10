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

## Otras conexiones

- Puerto de uplink hacia MikroTik: **pendiente de confirmar**.
- Puerto exacto EAP225: **pendiente de confirmar**.
- Puertos de Raspberry Pi, Yún y estaciones: no inferir de registros anteriores.

## Incidencias abiertas

Omada ha mostrado discrepancias en listados de clientes online/offline; esas vistas no demuestran ausencia de enlace. Diagnosticar correlacionando puerto, MAC, concesión DHCP, ARP y tráfico.

## Siguiente prueba segura

Consultar tabla MAC actual y estado de puertos (solo lectura) y reconciliar con NetBox. No cambiar VLAN, PoE ni configuración del switch hasta tener la topología vigente.
