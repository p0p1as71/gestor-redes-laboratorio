# PRAC-003 — Comprobar aislamiento efectivo de MEDION/OPNsense

**Estado:** PRUEBAS PARCIALES REALIZADAS — 10/10/2026.  
**Entorno:** MEDION, no réplica Lenovo.  
**Método:** inspección XML, rutas, firewall/NAT y pruebas ICMP/DNS desde `debian-client01`.

## Concepto

La palabra `isolated` en libvirt define una red sin `forward` propio; una VM multihomed como OPNsense puede comunicar esa LAN con otra red. Es necesario verificar el sistema completo.

## Arquitectura observada

```text
debian-client01 10.10.10.179/24
       ↕ enp1s0 / vnet2
lab-isolated / virbr-lab (sin forward libvirt)
       ↕ vnet1 / em1
OPNsense 10.10.10.1 (LAN)
       ↕ firewall + NAT + IPv4 forwarding
OPNsense 192.168.122.159 (WAN em0 / vnet0)
       ↕
default / virbr0 → gateway 192.168.122.1 → salida exterior
```

Tercera interfaz de OPNsense: `ue0` (RTL8153 vía USB passthrough, MAC `00:E0:4C:68:31:B0`, conectada físicamente al SG2210P puerto 6). Enlace activo 1 Gbps, sin IP ni `UP` administrativo.

## Evidencias y resultados

| Prueba | Resultado |
|---|---|
| VM OPNsense | Dos NIC e1000 + Realtek USB; ejecución verificada |
| VM Debian | Una NIC e1000e en `lab-isolated` |
| XML `lab-isolated` | Sin `forward` ni IP de bridge declarados |
| Dirección Debian | Inicialmente link-local `169.254.229.206`; después `10.10.10.179` por DHCP |
| Ruta Debian | Predeterminada por `10.10.10.1` |
| Ping `10.10.10.1` | 4/4 respuestas, 0 % pérdidas |
| Ping `192.168.122.1` | 4/4 respuestas, 0 % pérdidas |
| Ping `1.1.1.1` | 4/4 respuestas, 0 % pérdidas |
| DNS `debian.org` | Resolución IPv4 correcta; nameserver `10.10.10.1` |
| Kernel OPNsense | Forwarding IPv4 habilitado |
| PF en OPNsense | Regla LAN → any; NAT LAN → WAN configurados |
| Ruta hacia `192.168.88.1` consultada en Debian | Vía `10.10.10.1`; **solo consulta de ruta, no prueba de acceso** |
| Acceso efectivo a la LAN física | NO COMPROBADO |

## Conclusión

**No declarar aislamiento total.** El cliente tiene salida a Internet a través de OPNsense y libvirt `default`. No se ha demostrado si puede alcanzar directamente dispositivos de la LAN física `192.168.88.0/24`. Una ruta de salida no prueba acceso efectivo.

## Siguiente decisión necesaria

Definir la política deseada: laboratorio sin salida, con Internet restringido, o con salida controlada y bloqueo explícito a redes privadas. Antes de cambios: comprobar configuración y respaldo, hacer un único cambio reversible y validar.
