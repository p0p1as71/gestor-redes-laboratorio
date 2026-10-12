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

## Cambio comunicado el 12/10/2026 — RTL8153 y OPNsense OPT1

En Debian 13 se diagnosticó la ausencia de `rtl_nic/rtl8153b-2.fw`, se instaló `firmware-realtek` y, tras reiniciar físicamente el adaptador, cesaron los errores indicados. Se recuperó el passthrough USB `0bda:8153` a `opnsense-lab`; OPNsense observó `ue0`, MAC `00:e0:4c:68:31:b0`, enlace 1 Gbps full-duplex activo. La persistencia se configuró por vendor/product y se verificó en la sesión, sin demostrar todavía comportamiento tras reinicios posteriores.

**Asignación actual comunicada:** WAN `re1` y LAN `re0` (interfaces virtuales conservadas) y nueva OPT1 `ue0` con `10.20.20.1/24`. El switch SG2210P conecta el adaptador por su puerto 6 **Access VLAN 20**, nueva red `LAB-FISICO` (`10.20.20.0/24`). DHCP de OPT1 no verificado y sin pruebas con cliente físico.

[Detalle de la actualización OPNsense](../opnsense/README.md).

## Topología comprobada el 10/10 (histórica)

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

**Nota:** la topología anterior refleja los nombres `em0`/`em1` y la interfaz `ue0` sin IP el **10/10**, no el estado informado el **12/10**.

## Tráfico sintético y captura PCAP — sesión 12–13/10/2026

En `debian-client01` (`enp1s0`, `10.10.10.179/24`, gateway `10.10.10.1`) se creó `/etc/systemd/system/netlab-traffic.service` para generar tráfico ICMP al gateway, DNS de `example.com` y HTTPS con `curl`. La ejecución manual funcionó. Se instaló `tcpdump` y se obtuvo `/root/netlab-captures/captura-06.pcap`, con STP periódico, ICMP, DNS y TCP/HTTPS según el informe de sesión. **El PCAP no está incorporado al repositorio.**

Se probaron disparos automáticos mediante `netlab-traffic.timer`: el intervalo original de 5 minutos llegó a funcionar; una modificación temporal a 30 segundos generó configuración inválida `bad-setting`. **Timer pendiente de reparación**. Próxima validación: capturar también en WAN para observar NAT. [PRAC-005](../../practicas/diagnostico/PRAC-005-trafico-pcap-debian-client.md).

## Resultados funcionales (10/10)

Desde `debian-client01` se verificaron con cuatro paquetes ICMP y 0 % de pérdida: `10.10.10.1`, `192.168.122.1` y `1.1.1.1`. `getent ahostsv4 debian.org` resolvió nombres; DNS configurado `10.10.10.1`.

**Conclusión:** la LAN llamada `lab-isolated` **sí tiene salida al exterior** mediante OPNsense, firewall/NAT y `default`. No es un entorno completamente aislado. La ausencia de IP/ruta en `ue0` no demuestra imposibilidad de comunicación a nivel 2; no se han comprobado accesos desde la VM a redes privadas físicas.

El funcionamiento tras futuros reinicios, cierre de tapa, seguridad de acceso remoto y aislamiento frente a otras LAN siguen pendientes.

[Detalle OPNsense](../opnsense/README.md) · [Práctica y mediciones](../../practicas/firewall-nat/PRAC-003-aislamiento-opnsense.md).
