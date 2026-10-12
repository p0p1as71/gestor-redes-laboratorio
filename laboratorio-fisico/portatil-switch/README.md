# MEDION netlab-ws01 — conexión física al SG2210P

**Estado (10/10/2026):** el usuario identifica el equipo del puerto 6 como MEDION `netlab-ws01`, conectado mediante adaptador USB/Ethernet. En Omada se observa enlace activo de 1 Gbps en el puerto 6.

- Switch: SG2210P, puerto 6.
- Equipo: MEDION `netlab-ws01`.
- Interfaz física: adaptador USB/Ethernet, Realtek RTL8153, MAC `00:E0:4C:68:31:B0` comprobada en OPNsense (`ue0`) y anteriormente en el anfitrión.
- En anfitrión, el adaptador estaba sin IP y sin bridge superior; en OPNsense, `ue0` sin IP ni estado UP administrativo. VLAN y política de comunicación física pendientes.
- Función: estación física del laboratorio que aloja virtualización adicional independiente de la réplica principal Lenovo L13.
- **Corrección tras verificación:** el USB/Ethernet sí está pasado a OPNsense y reconocido como `ue0`, con enlace a 1 Gbps. No aparece en las rutas IPv4 ni NAT observadas. Esto no acredita un bloqueo absoluto de tráfico físico.

## Actualización de sesión 12/10/2026 — VLAN 20 y OPT1

Tras diagnosticar e instalar `firmware-realtek` en el MEDION, se recuperó el passthrough USB RTL8153 a OPNsense. El adaptador aparece como `ue0`, con MAC `00:E0:4C:68:31:B0`, enlace 1000baseT full-duplex activo. OPNsense lo asignó a **OPT1** con dirección **`10.20.20.1/24`**; SG2210P **puerto 6 se configuró como Access VLAN 20 `LAB-FISICO`** (`10.20.20.0/24`). El adaptador estuvo provisionalmente conectado al Lenovo durante la actualización del MikroTik, pero la intervención posterior lo devuelve a OPNsense según informe.

La descripción anterior de `ue0` sin IP y VLAN pendiente corresponde al **10/10** y queda conservada como registro histórico. La nueva interfaz no demuestra todavía que DHCP funcione o que un cliente físico tenga conectividad; las reglas de firewall/routing y el aislamiento están pendientes.

La identificación del equipo/puerto se fundamenta en la captura Omada y la confirmación del usuario. No acredita modificaciones de NetBox.

[Topología física](../topologia.md) · [Plataforma virtual MEDION](../../laboratorio-virtual/medion-netlab-ws01/README.md).
