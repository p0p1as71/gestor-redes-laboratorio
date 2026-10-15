# Máquinas virtuales — inventarios separados

## Réplica principal sobre Lenovo L13

**Estado en el informe 10/10/2026:** sin VMs creadas en la fase de preparación allí descrita. Objetivo: VM-GW-ADMIN, VM-ROUTER, VM-YUN, VM-ESP01, VM-ESP02, VM-ESP03 y VM-WIN11, más switch y AP lógicos. La existencia actual debe contrastarse directamente con el anfitrión. El ajuste documental del 10/10 propone además VM-RPI3 para prácticas, pendiente de decisión y creación; no atribuir al cliente VM-WIN11 la identidad del portátil físico sin confirmar.

## Prácticas independientes sobre MEDION

| Identificador | Anfitrión | Estado en CHANGELOG |
|---|---|---|
| `opnsense-lab` | MEDION | Creada y activa en las pruebas registradas |
| `debian-client01` | MEDION | Ejecutando el 10/10; `vnet2` en `lab-isolated`, IP 10.10.10.179 DHCP, conectividad exterior comprobada |

Ninguna VM de MEDION se cuenta como máquina de la réplica del Lenovo.

Para cada VM registrar: anfitrión, propósito, interfaces, redes, recursos, fecha/evidencia de comprobación y política de respaldo.


## Nuevo objetivo Lenovo — PYME virtual (15/10/2026)

El inventario de VMs de réplica descrito arriba es **histórico**, no un despliegue ni la lista de creación vigente. Nuevos objetivos: **Windows 11** (KVM/QEMU, puesto de trabajo, RAM inicial de planificación 4 GB); **OpenMediaVault** (KVM/QEMU, servidor NAS/SMB sin escritorio, 1–2 GB RAM previstos y cuatro discos virtuales de prueba para comparar RAID 0/1/5/10, configuraciones sucesivas); **CUPS** (preferentemente Docker aislado, 100–200 MB estimados, con acceso IPP diseñado explícitamente). Estos consumos no se han medido. La disponibilidad de CPU/RAM/SSD externo y licencias se verificará antes de crear máquinas. No se han implementado estas VMs en esta intervención. MEDION sigue independiente.
