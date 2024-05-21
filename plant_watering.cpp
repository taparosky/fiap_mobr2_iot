const int soilMoisturePin = A0;  // Soil moisture sensor pin
const int pumpPin = 4;           // Water pump pin
const int ledPin = 12;          // LED pin

int moistureValue = 0; 
int thresholdValue = 500; // Ajuste baseado no solo e no sensor

void setup() {
  pinMode(pumpPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  moistureValue = analogRead(soilMoisturePin); 

  Serial.print("Valor da umidade: ");
  Serial.println(moistureValue);

  if (moistureValue > thresholdValue) {  
    digitalWrite(pumpPin, LOW);   // Desliga a bomba
    digitalWrite(ledPin, LOW);   // Desliga o LED
  } else {
    digitalWrite(pumpPin, HIGH);  // Liga a bomba
    digitalWrite(ledPin, HIGH);  // Liga o LED
  }
  delay(1000); // Checa a cada segundo
}
