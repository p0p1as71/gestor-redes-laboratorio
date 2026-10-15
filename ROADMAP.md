# Hoja de ruta — Gestor de Redes

Las tareas son planes, no ejecución verificada. **Tres ámbitos**: físico, **PYME virtual Lenovo (objetivo desde 15/10; antigua réplica histórica)** y plataforma MEDION adicional.

## P0 — Seguridad y coherencia documental
- [x] Reconciliar síntesis de arquitectura/IP y ficha MEDION/SG2210P con VLAN 20 y OPT1, distinguiendo datos históricos del 10/10 y 12/10 (auditoría 13/10).
- [x] Registrar retrospectivamente la fusión real del PR #1 en criterios V2, conservando controles pendientes.
- [x] Preparar [plan de verificaciones AUD-TOP-2026-10-13](operacion/auditorias/PLAN-VERIFICACIONES-AUD-TOP-2026-10-13.md) para equipos físicos, Lenovo, MEDION, NetBox y evidencias (sin ejecutar comprobaciones).
- [x] Resolver discrepancia **H01 del sketch ESP32-01 publicado**: commit `6d9aaae` del 15/10 incorpora servidor HTTP sobre W5500. **No equivale a revalidación funcional posterior en hardware**.
- [x] Repositorio privado confirmado el 10/10/2026.
- [x] Separar conceptualmente réplica virtual Lenovo de prácticas MEDION.
- [ ] Completar revisión de colaboradores, alertas y alcance de seguridad: ruleset `Proteccion-main` activo para `main` y Gitleaks histórico 104 commits sin hallazgos; no concluir que la auditoría global está cerrada.
- [x] Actualizar relaciones físicas comunicadas: Pi 3/Yún en MikroTik y portátil en SG2210P, separando evidencia histórica de estado actual.
- [ ] Reconciliar inventario físico (incluido MEDION identificado en puerto 6; verificar otros puertos y mapa actual) con NetBox.
- [ ] Definir procedimientos de exportaciones de configuración sanitizadas.

## P0.1 — Enrutamiento físico Pi 4 / MikroTik (15/10/2026)
- [x] Diagnosticar ruta errónea `192.168.88.1` por gateway doméstico `192.168.1.1 dev wlan0`.
- [x] Guardar en NetworkManager ruta estática `192.168.88.0/24 via 192.168.100.2 dev eth0` y verificar selección con `ip route get`.
- [x] Registrar evidencia de acceso a consola MikroTik mediante SSH desde Raspberry Pi 4 (Termius/Tailscale; intento fallido en log distinguido de sesión abierta).
- [ ] Verificar permanencia de ruta tras reiniciar Raspberry Pi 4, con autorización y ventana apropiadas.
- [ ] Probar separadamente acceso SSH directo Lenovo→MikroTik si forma parte del objetivo operativo.

## P1 — PYME virtual Lenovo L13 (objetivo vigente desde 15/10)
- [ ] Finalizar diagnóstico de conectividad Omada VPS ↔ laboratorio y migrar controlador con backup, restauración, adopción y rollback comprobados.
- [ ] Medir recursos libres (RAM/CPU/disco) en Lenovo una vez retirado Omada bajo autorización.
- [ ] Revisar pool `lab-vms`, SSD `LAB-VMS`, `LAB-NET`, Docker existente y políticas de aislamiento.
- [ ] Diseñar y activar red de pruebas aislada con Linux Bridge (sin conectar aún al SG2210P).
- [ ] Crear Windows 11 (puesto de trabajo; RAM 4 GB estimados) y validar su red.
- [ ] Crear OpenMediaVault (NAS/SMB; 1–2 GB RAM estimados), cuatro discos virtuales y prácticas RAID 0/1/5/10.
- [ ] Integrar CUPS/IPP aislado, sin modificar contenedores existentes.
- [ ] Confirmar disponibilidad del adaptador USB-Ethernet para Lenovo, puerto SG2210P, VLAN, DHCP y NetBox; enlazar solo tras autorización y prueba de aislamiento.
- [ ] Documentar prácticas IP/ARP, SMB, RAID, impresión y monitorización.

## Diseño histórico sustituido — réplica virtual completa Lenovo (10/10)

Las tareas siguientes se conservan solo como antecedentes, **no como trabajo vigente**. No crear VM-GW-ADMIN, VM-ROUTER ni réplicas ESP/Yún/RPi3 salvo nueva decisión.

- [ ] Confirmar estado del pool `lab-vms`, `LAB-NET` y redes libvirt.
- [ ] Elegir VM-ROUTER y switch virtual L2/VLAN.
- [ ] Diseñar WAN controlada, red de tránsito, LAN y política de direccionamiento.
- [ ] Dimensionar y crear VM-GW-ADMIN y VM-ROUTER.
- [ ] Crear equivalentes VM-YUN y VM-ESP01/02/03, VM-WIN11 y AP lógico.
- [ ] Decidir y dimensionar el equivalente VM-RPI3 propuesto para prácticas; no presumir identidad del portátil físico.
- [ ] Ejecutar pruebas comparativas de routing, DHCP, VLAN y firewall con la red física.

## P1.1 — Migración Omada al VPS: diagnóstico y continuidad
- [x] Recuperar espacio del VPS según sesión 15/10 (150 GB totales, uso final 32 %), conservando 3 backups locales; retención de backup modificada con copia previa.
- [x] Crear swap de 4 GiB y configurar persistencia en `fstab`; prueba tras reinicio pendiente.
- [x] Habilitar aceptación de rutas Tailscale en VPS y comprobar ping VPS → MikroTik LAN `192.168.88.1` (4/4 respuestas).
- [ ] Validar ejecución y restauración de backup del VPS; comprobar retención remota.
- [ ] Verificar swap tras reinicio autorizado.
- [ ] Repetir sniffer MikroTik `ether1` conservando evidencia de ICMP y origen IP/SNAT.
- [ ] Probar comunicación desde VPS a SG2210P y EAP225 sin cambios de firewall preventivos.
- [ ] Investigar compatibilidad Omada 6.3.0.45 con Debian 12, requisitos y puertos; elegir nativo o Docker.
- [ ] Respaldar controlador Lenovo, planificar rollback, instalar/restaurar en VPS, adoptar equipos y verificar operación.
- [ ] Retirar Omada de Lenovo **solo tras prueba funcional**, medir RAM liberada.

## P2 — MEDION: plataforma de pruebas adicional
- [x] Verificar WAN `em0` y LAN `em1` de OPNsense (estado histórico 10/10/2026); el 12/10 se reportaron como `re1`/`re0`.
- [x] Comprobar salida exterior de `lab-isolated`: se confirmó Internet vía OPNsense (10/10/2026).
- [ ] Definir y validar política de bloqueo de acceso a redes privadas físicas.
- [x] Identificar segunda VM: `debian-client01` (10/10/2026).
- [x] Recuperar RTL8153 con `firmware-realtek` y passthrough USB a OPNsense (12/10).
- [x] Configurar tercera interfaz `OPT1/ue0` con `10.20.20.1/24` y enlace 1 Gbps (12/10).
- [x] Crear VLAN 20 `LAB-FISICO` y configurar puerto 6 del SG2210P como Access (12/10).
- [ ] Confirmar servicio DHCP IPv4 en OPT1 y pool `10.20.20.100–200`.
- [ ] Conectar primer cliente físico VLAN 20 y validar IP, gateway y comunicación `10.20.20.1`.
- [ ] Diseñar y comprobar reglas de firewall y routing para segmentación entre LAB-FISICO, LAN virtual y red física existente.
- [x] Crear `netlab-traffic.service` y validar ejecución manual de ICMP/DNS/HTTPS en `debian-client01` (12–13/10).
- [x] Instalar `tcpdump` y obtener `captura-06.pcap` con STP, ICMP, DNS y TCP/HTTPS en LAN virtual.
- [ ] Reparar `netlab-traffic.timer` (estado `bad-setting`) y restablecer intervalo de 5 minutos; verificar ejecuciones automáticas.
- [ ] Comparar capturas LAN/WAN de OPNsense para observar NAT directamente.
- [ ] Verificar comportamiento con tapa cerrada.

## P3 — Mejoras físicas comprobadas el 12/10
- [x] Actualizar RouterOS/RouterBOOT del MikroTik hEX lite a 7.24.5 con backups y comprobaciones básicas.
- [x] Probar comunicación HTTP ESP32-02 → ESP32-01 y monitorización ESP32-03.
- [x] Corregir y documentar cableado ESP32: ESP32-01 → SG2210P puerto 3, ESP32-02 → puerto 4 y ESP32-03 → puerto 5 (intervención del 12/10/2026). Captura Omada posterior: enlaces activos en puertos 3–5.
- [ ] Correlacionar en Omada cada MAC actual con ESP32-02/03 para disponer de verificación independiente de identidad por puerto (la captura muestra nombres WIZnet, no etiquetas ESP32).
- [ ] Repetir pruebas ESP32 con los tres nodos activos y reservas DHCP observadas.
- [x] Incorporar los tres archivos fuente `.ino` ESP32 a GitHub (commit `d4f81cc`).
- [ ] Verificar versiones de firmware y revisar código fuente de ESP32.

## P4 — Servicios y operación
- [ ] Comprobar dashboard y reconciliar datos NetBox/LibreNMS.
- [x] Definir y probar tres roles iniciales para ESP32 físicos: servidor, cliente y monitor HTTP.
- [ ] Documentar evidencias fechadas y prácticas nuevas.

Fuentes: informe de arquitectura virtual aportado el 10/10/2026 (diseño Lenovo) y CHANGELOG (historial físico/MEDION).

