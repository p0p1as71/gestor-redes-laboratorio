# Hoja de ruta — Gestor de Redes

Las tareas son planes, no ejecución verificada. **Tres ámbitos**: físico, réplica virtual Lenovo y plataforma MEDION adicional.

## P0 — Seguridad y coherencia documental
- [x] Repositorio privado confirmado el 10/10/2026.
- [x] Separar conceptualmente réplica virtual Lenovo de prácticas MEDION.
- [ ] Revisar colaboradores, protecciones y escaneo exhaustivo de secretos.
- [x] Actualizar relaciones físicas comunicadas: Pi 3/Yún en MikroTik y portátil en SG2210P, separando evidencia histórica de estado actual.
- [ ] Reconciliar inventario físico (incluido MEDION identificado en puerto 6; verificar otros puertos y mapa actual) con NetBox.
- [ ] Definir procedimientos de exportaciones de configuración sanitizadas.

## P1 — Réplica virtual principal Lenovo L13
- [ ] Confirmar estado del pool `lab-vms`, `LAB-NET` y redes libvirt.
- [ ] Elegir VM-ROUTER y switch virtual L2/VLAN.
- [ ] Diseñar WAN controlada, red de tránsito, LAN y política de direccionamiento.
- [ ] Dimensionar y crear VM-GW-ADMIN y VM-ROUTER.
- [ ] Crear equivalentes VM-YUN y VM-ESP01/02/03, VM-WIN11 y AP lógico.
- [ ] Decidir y dimensionar el equivalente VM-RPI3 propuesto para prácticas; no presumir identidad del portátil físico.
- [ ] Ejecutar pruebas comparativas de routing, DHCP, VLAN y firewall con la red física.

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

