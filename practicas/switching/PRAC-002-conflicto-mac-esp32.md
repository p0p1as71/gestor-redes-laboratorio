# PRAC-002 — Diagnóstico de conflicto MAC de tres ESP32

- **Origen:** CHANGELOG, 02–03/10/2026.
- **Entorno:** laboratorio físico SG2210P + MikroTik + tres ESP32.
- **Estado:** VERIFICADO HISTÓRICAMENTE (03/10); prueba actual no repetida.

## Concepto y objetivo
Un switch Ethernet aprende qué MAC aparece por cada puerto. Si varios equipos anuncian la misma MAC, esa entrada puede oscilar de puerto y la identificación individual deja de ser fiable.

## Estado inicial observado
Tres nodos compartían MAC Ethernet de ejemplo `02:00:00:12:34:56`; se observó aprendizaje alternante de esa MAC en puertos Gi1/0/3, Gi1/0/4 y Gi1/0/5. No equivale a una colisión Ethernet física: es un conflicto de identidad de capa 2.

## Actuación histórica registrada
Se identificaron las placas por USB, se corrigió la identidad Ethernet utilizada por el firmware y se actualizaron reservas DHCP en el MikroTik.

## Resultado documentado
| Equipo | Puerto | IP DHCP |
|---|---|---|
| ESP32-01 | Gi1/0/3 | 192.168.88.245 |
| ESP32-02 | Gi1/0/5 | 192.168.88.246 |
| ESP32-03 | Gi1/0/4 | 192.168.88.247 |

El historial registra MAC diferentes, reservas DHCP `bound` y tabla MAC coherente tras la corrección.

## Comprobación reproducible (solo lectura)
1. Inspeccionar enlaces, tabla MAC del switch y concesiones DHCP.
2. Relacionar cada puerto físico con MAC, IP y nodo identificado.
3. Observar cambios de aprendizaje, si existen, sin modificar firmware.
4. Registrar evidencia sanitizada y fecha de consulta.

## Conclusión
La asignación de IP de capa 3 depende de identificar correctamente los nodos de capa 2, pero la dirección MAC por sí sola no certifica toda la identidad de un dispositivo.
