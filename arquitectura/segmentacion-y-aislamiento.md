# Segmentación y aislamiento

## Dominios distintos
- **Curso**: teoría, test, criterios de evaluación.
- **Laboratorio físico**: hosts, switching, routing y servicios de prueba.
- **Réplica virtual Lenovo**: objetivo funcional del laboratorio físico, redes y VMs propias.
- **Plataforma virtual MEDION**: pruebas OPNsense/libvirt independientes de la réplica Lenovo.
- **Entorno doméstico y producción**: infraestructura que debe conservar su funcionamiento.

## Regla operativa
Una interfaz o red denominada «aislada» no demuestra por sí sola aislamiento efectivo. Se requiere comprobar conectividad permitida y denegada, rutas, NAT y reglas del firewall desde ambos lados.

## MEDION: pruebas verificadas el 10/10/2026
- `lab-isolated` no tiene `forward` propio en libvirt, pero OPNsense conecta ese segmento con `default`.
- Debian alcanzó `1.1.1.1`; no puede describirse como completamente aislado.
- Realtek USB físico pasado a OPNsense como `ue0`, sin IP; bloqueo a otras redes privadas aún no probado.

## Verificaciones abiertas
- Revisar XML de redes libvirt.
- Contrastar interfaces de OPNsense.
- Comprobar rutas y reglas entre la red doméstica y LAN física.
- Revisar alcance de Tailscale y otros accesos de administración.

Estado: **SALIDA A INTERNET VERIFICADA / AISLAMIENTO FRENTE A REDES PRIVADAS NO VERIFICADO**.

