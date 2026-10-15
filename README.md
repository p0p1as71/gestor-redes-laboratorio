# Gestor de Redes — Laboratorio y Curso

Documentación de ingeniería y aprendizaje del curso de Gestor de Redes, con laboratorios físico y virtual. El repositorio describe **qué está construido, qué se ha probado y qué queda pendiente**, sin equiparar diseños con resultados verificados.

> **Estado:** en desarrollo. Esta documentación no sustituye la comprobación de los sistemas en vivo.

## Navegación

| Área | Contenido |
|---|---|
| [Curso](curso/) | 19 unidades identificadas; subtemas de UD01–UD09, actividades y evaluaciones documentadas parcialmente |
| [Arquitectura](arquitectura/README.md) | Topologías, segmentación, direccionamiento y decisiones |
| [Skills y procedimientos](skills/README.md) | Auditoría documental reutilizable; activación y permisos explícitos |
| [Laboratorio físico](laboratorio-fisico/README.md) | Raspberry Pi, MikroTik, SG2210P, EAP225, ESP32, Arduino Yún y estaciones |
| [Laboratorio virtual](laboratorio-virtual/README.md) | PYME virtual Lenovo (nuevo objetivo) y plataforma adicional MEDION |
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

## Estado técnico resumido (documentación histórica al 13-10-2026)

- **Físico:** Pi 4 como gateway/admin; MikroTik con Pi 3 de prácticas y Yún en puertos LAN; SG2210P con EAP225 (puerto 2), tres ESP32 (puertos 3/4/5 según corrección comunicada 12/10) y el adaptador RTL8153 del MEDION al puerto 6, **Access VLAN 20**. MikroTik sigue administrando la LAN `192.168.88.0/24`; VLAN 20 `LAB-FISICO` usa `10.20.20.0/24`. [Mapa físico y fuentes](laboratorio-fisico/topologia.md).
- **Virtual principal (diseño):** Lenovo L13: **diseño histórico** de réplica gateway → router → switch → hosts; sustituido como objetivo el 15/10 por PYME virtual. Infraestructura libvirt preparada históricamente; VMs de PYME sin crear.
- **Virtual adicional (verificado 10/10):** MEDION `netlab-ws01` con `opnsense-lab` y `debian-client01`; LAN 10.10.10.0/24 con salida a Internet mediante OPNsense. El 10/10, la interfaz USB Realtek `ue0` estaba sin IP; según intervención del 12/10 está asignada a `OPT1/ue0`, `10.20.20.1/24` y conectada por VLAN 20 al SG2210P. WAN/LAN se reportaron como `re1`/`re0` el 12/10, frente a `em0`/`em1` el 10/10. DHCP OPT1 y comunicación con un cliente físico no verificados.
- **Pendiente de comprobar:** asignación de LAB-NET en Lenovo, política de acceso desde MEDION a redes privadas, correlación inequívoca MAC↔placa ESP32-02/03 y comprobación de puertos históricos Pi 3/Yún, conciliación NetBox y servicio permanente del dashboard.

El detalle histórico y el grado de evidencia de cada elemento están en el [CHANGELOG](CHANGELOG.md).

## Estados documentales

`PLANIFICADO` · `EN PREPARACIÓN` · `EN PRUEBAS` · `VERIFICADO` · `DOCUMENTADO` · `PENDIENTE`.

**VERIFICADO requiere evidencia.** Una propuesta o referencia histórica no es automáticamente el estado actual.

## Seguridad

**Visibilidad actual: PÚBLICO (comprobado en GitHub el 15/10/2026);** era privado el 10/10, según registro histórico. **Revisión de seguridad de publicación NO cerrada**: quedan pendientes el escaneo especializado de todo el historial y ramas, comprobación de permisos y alertas. Véase [revisión de publicación](operacion/seguridad/REVISION-PUBLICACION.md). No publicar secretos, claves, contraseñas Wi-Fi, tokens, capturas no revisadas, copias brutas de configuración ni información personal de terceros. `.gitignore` ayuda a evitar inclusiones accidentales, pero **no garantiza** la protección de secretos ya comprometidos o añadidos forzosamente.

Las prácticas no deben cambiar por accidente Starlink, VPS, Tailscale o sistemas de producción.


## Decisión arquitectónica — 15/10/2026

Se sustituye el objetivo de **réplica virtual completa del laboratorio físico en Lenovo** por una **PYME virtual** integrada inicialmente de forma aislada y, solo tras validación, conectable al laboratorio físico mediante USB-Ethernet y Linux Bridge. Se prevén Windows 11, OpenMediaVault con discos virtuales para ejercicios RAID y CUPS/IPP aislado. **No se ha construido ni conectado todavía**. [Diseño actualizado](laboratorio-virtual/lenovo-l13/README.md).

Como prerrequisito de capacidad se **planifica** migrar Omada Controller 6.3.0.45 del Lenovo al VPS Hetzner, previa prueba de conectividad, backup, compatibilidad y reversión; **Omada sigue en Lenovo**. El MEDION permanece como ámbito independiente. [Plan Omada](servicios/omada/README.md).
