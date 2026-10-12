# Criterios V2 — revisión previa y cierre retrospectivo

- [x] Rama de trabajo separada y main conservada.
- [x] Repositorio privado confirmado el 10/10/2026.
- [x] README y documentación inicial por responsabilidad.
- [x] Prácticas históricas separadas de prácticas pendientes.
- [ ] Comprobar colaboradores y permisos en configuración de GitHub.
- [ ] Revisar reglas de protección de main.
- [ ] Revisar alertas de secret scanning, si están disponibles.
- [ ] Ejecutar revisión de secretos de todas las ramas e historial con herramienta especializada.
- [ ] Validar automáticamente todos los enlaces internos (la revisión principal/manual es favorable; el barrido completo fue limitado por las consultas de la integración y NO se certifica aún).
- [ ] Contrastar inventario, puertos y redes con sistemas reales, antes de declarar estado vigente.
- [ ] Aprobar la integración después de revisar el diff del pull request.

**Nota histórica:** esta condición se redactó antes de fusionar V2. El PR #1 ya está fusionado; los controles sin marcar continúan pendientes y no se consideran completados por la fusión.

## Auditoría documental adicional — 11/10/2026

- Se sustituyeron referencias desactualizadas a portátil sin identificar por MEDION `netlab-ws01` (SG2210P puerto 6).
- Se corrigieron fichas que presentaban como pendientes las interfaces OPNsense, el cliente Debian, el NAT y la salida a Internet, verificados el 10/10/2026.
- Se actualizó la condición de seguridad: **`lab-isolated` tiene salida al exterior a través de OPNsense; el bloqueo de acceso a redes privadas NO está verificado.**
- Se conservaron como históricos los puertos ESP32 y la identidad de la ruta exacta dentro de MikroTik aún por reconfirmar.
- Quedan fuera del alcance de esta auditoría las autorizaciones GitHub, el escaneo completo de secretos y la inspección de NetBox/sistemas en vivo. No declarar resueltos estos controles.

**Nota histórica de aprobación:** el usuario autorizó la integración V2 aceptando que determinados controles quedaran diferidos. Esta nota registra esa decisión conocida; no constituye validación técnica retrospectiva de los controles abiertos.

## Estado final del PR #1 — 11/10/2026

- PR: [#1 — docs: reorganización V2](https://github.com/p0p1as71/gestor-redes-laboratorio/pull/1).
- **Fusionado** el 11/10/2026 a las **12:18:56 UTC** (14:18:56 hora peninsular española).
- Commit squash de integración: `952e098e3803049fd6e855a1f18e34f18db72661`.
- El cierre del PR fue autorizado con controles pendientes aceptados para revisión posterior, no por certificación de todos los requisitos.
- **Permanecen pendientes**: permisos y protecciones GitHub, secret scanning y análisis especializado del historial, validación automática íntegra de enlaces, conciliación con NetBox y comprobaciones de topología y aislamiento en vivo.
- **Estado documental:** V2 fusionada y publicada; cierre técnico y de seguridad completo **NO acreditado**. No modificar retrospectivamente casillas pendientes.
