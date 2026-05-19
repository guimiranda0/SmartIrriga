#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

#define RELAY_PIN 23

void callback(char* topic, byte* payload, unsigned int length) {

  String mensagem = "";

  for (int i = 0; i < length; i++) {
    mensagem += (char)payload[i];
  }

  Serial.print("Mensagem recebida: ");
  Serial.println(mensagem);

  if (mensagem == "LIGAR") {
    digitalWrite(RELAY_PIN, LOW);
  }

  if (mensagem == "DESLIGAR") {
    digitalWrite(RELAY_PIN, HIGH);
  }
}

void conectarWiFi() {

  Serial.println("Conectando no WiFi");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado!");
}

void conectarMQTT() {

  while (!client.connected()) {

    Serial.println("Conectando ao MQTT...");

    if (client.connect("ESP32_WOKWI")) {

      Serial.println("MQTT conectado!");

      client.subscribe("horta/irrigacao");

      Serial.println("Inscrito no tópico!");

    } else {

      Serial.print("Falha MQTT: ");
      Serial.println(client.state());

      delay(2000);
    }
  }
}

void setup() {

  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH);

  conectarWiFi();

  client.setServer(mqtt_server, 1883);

  client.setCallback(callback);

}

void loop() {

  if (!client.connected()) {
    conectarMQTT();
  }

  client.loop();
}
