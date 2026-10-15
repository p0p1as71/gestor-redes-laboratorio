# Omada Software Controller

**Anfitrión documentado:** Lenovo ThinkPad L13 Gen 3.
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


## Migración prevista al VPS Hetzner — 15/10/2026 (SIN INICIAR)

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

**Estado:** solo preparación y diagnóstico; Omada aún en Lenovo, migración pendiente.


## Diagnóstico en Lenovo, 15/10/2026

Comprobados y aportados por el usuario: paquete `omadac` v6.3.0.45, unidad systemd `tpeap.service` activa, instalación `/opt/tplink/EAPController`, MongoDB integrado en puerto `27217`, consumo atribuido al servicio **~3,9 GB RAM y 234,1 MB swap**. Estas cifras son mediciones previas, no memoria liberada.

El bridge `br-pyme` del Lenovo funciona y alcanza MikroTik, pero **Omada sigue alojado y activo en Lenovo**. Instalación, restauración y adopción en VPS, pruebas de continuidad y retirada posterior siguen pendientes.
