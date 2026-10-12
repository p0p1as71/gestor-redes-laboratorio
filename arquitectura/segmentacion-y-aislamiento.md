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

## Actualización documental MEDION / FÍSICO del 12/10/2026

- En OPNsense se añadió `OPT1/ue0` sobre RTL8153 con `10.20.20.1/24`; SG2210P puerto 6 se configuró como **Access VLAN 20 LAB-FISICO**.
- LAN virtual OPNsense: `10.10.10.0/24`; LAN física MikroTik: `192.168.88.0/24`; nueva VLAN física: `10.20.20.0/24`. No confundir con `LAB-NET` del Lenovo.
- Que el switch conserve los puertos 1–5 fuera de la VLAN 20 **no certifica aislamiento L3**: hay que revisar las rutas y políticas entre interfaces OPNsense, el NAT de libvirt y los segmentos privados.
- **Sin validar:** DHCP IPv4 OPT1, cliente físico VLAN 20, reglas y comunicaciones permitidas/denegadas entre redes. No considerar ninguna de ellas una política de bloqueo efectiva.

## Verificaciones abiertas
- Revisar XML de redes libvirt.
- Contrastar interfaces de OPNsense.
- Comprobar rutas y reglas entre la red doméstica y LAN física.
- Revisar alcance de Tailscale y otros accesos de administración.

Estado: **SALIDA A INTERNET VERIFICADA / AISLAMIENTO FRENTE A REDES PRIVADAS NO VERIFICADO**.

