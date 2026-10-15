# Arquitectura general del laboratorio de redes

## Tres implementaciones diferenciadas

1. **Físico:** Raspberry Pi 4 → MikroTik; Pi 3 y Yún conectados directamente a puertos LAN del MikroTik; SG2210P conectado al MikroTik y, al switch, EAP225, tres ESP32 y adaptador RTL8153 del MEDION `netlab-ws01` en puerto 6 del SG2210P, configurado Access VLAN 20 el 12/10.
2. **Virtual principal Lenovo L13:** PYME virtual (Windows 11, OpenMediaVault, CUPS/IPP y Linux Bridge, diseño aprobado el 15/10, aún no desplegado), sustituyendo la réplica funcional como objetivo activo; [detalle](../laboratorio-virtual/lenovo-l13/README.md).
3. **Virtual adicional MEDION:** KVM/QEMU con OPNsense y redes libvirt, para pruebas separadas; [detalle](../laboratorio-virtual/medion-netlab-ws01/README.md).

## Laboratorio físico — conexiones documentadas

El [diagrama físico y mapa de conexiones](../laboratorio-fisico/topologia.md) recoge la actualización del usuario del 10/10/2026 y la evidencia histórica del CHANGELOG. Es la referencia documental vigente del cableado, con ESP32-01/02/03 comunicados en puertos 3/4/5 desde el 12/10 y correlación MAC↔placa pendiente.

La Pi 3 es estación de prácticas y pruebas. El Yún cuelga de otro puerto LAN del MikroTik; el MEDION se conecta mediante Realtek USB/Ethernet al puerto 6 del SG2210P. No representar estos tres equipos como una única rama del switch.

El informe de diseño de la réplica citó **TL-SG108PE** como modelo de referencia en una versión anterior de topología; el CHANGELOG posterior registra el **SG2210P** como switch instalado. Revisar el inventario vivo para identificar cualquier dispositivo adicional; no equiparar ambos modelos.

## Lenovo — PYME virtual (objetivo vigente desde 15/10)

El [diseño Lenovo](../laboratorio-virtual/lenovo-l13/README.md) prevé Windows 11, OpenMediaVault con discos virtuales para prácticas RAID, CUPS/IPP y un Linux Bridge inicialmente aislado. Un enlace posterior mediante Ethernet al SG2210P requerirá validación de VLAN, DHCP, rutas, permisos e IPAM. **No se ha desplegado ni conectado**.

**Diseño anterior, histórico 10/10:** una réplica gateway, router, switch y hosts (VM-RPI3/VM-YUN/VM-ESP). Ya no es el plan de ejecución. La red LAB-NET 192.168.50.0/24 consta en registros antiguos de Lenovo y su función actual debe consultarse antes de asignarla a la PYME.

## Virtualización adicional MEDION (estado histórico 10/10 y actualización 12/10)

| Componente MEDION | Función / relación |
|---|---|
| netlab-ws01 | Anfitrión Debian 13 con libvirt |
| default | Red NAT propia de MEDION |
| lab-isolated | Segmento interno libvirt; conexión desde Debian a Internet verificada mediante OPNsense |
| opnsense-lab | WAN `em0` 192.168.122.159/24 en `default`; LAN `em1` 10.10.10.1/24 en `lab-isolated`; interfaz física USB `ue0` sin IP |
| debian-client01 | Cliente en `lab-isolated` con 10.10.10.179/24 por DHCP; salida a Internet y DNS verificados |

[Detalle MEDION](../laboratorio-virtual/medion-netlab-ws01/README.md). LAB-NET (Lenovo) y lab-isolated (MEDION) pertenecen a anfitriones distintos.

**Actualización informada 12/10/2026:** OPNsense conservó WAN/LAN virtuales pero las interfaces fueron reportadas como WAN `re1` y LAN `re0` (nombres históricos `em0`/`em1` el 10/10; causa pendiente de comprobar). Se añadió OPT1 sobre RTL8153 `ue0` con `10.20.20.1/24`; SG2210P puerto 6 opera Access VLAN 20 `LAB-FISICO`. La VLAN 20 no sustituye la LAN MikroTik `192.168.88.0/24` y no existe cliente físico probado ni DHCP OPT1 acreditado. [Detalle OPNsense](../laboratorio-virtual/opnsense/README.md).

## Límites

No alterar de forma incidental el entorno doméstico, Tailscale, Docker, VPS ni producción. Distinguir diseño, configuración histórica y estado comprobado del momento.


## Cambio de estrategia acordado — 15/10/2026

El diseño de réplica funcional del 10/10 es **histórico y sustituido como objetivo activo**. En Lenovo se proyecta una **PYME virtual** con Windows 11 como puesto de trabajo; OpenMediaVault como NAS con discos virtuales para RAID 0/1/5/10; y CUPS/IPP en contenedor aislado (sin enlazar Docker de producción). KVM/QEMU alojará las VMs y un Linux Bridge conectará sus interfaces, inicialmente en red de prueba aislada. Solo después de revisar puertos, VLAN, DHCP, reservas y controles de acceso podrá estudiarse un uplink USB-Ethernet al SG2210P en la LAN `192.168.88.0/24`. Direcciones `.110`, `.120` y `.130` son **propuestas**, no reservas. El adaptador del MEDION es parte de otra plataforma: **no asumir disponibilidad del mismo adaptador para Lenovo**.

La reducción de consumo del Lenovo depende de una futura migración controlada de Omada al VPS Hetzner; no se ha iniciado. MEDION y producción se mantienen separados. [Diseño PYME](../laboratorio-virtual/lenovo-l13/README.md).
