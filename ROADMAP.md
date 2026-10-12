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
- [x] Verificar WAN `em0` y LAN `em1` de OPNsense (10/10/2026).
- [x] Comprobar salida exterior de `lab-isolated`: se confirmó Internet vía OPNsense (10/10/2026).
- [ ] Definir y validar política de bloqueo de acceso a redes privadas físicas.
- [x] Identificar segunda VM: `debian-client01` (10/10/2026).
- [ ] Verificar comportamiento con tapa cerrada.

## P3 — Mejoras físicas comprobadas el 12/10
- [x] Actualizar RouterOS/RouterBOOT del MikroTik hEX lite a 7.24.5 con backups y comprobaciones básicas.
- [x] Probar comunicación HTTP ESP32-02 → ESP32-01 y monitorización ESP32-03.
- [ ] Reconfirmar los puertos 4/5 para ESP32-02/03 tras corregir cables.
- [ ] Repetir pruebas ESP32 con los tres nodos activos y reservas DHCP observadas.
- [ ] Incorporar fuentes y versiones definitivas de los tres firmwares ESP32 tras revisión.

## P4 — Servicios y operación
- [ ] Comprobar dashboard y reconciliar datos NetBox/LibreNMS.
- [x] Definir y probar tres roles iniciales para ESP32 físicos: servidor, cliente y monitor HTTP.
- [ ] Documentar evidencias fechadas y prácticas nuevas.

Fuentes: informe de arquitectura virtual aportado el 10/10/2026 (diseño Lenovo) y CHANGELOG (historial físico/MEDION).

