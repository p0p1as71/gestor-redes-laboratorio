# PRAC-003 — Verificación del aislamiento virtual con OPNsense

- **Origen:** diseño MEDION/OPNsense documentado 05–10/10/2026.
- **Entorno:** laboratorio virtual MEDION, libvirt y OPNsense.
- **Estado:** PLANIFICADO; resultados de conectividad pendientes.

## Concepto y objetivo
Una red con nombre `lab-isolated` no equivale necesariamente a un sistema aislado: una VM con dos interfaces puede enrutar tráfico entre segmentos según firewall, rutas y NAT.

## Arquitectura por contrastar
`default` (NAT libvirt) ↔ interfaz WAN de `opnsense-lab` ↔ interfaz LAN ↔ `lab-isolated` ↔ cliente virtual.

## Requisitos previos
Verificar XML de redes y dominio, identificar cliente real, interfaces, direcciones, rutas y reglas. Ningún cambio a la red doméstica, Tailscale o máquinas ajenas.

## Matriz de pruebas todavía sin ejecutar
| Origen | Destino | Política que debe definirse | Resultado |
|---|---|---|---|
| Cliente LAN virtual | Gateway OPNsense | Acceso de red local | Pendiente |
| Cliente LAN virtual | Red `default` | Según routing/firewall | Pendiente |
| Cliente LAN virtual | Red doméstica | Denegar salvo autorización | Pendiente |
| Cliente LAN virtual | Internet | Definir explícitamente | Pendiente |

## Procedimiento previsto
1. Inspección de solo lectura de redes libvirt y adaptadores OPNsense.
2. Documentar política de comunicación permitida y denegada.
3. Ejecutar pruebas de conexión autorizadas, una por vez.
4. Evaluar rutas y filtrado sin tocar entornos reales.
5. Registrar resultados positivos y negativos como evidencia.

## Condición de cierre
Solo declarar VERIFICADO cuando exista evidencia fechada que demuestre la política acordada desde cliente, router y anfitrión.
