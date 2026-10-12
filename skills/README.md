# Skills y procedimientos — Gestor de Redes

Biblioteca de procedimientos reutilizables del proyecto. Cada `SKILL.md` define una **forma de trabajar**, no un permiso de acceso ni una fuente de verdad operacional.

| Skill | Función | Estado |
|---|---|---|
| [auditoria-topologia](auditoria-topologia/SKILL.md) | Auditoría de la topología documentada, separando físico, Lenovo y MEDION | Propuesto para revisión |

## Uso desde el Proyecto de ChatGPT

1. Abrir el Proyecto **Gestor de Redes** en ChatGPT.
2. Añadir como archivo de referencia el `SKILL.md` de [auditoria-topologia](auditoria-topologia/SKILL.md), o pedir a ChatGPT que lo consulte en GitHub si la conexión tiene acceso a este repositorio.
3. Solicitar expresamente: **«Aplica el procedimiento auditoria-topologia al repositorio gestor-redes-laboratorio. Haz solo lectura, separa físico/Lenovo/MEDION y cita las evidencias. No modifiques nada.»**
4. Revisar hallazgos y autorizar individualmente, si procede, cada cambio posterior.

**Importante:** guardar este archivo en GitHub o adjuntarlo como referencia a un Proyecto de ChatGPT **no instala automáticamente un Skill nativo** ni garantiza activación autónoma. En ChatGPT Plus puede utilizarse como procedimiento documentado; en un entorno compatible con Agent Skills puede empaquetarse como Skill instalable. Las restricciones del archivo no sustituyen permisos efectivos de las herramientas.

## Gobernanza

- `CONTRIBUTING.md` determina los estados y criterios de evidencia.
- GitHub conserva la versión de procedimientos y documentación.
- NetBox es la referencia prevista para inventario/IPAM cuando estén reconciliados.
- Cada auditoría debe fechar fuentes y distinguir documentación histórica de mediciones actuales.
- Ningún procedimiento autoriza cambios de equipos, servicios o ramas protegidas por sí solo.
