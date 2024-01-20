int relay_pin = 7;
void setup() {
  pinMode(relay_pin, OUTPUT);
}
void loop() {
  digitalWrite(relay_pin, HIGH);
  delay(10000);
  digitalWrite(relay_pin, LOW);
  delay(10000);
}