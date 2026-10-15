# Direccionamiento IP

| Segmento | Dirección/red de referencia | Función | Estado documental |
|---|---|---|---|
| LAN doméstica | 192.168.1.0/24 | Transporte externo al laboratorio | Histórico; contrastar |
| Tránsito Pi ↔ MikroTik | 192.168.100.0/30 | Enlace dedicado | Verificado históricamente |
| Raspberry Pi 4 eth0 | 192.168.100.1/30 | Gateway del tránsito | Verificado históricamente |
| MikroTik ether1 | 192.168.100.2/30 | WAN del laboratorio | Verificado históricamente |
| LAN de laboratorio | 192.168.88.0/24 | Dispositivos físicos | Documentado; revisar clientes |
| MikroTik LAN | 192.168.88.1 | Gateway/DHCP LAN | Verificado históricamente |
| Lenovo libvirt `default` | 192.168.122.0/24 según informe Lenovo | NAT del Lenovo | Histórico por verificar |
| MEDION libvirt `default` | 192.168.122.0/24; OPNsense WAN 192.168.122.159/24 | NAT libvirt MEDION | Verificado 10/10/2026 |
| MEDION libvirt `lab-isolated` | 10.10.10.0/24; OPNsense LAN 10.10.10.1; Debian 10.10.10.179 (DHCP) | Segmento virtual, con salida vía OPNsense | Verificado históricamente 10/10/2026; conservado según 12/10 |
| MEDION / OPNsense `OPT1/ue0` | `10.20.20.1/24` | Gateway previsto de LAB-FISICO | Interfaz y enlace verificados según informe 12/10 |
| LAB-FISICO / VLAN 20 | `10.20.20.0/24` | Segmento físico nuevo por SG2210P puerto 6 Access | VLAN configurada; sin cliente físico ni DHCP acreditado |
| LAB-FISICO / pool DHCP previsto | `10.20.20.100–10.20.20.200` | Direcciones de clientes | Introducido en asistente, servicio DHCP sin verificar |

| Ruta en Raspberry Pi 4 (15/10) | Destino `192.168.88.0/24` vía `192.168.100.2 dev eth0` | Alcanzar LAN MikroTik desde Pi 4 | Guardada en NetworkManager y activa según `ip route get`; reinicio sin verificar |

**Regla:** NetBox será la referencia del inventario e IPAM una vez reconciliado. No deducir direcciones actuales de capturas antiguas.

## Actualización física 10/10/2026

Pi 3 y Yún están documentados en MikroTik LAN; el portátil adicional está en SG2210P. El MEDION del puerto 6 no tenía IP en el adaptador USB/Ethernet; su MAC `00:E0:4C:68:31:B0` fue comprobada dentro de OPNsense como `ue0`. Las IP históricas de Pi 3/Yún y ESP32 no se convierten en asignaciones actuales por actualizar el diagrama.

## Actualización 12/10/2026

El 10/10 `ue0` se observó sin dirección IP; **el 12/10** quedó configurada como OPNsense `OPT1`, `10.20.20.1/24`, sobre VLAN 20 mediante SG2210P puerto 6 Access. El nombre de las interfaces virtuales OPNsense pasó en las observaciones de `em0`/`em1` (10/10) a `re1`/`re0` (12/10), sin causa confirmada. No se ha demostrado concesión DHCP de OPT1 ni aislamiento entre segmentos. Las redes `default` de Lenovo y MEDION son independientes aunque coincidan en prefijo.

Lenovo y MEDION conservan sus redes independientes: [redes por anfitrión](../laboratorio-virtual/redes-libvirt/README.md).
