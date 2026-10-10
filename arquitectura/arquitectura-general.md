# Arquitectura general

**Origen**: reconstrucción documental del CHANGELOG hasta el 10-10-2026; no auditoría en vivo.

## Entorno físico

```text
Starlink / red doméstica
  └── Raspberry Pi 4 (gateway de laboratorio)
       ├── Wi-Fi doméstica: 192.168.1.0/24 (referencia histórica)
       └── eth0: 192.168.100.1/30
            └── MikroTik ether1: 192.168.100.2/30
                 └── LAN 192.168.88.0/24
                      └── Switch TP-Link SG2210P
                           ├── EAP225
                           └── ESP32 Ethernet (tres nodos documentados)
```

Arduino Yún, estaciones de trabajo y Raspberry Pi 3 forman parte del inventario del laboratorio, pero sus puertos actuales requieren verificación.

## Entorno virtual

```text
MEDION netlab-ws01 / Debian 13
  └── KVM/QEMU y libvirt
       ├── default (NAT)
       └── lab-isolated (red interna)
            └── OPNsense (WAN prevista: default; LAN prevista: lab-isolated)
```

Ambas redes se documentaron activas, persistentes y con autoinicio. El aislamiento extremo a extremo, la asignación de interfaces y la segunda VM deben contrastarse antes de considerarlos verificados.

## Límite
No modificar Starlink, Tailscale, VPS ni servicios ajenos al laboratorio como efecto colateral de las prácticas.
