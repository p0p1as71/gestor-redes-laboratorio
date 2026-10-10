# MEDION netlab-ws01 — plataforma virtual adicional

**Ámbito:** independiente de la réplica virtual principal del Lenovo L13.

## Estado comprobado — sesión 10/10/2026

- Anfitrión Debian 13; KVM/QEMU, libvirt `qemu:///system`.
- VMs en ejecución: `opnsense-lab` y `debian-client01`.
- Redes libvirt `default` y `lab-isolated`: activas, persistentes y con autostart.
- `lab-isolated`: bridge `virbr-lab`; XML sin elemento `forward` ni IP propia; 2 conexiones virtuales.
- OPNsense: `vnet0` → `default` (WAN `em0`); `vnet1` → `lab-isolated` (LAN `em1`).
- Debian: `vnet2` → `lab-isolated` exclusivamente.
- Conexión física MEDION ↔ SG2210P puerto 6 por adaptador Realtek RTL8153, MAC `00:E0:4C:68:31:B0`, enlace 1 Gbps.
- El adaptador aparece como `enx00e04c6831b0` en el anfitrión sin IP ni master; también se confirmó **passthrough USB a OPNsense**, donde aparece como `ue0`, enlace activo y sin IP ni flag administrativo UP.

## Topología comprobada

```text
MEDION netlab-ws01 (Debian 13)
  ├── Wi-Fi del anfitrión (ruta física de salida no analizada)
  ├── USB RTL8153 ── SG2210P puerto 6
  │     └── passthrough a OPNsense como ue0 (sin IP; enlace activo)
  └── libvirt
       ├── default / virbr0 / 192.168.122.0/24
       │     └── OPNsense WAN em0: 192.168.122.159/24 (DHCP)
       └── lab-isolated / virbr-lab
             ├── OPNsense LAN em1: 10.10.10.1/24
             └── Debian enp1s0: 10.10.10.179/24 (DHCP)
```

## Resultados funcionales

Desde `debian-client01` se verificaron con cuatro paquetes ICMP y 0 % de pérdida: `10.10.10.1`, `192.168.122.1` y `1.1.1.1`. `getent ahostsv4 debian.org` resolvió nombres; DNS configurado `10.10.10.1`.

**Conclusión:** la LAN llamada `lab-isolated` **sí tiene salida al exterior** mediante OPNsense, firewall/NAT y `default`. No es un entorno completamente aislado. La ausencia de IP/ruta en `ue0` no demuestra imposibilidad de comunicación a nivel 2; no se han comprobado accesos desde la VM a redes privadas físicas.

El funcionamiento tras futuros reinicios, cierre de tapa, seguridad de acceso remoto y aislamiento frente a otras LAN siguen pendientes.

[Detalle OPNsense](../opnsense/README.md) · [Práctica y mediciones](../../practicas/firewall-nat/PRAC-003-aislamiento-opnsense.md).
