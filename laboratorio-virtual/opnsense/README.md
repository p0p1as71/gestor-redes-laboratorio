# OPNsense — router/firewall virtual

**VM documentada:** `opnsense-lab` en MEDION `netlab-ws01`.

## Instalación registrada

- Disco virtual de 20 GiB y sistema de archivos ZFS.
- Instalación mediante ISO, desmontada posteriormente.
- La VM estaba en ejecución cuando se intentó iniciar otra vez (respuesta «dominio ya activo»).

## Arquitectura prevista, no confirmada como asignación actual

```text
libvirt default (NAT) → interfaz WAN OPNsense
OPNsense → interfaz LAN → libvirt lab-isolated → clientes virtuales
```

## Sin verificar

- Orden real de interfaces y asociación WAN/LAN.
- IPv4, DHCP, DNS, reglas firewall y NAT.
- Conectividad de una máquina cliente.
- Aislamiento respecto de la red doméstica.
- Políticas de acceso administrativo y respaldo de configuración.

**Acción siguiente:** inspección de solo lectura en MEDION de la definición de VM y redes; registrar resultados antes de cambiar algo.
