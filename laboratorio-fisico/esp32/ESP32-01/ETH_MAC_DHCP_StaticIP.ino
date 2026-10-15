/**
 ******************************************************************************
 * @file     ETH_MAC_DHCP_StaticIP.ino
 * @brief    Initialize W5500 Ethernet module using DHCP with a static IP fallback.
 * @version  V1.0
 * @date     2025-07-03
 * @license  MIT
 * @copyright Copyright (c) 2025, Waveshare Electronics CO.,LTD
 *
 * Experiment Objective:
 * Demonstrate how to configure the W5500 Ethernet module via DHCP, and fallback 
 * to a static IP if DHCP fails.
 *
 * Hardware Resources:
 * 1. ESP32-S3-ETH
 *
 * Experiment Phenomenon:
 * 1. The W5500 module initializes via SPI with custom pin settings.
 * 2. Attempts to obtain an IP address via DHCP.
 * 3. If DHCP fails, uses a static IP as backup.
 * 4. Prints the assigned IP address to the serial console.
 *
 * Notes:
 * - Requires the Ethernet_Generic library or compatible W5500 Ethernet library.
 * - Be sure the W5500 module is properly connected to the MCU.
 *
 ******************************************************************************
 *
 * Development Platform: Arduino IDE / PlatformIO
 * Support Forum: service.waveshare.com
 * Company Website: www.waveshare.com
 *
 ******************************************************************************
 */

#include <SPI.h>
#include <Ethernet_Generic.h>  // Or Ethernet.h depending on installed library
#include <esp_mac.h>

// W5500 Pin Assignments
#define W5500_CS     14  // Chip Select (CS)
#define W5500_RST     9  // Reset (RST)
#define W5500_INT    10  // Interrupt (INT) - optional
#define W5500_MISO   12  // MISO
#define W5500_MOSI   11  // MOSI
#define W5500_SCK    13  // SPI Clock (SCK)

// MAC address (can be random but should be unique on the network)
byte mac[6];

// Ethernet client instance
EthernetClient client;

// HTTP server listening on TCP port 80
EthernetServer server(80);

void setup() {
  // Start serial communication
  Serial.begin(115200);
  Serial.println("BOOT OK");
  esp_read_mac(mac, ESP_MAC_ETH);

  // Initialize SPI with custom pins
  SPI.begin(W5500_SCK, W5500_MISO, W5500_MOSI, W5500_CS);

  // Optional: Reset the W5500 module
  pinMode(W5500_RST, OUTPUT);
  digitalWrite(W5500_RST, LOW);
  delay(100);
  digitalWrite(W5500_RST, HIGH);
  delay(100);

  // Initialize Ethernet with specified CS pin
  Ethernet.init(W5500_CS);

  // Configure Ethernet using DHCP only
  if (Ethernet.begin(mac) == 0) {
    Serial.println("DHCP failed.");
  }

  delay(1000);

  // Print the assigned IP address
  Serial.print("IP Address: ");
  Serial.println(Ethernet.localIP());
  server.begin();
  Serial.println("HTTP server started on port 80");
}

void loop() {

  EthernetClient client = server.available();

  if (client) {
    Serial.println("HTTP client connected");

    unsigned long startTime = millis();
    bool currentLineIsBlank = true;

    while (client.connected() && millis() - startTime < 2000) {
      if (client.available()) {
        char c = client.read();

        if (c == '\n' && currentLineIsBlank) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html; charset=UTF-8");
          client.println("Connection: close");
          client.println();
          client.println("<html><body>");
          client.println("<h1>ESP32-01 - Laboratorio de redes</h1>");
          client.println("<p>Servidor HTTP funcionando.</p>");
          client.println("</body></html>");
          break;
        }

        if (c == '\n') {
          currentLineIsBlank = true;
        } else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }
    }

    delay(1);
    client.stop();
    Serial.println("HTTP client disconnected");
  }
}
