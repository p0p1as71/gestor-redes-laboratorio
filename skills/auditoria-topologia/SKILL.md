---
name: auditoria-topologia
description: "Audita la coherencia documental de la topología del laboratorio Gestor de Redes, separando el entorno físico, la réplica virtual Lenovo y la plataforma MEDION. Usar cuando se solicite revisar conexiones, inventario, direccionamiento, evidencias o discrepancias sin modificar equipos."
---

# Auditoría documental de topología — Gestor de Redes

## Propósito y autoridad

Examinar la coherencia de la documentación y las evidencias del repositorio `gestor-redes-laboratorio`. Este procedimiento NO es un agente, no otorga permisos de ejecución y no certifica el estado operativo presente de los dispositivos.

**Modo por defecto: lectura y propuesta.** Un informe de auditoría no autoriza cambios en GitHub, NetBox, MikroTik, Raspberry Pi, TP-Link, OPNsense, libvirt, Lenovo, MEDION ni otros sistemas.

## Activación y entradas

Aplicar si el usuario pide «auditar topología», «revisar cableado o IP», «comparar documentación con inventario», «detectar inconsistencias» o una verificación equivalente.

Entradas mínimas:
- Alcance indicado por el usuario: físico, Lenovo, MEDION o transversal.
- Versión/ref del repositorio que se analiza; registrar fecha y commit si están disponibles.
- Documentos y evidencias realmente accesibles, con sus fechas.

Si falta acceso a una fuente, indicarlo; **no suplirlo con supuestos**.

## Fuentes documentales que conviene examinar

1. `README.md` y `CONTRIBUTING.md`: responsabilidad de cada sistema, estados y seguridad.
2. `arquitectura/arquitectura-general.md`, `arquitectura/direccionamiento-ip.md` y `arquitectura/revision-topologia-2026-10-10.md`.
3. `laboratorio-fisico/topologia.md` y fichas de equipos pertinentes.
4. `laboratorio-virtual/README.md`, `laboratorio-virtual/lenovo-l13/README.md` y `laboratorio-virtual/medion-netlab-ws01/README.md`.
5. `servicios/netbox/README.md`, `practicas/`, `evidencias/` y `CHANGELOG.md` cuando proceda.

Los documentos anteriores son fuentes documentales, no pruebas automáticas de estado en vivo.

## Separación obligatoria de ámbitos

- **FÍSICO:** Raspberry Pi 4 como gateway y administración, MikroTik, SG2210P, EAP225, Raspberry Pi 3 de prácticas, Arduino Yún, nodos ESP32 y enlaces físicos asociados.
- **LENOVO:** diseño e implementación de la réplica virtual principal. No presentar las máquinas o enlaces previstos como desplegados salvo evidencia expresa.
- **MEDION:** plataforma adicional `netlab-ws01`, OPNsense, `debian-client01` y redes virtuales propias. El enlace físico MEDION–switch no convierte sus redes virtuales en la réplica Lenovo.

Indicar siempre anfitrión, ámbito y naturaleza del enlace. No mezclar `LAB-NET` (Lenovo), `lab-isolated` (MEDION), la LAN MikroTik y `LAB-FISICO`/VLAN 20 por coincidencias de nombres o funciones.

## Procedimiento

1. **Fijar el corte documental.** Anotar rama/ref, commit si puede verificarse, fecha de consulta y alcance. Distinguir un documento histórico de su versión vigente.
2. **Extraer afirmaciones comprobables.** Identificar equipo, función, anfitrión, interfaz, puerto, red/IP, VLAN y conexión. No completar campos ausentes.
3. **Reconstruir cada ámbito por separado.** Elaborar una relación de conexiones para físico, Lenovo y MEDION antes de cualquier comparación transversal.
4. **Contrastar con trazabilidad.** Enlazar cada afirmación con archivo/sección, fecha de la evidencia y, cuando exista, medición, configuración saneada o prueba. Una afirmación en GitHub no acredita por sí sola un enlace operativo actual.
5. **Clasificar.** Emplear los estados documentales definidos en `CONTRIBUTING.md` (`PLANIFICADO`, `EN PREPARACIÓN`, `EN PRUEBAS`, `VERIFICADO`, `DOCUMENTADO`, `PENDIENTE`) indicando si la verificación es **histórica**. Reservar `VERIFICADO` a resultados con evidencia identificable y alcance temporal claro.
6. **Detectar divergencias.** Separar contradicciones internas, documentos obsoletos, elementos sin evidencia y diferencias respecto al inventario vivo. No afirmar divergencias con NetBox o equipos en vivo si no se han consultado.
7. **Proponer reconciliación.** Enumerar comprobaciones concretas, fuentes pendientes y cambios documentales sugeridos. No aplicar cambios automáticamente.

## Fuente de verdad y límites

- **NetBox:** inventario, IPAM y conexiones cuando hayan sido contrastados y reconciliados; no asumir sincronización automática.
- **GitHub:** decisiones, procedimientos, registros históricos y evidencias revisadas.
- **LibreNMS:** monitorización y alertas observadas, no autoridad de inventario ni aprobación.
- **Ansible/AWX:** automatización futura o explícitamente autorizada, nunca activación implícita.
- **Equipos vivos:** solo comprobaciones autorizadas. La ausencia de acceso significa «no verificado», no «desconectado».

Prohibido dentro de esta auditoría sin autorización específica:
- Alterar configuraciones, lanzar despliegues o reinicios, ejecutar escaneos de red o intervenir en producción.
- Crear commits, pushes, merges o cambios en NetBox por iniciativa propia.
- Exponer credenciales, tokens, contraseñas, configuraciones brutas, direcciones privadas sensibles innecesarias o datos de terceros.
- Declarar confirmada una topología a partir únicamente de documentación antigua.

## Formato de salida

Entregar:
1. **Alcance y corte** (rama/commit, fecha, fuentes consultadas y no accesibles).
2. **Resumen por ámbito:** FÍSICO / LENOVO / MEDION.
3. **Tabla de hallazgos:** ID · ámbito · afirmación o discrepancia · evidencia y fecha · estado · impacto · siguiente comprobación.
4. **Datos no verificables** (sin suplirlos con inferencias).
5. **Propuesta documental**, distinguiendo archivos a modificar y cambios operativos que requerirían autorización adicional.

Terminar siempre indicando: «Auditoría documental: no se han modificado configuraciones ni inventarios». Si en esa ejecución se realizó alguna modificación autorizada de documentación, describirla por separado y no utilizar esa frase como afirmación de que no se cambió GitHub.
