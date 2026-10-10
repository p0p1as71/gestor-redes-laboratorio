# NetBox — inventario, IPAM y conectividad

**Histórico:** NetBox Community 4.7.1 documentado el 27/09/2026, desplegado en Raspberry Pi 4 mediante Docker Compose, puerto HTTP 8001 (consultar accesos vigentes).

Servicios: `netbox`, `netbox-worker`, PostgreSQL, Redis y Redis-cache. El historial registra recuperación tras reinicio y cambio a `restart: unless-stopped` en los cinco servicios; no implica comprobación actual.

## Autoridad de datos

Fuente canónica **prevista y a reconciliar** para dispositivos, interfaces, direcciones, cables y VLAN. GitHub almacena decisiones y evidencias versionadas, no debe competir con NetBox como inventario duplicado.

## Criterios

- Registrar modelo/fabricante y rol antes de asociar interfaces y conexiones.
- Diferenciar topología documentada de conexión física comprobada.
- Referenciar prueba, fecha y origen de cada dato relevante.
- No crear automáticamente equipos, VLAN o IP a partir de propuestas del curso.

## Pendientes

Conciliar switch SG2210P, EAP225, ESP32, Pi 3, MEDION, puertos y direcciones actuales; revisar copias de seguridad, actualizaciones y disponibilidad sin intervenir todavía.
