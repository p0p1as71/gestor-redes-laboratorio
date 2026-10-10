# MEDION netlab-ws01 — conexión física al SG2210P

**Estado (10/10/2026):** el usuario identifica el equipo del puerto 6 como MEDION `netlab-ws01`, conectado mediante adaptador USB/Ethernet. En Omada se observa enlace activo de 1 Gbps en el puerto 6.

- Switch: SG2210P, puerto 6.
- Equipo: MEDION `netlab-ws01`.
- Interfaz física: adaptador USB/Ethernet, identificación exacta y MAC actual pendientes de contrastar.
- Dirección IP, VLAN y DHCP: pendientes de comprobar.
- Función: estación física del laboratorio que aloja virtualización adicional independiente de la réplica principal Lenovo L13.
- **Precaución:** el enlace Ethernet del MEDION al laboratorio físico no acredita que sus redes libvirt ni las interfaces de OPNsense estén conectadas o enrutadas hacia la LAN doméstica.

La identificación del equipo/puerto se fundamenta en la captura Omada y la confirmación del usuario. No acredita modificaciones de NetBox.

[Topología física](../topologia.md) · [Plataforma virtual MEDION](../../laboratorio-virtual/medion-netlab-ws01/README.md).
