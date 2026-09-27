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