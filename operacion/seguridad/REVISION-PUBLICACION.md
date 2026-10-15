# Revisión de seguridad y publicación

**Fecha:** 2026-10-10  
**Estado de visibilidad comprobado:** repositorio privado.  
**Alcance:** revisión documental; no auditoría de infraestructura ni escaneo especializado de secretos.

## Comprobaciones realizadas

- [x] Confirmar la visibilidad privada en GitHub.
- [x] Revisar los nombres y tipos de archivos existentes en el historial de main.
- [x] Examinar referencias textuales a credenciales en las versiones de CHANGELOG de main disponibles.
- [x] Identificar la exposición histórica de topología, puertos, IP y medios de administración.
- [x] Conservar la rama de reorganización sin fusionar a main.

**Resultado:** no se detectaron valores literales de contraseñas, tokens o claves privadas en los documentos históricos examinados. Sí se documentaron detalles operativos de infraestructura durante la etapa pública. No se ha comprobado que existan copias externas del historial.

## Comprobaciones limitadas por permisos de integración

- [ ] Enumerar todos los colaboradores autorizados: el acceso por API no fue permitido.
- [ ] Consultar protección de rama main: GitHub devolvió 403 para esta integración.
- [ ] Consultar alertas de secret scanning: endpoint no disponible mediante esta conexión.
- [ ] Consultar permisos de GitHub Actions: endpoint no disponible mediante esta conexión.

**Importante:** un acceso de API denegado no significa que el control esté desactivado.

## Pendientes recomendados

1. Comprobar en GitHub Settings > Collaborators and teams quién tiene acceso.
2. Comprobar en Settings > Rules > Rulesets las reglas de protección de main, si existen.
3. Comprobar Settings > Security y las alertas disponibles de secret scanning.
4. Ejecutar en un entorno autorizado un detector de secretos sobre todos los commits y ramas.
5. Mantener las credenciales y copias de configuración sensibles fuera del repositorio, incluso privado.
6. Evaluar la exposición histórica anterior a la transición a privado.

## Criterios para cerrar la revisión

- Confirmar acceso de colaboradores y protecciones apropiadas.
- Resolver alertas reales que aparezcan.
- Registrar fecha, evidencia y resultado de la inspección restante.
- No confundir ausencia de coincidencias textuales con garantía absoluta de ausencia de secretos.


---

## Revisión parcial de visibilidad y publicación — 15/10/2026

**Resultado directamente contrastado:** API de GitHub indica `visibility=public` y `private=false` para `p0p1as71/gestor-redes-laboratorio`. El dato «privado» del 10/10 queda como observación histórica, no como estado actual. No se conoce la fecha exacta del cambio de visibilidad.

**Alcance de comprobaciones realizadas en esta revisión:** consulta del árbol de la rama `main` (archivos versionados de documentación, prácticas, sketches y procedimientos), lectura de muestras de archivos de alto interés: README, CHANGELOG, revisión de publicación anterior, fichas MikroTik/ESP32/Omada y reglas de contribución; búsqueda de texto en el índice GitHub de `password`, `token`, `BEGIN PRIVATE KEY` y `tailscale`. Esas búsquedas no identificaron en los resultados examinados **material literal de claves privadas, contraseñas o tokens operativos**. **Esto no es un escaneo exhaustivo ni prueba ausencia de secretos.** El índice de código no sustituye un análisis de todas las versiones, ramas, blobs borrados o logs.

### Exposición que sí existe

- La documentación pública describe CIDR/IP internas, direcciones de administración, topología, puertos, relaciones de tránsito, VLAN 20, Tailscale y nombres de servicios. Las IP privadas y MAC **no son secretos de autenticación**, pero facilitan el reconocimiento de una instalación si un atacante alcanza la red por otra vía.
- El CHANGELOG conserva una referencia histórica a permitir temporalmente `diffie-hellman-group14-sha1` y `ssh-rsa` para compatibilidad con Arduino Yún. Es evidencia de un cliente SSH legado, **no demuestra que todos los equipos permitan esos algoritmos ni que el servicio esté expuesto a Internet**.
- Se describen interfaces de gestión MikroTik/Omada/NetBox, sin verificar exposición WAN real. No confundir divulgación de rutas de administración con prueba de acceso externo.
- No se encontraron PCAP, capturas originales, backups binarios ni exportaciones brutas en el árbol actual de `main`; la existencia de objetos históricos accesibles en Git no ha sido descartada.

### Controles pendientes ANTES de declarar segura la publicación

1. **P0 — Historia completa:** ejecutar en entorno autorizado una herramienta de detección de secretos (por ejemplo, Gitleaks) sobre `git log -p --all` o sobre el historial Git completo, **incluyendo todas las ramas/tags existentes**. Revisar resultados sin publicar valores sensibles; no subir el informe bruto si contiene hallazgos.
2. **P0 — GitHub Security:** inspeccionar alertas de secret scanning/push protection, colaboradores y permisos de escritura, reglas de protección de `main` y automatizaciones de Actions. El acceso de la integración puede impedir algunas consultas: no interpretar 403 como control desactivado.
3. **P1 — Publicación mínima:** revisar si es necesario conservar públicamente IP de gestión, MAC completas, UUID de interfaces y rutas de administración detalladas. Preferir ejemplos sintéticos o documentación privada cuando la reproducibilidad no exija los valores reales.
4. **P1 — Servicios:** desde los segmentos autorizados, verificar reglas WAN, acceso a SSH/WebFig/WinBox y al controlador Omada/NetBox. **No ejecutar escaneo remoto ni cambiar reglas sin autorización**.
5. **Si aparecen secretos:** revocar/rotar credenciales primero; después decidir limpieza de historial y revisión de forks/cachés. Borrar líneas en `main` **no elimina** un valor comprometido de commits anteriores.

**Dictamen 15/10:** `PUBLICACIÓN YA ACTIVA / SIN SECRETO LITERAL DETECTADO EN MUESTRA / AUDITORÍA DE SECRETOS Y EXPOSICIÓN EXTERNA INCOMPLETA`. No declarar publicación segura hasta completar los controles P0.


## Actualización de controles verificados — 15/10/2026 (posterior a la revisión parcial)

- **Visibilidad actual:** repositorio público; el estado privado de 10/10 es histórico.
- **Protección de rama:** ruleset GitHub `Proteccion-main` ID `25191874`, `enforcement=active`, `include=["~DEFAULT_BRANCH"]`, aplicable a `main`; exige PR con **0 aprobaciones**, prohíbe eliminación y force push. Configuración comprobada por API; no se ha efectuado un push de rechazo de prueba.
- **Escaneo local registrado:** `gitleaks detect --source ~/gestor-redes-laboratorio --log-opts="--all" --redact --no-banner` examinó **104 commits**, resultado `no leaks found`; 10 referencias de ramas contrastadas. Escaneo favorable según firmas predeterminadas, no certifica secretos fuera de reglas, commits inalcanzables, servicios, colaboradores ni alertas GitHub Security.
- Los puntos del plan anterior de ejecutar Gitleaks y crear reglas **ya tienen ejecución documentada**. Siguen pendientes acceso/permisos de colaboradores, alertas, posibles objetos inalcanzables y exposición operativa. Se conserva el historial previo, sin presentarlo como estado actual.

**Dictamen vigente:** PUBLICACIÓN ACTIVA / RULESET DE `main` CONFIRMADO / GITLEAKS SIN HALLAZGOS EN ALCANCE ANALIZADO / AUDITORÍA GENERAL TODAVÍA ABIERTA.
