# MEDION netlab-ws01 — anfitrión virtual

**Base documental:** CHANGELOG 05–10/10/2026, no comprobación en vivo.

- Sistema: Debian 13.
- Hipervisor: KVM/QEMU; administración libvirt mediante `qemu:///system`, Virt-Manager y virsh.
- Redes de libvirt documentadas: `default` y `lab-isolated`, ambas activas, persistentes y con autoinicio en última comprobación registrada.
- VM identificada: `opnsense-lab`, creada y arrancada.
- Segunda VM: se comunicó su inicio, pero nombre y configuración no constan suficientemente confirmados.
- Adaptador USB Ethernet: Realtek RTL8153, identificador USB `0bda:8153`, interfaz observada `enx00e04c6831b0`. Passthrough no confirmado.

## Requisito operativo

Con tapa cerrada debe permanecer encendido, sin suspensión ni hibernación, y mantener redes y VMs. **Configuración y resultado aún pendientes de comprobación**.

## Validación pendiente

1. Inventario de VMs e interfaces realmente asignadas.
2. Estado de autoinicio de **cada VM** (no confundir con autoinicio de redes).
3. XML de `default` y `lab-isolated`.
4. Comportamiento real de tapa cerrada.
5. Rutas desde anfitrión y seguridad de acceso a LAN doméstica.

No ejecutar cambios sobre servicios ajenos al laboratorio.
