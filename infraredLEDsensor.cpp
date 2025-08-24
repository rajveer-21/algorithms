const int ledPin = 13;
#define IR_SENSOR 7
void setup() 
{
  pinMode(IR_SENSOR, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
}

void loop() 
{
  int sensorState = digitalRead(IR_SENSOR);
  digitalWrite(ledPin, LOW);
  if(sensorState == LOW)
  {
    Serial.println("object detected!");
    digitalWrite(ledPin, HIGH);
  }
  if(sensorState == HIGH)
  digitalWrite(ledPin , LOW);
  delay(500);
}
