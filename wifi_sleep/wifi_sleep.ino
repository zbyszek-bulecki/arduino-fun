#include <WiFi.h>
#include <WiFiMulti.h>

#define uS_TO_S_FACTOR 1000000
#define TIME_TO_SLEEP 5

WiFiMulti WiFiMulti;

void setup() {
  Serial.begin(115200);

    delay(10);

  // We start by connecting to a WiFi network
  WiFiMulti.addAP("Pancernik", "KawkaKawusia@2k21");

  Serial.println();
  Serial.println();
  Serial.print("Waiting for WiFi... ");

  while (WiFiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  const uint16_t port = 3000;
  const char* host = "192.168.1.17";  // ip or dns

  Serial.print("Connecting to ");
  Serial.println(host);

  WiFiClient client;

  if (!client.connect(host, port)) {
    Serial.println("Connection failed.");
    Serial.println("Waiting 5 seconds before retrying...");
    delay(5000);
    return;
  }

  client.print("nya");

  int maxloops = 0;

  if (client.available() > 0) {
    String line = client.readStringUntil('\r');
    Serial.println(line);
  } else {
    Serial.println("client.available() timed out ");
  }

  Serial.println("Closing connection.");
  client.stop();
  Serial.println("Waiting 5 seconds before restarting...");
  delay(5000);


  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  Serial.println("ESP32 is going to sleep now ;-)");
  Serial.flush();
  esp_deep_sleep_start();
}

void loop() {
  //This is not going to be called
}
