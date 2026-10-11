# MEDION netlab-ws01 — conexión física al SG2210P

**Estado (10/10/2026):** el usuario identifica el equipo del puerto 6 como MEDION `netlab-ws01`, conectado mediante adaptador USB/Ethernet. En Omada se observa enlace activo de 1 Gbps en el puerto 6.

- Switch: SG2210P, puerto 6.
- Equipo: MEDION `netlab-ws01`.
- Interfaz física: adaptador USB/Ethernet, Realtek RTL8153, MAC `00:E0:4C:68:31:B0` comprobada en OPNsense (`ue0`) y anteriormente en el anfitrión.
- En anfitrión, el adaptador estaba sin IP y sin bridge superior; en OPNsense, `ue0` sin IP ni estado UP administrativo. VLAN y política de comunicación física pendientes.
- Función: estación física del laboratorio que aloja virtualización adicional independiente de la réplica principal Lenovo L13.
- **Corrección tras verificación:** el USB/Ethernet sí está pasado a OPNsense y reconocido como `ue0`, con enlace a 1 Gbps. No aparece en las rutas IPv4 ni NAT observadas. Esto no acredita un bloqueo absoluto de tráfico físico.

La identificación del equipo/puerto se fundamenta en la captura Omada y la confirmación del usuario. No acredita modificaciones de NetBox.

[Topología física](../topologia.md) · [Plataforma virtual MEDION](../../laboratorio-virtual/medion-netlab-ws01/README.md).
