# Dashboard de topología

Se documentó la transferencia de un archivo HTML a la Raspberry Pi 4. La copia del archivo **no demuestra** que el servidor HTTP ni su autoinicio funcionen.

## Situación

- Vista física descrita anteriormente: Starlink → Raspberry Pi 4 → MikroTik → SG2210P → EAP225 / ESP32; incompleta como representación vigente.
- Vista física objetivo: añadir Pi 3 y Yún en puertos LAN del MikroTik, y MEDION en el puerto 6 del SG2210P, conforme al [mapa físico](../../laboratorio-fisico/topologia.md).
- Fuente HTML ausente del repositorio revisado: esta actualización documental no modifica el dashboard desplegado.
- Vista lógica: LAN doméstica, tránsito /30, LAN laboratorio y accesos de administración.
- Fichero publicado en anfitrión según historial; servicio `lab-dashboard.service` pendiente de existencia/estado.

## Pendientes

Recuperar versión fuente revisada del HTML, verificar HTTP y persistencia, documentar método de instalación y dependencias. Evitar exponer rutas administrativas y secretos en el dashboard.

