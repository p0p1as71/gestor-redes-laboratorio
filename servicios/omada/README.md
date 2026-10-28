# Omada Software Controller

**Anfitrión actual según informe recibido el 28/10/2026:** VPS Hetzner `Ailab-core01`. Omada desinstalado del Lenovo.
**Componentes documentados el 03/10:** Omada Network Application 6.3.0.45, Java 17, MongoDB 8.0.32, jsvc. Versiones históricas, no verificadas hoy.

- Equipos adoptados: SG2210P y EAP225.
- Interfaz web: puertos 8088/TCP y 8043/TCP según instalación.
- Para continuidad de adopción al cambiar el Lenovo de red, se documentó descubrimiento mediante DHCP Option 138 anunciando su dirección Tailscale.
- Se observaron conexiones al puerto 29814/TCP y eventos previos `Heartbeat Missed` / `Disconnected`.

## Incidencia de clientes

Los listados de clientes en Omada mostraron discrepancias frente a las conexiones esperadas. Antes de interpretar una ausencia en la interfaz, comparar:
1. Estado físico del puerto / enlace.
2. Tabla de MAC del switch.
3. Concesiones DHCP del MikroTik.
4. ARP y pruebas activas autorizadas.
5. Historia online/offline de Omada.

## Límites

No usar Tailscale como sustituto implícito de una LAN o de medidas de seguridad. No reconfigurar controlador, DHCP ni dispositivos adoptados sin verificar estado y posibilidad de reversión.


## Plan histórico de migración — 15/10/2026 (SUPERADO)

**Objetivo:** liberar RAM del Lenovo y mantener Omada Network Controller (v6.3.0.45 documentada) disponible sin depender de él, mediante alojamiento en VPS Debian 12 `Ailab-core01`. Controlador actual Lenovo **permanece operativo**; no realizar corte ni desinstalación antes de backup, adopción validada y reversión preparada.

**Camino previsto:** VPS → Tailscale → Raspberry Pi 4 (gateway/route advertisement) → MikroTik → SG2210P/EAP225 en `192.168.88.0/24`. No suponer que ping al MikroTik implica conectividad hacia el switch o AP. Evitar aperturas innecesarias de puertos del VPS a Internet: preferir administración y comunicación mediante Tailscale con política de acceso explícita.

### VPS: preparación documentada en sesión 15/10

- En VPS Hetzner Debian 12, el disco de 150 GB llegó al 95 %. Tras conservar tres backups locales recientes, el uso reportado es **46 GB usados / 99 GB libres / 32 %**, liberando aprox. 91 GB. Se editó `/home/ailab/ai-lab-core/scripts/backup.sh` con copia previa `backup.sh.bak-20261015` para retener tres carpetas locales antes de sincronizar Google Drive. **La ejecución completa, restaurabilidad y política de retención remota están pendientes**.
- Swap de **4 GiB** creado y activado en `/swapfile`, persistencia configurada en `/etc/fstab`; memoria reportada 15 GiB total, 6,2 GiB disponible, swap usada 0. Reinicio no probado.
- Se habilitó `tailscale set --accept-routes=true` en VPS; Raspberry anuncia `192.168.100.0/30` y `192.168.88.0/24`. La salida Internet general del VPS permaneció en Hetzner según informe.
- Ping VPS → MikroTik LAN `192.168.88.1` **4/4 respuestas** (0 % pérdida; RTT medio ~71 ms) el 15/10. SSH VPS → MikroTik WAN `192.168.100.2` documentado correcto. **No se ha validado acceso VPS → SG2210P/EAP225**. La captura ICMP del sniffer de `ether1` no se conservó al cerrarse Termius; **origen del tráfico, posible SNAT y recorrido exacto siguen pendientes**.

### Validación requerida antes de migrar

1. Repetir captura ICMP MikroTik `ether1` y ping desde VPS, con dos sesiones independientes, conservar salida saneada y determinar origen IP/SNAT. No registrar sniffer como prueba realizada.
2. Probar comunicación VPS → SG2210P y EAP225 mediante rutas y protocolos de administración autorizados, sin alterar reglas hasta diagnosticar.
3. Verificar compatibilidad Omada Controller 6.3.0.45 con Debian 12, dependencias y modalidad nativa frente a Docker, consumo RAM/CPU/disco y puertos concretos de gestión/adopción/heartbeat.
4. Hacer backup verificable de Omada en Lenovo, diseñar restauración/rollback, elegir estrategia de adopción y dirección del nuevo controller (DHCP Option 138 actual apunta al Lenovo por Tailscale).
5. Instalar/restaurar en VPS **solo tras autorización**, probar adopción y continuidad SG2210P/EAP225, y entonces retirar Omada del Lenovo.
6. Reconciliar direcciones/servicios en NetBox y registrar métricas de RAM liberada y estado final en GitHub.

**Restricciones:** VPS aloja servicios de producción; no afectar bases, Docker, Tailscale ni copias existentes por la migración. Separar MEDION (OPNsense/VLAN20) del recorrido de Omada. No incluir secretos, IP pública del VPS, tokens, backups o capturas sin saneamiento en el repositorio público.

**Estado de esta sección:** histórico del 15/10, superado por la migración completada comunicada el 28/10.


## Diagnóstico histórico en Lenovo, 15/10/2026

Comprobados y aportados por el usuario: paquete `omadac` v6.3.0.45, unidad systemd `tpeap.service` activa, instalación `/opt/tplink/EAPController`, MongoDB integrado en puerto `27217`, consumo atribuido al servicio **~3,9 GB RAM y 234,1 MB swap**. Estas cifras son mediciones previas, no memoria liberada.

Este fue el estado del 15/10. **Superado:** el controlador está en VPS y desinstalado del Lenovo según resumen recibido el 28/10.


## Estado actual comunicado el 28/10/2026 — MIGRACIÓN COMPLETADA

**Origen:** informe del usuario; fecha exacta de las operaciones no indicada y no se hicieron comprobaciones directas en equipos desde esta edición.

| Componente | Estado comunicado |
|---|---|
| Omada Network Application | v6.3.0.45 en VPS Hetzner `Ailab-core01` |
| Tailscale VPS | `100.87.19.25` |
| Trayecto lógico de gestión | VPS → Tailscale → Raspberry Pi 4 → MikroTik |
| SG2210P | `192.168.88.251` — conectado |
| EAP225 | `192.168.88.250` — conectado |
| Lenovo L13 | Omada desinstalado, preparado para KVM/QEMU |

**RAM Lenovo tras migración:** total 15 GiB; utilizada 6,6 GiB; libre 6,7 GiB; **disponible 8,7 GiB**. Swap total 2,0 GiB y usada 1,7 GiB. La memoria disponible incluye caché recuperable y no equivale a memoria asignada a VMs. La swap ocupada no demuestra presión actual de memoria. **No existe medición anterior directamente comparable** para calcular cuánto liberó exactamente Omada.

**Evidencia no aportada en el resumen:** procedimiento exacto de copia/restauración y rollback, método de instalación, puertos y sniffer/SNAT, comprobación tras reinicio. No tratarlos como validados individualmente. El texto de preparación del 15/10 más arriba es histórico.
