# Segmentación y aislamiento

## Dominios distintos
- **Curso**: teoría, test, criterios de evaluación.
- **Laboratorio físico**: hosts, switching, routing y servicios de prueba.
- **Réplica virtual Lenovo**: objetivo funcional del laboratorio físico, redes y VMs propias.
- **Plataforma virtual MEDION**: pruebas OPNsense/libvirt independientes de la réplica Lenovo.
- **Entorno doméstico y producción**: infraestructura que debe conservar su funcionamiento.

## Regla operativa
Una interfaz o red denominada «aislada» no demuestra por sí sola aislamiento efectivo. Se requiere comprobar conectividad permitida y denegada, rutas, NAT y reglas del firewall desde ambos lados.

## Verificaciones abiertas
- Revisar XML de redes libvirt.
- Contrastar interfaces de OPNsense.
- Comprobar rutas y reglas entre la red doméstica y LAN física.
- Revisar alcance de Tailscale y otros accesos de administración.

Estado: **DOCUMENTADO / validación parcial pendiente**.

