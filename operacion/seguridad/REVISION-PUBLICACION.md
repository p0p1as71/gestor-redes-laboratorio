# Revisión de publicación del repositorio

**Situación confirmada:** GitHub informa que el repositorio es **público**; el README anterior decía privado.

## Antes de fusionar la reorganización

- [ ] Revisar direcciones IP administrativas, direcciones Tailscale, MAC y topologías expuestas en todo el historial.
- [ ] Revisar capturas, exportaciones y referencias a servicios externos.
- [ ] Confirmar que no se publicaron contraseñas, tokens, secretos, claves privadas ni copias de configuración.
- [ ] Decidir qué documentación debe permanecer pública y cuál debe mantenerse fuera del repositorio.
- [ ] Comprobar también el historial Git, no solo el árbol actual. Borrar una línea en un commit posterior **no elimina** su exposición histórica.
- [ ] Rotar cualquier secreto que se descubra publicado.

## Regla

`.gitignore` previene incorporaciones accidentales en el futuro, pero no vuelve privado un repositorio ni elimina información ya publicada.

**Estado:** pendiente de revisión detallada; no afirmar ausencia de secretos.
