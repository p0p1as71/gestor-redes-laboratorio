# Redes libvirt — diseño y validación

| Red | Función documentada | Última constatación histórica | Pendiente |
|---|---|---|---|
| `default` | Segmento con NAT | Activa, persistente y autoinicio | XML, subred y rutas actuales |
| `lab-isolated` | Segmento interno | Activa, persistente y autoinicio | Confirmar aislamiento real |

## Diferencias relevantes

Una red *activa* solo indica que está disponible en libvirt. Una red *aislada* de nombre no certifica que el tráfico quede bloqueado. Validar topología, forwarding, interfaces, rutas, firewall y pruebas positivas/negativas desde un cliente.

## Matriz mínima de pruebas (PENDIENTE)

| Origen | Destino | Resultado esperado | Resultado observado |
|---|---|---|---|
| Cliente virtual LAN | OPNsense LAN | Según diseño de interfaz | Sin medir |
| Cliente virtual LAN | Internet | Según política NAT/firewall | Sin medir |
| Cliente virtual LAN | Red doméstica | Denegado, salvo autorización explícita | Sin medir |
| Anfitrión MEDION | Cliente virtual | Según política de administración | Sin medir |

**No suponer denegación** por el simple nombre `lab-isolated`. No modificar red `default` ni firewall del anfitrión sin evaluar dependencias.
