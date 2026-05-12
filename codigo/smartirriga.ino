int rele = 7;

void setup() {
  pinMode(rele, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  Serial.println("Umidade: 75%");
  Serial.println("MQTT: horta/irrigacao");

  digitalWrite(rele, HIGH);
  delay(2000);

  digitalWrite(rele, LOW);
  delay(2000);
}
