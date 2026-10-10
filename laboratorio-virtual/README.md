# Laboratorio virtual — dos ámbitos independientes

**Corrección arquitectónica del 10/10/2026:** el laboratorio virtual principal es la **réplica funcional del laboratorio físico sobre el Lenovo ThinkPad L13 Gen 3**. La virtualización del MEDION es un ámbito adicional de prácticas y NO sustituye la réplica.

## 1. Réplica principal — Lenovo L13

[Diseño de la réplica](lenovo-l13/README.md). Cadena prevista: WAN controlada → VM-GW-ADMIN (equivalente Pi 4) → tránsito → VM-ROUTER (equivalente MikroTik) → switch L2/VLAN → VM-YUN, VM-ESP01/02/03, AP lógico, Windows 11.

Estado según informe de arquitectura de 10/10: infraestructura KVM/libvirt y SSD `LAB-VMS` preparada; `LAB-NET` existente pero sin función final acordada; VMs de la réplica aún no creadas en la fase documentada. No extrapolar ese estado al presente sin consulta.

## 2. Plataforma adicional — MEDION netlab-ws01

[MEDION](medion-netlab-ws01/README.md) con OPNsense, red `default` y `lab-isolated`: actividad real separada de la réplica del Lenovo. [OPNsense](opnsense/README.md) y la [práctica PRAC-003](../practicas/firewall-nat/PRAC-003-aislamiento-opnsense.md) pertenecen a este segundo ámbito.

## Regla de atribución

Cada máquina, red, prueba y evidencia debe indicar **anfitrión: Lenovo o MEDION**. No reunir interfaces ni direcciones de ambos equipos en una única topología efectiva ni considerar realizadas en uno las tareas del otro.
