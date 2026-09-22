# Changelog

Registro de los cambios relevantes del proyecto.

## 2026-09-20

### Añadido

- Creado el repositorio local `gestor-redes-laboratorio`.
- Inicializado Git en el repositorio.
- Creada la estructura inicial de documentación.
- Creado el README principal.
- Preparada la documentación inicial del laboratorio virtual y físico.

### Estado

- Repositorio local operativo.
- Repositorio remoto de GitHub creado como privado.
- Laboratorio virtual en fase de preparación.
- Máquinas virtuales todavía no creadas.

### Pendiente

- Conectar el repositorio local con GitHub.
- Crear el primer commit.
- Continuar documentando el laboratorio virtual.


---

## 2026-09-20 — Preparación y construcción del laboratorio

### Repositorio y documentación

- Creado el repositorio local `gestor-redes-laboratorio`.
- Inicializado Git y establecida la rama `main`.
- Creada la estructura inicial de documentación:
  - `curso/`
  - `laboratorio-virtual/`
  - `laboratorio-fisico/`
  - `arquitectura/`
  - `diagramas/`
  - `evidencias/`
  - `docs/`
- Creado el README principal del proyecto.
- Creado el CHANGELOG inicial.
- Creado el repositorio remoto privado de GitHub.
- Configurado el remoto `origin`.
- Realizado el primer commit.
- Realizado el primer `push` a `origin/main`.

### Preparación del almacenamiento del laboratorio virtual

- Identificado el SSD externo utilizado para el laboratorio virtual como un Apple SSD `SM0256G` de aproximadamente 233,8 GB.
- Revisada la estructura de particiones existente.
- Identificada una estructura anterior que incluía una partición LUKS2.
- Comprobado el volumen LUKS2 y sus características mediante `cryptsetup`.
- Desmontadas las particiones necesarias antes de reutilizar el dispositivo.
- Eliminadas las firmas de las estructuras anteriores.
- Creada una nueva tabla de particiones GPT.
- Creada una única partición destinada al laboratorio virtual.
- Formateada la partición como `ext4`.
- Etiquetada como `LAB-VMS`.
- Configurado el montaje en `/mnt/lab-vms`.
- Preparado el almacenamiento para alojar posteriormente los discos de las máquinas virtuales.
- El SSD interno del Lenovo no fue modificado.

### Plataforma de virtualización

- Verificada la disponibilidad de virtualización Intel VT-x en el Lenovo ThinkPad L13 Gen 3.
- Comprobada la disponibilidad de KVM en el kernel.
- Instalados QEMU, libvirt y Virt-Manager.
- Comprobado el funcionamiento del servicio de libvirt.
- Añadido el usuario al grupo correspondiente para la administración de libvirt.
- Comprobado el acceso mediante `virsh` utilizando `qemu:///system`.
- Creado el pool de almacenamiento `lab-vms`.
- Configurado el pool para utilizar `/mnt/lab-vms`.
- Comprobado que el pool se encontraba activo y preparado para futuras máquinas virtuales.

### Red virtual de libvirt

- Inspeccionada la red `default` proporcionada por libvirt.
- Identificada la red `192.168.122.0/24`.
- Comprobado que dicha red utiliza DHCP y NAT.
- Decidido no modificar la red `default` para evitar mezclarla con la red específica del laboratorio.
- Definido como objetivo crear posteriormente una red virtual propia y aislada.
- La red virtual específica del laboratorio todavía no ha sido creada.
- No se han creado todavía máquinas virtuales.
- No se han desplegado todavía Windows 11 ni Debian Server.

### Exploración y preparación de la Raspberry Pi 4

- Identificada la Raspberry Pi 4 Model B Rev 1.2.
- Comprobada la arquitectura ARM64.
- Identificado Debian 13.7 como sistema operativo.
- Comprobado el kernel utilizado.
- Identificadas las interfaces Ethernet `eth0`, Wi-Fi `wlan0` y otras interfaces del sistema.
- Revisado el estado general del sistema y del almacenamiento.
- Comprobado que la Raspberry dispone de Ethernet Gigabit y Wi-Fi.
- Revisados los servicios existentes.
- Confirmado el funcionamiento de NetworkManager.
- Confirmado Tailscale como mecanismo de conectividad remota.
- Confirmado NoMachine como principal mecanismo de acceso gráfico remoto.
- Conservado el entorno XFCE/X11.
- Revisada la situación de Raspberry Pi Connect.
- Detectado que `rpi-connect-wayvnc.service` no era funcional en el entorno X11 utilizado.
- Realizada la exploración de RealVNC, permaneciendo inactivo.
- No se realizaron acciones destructivas sobre estos servicios.
- La Raspberry Pi se mantuvo inicialmente conectada por Ethernet al MikroTik para realizar las pruebas del laboratorio.

### Diagnóstico inicial Raspberry Pi ↔ MikroTik

- Comprobado el enlace físico Ethernet de la Raspberry Pi.
- Identificado el enlace de `eth0` a 100 Mb/s Full Duplex durante las pruebas iniciales.
- Comprobado el estado de `carrier` de la interfaz.
- Observado inicialmente que DHCP no proporcionaba una dirección IPv4 en determinadas pruebas.
- Probada temporalmente una dirección `192.168.88.2/24`.
- Comprobada la conectividad con `192.168.88.1`.
- Retirada posteriormente la dirección temporal.
- No se realizó una modificación permanente de la configuración de red de la Raspberry durante esta fase.
- Instalado `mactelnet-client` para facilitar futuras tareas de diagnóstico con equipos MikroTik mediante MAC.

### MikroTik hEX lite

- Identificado el MikroTik hEX lite RB750r2 como router principal del laboratorio físico.
- Realizado un restablecimiento físico durante la fase inicial de exploración.
- Identificado RouterOS 7.1.2.
- Revisada la configuración inicial del equipo.
- Identificado `ether1` como interfaz WAN inicial.
- Identificados `ether2`–`ether5` como puertos LAN.
- Identificado el bridge LAN.
- Identificada inicialmente la red LAN `192.168.88.0/24`.
- Identificada la dirección LAN `192.168.88.1`.
- Comprobado el funcionamiento del servidor DHCP.
- Comprobado el funcionamiento de NAT y del firewall.
- Revisadas las interfaces y los puertos del bridge mediante WebFig.
- No se realizó una actualización de RouterOS ni del firmware RouterBOARD.

### Recuperación y auditoría del Arduino Yún

- Identificado el Arduino Yún original de primera generación.
- Identificado el microcontrolador ATmega32U4 y el procesador Atheros AR933x.
- Identificado el sistema Linux Linino/OpenWrt.
- Identificado el dispositivo serie `/dev/ttyACM0`.
- Configurado el acceso del usuario al dispositivo serie mediante el grupo `dialout`.
- Utilizado Arduino IDE 1.8.19.
- Seleccionada la placa Arduino Yún.
- Recuperado el acceso a la consola Linux del Yún.
- Subido y utilizado `YunSerialTerminal`.
- Realizado un reinicio mediante `YUN RST`.
- Recuperada la consola `root@linino:/#`.
- Identificado Linino Attitude Adjustment, r41182.
- Identificado Linux 3.3.8 sobre arquitectura MIPS.
- Identificados los componentes Atheros AR9330, CPU a 400 MHz, 64 MB de RAM y 16 MB de flash.
- Auditadas las interfaces `eth0`, `eth1`, `wlan0` y `lo`.
- Revisada la configuración de red existente.
- Revisados DHCP/dnsmasq, SSH/dropbear, rutas y servicios.
- Identificada una configuración Wi-Fi anterior.
- No se realizó un restablecimiento de fábrica del Arduino Yún.

### Arduino Yún conectado al laboratorio

- Conectado físicamente el Arduino Yún al `ether3` del MikroTik.
- Verificado el enlace Ethernet a 100 Mb/s Full Duplex.
- Obtenida mediante DHCP la dirección `192.168.88.253/24`.
- Identificado el gateway `192.168.88.1`.
- Identificado el DNS `192.168.88.1`.
- Identificada la dirección MAC del Arduino Yún.
- Verificado el ping desde el Yún hacia `192.168.88.1`.
- Verificada la comunicación desde el Yún hacia la Raspberry Pi en `192.168.88.254` durante las pruebas iniciales.
- Verificada la correspondencia ARP entre las direcciones IP y las MAC de los equipos.
- Comprobado que el Yún no disponía todavía de una ruta funcional hacia Internet.
- El intento de alcanzar `8.8.8.8` devolvió `Network is unreachable`.
- No se modificó el routing del Yún para proporcionar Internet en esta fase.

### Arquitectura física inicial

- Definida la utilización de la Raspberry Pi, MikroTik, switch PoE, Arduino Yún, ESP32 y punto de acceso como componentes del laboratorio físico.
- Definido el MikroTik como router principal de la LAN del laboratorio.
- Definido el switch PoE como elemento de switching y alimentación para los futuros nodos PoE.
- Planificada la utilización de tres placas Waveshare ESP32-S3-POE-ETH.
- Planificada la utilización de un punto de acceso Wi-Fi alimentado mediante PoE.
- Definido el uso de latiguillos Ethernet Cat6 cortos.
- Establecido el objetivo de mantener el laboratorio físicamente separado de la red doméstica y de los servicios de producción.

### Arquitectura común físico/virtual

- Establecido como principio de arquitectura que el laboratorio físico y el laboratorio virtual representan la misma arquitectura lógica.
- Definido el modelo lógico común:

  `Internet → Router → Switch → Hosts`

- Establecida la correspondencia conceptual entre:
  - Raspberry Pi / WAN de laboratorio.
  - MikroTik / router.
  - TP-Link TL-SG108PE / switch.
  - Arduino Yún y ESP32 / hosts.
  - Ethernet físico / interfaces de red virtuales.
  - PoE físico / alimentación de los nodos físicos.
- Definido el objetivo de practicar primero conceptos de red en el entorno virtual y posteriormente reproducirlos en el entorno físico.
- Esta arquitectura común queda como decisión de diseño del proyecto; los componentes virtuales equivalentes todavía están pendientes de implementación.

---

## 2026-09-21 — Configuración del gateway y enlace Raspberry Pi ↔ MikroTik

### Raspberry Pi como gateway

- Definida la Raspberry Pi 4 como gateway de acceso del laboratorio físico.
- Mantenida la conexión de la Raspberry Pi a Internet mediante `wlan0`.
- Configurada `wlan0` en la red `192.168.1.0/24`.
- Dirección de la Raspberry Pi en Wi-Fi: `192.168.1.236`.
- Gateway externo: `192.168.1.1`.
- Configurada una red dedicada para el enlace Raspberry Pi ↔ MikroTik.
- Configurada `eth0` de la Raspberry Pi con `192.168.100.1/30`.
- Definido el enlace dedicado `192.168.100.0/30`.
- No configurados gateway ni DNS adicionales en `eth0`.
- Activado el reenvío IPv4 en la Raspberry Pi.
- Preparada la Raspberry Pi para actuar como router entre Wi-Fi y la LAN del laboratorio.
- Configurada una regla NAT/MASQUERADE para permitir posteriormente la salida de `192.168.88.0/24` a través de `wlan0`.
- Instalado `tcpdump` en la Raspberry Pi para futuras prácticas de captura y análisis de tráfico.
- Mantenidos Tailscale, NoMachine y los servicios existentes.

### Configuración del MikroTik

- Reconfigurado `ether1` como enlace WAN hacia la Raspberry Pi.
- Configurada la dirección `192.168.100.2/30` en `ether1`.
- Configurada la ruta por defecto hacia `192.168.100.1`.
- Conservada la LAN `192.168.88.0/24`.
- Conservada la dirección LAN del MikroTik `192.168.88.1`.
- Mantenido el servidor DHCP de la LAN.
- Mantenidos `ether2`–`ether5` dentro del bridge LAN.
- Añadida una regla específica de firewall para permitir el acceso WebFig HTTP desde la Raspberry Pi a través del enlace `192.168.100.0/30`.
- Mantenidos los servicios de administración necesarios.
- WebFig HTTP activo en el puerto 80.
- SSH activo en el puerto 22.
- HTTPS en el puerto 443 desactivado.
- Winbox activo en el puerto 8291.

### Validación del enlace dedicado

- Conectado físicamente el enlace entre la Raspberry Pi y `ether1` del MikroTik.
- Verificada la comunicación entre `192.168.100.1` y `192.168.100.2`.
- Verificado el ping con respuesta completa.
- Registrada una latencia aproximada de 0,36 ms en las pruebas realizadas.
- Verificado el acceso WebFig del MikroTik desde la Raspberry Pi.
- Verificado el acceso SSH desde la Raspberry Pi al MikroTik.
- Confirmado que el enlace Raspberry Pi ↔ MikroTik funciona independientemente de la LAN `192.168.88.0/24`.

### Pruebas y observaciones

- Durante las pruebas de WebFig se identificó que los navegadores utilizados desde el Lenovo no pertenecían a la sesión gráfica de la Raspberry Pi.
- Esta diferencia de entorno explicó determinadas pruebas de acceso que no coincidían con los resultados obtenidos mediante `curl` y desde la propia Raspberry Pi.
- Posteriormente se confirmó el funcionamiento de WebFig desde la Raspberry Pi.

### Estado al cierre del 21/09

- Raspberry Pi conectada a Internet mediante Wi-Fi: **VERIFICADO**.
- Raspberry Pi ↔ MikroTik mediante `192.168.100.0/30`: **VERIFICADO**.
- Raspberry Pi configurada como gateway: **CONFIGURADO**.
- Reenvío IPv4 en Raspberry Pi: **CONFIGURADO**.
- NAT para la red `192.168.88.0/24`: **CONFIGURADO**.
- MikroTik configurado como router de la LAN `192.168.88.0/24`: **CONFIGURADO**.
- DHCP de la LAN: **ACTIVO**.
- Arduino Yún conectado a la LAN del MikroTik: **OPERATIVO**.
- Salida efectiva de los equipos de la LAN `192.168.88.0/24` hacia Internet mediante la Raspberry Pi: **PENDIENTE DE VALIDACIÓN**.
- Red virtual aislada del laboratorio: **PENDIENTE**.
- Máquinas virtuales: **PENDIENTES**.

### Próximos pasos

- Validar desde un equipo de la LAN `192.168.88.0/24` la salida hacia Internet a través de la Raspberry Pi.
- Documentar la topología física definitiva.
- Separar en documentos específicos la arquitectura, las prácticas y las evidencias.
- Documentar las prácticas realizadas con Raspberry Pi, MikroTik y Arduino Yún.
- Crear la red virtual aislada del laboratorio.
- Crear posteriormente las primeras máquinas virtuales.
- Reproducir en el laboratorio virtual los conceptos observados en la red física.