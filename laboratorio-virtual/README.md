# Laboratorio virtual — dos ámbitos independientes

**Corrección arquitectónica del 10/10/2026:** el laboratorio virtual principal es la **réplica funcional del laboratorio físico sobre el Lenovo ThinkPad L13 Gen 3**. La virtualización del MEDION es un ámbito adicional de prácticas y NO sustituye la réplica.

## 1. Réplica principal — Lenovo L13

[Diseño de la réplica](lenovo-l13/README.md). Cadena prevista: WAN controlada → VM-GW-ADMIN (equivalente Pi 4) → tránsito → VM-ROUTER (equivalente MikroTik) → switch L2/VLAN → VM-ESP01/02/03, AP lógico, Windows 11; VM-YUN como rama LAN del router. El ajuste del 10/10 propone VM-RPI3 como otra rama LAN para prácticas, sin acreditar aprobación ni creación.

Estado según informe de arquitectura de 10/10: infraestructura KVM/libvirt y SSD `LAB-VMS` preparada; `LAB-NET` existente pero sin función final acordada; VMs de la réplica aún no creadas en la fase documentada. No extrapolar ese estado al presente sin consulta.

## 2. Plataforma adicional — MEDION netlab-ws01

[MEDION](medion-netlab-ws01/README.md) con OPNsense, red `default` y `lab-isolated`: actividad real separada de la réplica del Lenovo. [OPNsense](opnsense/README.md) y la [práctica PRAC-003](../practicas/firewall-nat/PRAC-003-aislamiento-opnsense.md) pertenecen a este segundo ámbito.

## Regla de atribución

Cada máquina, red, prueba y evidencia debe indicar **anfitrión: Lenovo o MEDION**. No reunir interfaces ni direcciones de ambos equipos en una única topología efectiva ni considerar realizadas en uno las tareas del otro.


## Decisión vigente 15/10/2026 — sustitución del objetivo Lenovo

La **réplica integral** descrita arriba se conserva como **diseño histórico del 10/10**, no como roadmap vigente. El Lenovo pasa a ser **PYME virtual**: VM Windows 11, VM OpenMediaVault (NAS/SMB, RAID con discos virtuales), CUPS/IPP segregado y Linux Bridge. Red inicialmente aislada; conexión al SG2210P por USB-Ethernet solo después de verificar y autorizar la segmentación. La migración de Omada al VPS se estudia para liberar RAM; **no ejecutada**. MEDION continúa aparte, sin incorporarlo automáticamente. [Ficha Lenovo actualizada](lenovo-l13/README.md).
