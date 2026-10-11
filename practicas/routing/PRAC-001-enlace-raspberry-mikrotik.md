# PRAC-001 — Enlace de tránsito Raspberry Pi 4 ↔ MikroTik

- **Origen:** CHANGELOG, 21/09/2026 y consolidación del 27/09.
- **Entorno:** laboratorio físico.
- **Estado:** DOCUMENTADO HISTÓRICAMENTE (prueba ejecutada en septiembre; vigencia actual pendiente).

## Concepto y objetivo
Un segmento /30 aporta dos direcciones IPv4 de host utilizables. Sirve para conectar dos routers sin mezclar la LAN del laboratorio con el segmento de tránsito.

## Arquitectura de referencia
Raspberry Pi 4 `eth0` 192.168.100.1/30 ↔ MikroTik `ether1` 192.168.100.2/30; LAN del laboratorio detrás del MikroTik: 192.168.88.0/24.

## Evidencia histórica
- Comprobado ping entre las dos direcciones de tránsito.
- Verificado acceso de administración desde la Raspberry Pi al MikroTik.
- Configurados reenvío IPv4 y NAT en Raspberry Pi, según historial.
- Se registró pérdida de la ruta hacia la LAN tras reinicio posterior de la Raspberry Pi: persistencia no demostrada.

## Procedimiento de reproducción (NO EJECUTADO EN ESTA FASE)
1. Identificar físicamente enlaces y consultar interfaces y rutas de ambos equipos (solo lectura).
2. Comprobar ARP y respuesta ICMP entre las direcciones del tránsito.
3. Consultar ruta a 192.168.88.0/24 y reglas de forward/NAT sin alterarlas.
4. Si falla algo, formular cambio separado con respaldo y reversión.
5. Repetir medidas y registrar hora, origen, destino, interfaz y resultado.

## Conclusión
La conectividad fue verificada en septiembre; no se certifica el funcionamiento actual desde GitHub. Una ruta temporal funcional no garantiza persistencia.

## Próxima evidencia
Capturas o salidas sanitizadas de interfaces, rutas y pings fechados, con referencia al estado de NetBox.
