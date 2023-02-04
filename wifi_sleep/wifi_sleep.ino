#include <WiFi.h>
#include <WiFiMulti.h>

#define uS_TO_S_FACTOR 1000000
#define TIME_TO_SLEEP 5

WiFiMulti WiFiMulti;

void setup() {
  Serial.begin(115200);

  delay(10);

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
  const char* host = "192.168.1.17";

  Serial.print("Connecting to ");
  Serial.println(host);

  WiFiClient client;

  if (!client.connect(host, port)) {
    Serial.println("Connection failed.");
    Serial.println("Waiting 5 seconds before retrying...");
    delay(5000);
    return;
  }

  Serial.println("Server connected, sending message.");
  client.print("nya");
  Serial.println("Message sent.");

  // int maxloops = 0;

  // while (!client.available() && maxloops < 1000) {
  //   maxloops++;
  //   delay(1);  //delay 1 msec
  // }

  // if (client.available() > 0) {

    Serial.println("Reading response from server.");
    String line = client.readStringUntil('\n');
    Serial.print("The message reads: ");
    Serial.println(line);
  // } else {
  //   Serial.println("client.available() timed out ");
  // }

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
