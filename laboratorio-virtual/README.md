# Laboratorio virtual

## MEDION netlab-ws01
Anfitrión Debian 13, KVM/QEMU, libvirt y Virt-Manager según CHANGELOG.

## Redes
- `default`: activa, persistente y con autoinicio en la última comprobación documentada.
- `lab-isolated`: activa, persistente y con autoinicio; el aislamiento efectivo sigue pendiente de auditoría.

## Máquinas
- `opnsense-lab`: creada y arrancada según pruebas registradas.
- Segunda máquina: se informó de su inicio, pero su identidad/configuración no quedaron confirmadas documentalmente.

## Pendientes
Comprobar interfaces WAN/LAN de OPNsense, comportamiento con tapa cerrada, identidad de VMs, rutas y reglas de salida. No tocar la red doméstica para estas validaciones.
