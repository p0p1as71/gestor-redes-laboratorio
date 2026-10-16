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
```

- Desde la Raspberry Pi 3 se mantiene el acceso SSH al MikroTik a través de la LAN 192.168.88.0/24.
- Esta ruta proporciona una vía alternativa de administración y diagnóstico en caso de indisponibilidad de la Raspberry Pi 4.
- La ruta puede utilizarse desde equipos que tengan acceso a la red de Starlink, así como mediante un equipo accesible remotamente que disponga de conectividad hacia dicha red.
- La existencia de esta ruta no constituye un sistema de alta disponibilidad ni un failover automático.
- Se considera una ruta de administración de contingencia.
### Aprendizaje arquitectónico
- Las pruebas permitieron identificar que la disponibilidad del gateway principal y la disponibilidad de una ruta de administración no son necesariamente el mismo problema.
- La Raspberry Pi 4 concentra actualmente el gateway y la administración principal de la infraestructura.
- La Raspberry Pi 3 proporciona una segunda vía física de acceso al laboratorio gracias a su conectividad simultánea con Starlink y el MikroTik.
- Esta experiencia permitió identificar la importancia de diseñar también caminos de administración y recuperación ante fallos, además de la conectividad normal de producción.
### Gateway de contingencia — diseño futuro
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

---

## 2026-10-02 → 2026-10-03 — Ampliación física, Omada Controller, routing y corrección de los ESP32-S3

### Ampliación de la infraestructura física

Se amplió la red física del laboratorio incorporando un switch gestionable PoE, un punto de acceso inalámbrico y tres microcontroladores Ethernet.

Dispositivos incorporados:

| Dispositivo | Modelo | Dirección IP | Función |
|---|---|---|---|
| Switch | TP-Link Omada SG2210P | `192.168.88.251` | Switching gestionable y PoE |
| Punto de acceso | TP-Link Omada EAP225 | `192.168.88.250` | Acceso Wi-Fi del laboratorio |
| ESP32-01 | Waveshare ESP32-S3-POE-ETH | `192.168.88.245` | Nodo Ethernet de prácticas |
| ESP32-02 | Waveshare ESP32-S3-POE-ETH | `192.168.88.246` | Nodo Ethernet de prácticas |
| ESP32-03 | Waveshare ESP32-S3-POE-ETH | `192.168.88.247` | Nodo Ethernet de prácticas |

El SG2210P se conectó al MikroTik como switch principal de la LAN del laboratorio.

El EAP225 quedó conectado al SG2210P mediante Ethernet, con alimentación PoE y enlace negociado a 1 Gbps.

Direcciones MAC de los equipos Omada:

- SG2210P: `A8:29:48:FF:C9:68`
- EAP225: `C0:3A:55:A9:6B:C2`

### Instalación de Omada Software Controller

Se instaló y puso en funcionamiento Omada Software Controller en el Lenovo ThinkPad L13 Gen 3.

Componentes instalados o verificados:

- OpenJDK 17.
- MongoDB 8.0.32.
- `jsvc`.
- Omada Network Application 6.3.0.45.

Puertos del controlador:

- HTTP: `8088/TCP`.
- HTTPS: `8043/TCP`.

Se verificó el funcionamiento del servicio mediante `tpeap status` y el acceso HTTPS a la interfaz de administración.

El Lenovo quedó establecido como equipo anfitrión del controlador Omada.

### Adopción del SG2210P y EAP225

Se adoptaron correctamente los dispositivos:

- SG2210P: `192.168.88.251`.
- EAP225: `192.168.88.250`.

Durante las pruebas se observó que ambos dispositivos perdían comunicación con el controlador cuando el Lenovo dejaba de utilizar la dirección local `192.168.88.249`.

Los registros de Omada mostraban eventos:

- `Heartbeat Missed`.
- `Disconnected`.

La adopción inicial se había completado correctamente.

El problema estaba relacionado con la continuidad del canal de gestión entre los dispositivos Omada y el controlador al cambiar el Lenovo de red.

### Descubrimiento del controlador mediante DHCP Option 138

Para mantener una dirección de referencia estable se configuró en el MikroTik la opción DHCP 138.

Dirección anunciada del controlador:

`100.116.135.126`

Esta dirección corresponde a la interfaz Tailscale del Lenovo.

La opción DHCP se aplicó a la red:

`192.168.88.0/24`

Tras aplicar la configuración, SG2210P y EAP225 recuperaron la comunicación con Omada Controller.

Se verificaron conexiones TCP establecidas hacia el controlador mediante el puerto:

`29814/TCP`

**Resultado:** el controlador puede seguir siendo localizado mediante su dirección Tailscale cuando el Lenovo cambia entre la WLAN del laboratorio y la red Starlink, siempre que exista conectividad hacia esa dirección.

### Configuración de la WLAN Lab-Redes

Se creó y configuró desde Omada Controller la red inalámbrica:

`Lab-Redes`

Configuración:

- Banda de 2,4 GHz habilitada.
- Banda de 5 GHz habilitada.
- Seguridad WPA2-PSK / AES.
- Difusión del SSID habilitada.
- VLAN por defecto.
- Gestión centralizada mediante Omada Controller.

El EAP225 quedó administrado desde Omada.

También se verificó desde las herramientas del EAP225 la conectividad hacia la dirección Tailscale del Lenovo:

`100.116.135.126`

### Acceso local y remoto al controlador Omada

Se comprobaron dos vías de acceso a Omada Controller.

**Acceso local desde Lab-Redes:**

```text
https://192.168.88.249:8043
```

**Acceso mediante Tailscale:**

```text
https://100.116.135.126:8043
```

Se realizaron pruebas desde un teléfono POCO.

Durante el diagnóstico se observó que la configuración de VPN/Tailscale del teléfono podía interferir con el acceso directo al Lenovo cuando ambos dispositivos estaban conectados a la misma LAN.

Se mantuvieron diferenciados:

- Acceso directo mediante la dirección local del Lenovo.
- Acceso mediante su dirección Tailscale.

No fue necesario publicar el controlador directamente en Internet.

### Diagnóstico del routing Lenovo / Tailscale

Se detectó un conflicto de rutas al conectar el Lenovo directamente a la WLAN `Lab-Redes`.

Tailscale instalaba en la tabla de routing 52 una ruta hacia:

```text
192.168.88.0/24 dev tailscale0
```

Esto provocaba que determinados paquetes destinados a dispositivos de la LAN del laboratorio intentaran utilizar Tailscale, incluso cuando el Lenovo tenía conectividad directa mediante Wi-Fi.

La situación requería distinguir dos escenarios:

1. Lenovo conectado directamente a `Lab-Redes`.
2. Lenovo conectado a Starlink y accediendo al laboratorio mediante Tailscale.

### Corrección de prioridades de routing

Se validó inicialmente una regla temporal de política de routing:

```text
priority 2500 to 192.168.88.0/24 lookup main
```

La regla permite consultar prioritariamente la tabla principal para los destinos pertenecientes a la LAN del laboratorio.

Posteriormente se hizo persistente mediante su asociación al perfil NetworkManager:

`Lab-Redes`

Antes de modificar el perfil se creó una copia textual de su configuración.

**Comportamiento verificado:**

Lenovo conectado a `Lab-Redes`:

- NetworkManager instala automáticamente la regla de prioridad 2500.
- El tráfico hacia `192.168.88.0/24` utiliza la conexión Wi-Fi local.

Lenovo conectado a Starlink:

- La regla asociada a `Lab-Redes` desaparece automáticamente.
- La red `192.168.88.0/24` vuelve a alcanzarse mediante Tailscale.

Se verificó desde Starlink la conectividad con el EAP225:

`192.168.88.250`

**Resultado:** la selección de ruta se adapta automáticamente a la red utilizada por el Lenovo, sin necesidad de modificar manualmente las rutas en cada cambio de conexión.

---

### Incorporación de tres Waveshare ESP32-S3-POE-ETH

Se conectaron tres módulos Waveshare ESP32-S3-POE-ETH al switch SG2210P.

Los tres dispositivos establecieron enlaces físicos Ethernet a:

- 100 Mbps.
- Full Duplex.

Se definió el siguiente direccionamiento:

| Dispositivo | Dirección IP prevista |
|---|---|
| ESP32-01 | `192.168.88.245` |
| ESP32-02 | `192.168.88.246` |
| ESP32-03 | `192.168.88.247` |

Inicialmente solo se había creado la reserva DHCP correspondiente a ESP32-01.

### Detección del conflicto de direcciones MAC

Al conectar los tres dispositivos se comprobó que todos utilizaban la misma dirección MAC Ethernet:

```text
02:00:00:12:34:56
```

El problema impedía identificar correctamente los tres dispositivos como clientes Ethernet independientes.

La tabla MAC del SG2210P mostró que esa misma dirección aparecía alternativamente en los puertos utilizados por los ESP32.

Puertos implicados:

- `Gi1/0/3`.
- `Gi1/0/4`.
- `Gi1/0/5`.

La duplicación provocaba que el switch desplazara la asociación de la MAC entre los distintos puertos según el tráfico recibido.

En MikroTik, la dirección:

`192.168.88.245`

estaba asociada a la MAC duplicada:

`02:00:00:12:34:56`

Durante esta fase se decidió no crear todavía las reservas DHCP de ESP32-02 y ESP32-03.

### Diagnóstico mediante CLI del SG2210P

Se utilizó el terminal CLI del SG2210P desde Omada Controller.

Prompt EXEC:

```text
A8-29-48-FF-C9-68>
```

Modo Privileged EXEC:

```text
A8-29-48-FF-C9-68#
```

Se inspeccionaron los enlaces físicos y las entradas de la tabla MAC.

Se confirmó:

- Existencia de tres enlaces Ethernet activos.
- Negociación a 100 Mbps Full Duplex.
- Aprendizaje de la misma MAC en diferentes puertos.
- Imposibilidad de identificar correctamente los tres dispositivos mediante esa MAC compartida.

También se verificó desde MikroTik que `192.168.88.245` respondía a ICMP.

Un escaneo TCP con Nmap mostró el host activo, sin servicios TCP abiertos entre los 1000 puertos habituales examinados.

### Identificación física de los ESP32-S3 mediante USB

Se conectaron individualmente los tres ESP32 al Lenovo mediante USB.

Linux identificó el dispositivo:

```text
303a:1001 Espressif USB JTAG/serial debug unit
```

Puerto serie utilizado:

```text
/dev/ttyACM0
```

Se utilizó `esptool` para consultar la identidad grabada en cada microcontrolador.

Los tres dispositivos fueron identificados como:

- ESP32-S3 QFN56.
- Revisión 0.2.
- Wi-Fi.
- BLE.
- 8 MB de PSRAM.

MAC base de fábrica:

| Dispositivo | MAC base de fábrica |
|---|---|
| ESP32-01 | `28:84:85:54:C6:A0` |
| ESP32-02 | `28:84:85:53:12:F4` |
| ESP32-03 | `A4:CB:8F:F8:A6:3C` |

Esto confirmó que los tres microcontroladores tenían identidades físicas diferentes.

La MAC Ethernet duplicada no correspondía a la MAC base de fábrica de ninguno de ellos.

Durante estas pruebas, `esptool 4.7.0` presentó posteriormente el error:

```text
FileNotFoundError: stub_flasher_32s3.json
```

El error se produjo después de obtener los datos de identificación necesarios y no impidió completar esta fase del diagnóstico.

### Investigación del firmware original

Se analizó la aplicación existente en la memoria flash de los ESP32.

Se localizó explícitamente la dirección:

```text
02:00:00:12:34:56
```

El firmware utilizaba el controlador Ethernet W5500 y contenía esa dirección MAC configurada en la aplicación.

**Causa identificada:** la dirección MAC duplicada procedía del firmware utilizado, no de una identidad física duplicada entre los microcontroladores.

### Desarrollo del firmware Ethernet corregido

Se utilizó como base el ejemplo oficial de Waveshare para ESP32-S3-POE-ETH.

Librería Ethernet:

`Ethernet_Generic 2.8.1`

Se creó el sketch:

```text
~/Arduino/ESP32_ETH_UNIQUE/ESP32_ETH_UNIQUE.ino
```

El nuevo firmware obtiene una dirección MAC Ethernet derivada de la identidad propia del ESP32 mediante:

```cpp
esp_read_mac(mac, ESP_MAC_ETH);
```

La MAC obtenida se proporciona al controlador W5500 durante la inicialización Ethernet.

También se eliminó la dirección IP estática de respaldo incluida en el ejemplo utilizado.

El firmware quedó configurado para obtener el direccionamiento IPv4 exclusivamente mediante DHCP.

Herramientas utilizadas:

- Arduino CLI.
- ESP32 Arduino Core 2.0.12.
- Librería Ethernet_Generic 2.8.1.

Los tres ESP32 fueron compilados y reprogramados correctamente.

### Identidades Ethernet definitivas

Después de reprogramar los dispositivos se verificaron las siguientes identidades:

| Dispositivo | Puerto SG2210P | MAC Ethernet definitiva | IP reservada |
|---|---|---|---|
| ESP32-01 | `Gi1/0/3` | `2A:84:85:54:C6:A1` | `192.168.88.245` |
| ESP32-02 | `Gi1/0/5` | `2A:84:85:53:12:F5` | `192.168.88.246` |
| ESP32-03 | `Gi1/0/4` | `A6:CB:8F:F8:A6:3D` | `192.168.88.247` |

Los tres dispositivos mantienen enlaces Ethernet a 100 Mbps Full Duplex.

### Corrección de las reservas DHCP en MikroTik

Se eliminó la reserva antigua de ESP32-01 asociada a:

```text
02:00:00:12:34:56
```

Se identificaron las nuevas concesiones DHCP y se convirtieron en reservas estáticas.

Direccionamiento definitivo:

- ESP32-01 → `192.168.88.245`.
- ESP32-02 → `192.168.88.246`.
- ESP32-03 → `192.168.88.247`.

Se verificó en MikroTik:

- Tres reservas DHCP independientes.
- Tres direcciones MAC Ethernet diferentes.
- Estado `bound` en las tres reservas.
- Coincidencia entre `active-address` y la dirección IP reservada.

### Verificación de la tabla MAC del SG2210P

Se comprobó la asociación física de cada dispositivo con su puerto correspondiente:

```text
Gi1/0/3 → ESP32-01 → 2A:84:85:54:C6:A1
Gi1/0/4 → ESP32-03 → A6:CB:8F:F8:A6:3D
Gi1/0/5 → ESP32-02 → 2A:84:85:53:12:F5
```

En ESP32-03 fue necesario realizar un reinicio para que el dispositivo volviera a generar tráfico Ethernet.

Posteriormente, el SG2210P aprendió correctamente:

```text
A6:CB:8F:F8:A6:3D → Gi1/0/4
```

La tabla MAC quedó coherente con la identificación física de los tres dispositivos.

### Resultado de la corrección

El conflicto de identidad Ethernet quedó resuelto.

Se consiguió:

- Identificar individualmente los tres ESP32-S3.
- Determinar la causa de la MAC duplicada.
- Corregir el firmware.
- Obtener tres MAC Ethernet diferentes.
- Eliminar la dependencia de `02:00:00:12:34:56`.
- Configurar DHCP como único mecanismo de obtención de dirección IPv4.
- Crear tres reservas DHCP permanentes.
- Verificar las tres concesiones en estado `bound`.
- Asociar cada ESP32 a su puerto físico del SG2210P.

---

### Estado consolidado al 03/10/2026

| Componente | Estado |
|---|---|
| MikroTik RB750r2 | Operativo como router y servidor DHCP |
| TP-Link SG2210P | Operativo y adoptado en Omada |
| TP-Link EAP225 | Operativo y adoptado en Omada |
| WLAN `Lab-Redes` | Operativa |
| Omada Controller 6.3.0.45 | Operativo en Lenovo |
| Descubrimiento mediante DHCP Option 138 | Configurado y verificado |
| Acceso a Omada mediante Tailscale | Verificado |
| Routing automático Lenovo / Lab-Redes / Tailscale | Verificado |
| ESP32-01 | MAC única y reserva DHCP `bound` |
| ESP32-02 | MAC única y reserva DHCP `bound` |
| ESP32-03 | MAC única y reserva DHCP `bound` |
| Conflicto de MAC duplicada | Resuelto |

### Aprendizajes técnicos

1. Un enlace Ethernet activo no garantiza que un dispositivo tenga una identidad de red correcta.
2. La tabla MAC de un switch gestionable permite relacionar dispositivos y puertos físicos.
3. Una MAC duplicada puede provocar cambios continuos en el aprendizaje del switch y conflictos de identificación DHCP.
4. La MAC base de fábrica de un microcontrolador no tiene por qué coincidir con la MAC utilizada por una interfaz Ethernet externa.
5. El firmware de un dispositivo embebido puede determinar la identidad Ethernet presentada a la red.
6. Las reservas DHCP deben basarse en identidades de cliente correctas y verificadas.
7. La adopción de un dispositivo en un controlador no garantiza la continuidad de su comunicación de gestión.
8. DHCP Option 138 permite anunciar información de descubrimiento del controlador a dispositivos compatibles.
9. Las políticas de routing permiten priorizar rutas distintas según el contexto de conexión.
10. Tailscale puede proporcionar una dirección de gestión estable aunque el equipo controlador cambie de red local.

### Próximos pasos

- Integrar progresivamente SG2210P, EAP225 y ESP32 en LibreNMS y NetBox.
- Continuar el diagnóstico de identificación de clientes en Omada.
- Definir funciones prácticas individuales para ESP32-01, ESP32-02 y ESP32-03.
- Documentar los puertos físicos y conexiones definitivas en NetBox.
- Continuar la construcción del dashboard general del laboratorio.
- Mantener el firmware corregido de los ESP32 como referencia para futuras pruebas.

---

## 2026-10-03 — Dashboard web de topología del laboratorio

### Objetivo

Crear un dashboard web propio para representar visualmente la infraestructura del laboratorio de redes.

El objetivo es disponer de una vista general de los dispositivos físicos, sus conexiones y su función dentro de la arquitectura, complementando las herramientas de administración existentes.

Se mantiene la separación funcional:

- LibreNMS: monitorización, métricas y alertas.
- NetBox: inventario, direccionamiento IP y documentación.
- Omada Controller: administración del switch SG2210P y del punto de acceso EAP225.
- Dashboard web: visualización de la topología del laboratorio.

### Desarrollo del dashboard HTML

Se preparó un dashboard independiente en formato HTML.

Archivo de trabajo utilizado en el Lenovo:

`/home/ricardo/Descargas/lab-tv.html`

Se trabajó en la representación gráfica de la infraestructura física, incluyendo los siguientes elementos:

- Starlink.
- Raspberry Pi 4.
- MikroTik RB750r2.
- TP-Link SG2210P.
- TP-Link EAP225.
- Raspberry Pi 3.
- Arduino Yún.
- Tres ESP32-S3 Ethernet.
- Lenovo ThinkPad L13 Gen 3.

Se plantearon dos representaciones complementarias:

1. Topología física, centrada en equipos y conexiones.
2. Topología lógica, centrada en redes, direccionamiento y relaciones entre componentes.

### Publicación del archivo en Raspberry Pi 4

Se utilizó SCP desde el Lenovo para copiar el dashboard a la Raspberry Pi 4.

Comando ejecutado:

```bash
scp '/home/ricardo/Descargas/lab-tv.html' popi@100.90.39.30:/home/popi/lab-dashboard/index.html
```

La transferencia finalizó correctamente.

Resultado observado:

```text
lab-tv.html  100%  33KB
```

Archivo de destino:

```text
/home/popi/lab-dashboard/index.html
```

El acceso a la Raspberry Pi se realizó mediante su dirección Tailscale:

`100.90.39.30`

La transferencia no requirió publicar servicios adicionales directamente en Internet.

### Arquitectura del dashboard

La solución se basa en un documento HTML alojado en la Raspberry Pi 4.

Arquitectura prevista:

```text
Lenovo ThinkPad L13
        │
        │ Edición del HTML
        ▼
lab-tv.html
        │
        │ SCP / Tailscale
        ▼
Raspberry Pi 4
        │
        ▼
/home/popi/lab-dashboard/index.html
        │
        ▼
Servidor web local
        │
        ▼
Navegador del cliente
```

El dashboard es una herramienta independiente de las interfaces web de LibreNMS, NetBox y Omada.

### Servicio web del dashboard

Se planteó utilizar un servicio systemd denominado:

`lab-dashboard.service`

Puerto previsto:

`8085/TCP`

**Estado de verificación:**

- Archivo HTML preparado: CONFIRMADO.
- Transferencia mediante SCP: CONFIRMADA.
- Archivo copiado a la ruta de destino: CONFIRMADO por la transferencia.
- Servicio systemd habilitado: PENDIENTE DE VERIFICACIÓN.
- Arranque automático después de reinicio: PENDIENTE DE VERIFICACIÓN.
- Acceso HTTP desde otros dispositivos: PENDIENTE DE VERIFICACIÓN.

No se considera completada la publicación permanente hasta comprobar el funcionamiento del servidor web.

### Representación física y lógica

El dashboard se diseñó para facilitar la comprensión de dos aspectos diferentes de la infraestructura.

**Topología física**

Representación de los equipos reales y sus conexiones:

```text
STARLINK
   │
   ▼
RASPBERRY PI 4
   │
   ▼
MIKROTIK
   │
   ▼
SG2210P
   │
   ├── EAP225
   ├── ESP32-01
   ├── ESP32-02
   └── ESP32-03
```

Este esquema es una representación simplificada del segmento principal. No sustituye el inventario completo de puertos y enlaces físicos.

**Topología lógica**

Representación de las redes y funciones:

- Red doméstica Starlink: `192.168.1.0/24`.
- Red de tránsito Raspberry Pi 4 ↔ MikroTik: `192.168.100.0/30`.
- LAN del laboratorio: `192.168.88.0/24`.
- Red privada de administración Tailscale.
- Funciones de gateway, routing, switching y acceso inalámbrico.

### Resultado

Se dispone de un archivo HTML del dashboard transferido a la Raspberry Pi 4.

El trabajo establece la base para una interfaz visual propia del laboratorio, independiente de las plataformas de monitorización e inventario.

### Pendientes

1. Verificar si `lab-dashboard.service` existe y está habilitado.
2. Comprobar el acceso HTTP al dashboard desde el Lenovo.
3. Verificar la recuperación automática después de reiniciar la Raspberry Pi.
4. Revisar la representación física tras incorporar el SG2210P y los tres ESP32.
5. Mantener sincronizada la representación lógica con las configuraciones reales de MikroTik, Omada y Tailscale.
6. Diferenciar visualmente dispositivos, redes, enlaces y funciones.
7. Estudiar una futura integración de datos de LibreNMS o NetBox sin modificar los servicios existentes.

### Aprendizajes

- Una topología física representa dispositivos, puertos y conexiones reales.
- Una topología lógica representa redes, direccionamiento, rutas y funciones.
- Una herramienta de visualización no sustituye a un sistema de monitorización.
- La publicación de un archivo HTML y la puesta en marcha de un servicio web son operaciones distintas.
- El acceso mediante Tailscale permite administrar y transferir archivos sin publicar servicios directamente en Internet.

---

## 2026-10-05 → 2026-10-07 — Laboratorio virtual MEDION, KVM/QEMU y OPNsense

### Objetivo

Ampliar el laboratorio de redes mediante una plataforma de virtualización independiente, utilizando el equipo MEDION como estación de trabajo para prácticas de sistemas, routing, firewall y redes virtuales.

La arquitectura permite experimentar con routers, servidores y clientes virtuales sin modificar directamente la infraestructura física del laboratorio.

Se mantiene la separación entre:

- Laboratorio físico: Raspberry Pi, MikroTik, SG2210P, EAP225 y dispositivos Ethernet.
- Laboratorio virtual: MEDION, KVM/QEMU, libvirt y máquinas virtuales.
- Red doméstica: Starlink y dispositivos habituales.
- Servicios existentes: infraestructura de administración, monitorización y producción.

### Equipo anfitrión

Se utilizó el equipo:

`netlab-ws01`

Sistema operativo:

`Debian 13`

El MEDION queda destinado a funcionar como estación de trabajo del laboratorio virtual.

Su función es ejecutar máquinas virtuales y permitir prácticas de:

- Configuración de interfaces de red.
- Routing entre subredes.
- NAT.
- DHCP.
- DNS.
- Firewall.
- Administración de sistemas.
- Diagnóstico de conectividad.
- Segmentación y aislamiento de redes.

### Plataforma de virtualización

Se preparó la infraestructura de virtualización utilizando:

- KVM/QEMU.
- libvirt.
- Virt-Manager.
- `virsh`.

Se utilizó la conexión de administración:

```text
qemu:///system
```

La plataforma permite administrar las máquinas virtuales y las redes definidas en libvirt.

### Arquitectura de redes virtuales

Se trabajó con dos redes de libvirt:

| Red | Función | Características |
|---|---|---|
| `default` | Red virtual de salida | NAT |
| `lab-isolated` | Red interna del laboratorio | Aislada |

La red `default` proporciona una red virtual con NAT gestionada por libvirt.

La red `lab-isolated` se utiliza como segmento interno para las prácticas del laboratorio.

Se mantiene la distinción entre una red que proporciona conectividad de salida y una red destinada al tráfico interno entre máquinas virtuales.

### Verificación de redes libvirt

Se consultó el estado de las redes mediante:

```bash
virsh -c qemu:///system net-list --all
```

Resultado verificado:

```text
 Nombre         Estado   Inicio automático   Persistente
----------------------------------------------------------
 default        activo   si                  si
 lab-isolated   activo   si                  si
```

Se confirmó que ambas redes estaban:

- Activas.
- Definidas de forma persistente.
- Configuradas para iniciarse automáticamente.

### Configuración de autoinicio de lab-isolated

Se configuró el inicio automático de la red virtual aislada:

```bash
sudo virsh -c qemu:///system net-autostart lab-isolated
```

Resultado obtenido:

```text
La red lab-isolated ha sido marcada para iniciarse automáticamente
```

Posteriormente se verificó que la red aparecía con inicio automático habilitado.

Esto permite que la red virtual esté disponible después del arranque del anfitrión, sin necesidad de iniciarla manualmente.

### Máquina virtual OPNsense

Se creó la máquina virtual:

`opnsense-lab`

OPNsense se utiliza como plataforma de firewall y routing para el laboratorio virtual.

Su función prevista es administrar el tráfico entre:

- Una interfaz WAN virtual.
- Una interfaz LAN virtual aislada.
- Futuras máquinas cliente o servidor.

Se preparó una instalación de OPNsense sobre almacenamiento virtual.

Características documentadas:

- Disco virtual de 20 GiB.
- Sistema de archivos ZFS.
- Instalación mediante imagen ISO.
- Desmontaje de la ISO después de la instalación.

### Arranque de OPNsense

Se verificó la ejecución de la máquina virtual mediante:

```bash
virsh -c qemu:///system start opnsense-lab
```

El sistema devolvió:

```text
error: El dominio ya se encuentra activo
```

Este resultado confirma que, en el momento de la comprobación, la máquina virtual ya estaba arrancada.

No se consideró necesario iniciar una segunda instancia.

Posteriormente se continuó trabajando con las máquinas virtuales desde sus consolas.

### Topología virtual

La arquitectura utilizada se representa de forma simplificada:

```text
MEDION netlab-ws01
Debian 13
│
└── KVM/QEMU + libvirt
    │
    ├── Red default
    │   └── NAT / salida virtual
    │
    └── Red lab-isolated
        └── Segmento interno aislado

OPNsense VM
│
├── WAN
│   └── default
│
└── LAN
    └── lab-isolated
        │
        └── Futuras máquinas cliente
```

La máquina virtual OPNsense permite estudiar el comportamiento de un router/firewall entre redes virtuales.

La conexión de futuras máquinas a `lab-isolated` permitirá observar comunicaciones, configurar direccionamiento y aplicar reglas de firewall sin intervenir directamente en el MikroTik físico.

### Adaptador USB Ethernet

Durante la preparación del laboratorio se identificó un adaptador USB Ethernet basado en:

`Realtek RTL8153`

Identificador USB:

```text
0bda:8153
```

Interfaz Linux identificada:

```text
enx00e04c6831b0
```

Se estudió su posible utilización como interfaz de red adicional del MEDION.

La incorporación definitiva del adaptador a la arquitectura virtual, incluido cualquier posible passthrough, queda pendiente de verificación.

No se considera confirmada su asignación permanente a una máquina virtual.

### Funcionamiento del MEDION con la tapa cerrada

Se estableció como requisito operativo que el MEDION continúe funcionando cuando se cierre la tapa.

Comportamiento deseado:

- No suspender.
- No hibernar.
- No apagar.
- Mantener activas las máquinas virtuales.
- Mantener disponibles las redes virtuales.

La configuración y validación definitiva de este comportamiento quedan pendientes.

### Estado consolidado

| Componente | Estado |
|---|---|
| MEDION `netlab-ws01` | Operativo |
| Debian 13 | Instalado |
| KVM/QEMU | Preparado |
| libvirt | Operativo |
| Virt-Manager | Disponible |
| Red `default` | Activa, persistente y con autoinicio |
| Red `lab-isolated` | Activa, persistente y con autoinicio |
| Máquina virtual `opnsense-lab` | Creada y arrancada |
| OPNsense | Instalado |
| Disco virtual ZFS | Preparado |
| Adaptador USB Ethernet RTL8153 | Identificado |
| Passthrough del adaptador USB | Pendiente de verificación |
| Funcionamiento con tapa cerrada | Pendiente de verificación |
| Auditoría completa del aislamiento | Pendiente |

### Aprendizajes técnicos

1. KVM/QEMU proporciona virtualización de máquinas sobre un anfitrión Linux.
2. libvirt permite administrar máquinas, interfaces y redes virtuales.
3. Una red virtual puede configurarse para utilizar NAT o funcionar como segmento aislado.
4. El autoinicio de una red virtual es independiente del autoinicio de una máquina virtual.
5. OPNsense permite reproducir funciones de routing y firewall en un entorno virtual.
6. Una interfaz WAN virtual no implica necesariamente una conexión directa a una interfaz Ethernet física.
7. El aislamiento de una red virtual debe comprobarse mediante su configuración y pruebas reales de conectividad.
8. Un adaptador USB Ethernet puede ampliar las posibilidades de conexión del anfitrión, pero su detección no implica que esté asignado a una máquina virtual.
9. El comportamiento de suspensión del anfitrión puede afectar a la disponibilidad de todas sus máquinas virtuales.

### Próximos pasos

1. Auditar la configuración XML de las redes `default` y `lab-isolated`.
2. Verificar las interfaces virtuales asignadas a `opnsense-lab`.
3. Comprobar el direccionamiento de las interfaces WAN y LAN de OPNsense.
4. Validar mediante pruebas el aislamiento de `lab-isolated`.
5. Crear o completar una máquina cliente conectada a la LAN virtual.
6. Verificar comunicaciones entre el cliente y OPNsense.
7. Practicar DHCP, DNS, NAT, routing y reglas de firewall.
8. Evaluar la integración del adaptador USB Ethernet si existe una necesidad concreta.
9. Configurar y comprobar el comportamiento del MEDION al cerrar la tapa.
10. Documentar las configuraciones verificadas y conservar copias de seguridad antes de cambios importantes.

---

## 2026-10-07 → 2026-10-10 — Continuación del laboratorio, administración y planificación de prácticas

### Objetivo

Continuar la puesta en marcha del laboratorio físico y virtual, comprobar el funcionamiento de los componentes instalados y organizar las siguientes prácticas del curso de Gestor de Redes.

Se mantienen dos entornos diferenciados:

- Laboratorio físico: Raspberry Pi, MikroTik, SG2210P, EAP225, Arduino Yún y ESP32.
- Laboratorio virtual: MEDION `netlab-ws01`, KVM/QEMU, libvirt y OPNsense.

### Continuación de las pruebas del MEDION

Se continuó trabajando con el MEDION como anfitrión de máquinas virtuales.

Se confirmó mediante `virsh` que las redes virtuales:

- `default`
- `lab-isolated`

permanecían activas y configuradas para iniciarse automáticamente.

También se comprobó que la máquina virtual `opnsense-lab` ya estaba activa cuando se intentó iniciarla.

Durante la sesión se indicó que se habían iniciado dos máquinas y que se había accedido a sus respectivas consolas.

La identidad, configuración y estado final de la segunda máquina no quedan suficientemente acreditados en los registros disponibles para documentarlos como definitivos.

### Administración del laboratorio virtual

Se continuaron las comprobaciones desde las consolas de las máquinas virtuales.

Se mantiene como objetivo verificar:

- Interfaces de red asignadas a OPNsense.
- Correspondencia entre WAN y LAN.
- Direccionamiento IPv4.
- Servidor DHCP de la LAN virtual.
- Comunicación entre máquinas.
- Reglas de firewall.
- Aislamiento respecto a la red doméstica.

Estas comprobaciones no se consideran completadas hasta disponer de resultados verificables.

### Diagnóstico de clientes en Omada

Se continuó investigando la representación de clientes conectados al SG2210P y al EAP225.

Durante las comprobaciones aparecieron discrepancias entre los dispositivos esperados y los clientes mostrados en Omada.

También se revisaron exportaciones de información de clientes:

- Clientes conectados.
- Clientes desconectados.
- Clientes bloqueados.
- Historial de conexiones.
- Historial de autenticaciones de portal.

La existencia de estos archivos permite continuar el diagnóstico, pero no confirma por sí sola la causa de las discrepancias.

Se mantiene como referencia principal para identificar los ESP32 Ethernet la información verificada previamente:

- MAC Ethernet única.
- Puerto físico del SG2210P.
- Reserva DHCP del MikroTik.
- Dirección IPv4 asignada.

### Revisión de la conectividad del Lenovo

Se continuaron las comprobaciones de conectividad del Lenovo ThinkPad L13 Gen 3 con la infraestructura física.

Durante las pruebas se distinguieron las conexiones mediante:

- Ethernet.
- Adaptadores USB Ethernet.
- Wi-Fi del laboratorio.
- Tailscale.

Se mantiene como principio de diagnóstico comprobar la interfaz realmente utilizada y la ruta seleccionada antes de atribuir una incidencia a Omada, MikroTik o Tailscale.

No se documenta un cambio definitivo de topología del Lenovo sin una comprobación adicional.

### Organización de las prácticas diarias

Se definió una metodología de avance continuo para el curso de Gestor de Redes.

El objetivo es realizar diariamente una tarea que produzca una mejora, implementación o comprobación nueva en el laboratorio.

Ámbitos de trabajo:

- Infraestructura física.
- Infraestructura virtual.
- Routing.
- Switching.
- Direccionamiento IP.
- VLAN.
- DHCP.
- DNS.
- Firewall.
- NAT.
- Monitorización.
- Inventario.
- Automatización.
- Diagnóstico y documentación.

Se estableció como horario de presentación de las tareas:

`06:00`

Las tareas se preparan para su lectura por la mañana y ejecución práctica por la tarde.

Esta planificación no implica que todas las prácticas propuestas se hayan ejecutado.

### Metodología de ejecución

Se mantiene el procedimiento de trabajo del laboratorio:

1. Definir el objetivo técnico.
2. Explicar la arquitectura implicada.
3. Consultar el estado actual.
4. Realizar un único cambio controlado.
5. Verificar el resultado.
6. Documentar la evidencia.
7. Actualizar el CHANGELOG cuando corresponda.

Para la administración de los equipos Linux se mantiene la regla de ejecutar un solo comando cada vez, esperando su resultado antes de continuar.

### Estado documental al 10/10/2026

| Área | Situación |
|---|---|
| Laboratorio físico | Infraestructura ampliada y operativa según últimas comprobaciones documentadas |
| Omada | Controlador y dispositivos adoptados; diagnóstico de clientes pendiente |
| ESP32-S3 | Conflicto de MAC Ethernet resuelto |
| Dashboard HTML | Archivo transferido a Raspberry Pi 4; servicio web pendiente de verificar |
| MEDION | Anfitrión de virtualización operativo |
| Redes libvirt | `default` y `lab-isolated` activas, persistentes y con autoinicio |
| OPNsense | VM creada y arrancada |
| Segunda máquina virtual | Identidad y configuración pendientes de documentar |
| Aislamiento virtual | Auditoría completa pendiente |
| Prácticas diarias | Metodología y horario definidos |

### Próximos pasos

1. Completar la verificación de OPNsense y sus interfaces WAN/LAN.
2. Identificar y documentar la segunda máquina virtual del MEDION.
3. Validar mediante pruebas el aislamiento de `lab-isolated`.
4. Verificar el comportamiento del MEDION con la tapa cerrada.
5. Comprobar el estado del servicio web del dashboard HTML.
6. Continuar la investigación de clientes en Omada.
7. Actualizar NetBox con los dispositivos, interfaces y conexiones incorporados.
8. Definir funciones de diagnóstico para los tres ESP32.
9. Registrar las prácticas realizadas y sus resultados verificables.
10. Mantener actualizado el inventario y la documentación de la arquitectura física y virtual.

---

## 2026-10-10 — Consolidación de arquitectura y plan de validación del laboratorio

### Objetivo

Consolidar la documentación de los componentes físicos y virtuales del laboratorio de Gestor de Redes.

Identificar qué partes de la infraestructura están verificadas, cuáles necesitan comprobaciones adicionales y cómo deben documentarse las futuras modificaciones.

Esta entrada es una revisión documental. No representa una nueva instalación ni una modificación de configuración.

### Arquitectura física de referencia

```text
                    STARLINK
                       |
                Red doméstica
                 192.168.1.0/24
                       |
                 RASPBERRY PI 4
                       |
                Red de tránsito
                192.168.100.0/30
                       |
                 MIKROTIK
                192.168.88.1
                       |
                LAN LABORATORIO
                192.168.88.0/24
                       |
          +------------+------------+
          |                         |
       SG2210P                  Otros nodos
          |
    +-----+-----+-----+-----+
    |     |     |     |
  EAP225 ESP01 ESP02 ESP03
```

El esquema representa las relaciones principales. No constituye un inventario completo de conexiones físicas.

### Servicios de administración

| Herramienta | Función | Equipo |
|---|---|---|
| LibreNMS | Monitorización y métricas | Raspberry Pi 4 |
| NetBox | Inventario, IPAM y documentación | Raspberry Pi 4 |
| Omada Controller | Gestión de switch y punto de acceso | Lenovo L13 |
| Tailscale | Acceso administrativo remoto | Equipos configurados |
| Dashboard HTML | Visualización de topología | Raspberry Pi 4, archivo transferido |

El funcionamiento permanente del servidor web del dashboard HTML sigue pendiente de verificación.

### Arquitectura virtual de referencia

```text
MEDION netlab-ws01
|
+-- Debian 13
    |
    +-- KVM/QEMU
        |
        +-- libvirt
            |
            +-- default
            |   +-- Red NAT
            |
            +-- lab-isolated
                +-- Red virtual aislada

OPNsense VM
|
+-- WAN: default
|
+-- LAN: lab-isolated
```

La asignación de interfaces de OPNsense deberá contrastarse con su configuración real antes de considerar validada la topología completa.

### Separación de entornos

Se mantienen diferenciados cuatro ámbitos:

**CURSO**

- Temario.
- Ejercicios.
- Autoevaluaciones.
- Conceptos de redes.

**LABORATORIO VIRTUAL**

- KVM/QEMU.
- libvirt.
- OPNsense.
- Redes virtuales.
- Máquinas cliente y servidor.

**LABORATORIO FÍSICO**

- MikroTik.
- Raspberry Pi.
- SG2210P.
- EAP225.
- Arduino Yún.
- ESP32.
- Estaciones de trabajo.

**SERVICIOS EXISTENTES Y PRODUCCIÓN**

- Servicios ajenos al laboratorio.
- Infraestructura doméstica que debe conservar su funcionamiento.
- Sistemas de producción independientes.

Las prácticas deben evitar modificaciones innecesarias fuera de su entorno correspondiente.

### Plan de validación

| Comprobación | Objetivo | Estado |
|---|---|---|
| Inventario físico | Identificar equipos y puertos | Parcial |
| Direccionamiento IPv4 | Contrastar reservas e interfaces | Parcial |
| DHCP ESP32 | Verificar tres clientes independientes | Completado el 03/10 |
| Tabla MAC SG2210P | Comprobar asociación de puertos | Completado el 03/10 |
| Gestión Omada | Confirmar comunicación con controlador | Completado el 03/10 |
| Rutas Lenovo | Priorizar LAN local o Tailscale | Completado el 03/10 |
| Dashboard web | Verificar servidor y autoinicio | Pendiente |
| Interfaces OPNsense | Confirmar WAN/LAN | Pendiente |
| Aislamiento libvirt | Validar tráfico permitido y bloqueado | Pendiente |
| MEDION con tapa cerrada | Evitar suspensión del anfitrión | Pendiente |
| NetBox | Actualizar inventario y conexiones | Pendiente de actualización |

### Procedimiento para nuevas prácticas

Cada nueva intervención debe documentar:

1. Fecha y equipo afectado.
2. Objetivo de la práctica.
3. Estado inicial observado.
4. Cambio realizado.
5. Resultado de la comprobación.
6. Incidencias encontradas.
7. Solución aplicada, si procede.
8. Estado final y tareas pendientes.

No se registrarán como implementaciones completadas las propuestas que todavía no hayan sido ejecutadas y comprobadas.

### Siguientes prioridades

1. Completar la validación del laboratorio virtual MEDION/OPNsense.
2. Confirmar el aislamiento efectivo de las redes virtuales.
3. Verificar la publicación permanente del dashboard HTML.
4. Actualizar el inventario de NetBox.
5. Definir y probar funciones específicas para los tres ESP32.
6. Documentar las pruebas físicas y virtuales realizadas.

---

## 2026-10-10 — Actualización documental de conexiones físicas y separación de plataformas

**Alcance:** documentación en la rama del PR de reorganización V2; sin cambios de infraestructura, firmware, NetBox ni dashboard desplegado.

### Fuentes y correcciones

- Actualización del usuario: Raspberry Pi 3 para prácticas y pruebas; portátil en otro puerto del SG2210P; Yún en otro puerto LAN del MikroTik.
- Las entradas del 27/09 ya reflejan la redefinición de Pi 3 y su conexión al MikroTik. Se conservan las entradas anteriores como historial, incluida su denominación inicial de monitorización.
- Nuevo diagrama físico y mapa con origen/fecha de los datos; Pi 3 y Yún directamente en MikroTik, AP/ESP32/portátil en SG2210P.
- Corregida la ficha Yún: SSH desde Pi 4 sí figura como correcto el 22/09; vigencia actual sin comprobar.
- Réplica Lenovo separada: propuesta de VM-RPI3 y ramas LAN, sin acreditar aprobación ni creación de VMs.
- MEDION conserva OPNsense y redes propias; asignación WAN/LAN y segunda VM pendientes.
- La ficha del dashboard señala que su fuente HTML no está en el repositorio y que el despliegue no se ha actualizado.

### Pendientes explícitos

Identidad del portátil, mapa actual de puertos, IP/MAC/VLAN, servicios/rutas vigentes, reconciliación con NetBox, estado real de Lenovo y MEDION.

Los diagramas anteriores de este CHANGELOG describen estados fechados y pueden estar incompletos u obsoletos. La referencia documental vigente es [topología física](laboratorio-fisico/topologia.md); no constituye inspección en vivo.

---

## 2026-10-12 — Actualización de MikroTik hEX lite a RouterOS 7.24.5

**Equipo:** MikroTik hEX lite (RB750r2), arquitectura MIPSBE.

**Objetivo:** actualizar RouterOS y RouterBOOT conservando la configuración del laboratorio físico.

### Estado inicial

- RouterOS 7.1.2.
- RouterBOOT 7.1.2.
- Almacenamiento interno de 16 MiB, con aproximadamente 3,93 MiB libres.
- Copias de seguridad binarias y exportación de configuración realizadas antes de intervenir.

### Intervención realizada

1. Instalación y puesta en funcionamiento de WinBox 4.4 para Linux en el Lenovo.
2. Actualización integrada de RouterOS 7.1.2 a 7.12.1.
3. Actualización y activación de RouterBOOT 7.12.1.
4. Actualización integrada de RouterOS 7.12.1 a 7.24.5.
5. Actualización y activación de RouterBOOT 7.24.5.
6. Creación y descarga de una nueva copia de seguridad posterior a la actualización.

No fue necesario utilizar Netinstall ni restablecer la configuración.

### Validaciones posteriores

- RouterOS 7.24.5 confirmado mediante acceso SSH.
- RouterBOOT: current-firmware y upgrade-firmware en 7.24.5.
- Cinco interfaces Ethernet con enlace activo.
- LAN 192.168.88.1/24 y WAN 192.168.100.2/30 conservadas.
- Servidor DHCP del bridge habilitado.
- Reservas DHCP de Arduino Yún, Raspberry Pi 3, SG2210P, EAP225 y tres ESP32 conservadas.
- Tres reservas ESP32 en estado waiting durante la comprobación; conectividad de esos clientes no validada.
- Ruta por defecto mediante Raspberry Pi 4 (192.168.100.1) activa.
- Reglas fundamentales de firewall conservadas, incluida ALLOW Raspberry to LAB.
- Ping a Raspberry Pi 4: 4/4 respuestas, 0 % de pérdidas.
- Ping a 1.1.1.1: 4/4 respuestas, 0 % de pérdidas.
- Resolución DNS de example.com correcta.

### Incidencias y observaciones

- El actualizador inicial ofrecía 7.12.1; tras instalarla ofreció 7.24.5.
- Ambas actualizaciones se descargaron correctamente mediante el actualizador integrado, pese al almacenamiento limitado.
- El Lenovo necesitó un reinicio durante la intervención; posteriormente se recuperó el acceso SSH.
- Se observaron ajustes horarios de NTP tras los reinicios.
- No se detectaron pérdidas de configuración en las comprobaciones efectuadas.

### Estado final y pendientes

RouterOS y RouterBOOT actualizados a 7.24.5. Acceso administrativo, enrutamiento, conectividad IP a Internet y DNS verificados.

Pendiente comprobar el tráfico desde los clientes del laboratorio y confirmar el funcionamiento de los tres ESP32.

---

## 2026-10-12 — Implementación y pruebas HTTP entre ESP32 del laboratorio físico

**Entorno:** laboratorio físico, red 192.168.88.0/24.

**Objetivo:** establecer y comprobar comunicaciones HTTP entre tres placas Waveshare ESP32-S3-ETH con interfaz Ethernet W5500.

### Arquitectura

| Equipo | Dirección IPv4 | Puerto SG2210P | Función |
|---|---|---|---|
| ESP32-01 | 192.168.88.245 | LAN3 | Servidor HTTP |
| ESP32-02 | 192.168.88.246 | LAN4 | Cliente HTTP |
| ESP32-03 | 192.168.88.247 | LAN5 | Monitor HTTP |

### Intervención realizada

1. Revisión y corrección de las conexiones físicas LAN4/LAN5.
2. Comprobación de las reservas DHCP por dirección MAC en el MikroTik.
3. Carga del programa ESP32_HTTP_CLIENT.ino en ESP32-02.
4. Establecimiento de comunicaciones Ethernet mediante W5500.
5. Configuración de peticiones HTTP periódicas cada 10 segundos desde ESP32-02.
6. Pruebas de comunicación HTTP con ESP32-01.
7. Pruebas de monitorización HTTP desde ESP32-03.

### Resultados observados

- ESP32-02 obtuvo respuestas HTTP/1.1 200 OK del servidor ESP32-01.
- ESP32-03 registró cuatro respuestas HTTP satisfactorias en la serie observada.
- Latencias aproximadas de 19–20 ms en la prueba del monitor.
- Ningún error registrado durante esa serie de cuatro peticiones.
- Las tres reservas DHCP permanecieron configuradas tras actualizar RouterOS a 7.24.5.

### Observaciones y pendientes

- Durante la comprobación posterior del MikroTik, las reservas de los tres ESP32 figuraban en estado waiting.
- Ese estado no permite concluir por sí solo que exista un fallo de conectividad.
- Pendiente repetir las pruebas con los tres dispositivos conectados y activos.
- Pendiente documentar versiones definitivas de firmware y código fuente en el repositorio, si todavía no están incorporados.

### Estado final

Comunicación HTTP entre ESP32-02 y ESP32-01 comprobada satisfactoriamente.

Monitorización HTTP desde ESP32-03 comprobada satisfactoriamente en la serie de pruebas observada.

---

## 2026-10-12 — Desarrollo y puesta en servicio de los firmwares ESP32-02 y ESP32-03

**Entorno:** laboratorio físico, red 192.168.88.0/24.
**Hardware:** Waveshare ESP32-S3-POE-ETH con controlador Ethernet W5500.
**Herramientas:** Arduino IDE, librería Ethernet_Generic y monitor serie a 115200 baudios.

### 1. Situación inicial

ESP32-02 y ESP32-03 no disponían todavía de los programas HTTP correspondientes a sus funciones actuales.

Las placas ya habían participado en las prácticas Ethernet del 02–03/10/2026, durante las cuales se diagnosticó y corrigió un conflicto de direcciones MAC duplicadas.

El objetivo de esta intervención fue convertirlas en nodos funcionales independientes dentro de una arquitectura de comunicación y monitorización HTTP.

### 2. Arquitectura implementada

| Nodo | IPv4 reservada | Puerto SG2210P | Función |
|---|---|---|---|
| ESP32-01 | 192.168.88.245 | LAN3 | Servidor HTTP |
| ESP32-02 | 192.168.88.246 | LAN4 | Cliente HTTP |
| ESP32-03 | 192.168.88.247 | LAN5 | Monitor HTTP |

ESP32-01 actúa como servidor central de pruebas, escuchando conexiones TCP en el puerto 80.

ESP32-02 genera solicitudes HTTP periódicas y muestra las respuestas completas.

ESP32-03 comprueba la disponibilidad HTTP del servidor, mide tiempos de respuesta y mantiene contadores de resultados.

### 3. Preparación del entorno Ethernet

Los programas utilizan:

- Biblioteca SPI para la comunicación con W5500.
- Biblioteca Ethernet_Generic para las funciones Ethernet.
- Biblioteca esp_mac para obtener la identidad MAC.
- DHCP para obtener la configuración IPv4.
- Puerto serie para diagnóstico.

Configuración SPI:

| Señal | GPIO |
|---|---|
| CS | 14 |
| RST | 9 |
| MISO | 12 |
| MOSI | 11 |
| SCK | 13 |

El firmware realiza un reinicio del controlador W5500 antes de inicializar Ethernet.

La MAC se obtiene mediante esp_read_mac(mac, ESP_MAC_ETH).

La configuración IP se solicita mediante Ethernet.begin(mac).

### 4. Desarrollo del ESP32-02 — Cliente HTTP

**Programa:** ESP32_HTTP_CLIENT.ino.

Se implementaron las siguientes funciones:

1. Inicialización del puerto serie a 115200 baudios.
2. Lectura de la dirección MAC Ethernet.
3. Inicialización de SPI y W5500.
4. Reinicio físico del controlador Ethernet.
5. Obtención de configuración IPv4 por DHCP.
6. Creación de un cliente TCP mediante EthernetClient.
7. Conexión con ESP32-01 en 192.168.88.245:80.
8. Construcción de una solicitud GET / HTTP/1.1.
9. Envío de las cabeceras Host y Connection: close.
10. Lectura e impresión de la respuesta HTTP recibida.
11. Control de inactividad durante la lectura, con límite de tres segundos.
12. Cierre de la conexión TCP.
13. Programación de consultas periódicas cada diez segundos mediante millis().

**Validación:** se observaron respuestas HTTP/1.1 200 OK del servidor ESP32-01.

El programa permite generar y observar tráfico HTTP real entre dos microcontroladores conectados a la red Ethernet del laboratorio.

### 5. Desarrollo del ESP32-03 — Monitor HTTP

**Programa:** ESP32_HTTP_MONITOR.ino.

Se implementaron las siguientes funciones:

1. Inicialización del puerto serie y del controlador Ethernet.
2. Obtención de dirección MAC e IPv4 mediante DHCP.
3. Creación de conexiones TCP hacia ESP32-01.
4. Envío periódico de solicitudes HTTP GET.
5. Lectura de la primera línea de respuesta HTTP.
6. Comprobación del estado HTTP/1.1 200.
7. Clasificación de comprobaciones como ONLINE u OFFLINE.
8. Medición del tiempo transcurrido desde el inicio de la conexión hasta la recepción de la línea de estado o finalización de la espera.
9. Contador acumulado de comprobaciones correctas.
10. Contador acumulado de comprobaciones fallidas.
11. Presentación de resultados por el monitor serie.
12. Control de espera de tres segundos.
13. Repetición de comprobaciones cada diez segundos.

**Validación observada:**

- Cuatro comprobaciones satisfactorias.
- Cero fallos.
- Tiempos de respuesta aproximados de 19–20 ms.

El tiempo registrado incluye operaciones de conexión TCP y recepción HTTP. No representa exclusivamente la latencia de red.

### 6. ESP32-01 — Servidor de referencia

**Programa:** ETH_MAC_DHCP_StaticIP.ino.

Se utilizó un programa basado en el ejemplo de Waveshare y adaptado para funcionar como servidor HTTP.

El firmware:

- Inicializa W5500 y Ethernet.
- Obtiene configuración mediante DHCP.
- Escucha conexiones TCP en el puerto 80.
- Recibe solicitudes HTTP.
- Devuelve una respuesta HTTP/1.1 200 OK.
- Entrega una página HTML identificando al ESP32-01.
- Cierra la conexión después de responder.

Aunque el archivo conserva el nombre original relacionado con DHCP e IP estática, la versión documentada no implementa una IP estática de respaldo.

### 7. Conectividad y diagnóstico

Durante la intervención se revisó la correspondencia entre dispositivos, conexiones físicas y reservas DHCP.

Se corrigió la distribución de ESP32-02 y ESP32-03 entre LAN4 y LAN5 respecto al estado histórico del 03/10.

Las pruebas HTTP permitieron observar la comunicación TCP entre nodos y la respuesta del servidor.

La actualización del MikroTik a RouterOS 7.24.5 conservó las reservas DHCP existentes.

En una comprobación posterior, las reservas de los tres ESP32 aparecieron en estado waiting. No se consideró prueba suficiente de fallo de conectividad.

### 8. Limitaciones identificadas

- No existe recuperación DHCP completa en los programas cliente y monitor.
- Los contadores de ESP32-03 se pierden al reiniciar.
- ESP32-03 verifica el código HTTP, pero no el contenido de la página.
- No existe todavía almacenamiento persistente ni exportación centralizada de métricas.
- La disponibilidad HTTP no garantiza por sí sola el correcto funcionamiento de todos los servicios de red.
- Queda pendiente una prueba conjunta posterior con los tres nodos activos.

### 9. Incorporación de código y documentación a Git

Se incorporaron al repositorio local los programas:

- laboratorio-fisico/esp32/ESP32-01/ETH_MAC_DHCP_StaticIP.ino
- laboratorio-fisico/esp32/ESP32-02/ESP32_HTTP_CLIENT.ino
- laboratorio-fisico/esp32/ESP32-03/ESP32_HTTP_MONITOR.ino

Se actualizó laboratorio-fisico/esp32/README.md con la arquitectura, el funcionamiento de los tres nodos y las limitaciones conocidas.

Se conservó una copia de la documentación anterior en README.pre-20261012.md.

### 10. Resultado

Se implementó una arquitectura Ethernet con tres funciones diferenciadas:

**ESP32-01:** servidor HTTP.
**ESP32-02:** cliente HTTP periódico.
**ESP32-03:** monitor HTTP con validación de estado, medición de tiempo de respuesta y estadísticas.

Las comunicaciones y la monitorización fueron verificadas satisfactoriamente en las pruebas registradas.

La intervención constituye una práctica de desarrollo de firmware, configuración Ethernet, comunicación TCP/IP y monitorización de servicios.


---

## 2026-10-12 — Integración OPNsense ↔ laboratorio físico mediante RTL8153 y VLAN 20

**Plataforma:** MEDION `netlab-ws01`, Debian 13, VM `opnsense-lab`.  
**Objetivo:** disponer de una interfaz de OPNsense hacia un segmento Ethernet físico distinto de la LAN virtual y de la LAN MikroTik.

### 1. Recuperación del firmware RTL8153

En el anfitrión Debian se observaron los errores:

```text
failed to load rtl_nic/rtl8153b-2.fw (-2)
unable to load firmware patch rtl_nic/rtl8153b-2.fw
```

El fichero `/lib/firmware/rtl_nic/rtl8153b-2.fw` no existía y `firmware-realtek` no estaba instalado. Se confirmó disponibilidad del paquete `firmware-realtek 20250410-2` para Debian 13 Trixie (`non-free-firmware`), se instaló y se comprobó la existencia del firmware. Tras reinicialización física del adaptador, desaparecieron los errores observados.

### 2. Passthrough USB hacia OPNsense

El adaptador había alternado entre OPNsense (`ue0`) y el anfitrión (`enx00e04c6831b0`), con pérdidas anteriores del dispositivo en la VM. Tras corregir el firmware y arrancar OPNsense limpiamente:

- USB vendor/product: `0x0bda:0x8153`; passthrough persistente declarado por esos identificadores.
- Adaptador Realtek RTL8153 expuesto a FreeBSD/OPNsense como `ue0`.
- MAC: `00:e0:4c:68:31:b0`.
- Enlace: `1000baseT`, full-duplex, `status: active`.
- El adaptador dejó de aparecer como interfaz `enx00e04c6831b0` del host durante el passthrough.

**Límite de validación:** estable durante las pruebas de esta sesión; no se ha demostrado persistencia funcional tras múltiples reinicios.

### 3. Interfaces de OPNsense después de la intervención

Se conservaron WAN y LAN virtuales, y se incorporó una tercera interfaz física:

| Interfaz lógica | Interfaz reportada | Red / función |
|---|---|---|
| WAN | `re1` | Salida por libvirt `default`, conservada |
| LAN | `re0` | `10.10.10.1/24`, `lab-isolated` |
| OPT1 | `ue0` | `10.20.20.1/24`, LAB-FISICO |

En la sesión del 10/10 se habían documentado las NIC virtuales como `em0`/`em1`. La asignación `re1`/`re0` es la identificada en la intervención del **12/10**, que tiene prioridad para describir esa sesión; las denominaciones antiguas se conservan como historial. No se ha comprobado aquí qué causó el cambio de nombre.

`ifconfig ue0` confirmó `inet 10.20.20.1`, máscara `0xffffff00`, broadcast `10.20.20.255` y enlace activo. No se configuró upstream gateway ni IPv6 en OPT1.

### 4. VLAN 20 LAB-FISICO en TP-Link Omada

Inicialmente estaba documentada la red `Default` con VLAN ID 1. Se creó:

- Nombre: `LAB-FISICO`.
- VLAN ID: `20`.
- `DHCP Server Device`: `External Device`.
- SG2210P **puerto 6:** modo **Access VLAN 20**.
- Enlace `OPT1/ue0` ↔ RTL8153 ↔ SG2210P puerto 6: activo a 1 Gbps full-duplex tras el cambio.

Omada conserva funciones de switching/VLAN L2, mientras que OPNsense se prevé como gateway, firewall, router y servidor DHCP de la nueva red. En un puerto Access el adaptador recibe tráfico Ethernet sin etiqueta VLAN; no se configuró una subinterfaz 802.1Q en `ue0`.

**Los demás puertos no se migraron a VLAN 20.** La LAN MikroTik `192.168.88.0/24` y la LAN virtual OPNsense `10.10.10.0/24` permanecen como ámbitos distintos.

### 5. Direccionamiento y DHCP pendiente

- Red física nueva: `10.20.20.0/24`.
- Dirección OPT1/gateway: `10.20.20.1`.
- Plan de direcciones: `10.20.20.2–99` infraestructura/estáticas; `10.20.20.100–200` DHCP de clientes; `10.20.20.201–254` reserva futura.

Se introdujo en el asistente DHCP OPT1 habilitado con rango `10.20.20.100–10.20.20.200`. **NO consta verificado un servidor DHCP IPv4 funcionando**: durante las comprobaciones no aparecieron procesos `kea` o `dhcpd`, ni una sección `<dhcpd>` en la consulta indicada sobre `config.xml`. Estas observaciones requieren diagnóstico antes de concluir la causa.

### 6. Diagrama lógico de la intervención

```text
MEDION netlab-ws01 (Debian 13)
└── KVM/libvirt
    └── OPNsense
        ├── WAN re1 ── libvirt default / NAT
        ├── LAN re0 ── 10.10.10.1/24 ── lab-isolated ── Debian cliente VM
        └── OPT1 ue0 ── 10.20.20.1/24 ── RTL8153 (USB passthrough)
                                             │ 1 Gbps
                                             └── SG2210P puerto 6
                                                 Access VLAN 20
                                                 LAB-FISICO 10.20.20.0/24
```

### 7. Estado y trabajos pendientes

**Verificado durante la intervención (según informe de sesión):** instalación del firmware Realtek, recuperación del passthrough, interfaz `ue0` de OPNsense activa, asignación OPT1 `10.20.20.1/24`, enlace gigabit, creación de VLAN 20 y configuración Access de puerto 6, conservación de WAN y LAN virtual.

**Pendiente:**

1. Verificar/activar el servicio DHCP IPv4 de OPT1 y su configuración efectiva.
2. Conectar primer cliente físico a VLAN 20; probar dirección `10.20.20.x`, puerta de enlace y acceso a `10.20.20.1`.
3. Diseñar, aplicar y comprobar reglas de firewall, NAT y routing según la política de aislamiento aprobada.
4. Verificar qué tráfico puede salir de cada segmento y si hay rutas no deseadas hacia redes domésticas o de producción.
5. Comprobar persistencia de USB passthrough y servicio tras reinicios.
6. Reconciliar esta topología con NetBox; sin atribuir aún cliente físico a VLAN 20.

En esta sesión no se pudo utilizar el Lenovo como cliente Ethernet de prueba porque el único adaptador USB-Ethernet disponible estaba dedicado a OPNsense.

**Naturaleza de la entrada:** transcripción documental de resultados comunicados por el usuario; no representa una inspección independiente de los equipos ni una nueva intervención sobre su configuración.


---

## 2026-10-12/13 — Generación y captura de tráfico sintético en Debian Client

**Plataforma:** MEDION `netlab-ws01`, Debian 13, KVM/libvirt; VM `debian-client01` en red virtual `lab-isolated`.

**Objetivo:** producir y observar tráfico controlado ICMP, DNS y HTTPS, relacionándolo con la pila de red del curso.

### Servicio generador

- Se creó la unidad systemd `/etc/systemd/system/netlab-traffic.service`.
- Genera ICMP (`ping` a `10.10.10.1`), resolución DNS de `example.com` y consulta HTTPS con `curl`.
- Su ejecución **manual** fue comprobada satisfactoriamente.

### Entorno y captura

- VM cliente: `debian-client01`, interfaz `enp1s0`, IP `10.10.10.179/24`.
- Puerta de enlace/OPNsense LAN: `10.10.10.1`.
- Se instaló `tcpdump` y se creó `/root/netlab-captures/`.
- Tras varias capturas de prueba, se obtuvo `/root/netlab-captures/captura-06.pcap`.

### Tráfico observado según informe

- STP IEEE 802.1D, BPDUs de configuración aproximadamente cada 2 segundos, bridge ID `8000.52:54:00:3f:26:1c.8002`.
- ICMP `10.10.10.179` ↔ `10.10.10.1`.
- DNS vía `10.10.10.1:53`, resolución de `example.com`.
- TCP hacia puerto 443 y tráfico HTTPS; apertura SYN → SYN/ACK → ACK, transferencia y cierre FIN.

La captura en la interfaz LAN conserva `10.10.10.179` como IP de origen, **antes del punto NAT de OPNsense**. No se ha demostrado aún una traducción NAT comparando ambos lados; queda pendiente una captura en la interfaz WAN.

### Incidencia del timer systemd

Se probó `netlab-traffic.timer` con una programación inicial de cinco minutos que llegó a funcionar. El intento de reducir temporalmente la frecuencia a 30 segundos mediante `OnCalendar` generó una definición rechazada por systemd. **Estado de cierre del timer: `bad-setting`, no operativo.** El servicio manual siguió funcionando.

### Estado final y pendientes

**Conseguido:** generador manual funcional, `tcpdump` instalado y captura `captura-06.pcap` válida según las pruebas comunicadas.

**Pendiente:** reparar `netlab-traffic.timer`, restablecer 5 minutos y comprobar el disparo automático; realizar capturas LAN/WAN para observar NAT; registrar filtros y métodos de captura, y revisar cualquier PCAP antes de compartirlo por su contenido potencialmente sensible.

**Documentación:** [PRAC-005 — Generación y captura de tráfico en Debian Client](practicas/diagnostico/PRAC-005-trafico-pcap-debian-client.md).

**Límite de evidencia:** esta entrada recoge el informe facilitado por el usuario; el archivo PCAP no ha sido subido ni auditado directamente desde el repositorio.

---

## 2026-10-14 — Diagnóstico de conectividad Tailscale y habilitación de journald persistente en Raspberry Pi 4

**Ámbito:** entorno real de administración del laboratorio (`raspi` y Lenovo ThinkPad L13 Gen 3). No corresponde a la réplica virtual Lenovo ni a la plataforma MEDION.

### Incidencia y recuperación de conectividad

- La Raspberry Pi 4 (`Raspi`) y el Lenovo aparecieron desconectados en la aplicación móvil de Tailscale. La Raspberry tampoco respondió inicialmente a `tailscale ping`.
- Raspberry Pi 4: Wi-Fi `wlan0` en `192.168.1.236`, Ethernet `eth0` en `192.168.100.1/30`, Tailscale `100.90.39.30` y usuario SSH `popi`.
- Tras un **reinicio físico** de la Raspberry se recuperaron Tailscale y el acceso SSH desde el Lenovo. Se obtuvo `pong from raspi (100.90.39.30) via 192.168.1.236:41641 in 2ms`, mediante conexión directa sin relay DERP.
- Lenovo L13: Tailscale `100.116.135.126`, IP doméstica `192.168.1.192` y versión de Tailscale `1.104.1`. Se comprobó conectividad con la Raspberry y con el VPS `ailab-core01` (`100.87.19.25`). No se actualizó ni reinstaló Tailscale en el Lenovo.

### Diagnóstico y persistencia de registros en Raspberry Pi 4

- `journalctl --list-boots` mostraba únicamente el arranque actual. Se identificó la configuración efectiva `/usr/lib/systemd/journald.conf.d/40-rpi-volatile-storage.conf` con `Storage=volatile`, que impedía conservar el historial entre reinicios.
- Tras comprobar el espacio disponible, se creó la configuración independiente `/etc/systemd/journald.conf.d/90-persistent.conf`, sin modificar el archivo original de Raspberry Pi OS:

  ```ini
  [Journal]
  Storage=persistent
  SystemMaxUse=100M
  MaxRetentionSec=14day
  ```

- Se verificó el contenido y la prioridad de la configuración, se reinició de forma controlada `systemd-journald`, se ejecutó `journalctl --flush` y se comprobó la presencia de registros en `/var/log/journal`.
- Ocupación inicial reportada: **16 MB** (`Archived and active journals take up 16M in the file system`). Se configuraron un máximo de **100 MB** y una retención de **14 días**, sujetos a las reglas de conservación de journald.
- **Pendiente de validar:** que los registros persistan tras el siguiente reinicio ordinario de la Raspberry.

### Análisis de red y Tailscale en Lenovo L13

- NetworkManager registró la obtención de `192.168.88.249` en `Lab-Redes` a las 09:33:43 y problemas intermitentes de comunicación con DERP Madrid entre las 09:33 y las 09:37.
- A las 09:37:53 se solicitó activar `Starlink` desde `nm-applet` (PID 1835, UID 1000), se recibió `192.168.1.192` y se confirmó conectividad global; a las 09:38:04 los indicadores de salud de Tailscale eran correctos.
- El usuario indicó posteriormente que **es posible que él mismo efectuara el cambio de Wi-Fi**. No se considera demostrado un cambio automático no autorizado ni un fallo de NetworkManager.
- Los perfiles `Starlink` y `Lab-Redes` tenían autoconexión activada y prioridad `0`, ambos por DHCP. En `Lab-Redes`: `ipv4.method=auto`, `ipv4.never-default=no` y `ipv4.gateway=--` en la configuración consultada. No está demostrado que `Lab-Redes` careciera de acceso general a Internet.
- En ambos equipos aparecieron errores `logtail: upload failed 429: rate limited on bytes transferred per ID`, con reintentos posteriores satisfactorios. Afectan al envío de registros de diagnóstico; **no hay evidencia para atribuirles la desconexión original**.
- En el Lenovo se observaron intentos fallidos hacia `192.168.100.2:80` a través de la Raspberry mientras esta estaba desconectada. Revisar por separado si se repiten con la Raspberry operativa.

### Principio arquitectónico y límites

- Se establece como requisito que las redes físicas y de laboratorio dispongan de salida a Internet y mecanismos de administración remota **autorizada**, según su función, sin permitir por ello comunicación indiscriminada entre subredes.
- Deben mantenerse separados: acceso a Internet, acceso administrativo remoto, permisos entre redes, aislamiento experimental y servicios de producción. Tailscale permanece como componente de acceso remoto autorizado.
- Se evaluarán rutas alternativas de administración y puntos únicos de fallo en la infraestructura doméstica.
- **No se modificaron** Tailscale, Docker, NetBox ni LibreNMS en la Raspberry; tampoco se cambiaron las redes virtuales KVM ni la plataforma MEDION.

### Estado final y trabajos pendientes

**Verificado según informe del 14/10/2026:** Raspberry y Lenovo accesibles por Tailscale; comunicación directa Lenovo–Raspberry; SSH a la Raspberry recuperado; registros de journald escritos de forma persistente en disco con configuración independiente; uso inicial de 16 MB; Tailscale del Lenovo operativo.

**No demostrado:** causa exacta de la desconexión de Raspberry; participación de una actualización de Tailscale; ausencia general de Internet desde `Lab-Redes`; cambio de Wi-Fi automático.

**Pendiente:** (1) verificar persistencia de journald tras reiniciar; (2) probar Internet y Tailscale desde `Lab-Redes`; (3) revisar las rutas remotas autorizadas entre subredes; (4) investigar `192.168.100.2:80` si reaparece el fallo; (5) evaluar monitorización y alertas de conectividad de los nodos principales.

**Límite de evidencia:** registro documental basado en el informe aportado; no constituye auditoría directa de los equipos ni autorización para nuevos cambios de configuración.



---

## 2026-10-15 — Raspberry Pi 4: ruta persistente hacia MikroTik y recuperación de SSH

**Ámbito:** laboratorio FÍSICO (Raspberry Pi 4 `Raspi` / MikroTik). **Fuente:** diagnóstico y captura Termius aportados el 15/10/2026; no es inspección en vivo realizada desde este repositorio.

### Incidencia y diagnóstico

- La conexión SSH hacia `192.168.88.1:22` agotaba el tiempo desde Lenovo a través de Tailscale y también desde Raspberry Pi 4.
- Tailscale Lenovo↔Raspberry funcionaba (~5 ms); la Raspberry anunciaba `192.168.100.0/30` y `192.168.88.0/24`.
- `eth0` tenía `192.168.100.1/30`; faltaba ruta específica `192.168.88.0/24` en la Raspberry.
- Antes del cambio, `ip route get 192.168.88.1` elegía `via 192.168.1.1 dev wlan0` (Starlink), no el tránsito Ethernet al MikroTik.

### Corrección aplicada a la Raspberry (ya realizada)

1. Ruta temporal: `sudo ip route add 192.168.88.0/24 via 192.168.100.2 dev eth0`.
2. Primer intento de modificación NetworkManager por nombre de perfil falló por codificación UTF-8.
3. Se utilizó el UUID del perfil Ethernet `ff200535-83ed-33eb-97c5-943b6f133bfc`:
   `sudo nmcli con mod ff200535-83ed-33eb-97c5-943b6f133bfc +ipv4.routes "192.168.88.0/24 192.168.100.2"`.

### Verificación y evidencia

- NetworkManager mostró la ruta guardada: `192.168.88.0/24 192.168.100.2`.
- Consulta del kernel: `192.168.88.1 via 192.168.100.2 dev eth0 src 192.168.100.1`.
- Captura de Termius aportada: sesión de consola con prompt `[admin@MikroTik] >` y registro en MikroTik de un **intento fallido de autenticación** para `admin` desde `192.168.100.1` vía SSH. La combinación de la sesión observada y la identificación de acceso Raspberry→MikroTik comunicada por el usuario acredita acceso administrativo, sin interpretar el registro de intento fallido como un inicio de sesión exitoso.
- **No se adjunta a GitHub la captura original**: contiene identificadores de red; conservar referencia a evidencia aportada en la sesión.
- **Sin cambios** de firewall, Tailscale o servicios de producción; sin reiniciar interfaces.

### Resultado y pendiente

**Ruta guardada y activa; conexión SSH a consola MikroTik acreditada en la sesión del 15/10.** La persistencia *tras un reinicio real de la Raspberry* sigue **PENDIENTE DE VERIFICACIÓN**. Este registro no acredita por sí mismo acceso SSH directo Lenovo→MikroTik, sino administración desde la Raspberry alcanzada mediante Tailscale.

**Lección:** anunciar subredes en Tailscale no sustituye el enrutamiento local del router que las anuncia; comprobar `ip route get` antes de cambiar firewall.


---

## 2026-10-15 — Auditoría de secretos y reglas de protección del repositorio público

**Ámbito:** GitHub `p0p1as71/gestor-redes-laboratorio` y análisis local en Lenovo ThinkPad L13. **Categoría:** seguridad, gobernanza y publicación.

### Auditoría de secretos — Gitleaks

- El repositorio fue confirmado como **público** en GitHub; se corrigió la portada y se documentó una revisión parcial de publicación mediante el PR #9 (commit `0f49f15`).
- En Lenovo se instaló Gitleaks desde los repositorios de Ubuntu Noble; el ejecutable responde, aunque `gitleaks version` muestra `version is set by build process`.
- Comando de auditoría ejecutado: `gitleaks detect --source ~/gestor-redes-laboratorio --log-opts="--all" --redact --no-banner`.
- **Resultado consignado:** `104 commits scanned`, `no leaks found`. No se detectaron secretos reconocibles por las reglas predeterminadas de Gitleaks.
- `git branch -a`, `git ls-remote --heads origin` y `git show-ref` permitieron contrastar **10 ramas remotas** y sus SHA coincidentes en GitHub y Lenovo. La cobertura corresponde a refs actuales accesibles, no a objetos eliminados o inalcanzables.
- La auditoría no certifica ausencia absoluta de credenciales, exposición de servicios ni permisos de colaboración.

### GitHub CLI — diagnóstico sin cambios de seguridad acreditados

- La consulta de protección desde `gh api` devolvió HTTP 401; `gh auth status` identificó un token local inválido.
- Se inició `gh auth login`, que intentó proponer una clave pública SSH ya existente y abrir un navegador; no se acreditó finalización de la autenticación ni alta de clave nueva. Se decidió dejar `gh` sin intervención adicional y continuar con el conector GitHub de ChatGPT.
- Git por SSH del Lenovo y la integración GitHub de ChatGPT funcionaron de forma independiente.

### Reglas GitHub — estado observado el 15/10

- El usuario creó en la interfaz web el ruleset **`Proteccion-main`** (ID `25191874`); la API confirmó `enforcement=active` y reglas de **prohibición de borrado**, **bloqueo de force push** y **Pull Request obligatorio** con **0 aprobaciones requeridas**.
- **Incidencia de alcance pendiente:** la consulta directa de GitHub devolvió `conditions.ref_name.include=[]`. La rama `main` aparecía `protected=false` en su endpoint. Aunque el usuario comunicó haber configurado los objetivos, **no está verificado que el ruleset se aplique efectivamente a ninguna rama**.
- **No declarar `main` protegida** hasta confirmar que la regla contiene una condición de inclusión que coincida con `main` y que su aplicación es efectiva.
- Sigue pendiente consultar alertas GitHub Security, colaboradores/permisos, historial inalcanzable y superficie de exposición de servicios de administración.

### Impacto

Solo se instalaron herramientas de auditoría en Lenovo y se actualizó documentación GitHub. **No se modificaron equipos del laboratorio, VLAN, firewall, Tailscale ni NetBox.**

**Dictamen:** exploración inicial de secretos **favorable**; revisión de seguridad de publicación **abierta**; ruleset **creado pero aplicación a `main` no acreditada**.


### Verificación adicional del ruleset — 15/10/2026, 21:22 (hora local)

- El usuario confirmó haber actualizado `Proteccion-main` en GitHub.
- Consulta directa de la API: ruleset ID `25191874`, `enforcement=active`, `conditions.ref_name.include=["~DEFAULT_BRANCH"]`; **la rama predeterminada `main` queda incluida**.
- Reglas verificadas: `deletion` (impedir eliminación), `non_fast_forward` (impedir force push) y `pull_request` (exigir PR antes de integrar) con `required_approving_review_count=0`.
- **Estado: protección de `main` verificada a nivel de configuración del ruleset**. No se realizó un intento de push prohibido ni una prueba disruptiva de aplicación.
- Esta comprobación cierra el pendiente de alcance del ruleset descrito en la entrada anterior, sin cerrar la auditoría global de exposición de servicios ni permisos y alertas GitHub Security.


---

## 2026-10-15 — Decisión arquitectónica: PYME virtual Lenovo en lugar de réplica integral; preparar traslado de Omada a VPS

**Ámbitos:** laboratorio FÍSICO, Lenovo L13, VPS Hetzner y plataforma MEDION (separada). **Tipo:** decisión de arquitectura + resultados de diagnóstico comunicados por el usuario; **migración Omada y construcción de PYME NO iniciadas**.

### 1. Cambio de objetivo del laboratorio virtual Lenovo

- **Se descarta como plan activo** reproducir toda la cadena física Pi4 → MikroTik → switch → ESP32/Yún/RPi3 mediante VMs equivalentes. El diseño anterior del 10/10 se conserva como **historial**, no como tarea de ejecución.
- **Nuevo objetivo aprobado de diseño:** añadir una **red de pequeña empresa virtual** conectable más adelante al laboratorio físico, como si fueran equipos nuevos:
  - **Windows 11 VM**, puesto de trabajo KVM/QEMU para SMB, IP/DNS, diagnóstico y cliente IPP; RAM de planificación ~4 GiB.
  - **OpenMediaVault VM** como servidor NAS sin escritorio, SMB y **cuatro discos virtuales** para experimentar RAID 0, 1, 5 y 10 con montajes sucesivos; RAM prevista 1–2 GiB.
  - **CUPS** como servidor de impresión virtual IPP, preferentemente contenedor segregado; memoria estimada 100–200 MiB.
  - **Linux Bridge** como switch virtual, inicialmente con red de pruebas aislada; futuro enlace USB 3.0→Ethernet Lenovo→SG2210P solo tras validar puerto, VLAN, DHCP, NetBox y seguridad.
- RAM adicional orientativa del entorno ~5,5–6,5 GiB, sin medir la sobrecarga total real. Disco de VMs previsto en SSD externo `LAB-VMS`; comprobar su capacidad y disponibilidad actual antes de crear.
- Direcciones planteadas para eventual integración física: Windows `192.168.88.110`, OMV `192.168.88.120`, CUPS `192.168.88.130`; son **propuestas, no reservas ni concesiones**.
- **No confundir**: el adaptador RTL8153 actualmente documentado en MEDION sirve a OPNsense en SG2210P puerto 6 Access VLAN20; no hay puerto/adaptador confirmado ni conexión física Lenovo PYME implementada. Wi-Fi cliente del Lenovo seguirá fuera del bridge. Docker existente no se altera.
- **MEDION** continúa como plataforma independiente: OPNsense `lab-isolated`, LAB-FISICO/VLAN20 y sus prácticas sin integración automática con la PYME.

### 2. Dependencia: Omada Controller Lenovo → VPS Hetzner (solo PLANIFICADA)

**Motivo:** liberar RAM del Lenovo y desacoplar administración Omada del portátil, manteniendo SG2210P/EAP225 bajo gestión continua.

- Fuente del controlador: Lenovo L13, Omada Controller **v6.3.0.45** según sesiones previas; todavía operativo allí. Destino propuesto: VPS `Ailab-core01` Debian 12, vía Tailscale → Raspberry Pi 4 → MikroTik → red física `192.168.88.0/24`.
- El VPS aloja otros servicios. **No se ha instalado Omada ni trasladado su base de datos**; no se han apagado servicios del Lenovo ni autorizado aperturas públicas.
- El sistema de descubrimiento DHCP Option 138 documentado anteriormente apunta al Lenovo por Tailscale: debe diseñarse el cambio con reversión, sin modificarlo aún.

### 3. Preparación VPS — resultados reportados el 15/10

| Elemento | Antes / operación comunicada | Después / límite |
|---|---|---|
| Disco VPS | 150 GB, 95 % ocupado; backups acumulados en `/home/ailab/ai-lab-core/backups` | **46 GB usados, 99 GB libres, 32 %**; ~91 GB recuperados |
| Retención local | Copia `/home/ailab/ai-lab-core/scripts/backup.sh.bak-20261015`, edición `backup.sh` | Conserva 3 carpetas locales recientes antes de intentar sincronizar con Google Drive; **sin prueba integral/restauración** |
| Swap | Creado `/swapfile` de 4 GiB y entrada `/etc/fstab` | 15 GiB de RAM total, 6,2 GiB disponibles; swap 4 GiB activada, 0B usada; **reinicio pendiente** |
| Tailscale VPS | Activada aceptación de rutas anunciadas `--accept-routes=true` | Rutas Pi4 `192.168.100.0/30` y `192.168.88.0/24` aceptadas según prueba de sesión; salida general por Hetzner |

Estos cambios **ya se realizaron en sesión distinta según el informe aportado**. El trabajo documental actual no vuelve a ejecutar ni valida la restaurabilidad del backup.

### 4. Conectividad VPS ↔ MikroTik — distinción de evidencias

- Ping VPS → Raspberry Tailscale y Ethernet, y MikroTik WAN `192.168.100.2`, documentados como correctos. SSH VPS → MikroTik WAN, reportado correcto.
- Ping desde VPS a IP LAN MikroTik `192.168.88.1`, repetido el 15/10: **4 paquetes enviados, 4 recibidos, 0 % de pérdidas**, RTT promedio ~71,2 ms; **HECHO VERIFICADO por transcripción aportada**.
- Una captura de ICMP en MikroTik `/tool sniffer quick interface=ether1 ip-protocol=icmp` **se inició**, pero Termius cerró la sesión y su salida no se conservó. **NO contar como prueba de captura completada**; origen IP visto en `ether1`, SNAT en Raspberry y recorrido exacto no confirmados.
- **No acreditado:** VPS → SG2210P/EAP225; ping al router **no demuestra acceso** a dispositivos posteriores ni adopción remota operativa.
- En esta investigación no se cambiaron reglas ni rutas del MikroTik, según el informe aportado.

### 5. Orden de actuación acordado; no ejecutado aún

1. Captura ICMP en MikroTik `ether1` con sesión persistente + ping desde VPS, guardar resultados, identificar IP origen y comprobar si hay SNAT; después probar acceso a dispositivo Omada real.
2. Comprobar compatibilidad Omada v6.3.0.45/Debian 12, dependencias, puertos y rutas de adopción, y recursos reales del VPS; elegir instalación nativa o Docker sin tocar producción.
3. Validar backup/restauración del VPS, preparar backup del controlador Lenovo y plan de rollback.
4. Instalar y restaurar Omada en VPS **solo con autorización**, confirmar adopción/comunicación SG2210P/EAP225; desactivar Lenovo únicamente tras verificaciones.
5. Medir RAM/SSD libre del Lenovo, revisar KVM/libvirt y red `LAB-NET`, crear Linux Bridge inicialmente aislado; desplegar Windows 11, OpenMediaVault (cuatro discos virtuales) y CUPS/IPP en entorno segregado.
6. Integración futura por adaptador USB-Ethernet **del Lenovo** al SG2210P, previa comprobación de puerto/VLAN/IPAM/aislamiento y autorización; practicar y registrar resultados en GitHub y NetBox.

### Estado al cierre

**DECISIÓN DOCUMENTADA / MIGRACIÓN NO INICIADA / PYME VIRTUAL NO DESPLEGADA.** VPS preparado parcialmente; conectividad ICMP hasta el MikroTik LAN confirmada, **no** hasta Omada; sniffer no conservado. No se modificaron equipos, VPS, firmware, reglas, servicios, NetBox ni redes al documentar este cambio.


---

## 2026-10-15 — Reconciliación AUD-TOP R2 y cierre documental de H01 en `main`

**Motivo:** corregir documentación visible públicamente en `main` tras el informe de auditoría de solo lectura AUD-TOP-2026-10-15-R2, realizado con corte 22:18, y la confirmación posterior del usuario acerca del sketch ESP32-01. **No se han modificado dispositivos ni servicios.**

### H01 — ESP32-01

- **HECHO VERIFICADO EN GITHUB:** commit `6d9aaaede5c6296de6d0fb8f9a655ca862c9e937` (15/10, «fix: recuperar firmware HTTP original del ESP32-01») en la historia de `main` para `laboratorio-fisico/esp32/ESP32-01/ETH_MAC_DHCP_StaticIP.ino`.
- La versión publicada contiene MAC leída por `esp_read_mac`, DHCP con `Ethernet.begin(mac)`, servidor `EthernetServer(80)` y respuesta `HTTP/1.1 200 OK`. La discrepancia entre el firmware previamente versionado y la función de servidor indicada en README queda **RESUELTA DOCUMENTALMENTE Y EN CÓDIGO PUBLICADO**.
- Las respuestas HTTP y las pruebas cliente/monitor del 12/10 son **evidencias históricas**; no se ha reprogramado ni probado el ESP32-01 en vivo a raíz de este cambio. **Revalidación posterior en hardware: no acreditada.**
- La clasificación «H01 pendiente/sin intervenir» del informe R2 es **foto histórica desactualizada** respecto de la fuente publicada en `main`.

### H19 — Prioridad editorial del nuevo diseño Lenovo

- Corregidos encabezados y resúmenes de arquitectura y del índice del laboratorio virtual para señalar primero **PYME virtual Lenovo** como objetivo vigente desde el 15/10; la antigua réplica Pi4/MikroTik/switch/ESP32 permanece como **diseño histórico de 10/10**.
- El plan de auditoría del 13/10 queda expresamente marcado **histórico y parcialmente superado**; sus tareas relativas a H01 y las VMs de réplica no deben ejecutarse como si fueran la planificación actual. MEDION continúa independiente.

### Seguridad de publicación

- Reconciliado el documento `operacion/seguridad/REVISION-PUBLICACION.md` con el estado posterior del 15/10: repositorio **público**, ruleset `Proteccion-main` activo sobre `~DEFAULT_BRANCH` (main) con PR obligatorio y 0 revisiones, anti-borrado y anti-force-push; Gitleaks local documentado para **104 commits sin secretos detectados** bajo sus reglas.
- **No cerrar auditoría de seguridad global:** alertas GitHub Security, colaboradores/permisos, historial inalcanzable y exposición de servicios siguen pendientes. No confundir corrección documental con certificación operativa.

### Hallazgos no cerrados por este cambio

Siguen abiertos H04–H07, H09–H12, H14–H15, H17–H18 y H20–H22 en la medida indicada por el informe R2; H19 queda **resuelto en los índices principales**, sujeto a futuras revisiones de documentos históricos; H01 se cierra **en fuente publicada**, sin nueva prueba sobre hardware. El estado de Omada (Lenovo, migración VPS pendiente), conectividad VPS→SG2210P/EAP225 y aislamiento MEDION no se altera.

**Alcance efectivo:** documentación y GitHub exclusivamente. Sin cambios en red física, firmware desplegado, Lenovo/libvirt, MEDION, VPS, NetBox, Tailscale o producción.


---

## 2026-10-15 — Bridge `br-pyme` Lenovo operativo y auditoría de Omada

**Ámbito:** Lenovo ThinkPad L13 Gen 3, Linux Mint 22.3, extensión al laboratorio físico. Evidencia: comandos y resultados aportados por el usuario. El cambio GitHub solo documenta, no ejecuta configuración de red.

### Configuración y prueba — HECHOS VERIFICADOS EN LA SESIÓN

1. Se identificó la NIC USB-Ethernet `enx00e04c6808a2`; inicialmente con DHCP `192.168.88.237/24` y ruta default preferente hacia MikroTik. Wi-Fi Starlink `192.168.1.192/24`, gateway `192.168.1.1`.
2. Se creó `br-pyme` en NetworkManager mediante `nmcli connection add type bridge ifname br-pyme con-name br-pyme`, UUID `20409153-bc7e-44e3-95e5-4fe172dae4fd`. STP habilitado, filtrado VLAN desactivado, DHCP IPv4 y `ipv4.never-default yes`.
3. Se subordinó el perfil `Conexión cableada 1` al bridge y se activó. `bridge link show` mostró `enx00e04c6808a2 ... master br-pyme state learning`; la NIC dejó de tener IPv4, que pasó al bridge mediante DHCP como `192.168.88.236/24` (dinámica).
4. Durante la activación coexistieron default vía `192.168.88.1 dev br-pyme metric 425` y Starlink `192.168.1.1 dev wlp0s20f3 metric 600`. Tras `sudo nmcli device reapply br-pyme`, quedó **solo default IPv4 vía Starlink**.
5. `ping -c 4 -I br-pyme 192.168.88.1`: 4/4 respuestas, 0 % pérdidas, RTT min/avg/max 0,453/0,594/0,784 ms. **Demuestra host→MikroTik, no pruebas VM→LAN**.

### Comprobaciones adicionales

- `virsh net-list --all`: `default` y `LAB-NET` activas, autostart; mantenidas sin cambios. `virsh list --all`: **sin máquinas virtuales registradas**.
- Omada continúa en Lenovo: paquete `omadac` v6.3.0.45, unidad `tpeap.service` activa, instalación `/opt/tplink/EAPController`, MongoDB integrado en puerto `27217`, ~3,9 GB RAM y 234,1 MB swap atribuidos al servicio.
- **La migración Omada al VPS no ha comenzado**; no se ha detenido ni desinstalado el controlador, ni validado adopción desde VPS.

### Diferencias con el diseño anterior y próximos pasos

`br-pyme` **ya enlaza con la LAN física** mediante USB-Ethernet; el anterior objetivo de puente aislado con futura conexión ha quedado superado para el anfitrión. No hay VMs ni pruebas de aislamiento o VLAN adicional. Antes de crear y conectar Windows 11/OMV y CUPS, verificar políticas de red, DHCP/IPAM y riesgos. Omada debe migrarse con backup, restore, prueba de acceso SG2210P/EAP225 y rollback antes de desactivarlo en Lenovo. MEDION sigue separado. Persistencia de bridge/rutas tras reinicio no acreditada.

**CIERRE:** BRIDGE OPERATIVO / RUTA DEFAULT STARLINK CORRECTA / LIBVIRT SIN VMs / OMADA ACTIVO EN LENOVO / MIGRACIÓN PENDIENTE.


---

## 2026-10-15 — Conciliación de topología física con `br-pyme`

**Motivo:** tras el PR #15 se detectó que `laboratorio-fisico/topologia.md`, `laboratorio-fisico/README.md` y `arquitectura/arquitectura-general.md` seguían presentando el Lenovo como futura integración, a pesar de la prueba ya consignada del bridge físico.

- **DOCUMENTACIÓN ACTUALIZADA:** se añade el Lenovo L13 como equipo **físicamente conectado al SG2210P** mediante USB-Ethernet `enx00e04c6808a2` y `br-pyme`, con DHCP `192.168.88.236/24` y ping 4/4 al MikroTik `192.168.88.1` según la sesión técnica del 15/10.
- **PENDIENTE:** número de puerto real del SG2210P, persistencia tras reinicio y aislamiento/seguridad de las VM cuando existan. `br-pyme` no usa VLAN filtering; las máquinas virtuales Windows 11/OMV siguen sin crear. No se atribuye al Lenovo el puerto 6 Access VLAN20 ni la interfaz `ue0` del MEDION.
- **HISTÓRICO:** se conserva el cableado Raspberry Pi, MikroTik, EAP225, ESP32 y MEDION con fuentes y fechas previas, sin alterar sus relaciones.
- **ALCANCE:** solo corrección documental en GitHub; ningún cambio en equipos, switches, firewall, NetBox, Omada ni servicios.


---

## 2026-10-16 — Consolidación integral del README del Lenovo

- Se sustituyeron las tablas y el diagrama **obsoletos de la réplica del 10/10** por una arquitectura PYME actual, con tabla de componentes y estado, datos de red, recursos, secuencia vigente y antecedentes históricos separados.
- Se incorporó la configuración **verificada el 15/10** de `br-pyme` con USB-Ethernet `enx00e04c6808a2` enlazado al SG2210P, DHCP `192.168.88.236/24`, salida Starlink exclusiva y ping 4/4 hacia MikroTik.
- Se mantienen **0 VMs registradas**, Omada aún activo en Lenovo y migración al VPS pendiente; no se afirma segmentación VLAN ni validación de acceso desde VMs.
- Se distinguen los datos de almacenamiento/libvirt del **informe histórico 10/10** de las comprobaciones actuales; se marca como pendiente la identificación del puerto SG2210P del Lenovo.
- **Alcance:** solo documentación GitHub; no se alteraron redes, máquinas, servicios ni hardware.
