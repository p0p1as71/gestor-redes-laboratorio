# Hoja de ruta — Gestor de Redes

Las tareas son planes, no ejecución verificada. **Tres ámbitos**: físico, réplica virtual Lenovo y plataforma MEDION adicional.

## P0 — Seguridad y coherencia documental
- [x] Repositorio privado confirmado el 10/10/2026.
- [x] Separar conceptualmente réplica virtual Lenovo de prácticas MEDION.
- [ ] Revisar colaboradores, protecciones y escaneo exhaustivo de secretos.
- [ ] Reconciliar inventario físico (incluido SG2210P) con NetBox.
- [ ] Definir procedimientos de exportaciones de configuración sanitizadas.

## P1 — Réplica virtual principal Lenovo L13
- [ ] Confirmar estado del pool `lab-vms`, `LAB-NET` y redes libvirt.
- [ ] Elegir VM-ROUTER y switch virtual L2/VLAN.
- [ ] Diseñar WAN controlada, red de tránsito, LAN y política de direccionamiento.
- [ ] Dimensionar y crear VM-GW-ADMIN y VM-ROUTER.
- [ ] Crear equivalentes VM-YUN y VM-ESP01/02/03, VM-WIN11 y AP lógico.
- [ ] Ejecutar pruebas comparativas de routing, DHCP, VLAN y firewall con la red física.

## P2 — MEDION: plataforma de pruebas adicional
- [ ] Verificar asignación real WAN/LAN de OPNsense.
- [ ] Probar aislamiento de `lab-isolated`.
- [ ] Identificar segunda VM.
- [ ] Verificar comportamiento con tapa cerrada.

## P3 — Servicios y operación
- [ ] Comprobar dashboard y reconciliar datos NetBox/LibreNMS.
- [ ] Definir tres funciones útiles para ESP32 físicos.
- [ ] Documentar evidencias fechadas y prácticas nuevas.

Fuentes: informe de arquitectura virtual aportado el 10/10/2026 (diseño Lenovo) y CHANGELOG (historial físico/MEDION).
