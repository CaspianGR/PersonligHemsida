void setup() {
    Serial.begin(115200); // Start the Serial communication
    Serial.println("Tufty 2040 Example");
}

void loop() {
    Serial.println("Hello, Tufty 2040!");
    delay(1000); // Wait for a second
}
