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

---

## 2026-09-22 — Diagnóstico y acceso SSH Raspberry Pi ↔ MikroTik ↔ Arduino Yún

### Arduino Yún y conectividad de red

- Retomada la configuración del laboratorio físico utilizando la Arduino Yún conectada por Ethernet al MikroTik y alimentación USB independiente.
- Eliminado el USB de datos con el Lenovo como canal habitual de administración de la Yún.
- Verificada la configuración de red de la Yún:
  - IP: `192.168.88.253/24`
  - Gateway: `192.168.88.1`
  - Interfaz Ethernet: `eth1`
  - MAC: `B4:21:8A:F8:4D:C9`
- Detectada temporalmente la pérdida de la ruta por defecto de la Yún.
- Renovado DHCP y recuperada correctamente la puerta de enlace `192.168.88.1`.

### Diagnóstico de conectividad

- Verificada mediante `ping` y `tcpdump` la comunicación entre:
  - Raspberry Pi `192.168.100.1` ↔ MikroTik `192.168.100.2`
  - Raspberry Pi `192.168.100.1` ↔ Arduino Yún `192.168.88.253`
  - MikroTik `192.168.100.2` ↔ Arduino Yún `192.168.88.253`
- Verificado que el firewall del MikroTik permite el tráfico de administración desde `192.168.100.1` hacia `192.168.88.0/24`.

### Acceso SSH

- Comprobada la disponibilidad del servicio SSH de la Yún en `22/TCP` desde la Raspberry Pi.
- Identificada la antigüedad del servidor SSH de la Yún y sus requisitos de compatibilidad criptográfica.
- Configurado el cliente SSH de la Raspberry para permitir `diffie-hellman-group14-sha1` y `ssh-rsa` durante la conexión con la Yún.
- Establecido correctamente el acceso SSH desde la Raspberry Pi a la Yún como `root`.
- Confirmado el modelo operativo de administración:
  - Raspberry Pi → SSH → MikroTik
  - Raspberry Pi → SSH → Arduino Yún
- Comprobado que el acceso SSH directo MikroTik → Yún alcanza el servicio SSH, pero la autenticación no se completó; no se considera una ruta de administración operativa.
- Mantenido el USB del Lenovo como canal de recuperación y configuración de la Yún, no como canal normal de administración de red.

### Estado

- Acceso remoto por red desde la Raspberry Pi al MikroTik: **OPERATIVO**.
- Acceso remoto por red desde la Raspberry Pi a la Arduino Yún: **OPERATIVO**.
- Administración habitual de la Yún mediante USB desde el Lenovo: **NO NECESARIA**.
- USB del Lenovo para recuperación/configuración: **MANTENIDO**.

### Rutas de administración comprobadas

| Desde | Destino | IP destino | Comando de terminal | Resultado |
|---|---|---|---|---|
| **Raspberry** | **MikroTik** | `192.168.100.2` | `ssh admin@192.168.100.2` | **SSH OK** |
| **Raspberry** | **Yún** | `192.168.88.253` | `ssh -o KexAlgorithms=+diffie-hellman-group14-sha1 -o HostKeyAlgorithms=+ssh-rsa root@192.168.88.253` | **SSH OK** |
| **Raspberry** | **Yún — puerto SSH** | `192.168.88.253:22` | `nc -vz -w 3 192.168.88.253 22` | **TCP/22 OK** |
| **Raspberry** | **Yún** | `192.168.88.253` | `ping -c 3 192.168.88.253` | **PING OK** |
| **MikroTik** | **Raspberry** | `192.168.100.1` | `ping 192.168.100.1 count=3` | **PING OK** |
| **MikroTik** | **Yún** | `192.168.88.253` | `ping 192.168.88.253 count=3` | **PING OK** |
| **Yún** | **Raspberry** | `192.168.100.1` | `ping -c 3 192.168.100.1` | **PING OK** |

### Las dos rutas SSH de administración

**Raspberry → MikroTik**

```bash
ssh admin@192.168.100.2
```

**Raspberry → Arduino Yún**

```bash
ssh -o KexAlgorithms=+diffie-hellman-group14-sha1 -o HostKeyAlgorithms=+ssh-rsa root@192.168.88.253
```

Estas son las dos rutas SSH de administración comprobadas y funcionando en el laboratorio físico:

```text
RASPBERRY → MikroTik
RASPBERRY → Arduino Yún
```

---

## 2026-09-23 — Gestión de red — Instalación de LibreNMS en Raspberry Pi

### Preparación

- Se preparó la estructura de trabajo para la gestión de red:
  - `~/gestion-red/librenms/`
  - `~/gestion-red/librenms/deploy/`
- Se decidió utilizar **LibreNMS** como plataforma de monitorización de la infraestructura del laboratorio físico.
- El despliegue se realizó mediante **Docker**, manteniendo la plataforma de monitorización separada de los servicios principales del laboratorio.

### Despliegue de LibreNMS

- Se descargó y revisó el Docker oficial de LibreNMS.
- Se utilizó el Compose oficial como base para el despliegue.
- Se configuraron los siguientes componentes:
  - LibreNMS.
  - MariaDB como base de datos.
  - Redis para caché y sesiones.
  - Dispatcher.
  - Syslog-ng.
  - SNMP Trapd.
  - MSMTPD para correo.
- Se configuró `Europe/Madrid` como zona horaria.
- Se generó una contraseña aleatoria específica para MariaDB.
- Se sustituyó la comunidad SNMP de ejemplo `librenmsdocker` por una comunidad propia del laboratorio.
- La comunidad SNMP real no se documenta en GitHub por motivos de seguridad.

### Validaciones previas

- Se comprobaron previamente los puertos necesarios:
  - `8000/TCP`
  - `514/TCP+UDP`
  - `162/TCP+UDP`
- Todos los puertos comprobados estaban libres.
- Se validó el archivo Compose antes de iniciar el despliegue.

### Puesta en funcionamiento

- Se descargaron las imágenes Docker necesarias.
- Se crearon los contenedores del despliegue.
- Se verificó que los **7 contenedores** quedaron en estado `Up`.
- Se verificó mediante los logs la inicialización de la base de datos.
- Se verificó mediante los logs la inicialización de LibreNMS.
- Se comprobó que la aplicación web respondía correctamente mediante HTTP `302 → /login`.
- Se completó la instalación inicial desde el navegador del Lenovo.
- Se creó el usuario administrador de LibreNMS.

### Acceso remoto

- Se verificó el acceso a LibreNMS a través de la interfaz Tailscale de la Raspberry Pi:
  - `100.90.39.30:8000`
- LibreNMS quedó accesible desde el Lenovo mediante Tailscale.
- El acceso administrativo se mantiene mediante la red privada de Tailscale y no mediante una publicación directa de LibreNMS en Internet.

### Objetivo dentro del laboratorio

LibreNMS queda establecido como plataforma central de monitorización de la infraestructura de red del laboratorio físico.

La incorporación de dispositivos se realizará progresivamente, comenzando por el MikroTik y posteriormente incorporando el resto de equipos de red y dispositivos compatibles con SNMP.

### Estado al cierre

**LibreNMS instalado y operativo en la Raspberry Pi.**

### Pendiente para la próxima sesión

1. Validar la instalación desde LibreNMS.
2. Revisar la configuración de informes y errores.
3. Añadir el MikroTik como primer dispositivo monitorizado.
4. Configurar y comprobar SNMP entre LibreNMS y el MikroTik.
5. Verificar la recepción y representación de datos de monitorización.
6. Posteriormente incorporar:
   - Arduino Yún.
   - Switch TP-Link.
   - AP Wi-Fi.
   - Otros dispositivos del laboratorio compatibles con SNMP.

   ---

## 2026-09-24 → 2026-09-27 — Monitorización, Raspberry Pi 3B, LibreNMS y NetBox

### Raspberry Pi 3B — nodo de monitorización

- Incorporada una **Raspberry Pi 3 Model B v1.2** al laboratorio físico.
- Preparada una tarjeta microSD de 32 GB para el nuevo nodo.
- Preparada la tarjeta mediante Raspberry Pi Imager desde el Lenovo.
- Identificado el dispositivo de almacenamiento mediante `lsblk` y `lsusb`.
- Comprobado el dispositivo mediante `dmesg`.
- Eliminadas las estructuras de datos anteriores de la tarjeta antes de instalar el sistema.
- Sobrescritos los primeros 256 MiB del dispositivo.
- Grabada la imagen de Raspberry Pi OS mediante Raspberry Pi Imager.
- Confirmado el arranque de la Raspberry Pi 3B desde la nueva tarjeta SD.

La Raspberry Pi 3B queda definida como **nodo de monitorización y diagnóstico**, diferenciada de la Raspberry Pi 4.

### Arquitectura de las Raspberry Pi

**Raspberry Pi 4**

- Gateway del laboratorio.
- Gestión y administración.
- Tailscale.
- NoMachine.
- LibreNMS.
- Servicios de observabilidad.

**Raspberry Pi 3B**

- Nodo dedicado de monitorización y diagnóstico.
- No actúa como gateway.
- No sustituye a la Raspberry Pi 4.
- Funciones de routing separadas de las funciones de monitorización.

### Conectividad de la Raspberry Pi 3B

Se verificó una configuración con dos interfaces de red:

- Ethernet → MikroTik:
  - `192.168.88.252`
- Wi-Fi → Starlink:
  - `192.168.1.94`

- Añadida temporalmente una ruta desde la Raspberry Pi 3B hacia la red de tránsito `192.168.100.0/30` para permitir la comunicación con la Raspberry Pi 4.
- Verificada la comunicación bidireccional:
  - Raspberry Pi 3B → Raspberry Pi 4.
  - Raspberry Pi 4 → Raspberry Pi 3B.

### SNMP en Raspberry Pi 3B

- Instalado y activado `snmpd`.
- Creada una copia de seguridad de `/etc/snmp/snmpd.conf`.
- Ampliada la configuración SNMP para permitir la consulta de interfaces y contadores.
- Verificadas mediante SNMP las interfaces:
  - `lo`
  - `eth0`
  - `wlan0`
- Verificados los contadores de tráfico mediante SNMP.

### Integración de Raspberry Pi 3B en LibreNMS

- Incorporada la Raspberry Pi 3B a LibreNMS como `rpi3-monitor`.
- Discovery SNMP completado correctamente.
- Polling completado correctamente.
- LibreNMS monitoriza en la Raspberry Pi 3B:
  - CPU.
  - Memoria.
  - Almacenamiento.
  - Interfaces.
  - Tráfico.
  - Carga.
  - Uptime.
  - Temperatura.
  - Disponibilidad mediante ICMP.

La Raspberry Pi 3B queda establecida como **nodo de monitorización del laboratorio físico**, sin ejecutar una segunda instancia de LibreNMS.

---

### Raspberry Pi 4 — LibreNMS y administración

- Consolidada la **Raspberry Pi 4** como nodo de gateway, gestión y observabilidad del laboratorio.
- LibreNMS continúa operativo mediante Docker.
- Incorporada la propia Raspberry Pi 4 a LibreNMS mediante SNMP.
- Verificadas interfaces físicas, interfaces Docker y métricas del sistema.
- Tras un reinicio de la Raspberry Pi 4 se verificó la recuperación de:
  - Docker.
  - LibreNMS.
  - Tailscale.
  - Servicios de administración.
- Verificado posteriormente el funcionamiento normal del sistema tras el reinicio, incluyendo carga y memoria.

---

### Arduino Yún — diagnóstico de conectividad

- Continuado el diagnóstico del Arduino Yún `192.168.88.253`.
- Confirmada su presencia en la tabla ARP del MikroTik.
- Confirmada la conectividad MikroTik → Yún.
- Desde la Raspberry Pi 4, las conexiones ICMP/TCP hacia el Yún no obtuvieron respuesta.
- Mediante captura en el MikroTik se comprobó que las solicitudes TCP llegaban físicamente al segmento del Yún, pero no se observaba respuesta procedente del dispositivo.
- Se estableció como siguiente punto de diagnóstico el acceso físico al Yún mediante USB/serie para revisar su estado de red.
- El Yún permanece integrado en LibreNMS mediante **ICMP**, sin monitorización SNMP.

**Estado del Yún:**

- Conectividad física: **CONFIRMADA**
- Presencia en red: **CONFIRMADA**
- ICMP desde MikroTik: **CONFIRMADO**
- Respuesta ICMP/TCP desde Raspberry Pi 4: **NO CONFIRMADA**
- SNMP: **NO CONFIGURADO**
- Monitorización LibreNMS: **ICMP**

---

### NetBox — instalación y puesta en marcha

- Instalado **NetBox 4.7.1** mediante Docker Compose en la Raspberry Pi 4.
- NetBox se mantiene separado arquitectónicamente de LibreNMS.
- LibreNMS mantiene el puerto `8000`.
- NetBox utiliza el puerto `8001`.

Componentes desplegados:

- NetBox.
- NetBox Worker.
- PostgreSQL.
- Redis.
- Redis-cache.

- Completadas las migraciones iniciales de la base de datos.
- Verificado el funcionamiento de la interfaz web de NetBox.
- Creado el usuario administrativo `popi`.
- Conservados los datos mediante los volúmenes Docker existentes.

### Recuperación y persistencia de NetBox

- Después de un reinicio de la Raspberry Pi se comprobó que Docker estaba activo, pero los contenedores de NetBox no se iniciaban automáticamente.
- Identificada la causa: los contenedores tenían configurada la política:

`RestartPolicy=no`

- Recuperado NetBox mediante Docker Compose sin eliminar volúmenes ni reinstalar la aplicación.
- Verificado posteriormente el estado de los servicios:
  - PostgreSQL → `healthy`
  - Redis → `healthy`
  - Redis-cache → `healthy`
  - NetBox → `healthy`
- Creada una copia de seguridad de `docker-compose.override.yml`.
- Modificado `docker-compose.override.yml` para establecer:

`restart: unless-stopped`

en los cinco servicios:

- `netbox`
- `postgres`
- `redis`
- `redis-cache`
- `netbox-worker`

El objetivo es permitir la recuperación automática de la infraestructura NetBox después de futuros reinicios de la Raspberry Pi.

---

### Estado consolidado al 27/09/2026

| Componente | Función | Estado |
|---|---|---|
| Raspberry Pi 4 | Gateway / Gestión / Observabilidad | **OPERATIVA** |
| Raspberry Pi 3B | Monitorización / Diagnóstico | **OPERATIVA** |
| LibreNMS | Monitorización | **OPERATIVO** |
| NetBox | Inventario / Documentación de infraestructura | **OPERATIVO** |
| MikroTik hEX lite | Router del laboratorio | **OPERATIVO** |
| Arduino Yún | Nodo de laboratorio | **INTEGRADO / DIAGNÓSTICO PENDIENTE** |
| SNMP Raspberry Pi 3B | Monitorización | **OPERATIVO** |
| SNMP Raspberry Pi 4 | Monitorización | **OPERATIVO** |
| SNMP Arduino Yún | Monitorización | **PENDIENTE** |

### Próximos pasos

1. Resolver el diagnóstico de conectividad del Arduino Yún desde la Raspberry Pi 4.
2. Determinar si el Yún puede ser monitorizado mediante SNMP o mantener únicamente ICMP.
3. Continuar incorporando dispositivos de red a LibreNMS.
4. Documentar los equipos y relaciones de red en NetBox.
5. Continuar validando la recuperación automática de los servicios tras reinicios.
6. Integrar progresivamente switch, AP y nodos ESP32 en la plataforma de observabilidad.

---

## 2026-09-27 → 2026-09-28 — Consolidación de la red, funciones de los nodos y administración de contingencia

### MikroTik RB750r2 — consolidación de la red física

- Consolidada la configuración del MikroTik hEX lite RB750r2 como router principal de la red física del laboratorio.
- Confirmada la topología física actual:
  - `ether1` → Raspberry Pi 4 / enlace WAN del laboratorio.
  - `ether2` → Raspberry Pi 3.
  - `ether3` → Arduino Yún.
  - `ether4`–`ether5` → libres.
- Confirmada la red de tránsito Raspberry Pi 4 ↔ MikroTik:
  - Raspberry Pi 4: `192.168.100.1/30`.
  - MikroTik: `192.168.100.2/30`.
- Confirmada la LAN del laboratorio:
  - Red: `192.168.88.0/24`.
  - MikroTik: `192.168.88.1`.
  - Raspberry Pi 3: `192.168.88.252`.
  - Arduino Yún: `192.168.88.253`.
  - Raspberry Pi 4: `192.168.88.254`.
- Configurado/verificado DNS `1.1.1.1`.
- Configurada la zona horaria `Europe/Madrid`.
- Configurado NTP mediante `pool.ntp.org`.
- Verificada la sincronización correcta del reloj.
- Realizadas nuevas pruebas de conectividad entre los elementos de la red.
- Creado el backup:
  - `lab-mikrotik-2026-09-27.backup`
- Copiado externamente el backup a la Raspberry Pi 4.
- Eliminados backups antiguos innecesarios, conservando los automáticos relevantes.

### Raspberry Pi 4 — gateway y administración

- Consolidada la Raspberry Pi 4 como elemento con dos funciones principales dentro de la arquitectura:
  1. **Gateway de la red física del laboratorio**, proporcionando la salida hacia Internet mediante Starlink.
  2. **Estación principal de administración y observabilidad** de la infraestructura.
- Confirmadas sus direcciones principales:
  - Wi-Fi/Starlink: `192.168.1.236`.
  - Ethernet hacia MikroTik: `192.168.100.1`.
  - Presencia en la LAN: `192.168.88.254`.
- La función de administración de la Raspberry Pi 4 incluye actualmente:
  - LibreNMS para monitorización.
  - NetBox para inventario, IPAM y documentación.
  - futura automatización mediante Ansible/AWX.
- Tras un reinicio se detectó la pérdida de las rutas estáticas hacia la red `192.168.88.0/24`.
- Recuperada temporalmente la ruta:
  - `192.168.88.0/24 via 192.168.100.2`
- Verificada posteriormente la recuperación de la comunicación con la Raspberry Pi 3.
- La persistencia definitiva de esta ruta queda pendiente.

### Raspberry Pi 3 — revisión de función dentro del laboratorio

- Durante la integración inicial de la Raspberry Pi 3 se había planteado utilizarla como nodo de monitorización.
- Se comprobó posteriormente que esta función resultaba redundante, ya que la Raspberry Pi 4 ya proporciona la infraestructura de monitorización y administración mediante LibreNMS y NetBox.
- Se decidió redefinir la función principal de la Raspberry Pi 3 como **estación de trabajo, prácticas y diagnóstico del laboratorio**.
- La Raspberry Pi 3 queda destinada a:
  - pruebas de red;
  - prácticas de DNS;
  - pruebas de servicios;
  - diagnóstico;
  - experimentación;
  - pruebas con los elementos físicos del laboratorio.
- Esta decisión permite disponer de una estación Linux física para prácticas sin añadir otro ordenador convencional al laboratorio.
- Los dispositivos ESP32 se mantienen como nodos embebidos de experimentación y no sustituyen a una estación de trabajo general.
- En NetBox se refleja esta función mediante el concepto de **Desktop / estación de trabajo**.

### Raspberry Pi 3 — conectividad y pruebas

- Confirmadas sus conexiones:
  - Ethernet hacia MikroTik: `192.168.88.252`.
  - Wi-Fi hacia Starlink: `192.168.1.94`.
- Verificada la conectividad Raspberry Pi 4 → Raspberry Pi 3:
  - `3/3` respuestas.
  - `0 %` de pérdida.
  - RTT medio aproximado: `0,681 ms`.
- Verificado el acceso SSH desde la Raspberry Pi 4 hacia la Raspberry Pi 3.
- Verificada la conectividad MikroTik → Raspberry Pi 3:
  - `3/3` respuestas.
  - `0 %` de pérdida.
- Verificada la conectividad Raspberry Pi 3 → Raspberry Pi 4:
  - `3/3` respuestas.
  - `0 %` de pérdida.
- Recuperada temporalmente en la Raspberry Pi 3 la ruta hacia la red de tránsito:
  - `192.168.100.0/30 via 192.168.88.1`
- La persistencia definitiva de esta ruta queda pendiente.

### Descubrimiento de una ruta de administración de contingencia

- Durante las pruebas se identificó que la Raspberry Pi 3 dispone simultáneamente de conectividad hacia:
  - la red local de Starlink mediante Wi-Fi;
  - la red física del laboratorio mediante Ethernet.
- Esta doble conexión permite utilizar la Raspberry Pi 3 como punto intermedio de acceso a la red física del laboratorio cuando la Raspberry Pi 4 no esté disponible como punto de entrada habitual.
- La ruta de administración identificada puede representarse como:

```text
Lenovo / móvil
       │
       │ acceso remoto / red Starlink
       ▼
Raspberry Pi 3
192.168.1.94
       │
       │ SSH
       ▼
MikroTik
192.168.88.1
       │
       ├── LAN del laboratorio
       │
       └── enlace hacia Raspberry Pi 4
       - Desde la Raspberry Pi 3 se mantiene el acceso SSH al MikroTik a través de la LAN 192.168.88.0/24.
- Esta ruta proporciona una vía alternativa de administración y diagnóstico en caso de indisponibilidad de la Raspberry Pi 4.
- La ruta puede utilizarse desde equipos que tengan acceso a la red de Starlink, así como mediante un equipo accesible remotamente que disponga de conectividad hacia dicha red.
- La existencia de esta ruta no constituye un sistema de alta disponibilidad ni un failover automático.
- Se considera una ruta de administración de contingencia.
Aprendizaje arquitectónico
- Las pruebas permitieron identificar que la disponibilidad del gateway principal y la disponibilidad de una ruta de administración no son necesariamente el mismo problema.
- La Raspberry Pi 4 concentra actualmente el gateway y la administración principal de la infraestructura.
- La Raspberry Pi 3 proporciona una segunda vía física de acceso al laboratorio gracias a su conectividad simultánea con Starlink y el MikroTik.
- Esta experiencia permitió identificar la importancia de diseñar también caminos de administración y recuperación ante fallos, además de la conectividad normal de producción.
Gateway de contingencia — diseño futuro
- Se identificó como posible evolución futura la utilización de la Raspberry Pi 3 como gateway de respaldo.
- La arquitectura actualmente operativa continúa siendo:
  - Raspberry Pi 4 → gateway principal.
  - MikroTik → router de la LAN.
  - Raspberry Pi 3 → estación de trabajo/prácticas/diagnóstico.
- Se planteó un posible modo degradado de emergencia en el que la Raspberry Pi 3 pueda asumir determinadas funciones críticas si la Raspberry Pi 4 deja de estar disponible.
- Esta funcionalidad de failover no está implementada actualmente.
- No se modificó la red física existente para implementar este diseño.
- El gateway de respaldo queda registrado como diseño y práctica futura.

### LibreNMS — ampliación de la monitorización

- Ampliada la infraestructura monitorizada por LibreNMS durante el fin de semana.
- Estado de los dispositivos actualmente registrados:
  - MikroTik → ID `1`.
  - Arduino Yún → ID `2`.
  - Raspberry Pi 3 → ID `3`.
  - Raspberry Pi 4 → ID `4`.
- Verificado que los dispositivos permanecen registrados y no están marcados como eliminados o ignorados.
- Confirmadas en LibreNMS las principales interfaces de los dispositivos:
  - MikroTik: `ether1`–`ether5` y bridge.
  - Raspberry Pi 3: `eth0` y `wlan0`.
  - Raspberry Pi 4: `eth0` y `wlan0`.

### LibreNMS — SNMP

- Verificado SNMP v2c operativo en las Raspberry Pi 3 y 4.
- Verificadas consultas SNMP desde el entorno de LibreNMS hacia ambas Raspberry Pi.
- Ampliada la información SNMP disponible de la Raspberry Pi 4 para consultar recursos de:
  - memoria;
  - almacenamiento;
  - procesos.
- Reiniciado `snmpd` en la Raspberry Pi y ejecutado posteriormente un nuevo discovery.

### LibreNMS — discovery, polling y RRD

- Verificado el funcionamiento del discovery de los dispositivos.
- Verificado el descubrimiento de interfaces.
- Verificado el polling periódico.
- Verificada la actualización de los RRD.
- Verificada la generación de datos de tráfico.
- Verificada la adquisición de:
  - temperatura;
  - memoria;
  - almacenamiento;
  - disponibilidad;
  - rendimiento;
  - procesos;
  - interfaces.
- En la Raspberry Pi 3 se confirmó la adquisición de datos correspondientes a:
  - `eth0`;
  - `wlan0`;
  - procesos;
  - usuarios;
  - ping;
  - disponibilidad;
  - RRD.
- Comprobado que `rrdtool` puede generar directamente una gráfica a partir de los datos almacenados de la Raspberry Pi 3.

### LibreNMS — investigación de las gráficas

- Investigada la diferencia entre las gráficas de recursos mostradas para las Raspberry Pi y las mostradas para el MikroTik.
- Durante el diagnóstico se descartaron como causa:
  - pérdida de conectividad;
  - fallo de SNMP;
  - fallo de discovery;
  - ausencia de RRD;
  - fallo del polling.
- Confirmado que los datos de monitorización de las Raspberry Pi se están adquiriendo y almacenando correctamente.
- Comprobado mediante `rrdtool` que los datos disponibles pueden utilizarse para generar gráficas directamente.
- La investigación orientó el problema hacia la presentación o generación de determinados elementos del `Overview` de LibreNMS, y no hacia la adquisición de los datos.
- Durante la investigación se consultó la estructura disponible de `device_graphs` y se comprobó que el esquema utilizado no contiene la columna `port_id`.
- Como consecuencia, se decidió continuar la construcción de una vista específica mediante el dashboard personalizado del laboratorio.

### Dashboard personalizado `Lab`

- Creado y utilizado el dashboard personalizado `Lab` de LibreNMS.
- El dashboard permite construir una vista específica del laboratorio independientemente del `Overview` automático de cada dispositivo.
- Se incorporaron widgets para representar diferentes aspectos de la infraestructura, entre ellos:
  - `raspi Stats`;
  - `Mikrotik Stats`;
  - `Top Devices`;
  - `Device Summary Horizontal`;
  - `DHCP Lease Count`;
  - `Top Interfaces`;
  - `Alerts`;
  - `Eventlog`;
  - `Availability Map`;
  - `Top Errors`;
  - `Graylog`.
- Verificado visualmente el funcionamiento del dashboard y la representación de dispositivos y métricas.
- El dashboard `Lab` queda establecido como base para continuar construyendo la vista de observabilidad del laboratorio.

### NetBox — plataforma documental

- Continuada la utilización de NetBox Community `4.7.1` en la Raspberry Pi 4.
- Verificado el acceso mediante Tailscale en el puerto `8001`.
- Verificados los servicios Docker de:
  - NetBox;
  - NetBox Worker;
  - PostgreSQL;
  - Redis;
  - Redis-cache.
- Verificada la política `restart: unless-stopped` de los cinco servicios.
- Realizado backup de la configuración/override de Docker.
- Consolidado NetBox como fuente documental de verdad para:
  - inventario;
  - IPAM;
  - VLAN;
  - conexiones;
  - arquitectura del laboratorio.

### NetBox — inventario inicial

- Creado el Site:
  - nombre: `LAB-REDES`;
  - slug: `lab-redes`;
  - estado: `Activo`.
- Creado el fabricante `MikroTik`.
- Creado el rol de dispositivo `Router`.
- Iniciado el alta del modelo:
  - `MikroTik RB750r2 hEX lite`.
- Iniciado el inventario de los equipos principales del laboratorio:
  - MikroTik RB750r2 hEX lite;
  - Raspberry Pi 4;
  - Raspberry Pi 3;
  - Arduino Yún v1.2.
- Definidos conceptualmente sus papeles dentro del laboratorio:
  - MikroTik → router;
  - Raspberry Pi 4 → gateway/gestión;
  - Raspberry Pi 3 → estación de trabajo/prácticas;
  - Arduino Yún → nodo de experimentación/legacy.
- Iniciado el inventario de interfaces del MikroTik.
- Durante el alta de `ether1` se registró inicialmente la interfaz con el nombre `100BASE-TX` en lugar de `ether1`.
- La corrección del nombre de esta interfaz queda pendiente.
- Los cambios realizados en NetBox corresponden exclusivamente a documentación e inventario.
- NetBox no se está utilizando para modificar automáticamente los equipos reales.

### Separación entre documentación y operación

- Se mantiene NetBox como herramienta documental y de modelado de la infraestructura.
- La configuración real de la red continúa siendo responsabilidad de los equipos físicos correspondientes.
- La incorporación de dispositivos, interfaces, direcciones IP, VLAN y conexiones en NetBox no implica cambios automáticos en MikroTik, Raspberry Pi, LibreNMS u otros elementos del laboratorio.
- Se mantiene la separación entre:
  - infraestructura real;
  - monitorización mediante LibreNMS;
  - documentación mediante NetBox;
  - experimentación mediante la Raspberry Pi 3.

  Sí, continúa. Esta es la **PARTE 3/3**, con el cierre, estado y pendientes:

```markdown id="z5xq2k"
### Arquitectura física y función de los nodos

Al finalizar el fin de semana queda consolidada la siguiente distribución funcional:

```text
                         INTERNET
                            │
                         STARLINK
                            │
                           Wi-Fi
                            │
                    ┌───────▼────────┐
                    │ Raspberry Pi 4 │
                    │                │
                    │ Gateway        │
                    │ Administración │
                    └───────┬────────┘
                            │
                    192.168.100.0/30
                            │
                    ┌───────▼────────┐
                    │    MikroTik    │
                    │ 192.168.88.1   │
                    │     Router     │
                    └───────┬────────┘
                            │
                    192.168.88.0/24
                            │
             ┌──────────────┼──────────────┐
             │              │              │
           RPi 3           Yún       futuros nodos
        .252 / .1.94       .253
             │
             │
      Estación de trabajo
       / prácticas
```

- Raspberry Pi 4:
  - gateway principal;
  - administración;
  - monitorización;
  - documentación de infraestructura.
- MikroTik:
  - router de la LAN;
  - DHCP;
  - routing;
  - frontera de la red física del laboratorio.
- Raspberry Pi 3:
  - estación de trabajo;
  - prácticas;
  - pruebas;
  - diagnóstico;
  - experimentación con servicios de red.
- Arduino Yún:
  - nodo de experimentación;
  - dispositivo legacy;
  - plataforma para prácticas con hardware y servicios de red.
- Futuros ESP32, switch PoE y AP Wi-Fi:
  - elementos de expansión del laboratorio físico.

### Herramientas de gestión y observabilidad

La arquitectura de administración queda organizada conceptualmente de la siguiente manera:

```text
Raspberry Pi 4
│
├── LibreNMS
│   └── Monitorización y observabilidad
│
├── NetBox
│   └── Inventario, IPAM, VLAN y documentación
│
└── Ansible/AWX
    └── Automatización futura
```

- LibreNMS se mantiene como plataforma de monitorización.
- NetBox se mantiene como fuente documental de verdad.
- Ansible/AWX queda como componente de automatización pendiente.
- La Raspberry Pi 3 no duplica estas funciones y queda dedicada principalmente a prácticas y experimentación.

### Estado de la red y servicios al cierre del fin de semana

| Componente | Función | Estado |
|---|---|---|
| Raspberry Pi 4 | Gateway / gestión / observabilidad | **OPERATIVO** |
| MikroTik RB750r2 | Router de la LAN | **OPERATIVO** |
| Raspberry Pi 3 | Estación de trabajo / prácticas / diagnóstico | **OPERATIVO** |
| Arduino Yún | Nodo de experimentación / legacy | **INTEGRADO / DIAGNÓSTICO PENDIENTE** |
| LibreNMS | Monitorización | **OPERATIVO** |
| Dashboard `Lab` | Observabilidad personalizada | **OPERATIVO / EN DESARROLLO** |
| NetBox | Inventario / IPAM / documentación | **OPERATIVO** |
| Inventario NetBox | Documentación de equipos e interfaces | **EN DESARROLLO** |
| Ansible/AWX | Automatización | **PENDIENTE** |
| Gateway de respaldo RPi3 | Contingencia/failover | **DISEÑO FUTURO — NO IMPLEMENTADO** |

### Aprendizajes obtenidos durante el fin de semana

- La función de un dispositivo dentro de una arquitectura puede revisarse después de observar el funcionamiento real del sistema.
- Se comprobó que utilizar la Raspberry Pi 3 exclusivamente para monitorización duplicaría una función que ya proporciona la Raspberry Pi 4 mediante LibreNMS.
- La redefinición de la Raspberry Pi 3 como estación de trabajo permite disponer de un equipo físico dedicado a las prácticas del curso.
- Se identificó la diferencia entre:
  - gateway;
  - dispositivo de administración;
  - estación de trabajo;
  - nodo de monitorización;
  - ruta de administración de contingencia.
- Las pruebas demostraron que una red puede mantener una vía de administración aunque su gateway principal deje de estar disponible, siempre que exista otro equipo con conectividad hacia ambos segmentos.
- Se identificó la necesidad de considerar la persistencia de las rutas estáticas después de reinicios.
- La investigación de LibreNMS permitió distinguir entre problemas de adquisición de datos y problemas de presentación de los datos.
- La utilización de un dashboard personalizado permite construir una vista de observabilidad adaptada a las necesidades del laboratorio.

### Pendientes

1. Hacer persistentes las rutas estáticas recuperadas temporalmente en:
   - Raspberry Pi 4:
     - `192.168.88.0/24 via 192.168.100.2`
   - Raspberry Pi 3:
     - `192.168.100.0/30 via 192.168.88.1`
2. Continuar el diseño y organización del dashboard `Lab` de LibreNMS.
3. Completar el inventario de NetBox.
4. Corregir el nombre de la interfaz registrada inicialmente como `100BASE-TX` para que corresponda con `ether1`.
5. Incorporar progresivamente en NetBox:
   - interfaces;
   - direcciones IP;
   - IPAM;
   - VLAN;
   - conexiones físicas.
6. Continuar el diagnóstico del Arduino Yún.
7. Incorporar progresivamente nuevos elementos del laboratorio a LibreNMS y NetBox.
8. Incorporar posteriormente Ansible/AWX para automatización.
9. Mantener el posible gateway de contingencia de la Raspberry Pi 3 como práctica futura, sin implementarlo todavía.
10. Continuar documentando la evolución del laboratorio en el repositorio `gestor-redes-laboratorio`.

### Estado general

Al finalizar el 28/09/2026, la red física del laboratorio dispone de una arquitectura funcional con:

```text
Starlink
   │
   ▼
Raspberry Pi 4
Gateway + Administración
   │
   ▼
MikroTik
Router LAN
   │
   ├── Raspberry Pi 3
   │   Estación de trabajo / prácticas
   │
   ├── Arduino Yún
   │   Nodo de experimentación
   │
   └── futuros nodos
```

Sobre esta infraestructura se encuentran operativos:

```text
LibreNMS → monitorización
NetBox   → inventario y documentación
```

y queda prevista:

```text
Ansible/AWX → automatización
```

La Raspberry Pi 3 proporciona además una ruta de administración de contingencia hacia el MikroTik mediante su conectividad simultánea con la red Starlink y la LAN del laboratorio.

La arquitectura de failover automático todavía no está implementada y permanece como práctica futura.
```
---

## 2026-10-01 — Acceso remoto seguro al MikroTik mediante Tailscale

### Objetivo

Habilitar la administración remota del MikroTik hEX lite desde el móvil fuera de la red doméstica, reutilizando la infraestructura Tailscale ya existente y sin exponer puertos de administración directamente a Internet.

### Arquitectura utilizada

La Raspberry Pi 4 continúa actuando como gateway y nodo de administración del laboratorio físico.

Ruta de acceso remoto:

```text
Poco X7 Pro
→ Tailscale
→ Raspberry Pi 4
→ enlace 192.168.100.0/30
→ MikroTik hEX lite
```

Direcciones relevantes:

- Raspberry Pi 4 / Tailscale: `100.90.39.30`
- Raspberry Pi 4 / `eth0`: `192.168.100.1/30`
- MikroTik / `ether1`: `192.168.100.2`
- WinBox: TCP `8291`

### Configuración de Tailscale

Se configuró la Raspberry Pi 4 como **subnet router** para anunciar la red de tránsito entre Raspberry Pi y MikroTik:

```text
192.168.100.0/30
```

La ruta fue posteriormente aprobada desde la consola de administración de Tailscale.

Se verificó:

- `net.ipv4.ip_forward = 1`
- funcionamiento de la cadena `ts-forward`
- funcionamiento de `ts-postrouting`
- aplicación de MASQUERADE/SNAT al tráfico procedente de Tailscale

De esta forma, una conexión iniciada desde un dispositivo autorizado de la tailnet hacia `192.168.100.2` puede atravesar la Raspberry Pi 4 y alcanzar el MikroTik.

### Diagnóstico del acceso WinBox

Inicialmente, MikroTik Pro desde el móvil no conseguía conectarse a:

```text
192.168.100.2
```

Mediante `tcpdump` en `eth0` de la Raspberry Pi 4 se comprobó que los paquetes TCP SYN procedentes del móvil atravesaban correctamente Tailscale y llegaban hasta:

```text
192.168.100.2:8291
```

Sin embargo, el MikroTik no respondía.

También se comprobó directamente desde la Raspberry Pi 4:

```bash
nc -vz -w 3 192.168.100.2 8291
```

El intento expiraba por timeout.

Esto permitió descartar como origen del problema:

- Tailscale.
- El Poco X7 Pro.
- La conexión externa utilizada por el móvil.
- El routing de la Raspberry Pi 4.
- El enlace Ethernet Raspberry Pi 4 ↔ MikroTik.

### Causa identificada

El servicio WinBox estaba correctamente habilitado en RouterOS en TCP `8291`.

El problema estaba en el firewall `INPUT` del MikroTik.

Existían reglas específicas que permitían desde la Raspberry Pi 4:

- WebFig — TCP `80`.
- SSH — TCP `22`.
- SNMP — UDP `161`.

Pero no existía una autorización equivalente para WinBox.

La regla general:

```text
defconf: drop all not coming from LAN
```

descartaba finalmente las conexiones TCP `8291` recibidas por `ether1`.

### Corrección aplicada

Se añadió una regla específica de firewall antes del `DROP` general:

```text
ALLOW WinBox from Raspberry
```

Características:

- `chain`: `input`
- `action`: `accept`
- `protocol`: TCP
- `source`: `192.168.100.1`
- `interface`: `ether1`
- `destination port`: `8291`

No se abrió WinBox de forma general ni se creó ningún port forwarding desde Internet.

Tras aplicar la regla se verificó desde la Raspberry Pi 4:

```text
Connection to 192.168.100.2 8291 port [tcp/*] succeeded!
```

### Verificación remota

Con el Poco X7 Pro conectado mediante **datos móviles y Tailscale** se consiguió iniciar sesión correctamente en:

```text
admin@192.168.100.2
```

desde la aplicación MikroTik Pro.

Desde el móvil quedaron accesibles las funciones administrativas de RouterOS, incluyendo interfaces, IP, routing, firewall, archivos y demás apartados de configuración.

Por tanto, queda operativo el acceso:

```text
Internet
   │
   ▼
Tailscale
   │
   ▼
Raspberry Pi 4
Subnet Router
   │
   ▼
MikroTik
192.168.100.2
```

sin exposición directa del puerto WinBox a Internet.

### Verificación de la salida a Internet del laboratorio

También se realizó un `traceroute` desde el entorno del MikroTik hasta:

```text
8.8.8.8
```

Ruta observada:

1. `192.168.100.1` — Raspberry Pi 4.
2. `192.168.1.1` — gateway Starlink.
3. `100.64.0.1` — infraestructura/CGNAT del operador.
4. Salto intermedio sin respuesta ICMP.
5. a 9. Infraestructura pública de tránsito.
10. `8.8.8.8` — Google DNS.

El destino respondió con `0 %` de pérdida.

Esta prueba confirma experimentalmente la ruta de salida del laboratorio:

```text
MikroTik
→ Raspberry Pi 4
→ Starlink
→ CGNAT
→ Internet
```

### Estado final

- Acceso remoto mediante Tailscale: **OPERATIVO**.
- Raspberry Pi 4 como subnet router para `192.168.100.0/30`: **OPERATIVO**.
- WinBox remoto mediante MikroTik Pro: **OPERATIVO**.
- TCP `8291` accesible desde la Raspberry Pi 4 por `ether1`: **VERIFICADO**.
- Port forwarding desde Internet: **NO UTILIZADO**.
- Salida a Internet del MikroTik a través de Raspberry Pi 4/Starlink: **VERIFICADA**.
- RouterOS instalado: `7.1.2`.
- Actualización de RouterOS: **PENDIENTE**, a tratar como operación independiente con backup y comprobaciones previas.

### Acceso directo al MikroTik desde Lenovo L13 mediante Tailscale

Se eliminó la necesidad de utilizar la ruta indirecta de administración:

```text
Lenovo L13
→ NoMachine
→ Raspberry Pi 3
→ WebFig
→ MikroTik
```

Se configuró el Lenovo ThinkPad L13 para utilizar las rutas de subred anunciadas por Tailscale:

```bash
sudo tailscale set --accept-routes=true
```

#### Situación anterior

Antes del cambio, el Lenovo L13 no podía alcanzar la interfaz del MikroTik:

- Destino: `192.168.100.2`
- Resultado: `100 %` de pérdida ICMP.
- Tailscale estaba operativo, pero `RouteAll` aparecía como `false`.

#### Verificación después del cambio

Después de habilitar la aceptación de rutas de subred:

- `192.168.100.2` responde correctamente desde el Lenovo L13.
- `3/3` paquetes ICMP recibidos.
- `0 %` de pérdida.
- Latencia media aproximada: `6,5 ms`.

Se verificó posteriormente el acceso directo a WebFig desde Firefox en el Lenovo:

```text
http://192.168.100.2
```

La nueva ruta de administración queda:

```text
Lenovo L13
    │
    ▼
Tailscale
    │
    ▼
Raspberry Pi 4
Subnet Router
192.168.100.0/30
    │
    ▼
MikroTik
192.168.100.2
```

#### Resultado

- WebFig accesible directamente desde el Lenovo L13.
- Raspberry Pi 3 eliminada de la ruta habitual de administración del MikroTik desde el Lenovo.
- NoMachine ya no es necesario para este acceso.
- No se han abierto puertos del MikroTik directamente hacia Internet.
- Se reutiliza la infraestructura Tailscale existente.
- La Raspberry Pi 4 mantiene su función de subnet router para `192.168.100.0/30`.
- El acceso continúa limitado por las reglas específicas existentes en el firewall del MikroTik.

### Accesos remotos directos verificados

Quedan comprobadas dos rutas de administración directa del MikroTik mediante Tailscale:

| Dispositivo | Herramienta | Ruta | Estado |
|---|---|---|---|
| Poco X7 Pro | MikroTik Pro / WinBox | Poco → Tailscale → RPi4 → MikroTik | **OPERATIVO** |
| Lenovo L13 | Firefox / WebFig | Lenovo → Tailscale → RPi4 → MikroTik | **OPERATIVO** |

En ambos casos la Raspberry Pi 4 actúa como subnet router y proporciona acceso a la red de tránsito `192.168.100.0/30` sin publicar los servicios administrativos del MikroTik directamente en Internet.