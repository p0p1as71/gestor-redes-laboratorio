# PRAC-005 — Generación y captura de tráfico en Debian Client

- **Fecha:** 12–13/10/2026.
- **Entorno:** virtual, MEDION `netlab-ws01` (Debian 13), VM `debian-client01`.
- **Estado:** captura PCAP obtenida y servicio manual probado; timer systemd con configuración inválida.
- **Equipo(s):** `debian-client01`, OPNsense LAN `10.10.10.1/24`.

## Qué queremos conseguir

Generar y registrar tráfico sintético reproducible (ICMP, DNS y HTTPS) para analizar protocolos de red en una misma captura PCAP y distinguir tráfico anterior y posterior a una posible traducción NAT.

## Concepto y arquitectura

```text
MEDION netlab-ws01
└── KVM/libvirt
    └── lab-isolated
        ├── debian-client01: enp1s0 / 10.10.10.179/24
        └── OPNsense LAN: 10.10.10.1/24
            └── OPNsense WAN → libvirt default / salida NAT
```

El nombre `lab-isolated` corresponde a una red virtual que **sí dispone de salida al exterior a través de OPNsense** según pruebas previas; no equivale a aislamiento efectivo respecto de todas las redes.

## Intervención registrada

- Se creó `/etc/systemd/system/netlab-traffic.service` y se verificó su ejecución manual.
- Genera ICMP (`ping` a `10.10.10.1`), resolución DNS de `example.com` y solicitud HTTPS mediante `curl`.
- Se instaló `tcpdump` y se creó `/root/netlab-captures/` para guardar capturas PCAP.
- Tras varias pruebas, se obtuvo `/root/netlab-captures/captura-06.pcap`.

**El fichero PCAP se encuentra documentado en la VM; no se ha añadido como archivo al repositorio ni se ha analizado directamente aquí.**

## Observaciones consignadas

La captura final contiene, según el informe de la sesión:

| Tráfico | Evidencia descrita | Concepto |
|---|---|---|
| STP | BPDUs `STP 802.1d, Config` aproximadamente cada 2 s | Conmutación/control de capa 2 |
| ICMP/IPv4 | Tráfico `10.10.10.179` ↔ `10.10.10.1` | IP y diagnóstico de red |
| DNS | Consultas/respuestas mediante `10.10.10.1:53`, `example.com` | Resolución de nombres |
| TCP/HTTPS | Conexiones a puerto 443; SYN → SYN/ACK → ACK y FIN | Transporte TCP y aplicación HTTPS |

Bridge ID STP observado: `8000.52:54:00:3f:26:1c.8002`.

La observación de origen `10.10.10.179` al capturar en `enp1s0` es coherente con el hecho de que el tráfico todavía no ha cruzado el punto de traducción NAT de OPNsense. **La modificación de direcciones por NAT debe demostrarse comparando otra captura en la WAN**.

## Timer systemd: incidencia abierta

- Se creó/probó `netlab-traffic.timer` para automatizar la generación.
- Una configuración de intervalo inicial de 5 minutos llegó a funcionar.
- Al intentar una expresión `OnCalendar` con frecuencia de 30 segundos, systemd la rechazó.
- **Estado final informado: `bad-setting`**. El timer no está operativo.
- **Estado del servicio:** ejecución manual funcional.

No dar por restaurada la automatización hasta verificar nuevamente sintaxis, activación y disparos reales.

## Pendientes

1. Inspeccionar la unidad timer y corregir su sintaxis; restablecer intervalo de 5 minutos y verificar disparos.
2. Capturar simultáneamente en lado LAN y lado WAN de OPNsense para visualizar NAT.
3. Registrar filtros, tiempos y comandos efectivos de captura para reproducibilidad.
4. Conservar PCAP de forma controlada: puede contener metadatos de tráfico, IP y dominios; revisar antes de compartirlo.

## Conclusión

La práctica ofrece una captura combinada para estudiar Ethernet/STP, IPv4/ICMP, DNS, TCP y HTTPS. Su observación se limita a lo consignado en el informe del 12–13/10; no se ha auditado el PCAP directamente.
