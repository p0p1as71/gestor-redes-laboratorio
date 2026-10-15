# Laboratorio virtual — Lenovo PYME y MEDION independientes

**Objetivo vigente desde 15/10/2026:** en Lenovo crear una **PYME virtual** (Windows 11, OpenMediaVault, CUPS/IPP, Linux Bridge) inicialmente aislada; después, si se valida y autoriza, incorporarla como ampliación al laboratorio físico. **Sin despliegue acreditado.**

## 1. Lenovo ThinkPad L13 — PYME virtual (vigente)

[Diseño, recursos, aislamiento y secuencia de implementación](lenovo-l13/README.md). El cambio requiere liberar RAM y disco, con migración **prevista y no ejecutada** de Omada Controller desde Lenovo al VPS Hetzner, preservando los servicios existentes. No se asigna automáticamente `LAB-NET` ni un puerto del SG2210P.

## 2. MEDION netlab-ws01 — prácticas independientes

[MEDION](medion-netlab-ws01/README.md) con OPNsense y redes `default`, `lab-isolated` y enlace físico OPT1/VLAN20 reportados históricamente. [OPNsense](opnsense/README.md) y la [práctica PRAC-003](../practicas/firewall-nat/PRAC-003-aislamiento-opnsense.md) pertenecen a esta plataforma, **no** a la PYME Lenovo.

## 3. Antecedente histórico — réplica Lenovo del 10/10/2026

El plan inicial era replicar Pi4 → MikroTik → switch → clientes (VM-GW-ADMIN, VM-ROUTER, VM-RPI3, VM-YUN, VM-ESP, VM-WIN11, AP lógico). Se conserva para trazabilidad en el [diseño Lenovo](lenovo-l13/README.md), pero **no debe ejecutarse como plan actual**. `LAB-NET`, `virbr50` y los recursos libvirt son estados históricos pendientes de reconfirmar.

## Regla de separación

Distinguir siempre anfitrión y fuente de evidencia: **red física**, **PYME Lenovo** y **MEDION**. Ninguna configuración histórica o propuesta constituye prueba del estado operativo presente.
