# Reglas de documentación y cambios

## Principios
1. La gobernanza y el diagnóstico preceden a la modificación.
2. Separar curso, laboratorio físico, laboratorio virtual y servicios reales/de producción.
3. No declarar VERIFICADO sin evidencia identificable.
4. Un cambio operativo cada vez: estado inicial, copia de seguridad si procede, acción, validación y reversión.
5. No almacenar secretos, configuraciones brutas ni datos innecesarios en este repositorio público.

## Estados
- PLANIFICADO: idea registrada, no ejecutada.
- EN PREPARACIÓN: precondiciones en revisión.
- EN PRUEBAS: ejecución o medición iniciada; resultado no cerrado.
- VERIFICADO: evidencia reproducible de resultado concreto.
- DOCUMENTADO: información recogida; no acredita por sí mismo operación.
- PENDIENTE: falta comprobación o acción.

## Estructura de cada ficha
Identificador · Fecha · Alcance/entorno · Objetivo · Estado inicial · Cambio (si existe) · Resultado observado · Evidencia · Riesgos · Reversión · Estado final · Pendientes.

## Fuente de verdad
- **NetBox**: inventario, IPAM y conexiones cuando estén comprobados; no asumir sincronización automática.
- **GitHub**: arquitectura documentada, procedimientos, cambios y evidencias revisadas.
- **LibreNMS**: monitorización y eventos observables; no reemplaza inventario ni aprobación de cambios.
- **Ansible**: automatización propuesta bajo autorización explícita, nunca fuente de autoridad implícita.

Las exportaciones deben ser sanitizadas y revisadas antes de cualquier commit.
