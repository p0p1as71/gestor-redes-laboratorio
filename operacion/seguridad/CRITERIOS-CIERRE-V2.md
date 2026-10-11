# Criterios de revisión antes de fusionar V2

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

**No fusionar automáticamente; los puntos restantes requieren evidencia o decisión explícita.**

## Auditoría documental adicional — 11/10/2026

- Se sustituyeron referencias desactualizadas a portátil sin identificar por MEDION `netlab-ws01` (SG2210P puerto 6).
- Se corrigieron fichas que presentaban como pendientes las interfaces OPNsense, el cliente Debian, el NAT y la salida a Internet, verificados el 10/10/2026.
- Se actualizó la condición de seguridad: **`lab-isolated` tiene salida al exterior a través de OPNsense; el bloqueo de acceso a redes privadas NO está verificado.**
- Se conservaron como históricos los puertos ESP32 y la identidad de la ruta exacta dentro de MikroTik aún por reconfirmar.
- Quedan fuera del alcance de esta auditoría las autorizaciones GitHub, el escaneo completo de secretos y la inspección de NetBox/sistemas en vivo. No declarar resueltos estos controles.

**Antes de marcar el PR listo para fusionar:** aprobación explícita del usuario después de revisar los pendientes aceptados.
