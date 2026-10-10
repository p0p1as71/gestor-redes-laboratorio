# Revisión documental de topología — 10/10/2026

**Base revisada:** PR 1, rama docs/reorganizacion-v2, commit 9fca51c018874044af6a8554ffbf68d40217bb6d. Árbol completo examinado; sin AGENTS.md, diagramas binarios ni fuente HTML del dashboard. Se revisaron arquitectura, fichas, servicios, prácticas y CHANGELOG.

## Hallazgos y actualización aplicada

| Documento/área | Hallazgo | Tratamiento |
|---|---|---|
| arquitectura-general y topologia física | Pi 3/portátil omitidos; Yún solo histórico; mapa sin desarrollar | Referencia física única con diagrama, funciones, conexiones y evidencia |
| Fichas Pi 3 / MikroTik / SG2210P | Rol Pi 3 ya corregido; conexiones incompletas o ambiguas | Relación directa Pi 3/Yún–MikroTik y portátil–switch; puertos fechados |
| Ficha Yún | Negaba SSH desde Pi 4, contradiciendo 22/09 | Corregida como evidencia histórica, sin afirmar disponibilidad actual |
| Inventario / nueva ficha portátil | Portátil sin identidad ni conexión explícita | Alta documental provisional; NetBox no modificado |
| Réplica Lenovo / catálogo VMs / roadmap | Cadena inicial situaba Yún en switch; sin equivalente Pi 3 | Objetivo funcional ajustado y VM-RPI3 propuesta, sin afirmar decisión ni despliegue |
| MEDION / índice prácticas / segmentación | Riesgo de atribuir pruebas OPNsense a Lenovo | Ámbito MEDION explícito; esquema de asociaciones pendientes |
| Dashboard | Vista física incompleta; HTML ausente | Objetivo documentado; archivo desplegado no modificado |
| CHANGELOG | Diagramas parciales y roles antiguos; algunos ya corregidos después | Histórico conservado y nueva entrada que remite a topología vigente |
| README / direccionamiento / diagramas / NetBox | Referencias y pendientes dispersos | Enlaces y criterios reconciliados |

La actividad ACT-05 conserva su supuesto de edificio de dos plantas: no describe el laboratorio instalado y no necesita sustituir su enunciado. PRAC-001/002 conservan sus pruebas históricas fechadas.

## Límites de verificación

La declaración del usuario permite actualizar las relaciones físicas, pero no certifica puertos ni IP actuales. El repositorio registra ether2/Pi 3 y ether3/Yún en septiembre y puertos de ESP32 en octubre. No basta para comprobar hoy esos números, uplink, AP o portátil.

Sin acceso a sistemas en vivo no se acreditan identidad del portátil, datos de NetBox, rutas/VLAN/servicios, implementación Lenovo, aislamiento MEDION ni segunda VM. El informe de diseño Lenovo está citado en fichas, pero su archivo fuente no aparece en el árbol de la rama; no se reconstruye como evidencia nueva.

La propuesta conserva diseño, observación histórica y comunicación actual como clases de evidencia distintas. No afirma actualización operativa ni integración híbrida de redes.
