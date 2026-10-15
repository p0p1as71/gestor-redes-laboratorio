# Servicios de gestión

| Servicio | Responsabilidad | Situación documental |
|---|---|---|
| NetBox | Inventario, IPAM y conexiones | Desplegado según histórico; reconciliar |
| LibreNMS | Métricas y alertas | Referenciado en Raspberry Pi 4 |
| Omada | Administración SG2210P/EAP225 | Configuración y clientes requieren diagnóstico |
| Dashboard HTML | Visualización | Archivo transferido; servicio web no verificado |
| Ansible/AWX | Automatización controlada | Previsto; no afirmar instalación |
| Tailscale | Acceso administrativo existente | Mantener límites; no duplicar configuración |

Crear ficha por servicio al disponer de evidencia concreta. Evitar almacenar tokens o claves.

## Reorganización de cargas planificada — 15/10/2026

Se evalúa trasladar **Omada Controller** del Lenovo al VPS Hetzner para reducir RAM y dependencia del portátil, manteniendo el controlador actual operativo hasta validar backup/restauración, puertos y adopción de SG2210P/EAP225 vía Tailscale y Raspberry Pi 4. No se ha realizado la migración ni aprobado apertura de servicios públicos. Windows 11 y NAS OpenMediaVault se crearán después en una PYME virtual aislada del Lenovo; CUPS/IPP será servicio de prácticas segregado, no un cambio a los Docker existentes. [Detalle](omada/README.md).
