# Plan de verificaciones pendientes — auditoría AUD-TOP-2026-10-13

**Ámbito:** comprobaciones futuras; **NO son resultados verificados ni autorizaciones para operar**.  
**Origen:** informe documental AUD-TOP-2026-10-13, revisión de 13/10/2026.  
**Requisito:** intervención separada autorizada, consulta primero, un solo comando cada vez y sin afectar producción.

## Prioridad y dependencias

| Orden | Entorno | IDs | Objetivo de la comprobación | Evidencia que debe registrarse | Condición de cierre |
|---|---|---|---|---|---|
| 1 (mañana, aparte) | FÍSICO | H01 | Identificar código fuente del servidor HTTP ESP32-01 usado el 12/10, sin flashear | Sketch/versión/origen y contraste con equipo cuando se autorice | Fuente reproducible o discrepancia documental resuelta |
| 2 | MEDION | H04, H07 | Consultar interfaces actuales `re1`/`re0`/`ue0`, MAC, rutas, NAT, reglas OPNsense y XML de VM | Capturas sanitizadas, hora, interfaces↔MAC↔red | Estado observado y política de aislamiento diseñada (sin cambios implícitos) |
| 3 | FÍSICO/MEDION | H05, H06 | Decidir puerto y cliente **adicionales** para VLAN 20 antes de cambiar switching; inspeccionar servicio DHCP OPT1 | Asignación de puerto elegida, configuración DHCP consultada, responsabilidades | Plan aprobado; el DHCP solo se marcará verificado con servicio y concesión reales |
| 4 | FÍSICO | H08, H09 | Contrastar LLDP, tabla MAC, puertos 1–6, EAP225, Pi3/Yún y ESP32-02/03 | Identidad MAC↔equipo↔puerto, fecha | Correspondencia inequívoca, sin borrar mapeos históricos |
| 5 | LENOVO | H10 | Consultar libvirt, pool `lab-vms`, `LAB-NET`, bridges y VMs de réplica | Estado de redes/VMs y permisos de tránsito | Diferenciar creado, diseñado y activo; no desplegar |
| 6 | TRANSVERSAL | H11 | Contrastar NetBox contra realidad verificada, incluido VLAN20 y OPT1 | Exportación de solo lectura / diferencias tipificadas | Plan de corrección IPAM aprobado antes de escribir |
| 7 | EVIDENCIAS | H12 | Diseñar registro de resultados con hora, fuente, alcance y ubicación | Referencias y hashes de PCAP/exports saneados | Evidencia localizable y publicada solo tras revisión de privacidad |
| 8 | MEDION | H15 | Diagnosticar `netlab-traffic.timer` (`bad-setting`) | Definición real, errores y ejecución comprobada | Programación de cinco minutos y disparos demostrados |
| 9 | FÍSICO | H14 | Contrastar fuente HTML del dashboard con topología aprobada | Versión y estado de servicio | Fuente identificada y funcionamiento verificado |

## Seguridad y separación

- **FÍSICO:** LAN MikroTik `192.168.88.0/24`, SG2210P y VLAN 20 `LAB-FISICO` `10.20.20.0/24`. El puerto 6 ya conecta OPNsense; **no se ha identificado ni reservado un segundo puerto Access VLAN 20 para un cliente**.
- **MEDION:** `lab-isolated` `10.10.10.0/24` sale a Internet mediante OPNsense según registro histórico; **no está acreditado** el bloqueo de redes privadas. WAN `default` y OPT1 `ue0` pertenecen a MEDION, no a la réplica Lenovo.
- **LENOVO:** `LAB-NET` / réplica virtual principal en estado de diseño y preparación histórica, sin desplegar ni certificar VMs aquí.
- **PRODUCCIÓN / DOMÉSTICA:** no usar como destino de pruebas hasta diseñar una política explícita; no tocar Tailscale, servicios existentes ni red doméstica.

## Protocolo mínimo para cada intervención posterior

1. Definir objetivo, alcance, riesgos y sistemas afectados.
2. Obtener autorización expresa para las consultas o cambios sobre equipos.
3. Leer el estado inicial; un comando por turno en el Lenovo/MEDION.
4. Si se contempla un cambio, preparar copia pertinente y reversión antes de ejecutarlo.
5. Ejecutar **un solo cambio** y comprobar resultado frente a una expectativa definida.
6. Registrar fecha/hora, herramienta, interfaces, MAC, subred, resultado y limitaciones; excluir secretos.
7. Actualizar GitHub/NetBox solo con una autorización específica para esos cambios.

**Estado de este documento:** PLANIFICADO. No se han comprobado equipos ni configurado puertos, DHCP, reglas ni servicios por elaborar este plan.
