# Arquitectura general del laboratorio de redes

## Tres implementaciones diferenciadas

1. **Físico:** infraestructura real Raspberry Pi 4 → MikroTik → switch SG2210P → EAP225, ESP32 y otros nodos.
2. **Virtual principal Lenovo L13:** réplica funcional de esa cadena, todavía en fase de diseño e implementación; [detalle](../laboratorio-virtual/lenovo-l13/README.md).
3. **Virtual adicional MEDION:** KVM/QEMU con OPNsense y redes libvirt, para pruebas separadas; [detalle](../laboratorio-virtual/medion-netlab-ws01/README.md).

## Laboratorio físico — referencia actualizada por CHANGELOG

```text
Starlink / 192.168.1.0/24 (histórico)
  └── Raspberry Pi 4 (gateway/admin)
       └── tránsito 192.168.100.0/30
            └── MikroTik (LAN 192.168.88.0/24)
                 ├── Arduino Yún (conexión histórica)
                 └── SG2210P
                      ├── EAP225
                      └── ESP32 × 3
```

El informe de diseño de la réplica citó **TL-SG108PE** como modelo de referencia en una versión anterior de topología; el CHANGELOG posterior registra el **SG2210P** como switch instalado. Revisar el inventario vivo para identificar cualquier dispositivo adicional; no equiparar ambos modelos.

## Réplica virtual Lenovo (objetivo)

```text
WAN controlada → VM-GW-ADMIN → red de tránsito
    → VM-ROUTER → switch virtual L2/VLAN
       → VM-YUN + VM-ESP01/02/03 + AP lógico + Windows 11
```

El informe del 10/10 registra `LAB-NET` 192.168.50.0/24 en el Lenovo, sin función definitiva. No asignarle automáticamente la LAN de la réplica.

## Virtualización adicional MEDION (histórico documentado)

```text
MEDION netlab-ws01 (Debian 13)
  └── libvirt
       ├── default (NAT)
       └── lab-isolated (segmento interno)
             └── OPNsense (WAN/LAN previstas, asignación pendiente de comprobar)
```

**Importante:** `LAB-NET` (Lenovo) y `lab-isolated` (MEDION) no son la misma red.

## Límites

No alterar de forma incidental el entorno doméstico, Tailscale, Docker, VPS ni producción. Distinguir diseño, configuración histórica y estado comprobado del momento.
