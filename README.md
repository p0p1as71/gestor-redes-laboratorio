# Gestor de Redes — Laboratorio y Curso

Documentación de ingeniería y aprendizaje del curso de Gestor de Redes, con laboratorios físico y virtual. El repositorio describe **qué está construido, qué se ha probado y qué queda pendiente**, sin equiparar diseños con resultados verificados.

> **Estado:** en desarrollo. Esta documentación no sustituye la comprobación de los sistemas en vivo.

## Navegación

| Área | Contenido |
|---|---|
| [Curso](curso/) | 19 unidades identificadas; subtemas de UD01–UD09, actividades y evaluaciones documentadas parcialmente |
| [Arquitectura](arquitectura/README.md) | Topologías, segmentación, direccionamiento y decisiones |
| [Laboratorio físico](laboratorio-fisico/README.md) | Raspberry Pi, MikroTik, SG2210P, EAP225, ESP32, Arduino Yún y estaciones |
| [Laboratorio virtual](laboratorio-virtual/README.md) | Réplica principal Lenovo L13 y plataforma de prácticas adicional MEDION |
| [Servicios](servicios/README.md) | NetBox, LibreNMS, Omada, dashboard y automatización |
| [Prácticas](practicas/README.md) | Prácticas guiadas; [plantilla](practicas/plantillas/PRACTICA.md) |
| [Evidencias](evidencias/README.md) | Pruebas, resultados y material revisado |
| [Configuraciones](configuraciones/README.md) | Solo ejemplos o exportaciones sanitizadas |
| [Operación](operacion/README.md) | Procedimientos, incidencias, seguridad y recuperación |
| [Hoja de ruta](ROADMAP.md) | Próximos trabajos por prioridad |
| [Histórico](CHANGELOG.md) | Cronología conservada de cambios |
| [Reglas](CONTRIBUTING.md) | Estados, evidencias y criterios de publicación |

## Objetivo

Aplicar la secuencia **TEORÍA → CONCEPTO → PRÁCTICA → OBSERVACIÓN → CONCLUSIÓN** en entornos controlados.

## Responsabilidades y fuentes

- **NetBox:** fuente canónica prevista para inventario, direcciones IP y conexiones una vez reconciliados.
- **GitHub:** documentación versionada de decisiones, procedimientos y evidencias.
- **LibreNMS:** observación y alertas.
- **Ansible/AWX:** automatización futura bajo autorización, no ejecución implícita.

No se asume ninguna sincronización automática entre estos sistemas.

## Estado técnico resumido (documentación al 10-10-2026)

- **Físico:** Pi 4 como gateway/admin; MikroTik con Pi 3 de prácticas y Yún en puertos LAN; SG2210P con EAP225, tres ESP32 y un portátil de identidad pendiente. [Mapa físico y fuentes](laboratorio-fisico/topologia.md).
- **Virtual principal (diseño):** Lenovo L13: réplica funcional gateway → router → switch → hosts; infraestructura libvirt preparada y VMs previstas aún sin verificar como creadas.
- **Virtual adicional (histórico):** MEDION `netlab-ws01` con KVM/QEMU, redes `default` y `lab-isolated`, y VM `opnsense-lab`.
- **Pendiente de comprobar:** asignación de LAB-NET en Lenovo, aislamiento de MEDION, interfaces de OPNsense, identidad de segunda VM, mapa de puertos y servicio permanente del dashboard.

El detalle histórico y el grado de evidencia de cada elemento están en el [CHANGELOG](CHANGELOG.md).

## Estados documentales

`PLANIFICADO` · `EN PREPARACIÓN` · `EN PRUEBAS` · `VERIFICADO` · `DOCUMENTADO` · `PENDIENTE`.

**VERIFICADO requiere evidencia.** Una propuesta o referencia histórica no es automáticamente el estado actual.

## Seguridad

**Repositorio privado (verificado el 10/10/2026).** No publicar secretos, claves, contraseñas Wi-Fi, tokens, capturas no revisadas, copias brutas de configuración ni información personal de terceros. `.gitignore` ayuda a evitar inclusiones accidentales, pero **no garantiza** la protección de secretos ya comprometidos o añadidos forzosamente.

Las prácticas no deben cambiar por accidente Starlink, VPS, Tailscale o sistemas de producción.

