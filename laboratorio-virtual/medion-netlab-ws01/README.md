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

## Topología propia: diseño de conexiones, no asignación comprobada

| Origen | Destino previsto | Estado |
|---|---|---|
| default de MEDION | WAN de opnsense-lab | Asociación pendiente de comprobar |
| LAN de opnsense-lab | lab-isolated de MEDION | Asociación pendiente de comprobar |
| Cliente virtual por identificar | lab-isolated | Conexión pendiente de comprobar |

Las redes y opnsense-lab tienen ejecución histórica documentada. El inicio comunicado de una segunda VM no demuestra que sea el cliente del esquema.

No hay conexión física del MEDION al MikroTik o al SG2210P acreditada en esta revisión. El adaptador RTL8153 detectado no demuestra un cable conectado ni passthrough a OPNsense.
