# Direccionamiento IP

| Segmento | Dirección/red de referencia | Función | Estado documental |
|---|---|---|---|
| LAN doméstica | 192.168.1.0/24 | Transporte externo al laboratorio | Histórico; contrastar |
| Tránsito Pi ↔ MikroTik | 192.168.100.0/30 | Enlace dedicado | Verificado históricamente |
| Raspberry Pi 4 eth0 | 192.168.100.1/30 | Gateway del tránsito | Verificado históricamente |
| MikroTik ether1 | 192.168.100.2/30 | WAN del laboratorio | Verificado históricamente |
| LAN de laboratorio | 192.168.88.0/24 | Dispositivos físicos | Documentado; revisar clientes |
| MikroTik LAN | 192.168.88.1 | Gateway/DHCP LAN | Verificado históricamente |
| libvirt default | 192.168.122.0/24 en referencia del Lenovo | NAT de libvirt | No extrapolar al MEDION sin consulta |
| libvirt lab-isolated | Sin dirección confirmada en esta revisión | Segmento virtual | Verificación pendiente |

**Regla:** NetBox será la referencia del inventario e IPAM una vez reconciliado. No deducir direcciones actuales de capturas antiguas.
