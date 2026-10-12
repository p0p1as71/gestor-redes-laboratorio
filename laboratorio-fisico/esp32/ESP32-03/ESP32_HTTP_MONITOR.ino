
#include <SPI.h>
#include <Ethernet_Generic.h>
#include <esp_mac.h>

// Waveshare ESP32-S3-ETH + W5500
#define W5500_CS    14
#define W5500_RST    9
#define W5500_MISO  12
#define W5500_MOSI  11
#define W5500_SCK   13

byte mac[6];

IPAddress servidor(192, 168, 88, 245);
const uint16_t puertoHTTP = 80;

const unsigned long intervalo = 10000;
const unsigned long timeoutHTTP = 3000;

unsigned long ultimaConsulta = 0;
unsigned long correctas = 0;
unsigned long fallidas = 0;

void comprobarHTTP() {
  EthernetClient cliente;

  unsigned long inicio = millis();

  Serial.println();
  Serial.println("Comprobando ESP32-01...");

  if (!cliente.connect(servidor, puertoHTTP)) {
    fallidas++;
    Serial.println("Estado: OFFLINE (conexion TCP fallida)");
    return;
  }

  cliente.println("GET / HTTP/1.1");
  cliente.println("Host: 192.168.88.245");
  cliente.println("Connection: close");
  cliente.println();

  char primeraLinea[64];
  size_t longitud = 0;
  bool lineaCompleta = false;

  unsigned long inicioEspera = millis();

  while (millis() - inicioEspera < timeoutHTTP) {
    if (cliente.available()) {
      char c = cliente.read();

      if (c == '\n') {
        lineaCompleta = true;
        break;
      }

      if (c != '\r' && longitud < sizeof(primeraLinea) - 1) {
        primeraLinea[longitud++] = c;
      }
    } else if (!cliente.connected()) {
      break;
    }

    delay(1);
  }

  primeraLinea[longitud] = '\0';

  unsigned long tiempoRespuesta = millis() - inicio;

  bool correcto = lineaCompleta &&
                  strncmp(primeraLinea, "HTTP/1.1 200", 12) == 0;

  if (correcto) {
    correctas++;
    Serial.println("Estado: ONLINE");
  } else {
    fallidas++;
    Serial.println("Estado: OFFLINE / HTTP incorrecto");
  }

  Serial.print("Respuesta: ");
  Serial.println(primeraLinea);

  Serial.print("Tiempo de respuesta: ");
  Serial.print(tiempoRespuesta);
  Serial.println(" ms");

  Serial.print("Correctas: ");
  Serial.print(correctas);

  Serial.print(" | Fallidas: ");
  Serial.println(fallidas);

  cliente.stop();
}

void setup() {
  Serial.begin(115200);
  delay(1500);

  Serial.println("ESP32-03 - Monitor HTTP");

  esp_read_mac(mac, ESP_MAC_ETH);

  SPI.begin(W5500_SCK, W5500_MISO, W5500_MOSI, W5500_CS);

  pinMode(W5500_RST, OUTPUT);
  digitalWrite(W5500_RST, LOW);
  delay(100);
  digitalWrite(W5500_RST, HIGH);
  delay(100);

  Ethernet.init(W5500_CS);

  if (Ethernet.begin(mac) == 0) {
    Serial.println("ERROR: DHCP fallido");
    return;
  }

  Serial.print("IP asignada: ");
  Serial.println(Ethernet.localIP());

  comprobarHTTP();
  ultimaConsulta = millis();
}

void loop() {
  if (millis() - ultimaConsulta >= intervalo) {
    ultimaConsulta = millis();
    comprobarHTTP();
  }
}
