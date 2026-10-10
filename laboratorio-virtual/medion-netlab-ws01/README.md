# MEDION netlab-ws01 — entorno virtual adicional

**Este equipo NO aloja, por definición, la réplica virtual principal del laboratorio físico.** Es una plataforma separada de pruebas, documentada en el CHANGELOG entre el 05 y el 10/10/2026.

## Datos históricos

- Anfitrión Debian 13 con KVM/QEMU, libvirt `qemu:///system` y Virt-Manager.
- Redes `default` (NAT) y `lab-isolated`, activas, persistentes y autostart en comprobación registrada.
- `opnsense-lab` creada y ejecutándose.
- Segunda VM referida por usuario; identidad y configuración no confirmadas.
- Adaptador USB-Ethernet RTL8153 detectado, passthrough no demostrado.
- Requisito: funcionamiento con tapa cerrada; configuración/verificación pendientes.

## Trabajo pendiente propio

Verificar inventario de VMs, interfaces WAN/LAN de OPNsense, XML de `lab-isolated`, comportamiento de tapa y aislamiento.

## Límites

Ningún progreso realizado aquí significa automáticamente que la réplica Lenovo (VM-GW-ADMIN → VM-ROUTER → hosts) esté implementada. La red `LAB-NET` del Lenovo no pertenece a este anfitrión.
