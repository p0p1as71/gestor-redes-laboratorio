# Revisión de publicación del repositorio

**Estado actual confirmado (10/10/2026):** GitHub informa que el repositorio es **privado**. Anteriormente estuvo público; la modificación de visibilidad no revoca copias históricas.

## Antes de fusionar la reorganización

- [ ] Revisar direcciones IP administrativas, direcciones Tailscale, MAC y topologías expuestas en todo el historial.
- [ ] Revisar capturas, exportaciones y referencias a servicios externos.
- [ ] Confirmar que no se publicaron contraseñas, tokens, secretos, claves privadas ni copias de configuración.
- [ ] Decidir qué documentación debe permanecer pública y cuál debe mantenerse fuera del repositorio.
- [ ] Comprobar también el historial Git, no solo el árbol actual. Borrar una línea en un commit posterior **no elimina** su exposición histórica.
- [ ] Rotar cualquier secreto que se descubra publicado.

## Regla

`.gitignore` previene incorporaciones accidentales en el futuro, pero no controla la visibilidad de un repositorio ni elimina información ya publicada.

**Estado:** pendiente de revisión detallada; no afirmar ausencia de secretos.
