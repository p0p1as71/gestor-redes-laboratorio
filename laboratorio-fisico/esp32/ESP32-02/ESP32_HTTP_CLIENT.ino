
#include <SPI.h>
#include <Ethernet_Generic.h>
#include <esp_mac.h>

// Pines del W5500 en Waveshare ESP32-S3-ETH
#define W5500_CS    14
#define W5500_RST    9
#define W5500_MISO  12
#define W5500_MOSI  11
#define W5500_SCK   13

byte mac[6];

IPAddress servidor(192, 168, 88, 245);
const uint16_t puertoHTTP = 80;

const unsigned long intervalo = 10000;
unsigned long ultimaConsulta = 0;

void consultarServidor() {
  EthernetClient cliente;

  Serial.println();
  Serial.println("Consultando ESP32-01...");

  if (!cliente.connect(servidor, puertoHTTP)) {
    Serial.println("ERROR: conexion TCP fallida");
    return;
  }

  cliente.println("GET / HTTP/1.1");
  cliente.println("Host: 192.168.88.245");
  cliente.println("Connection: close");
  cliente.println();

  unsigned long inicio = millis();

  while (cliente.connected() || cliente.available()) {
    while (cliente.available()) {
      Serial.write(cliente.read());
      inicio = millis();
    }

    if (millis() - inicio > 3000) {
      Serial.println("Tiempo de espera agotado");
      break;
    }

    delay(1);
  }

  cliente.stop();
  Serial.println();
  Serial.println("Consulta finalizada");
}

void setup() {
  Serial.begin(115200);
  delay(1500);

  Serial.println("ESP32-02 - Cliente HTTP");

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

  consultarServidor();
  ultimaConsulta = millis();
}

void loop() {
  if (millis() - ultimaConsulta >= intervalo) {
    ultimaConsulta = millis();
    consultarServidor();
  }
}
