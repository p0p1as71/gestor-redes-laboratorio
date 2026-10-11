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
| MEDION libvirt `lab-isolated` | 10.10.10.0/24; OPNsense LAN 10.10.10.1; Debian 10.10.10.179 (DHCP) | Segmento virtual, con salida vía OPNsense | Verificado 10/10/2026 |

**Regla:** NetBox será la referencia del inventario e IPAM una vez reconciliado. No deducir direcciones actuales de capturas antiguas.

## Actualización física 10/10/2026

Pi 3 y Yún están documentados en MikroTik LAN; el portátil adicional está en SG2210P. El MEDION del puerto 6 no tenía IP en el adaptador USB/Ethernet; su MAC `00:E0:4C:68:31:B0` fue comprobada dentro de OPNsense como `ue0`. Las IP históricas de Pi 3/Yún y ESP32 no se convierten en asignaciones actuales por actualizar el diagrama.

Lenovo y MEDION conservan sus redes independientes: [redes por anfitrión](../laboratorio-virtual/redes-libvirt/README.md).
