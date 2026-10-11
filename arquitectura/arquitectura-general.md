# Arquitectura general del laboratorio de redes

## Tres implementaciones diferenciadas

1. **Físico:** Raspberry Pi 4 → MikroTik; Pi 3 y Yún conectados directamente a puertos LAN del MikroTik; SG2210P conectado al MikroTik y, al switch, EAP225, tres ESP32 y MEDION `netlab-ws01` en puerto 6 del SG2210P.
2. **Virtual principal Lenovo L13:** réplica funcional de esa cadena, todavía en fase de diseño e implementación; [detalle](../laboratorio-virtual/lenovo-l13/README.md).
3. **Virtual adicional MEDION:** KVM/QEMU con OPNsense y redes libvirt, para pruebas separadas; [detalle](../laboratorio-virtual/medion-netlab-ws01/README.md).

## Laboratorio físico — conexiones documentadas

El [diagrama físico y mapa de conexiones](../laboratorio-fisico/topologia.md) recoge la actualización del usuario del 10/10/2026 y la evidencia histórica del CHANGELOG. Es la referencia documental vigente del cableado, con puertos pendientes explícitos.

La Pi 3 es estación de prácticas y pruebas. El Yún cuelga de otro puerto LAN del MikroTik; el MEDION se conecta mediante Realtek USB/Ethernet al puerto 6 del SG2210P. No representar estos tres equipos como una única rama del switch.

El informe de diseño de la réplica citó **TL-SG108PE** como modelo de referencia en una versión anterior de topología; el CHANGELOG posterior registra el **SG2210P** como switch instalado. Revisar el inventario vivo para identificar cualquier dispositivo adicional; no equiparar ambos modelos.

## Réplica virtual Lenovo (objetivo)

El [diseño Lenovo](../laboratorio-virtual/lenovo-l13/README.md) conserva gateway, tránsito, router, switch y hosts. El ajuste propone VM-RPI3 para prácticas y sitúa VM-YUN en una rama LAN del router; son objetivos sin despliegue acreditado.

El informe citado registra LAB-NET 192.168.50.0/24 en Lenovo, sin función definitiva. No asignarle automáticamente la LAN de la réplica.

## Virtualización adicional MEDION (verificada el 10/10/2026)

| Componente MEDION | Función / relación |
|---|---|
| netlab-ws01 | Anfitrión Debian 13 con libvirt |
| default | Red NAT propia de MEDION |
| lab-isolated | Segmento interno libvirt; conexión desde Debian a Internet verificada mediante OPNsense |
| opnsense-lab | WAN `em0` 192.168.122.159/24 en `default`; LAN `em1` 10.10.10.1/24 en `lab-isolated`; interfaz física USB `ue0` sin IP |
| debian-client01 | Cliente en `lab-isolated` con 10.10.10.179/24 por DHCP; salida a Internet y DNS verificados |

[Detalle MEDION](../laboratorio-virtual/medion-netlab-ws01/README.md). LAB-NET (Lenovo) y lab-isolated (MEDION) pertenecen a anfitriones distintos.

## Límites

No alterar de forma incidental el entorno doméstico, Tailscale, Docker, VPS ni producción. Distinguir diseño, configuración histórica y estado comprobado del momento.

