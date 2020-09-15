int trigPin = 6;    // Trigger
int echoPin = 12;    // Echo
long duration, cm, inches;
int speaker = 3;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(speaker, OUTPUT);
}
 
void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135

  //if the distance in cm is lower than 6, play a low pitched sound
  if (cm == 6){
      tone(speaker, 500);
      Serial.println();
      Serial.print("TOO CLOSE: ");
  }  else if (cm == 5){
      tone(speaker, 700);
      Serial.println();
      Serial.print("TOO CLOSE: ");
    
   } else if (cm == 4){
      tone(speaker, 900);
      Serial.println();
      Serial.print("TOO CLOSE: ");
   } else if (cm == 3){
      tone(speaker, 1100);
      Serial.println();
      Serial.print("TOO CLOSE: ");
   }else if (cm == 2){
      tone(speaker, 1300);
      Serial.println();
      Serial.print("TOO CLOSE: ");
   } else if (cm == 1){
      tone(speaker, 1500);
      Serial.println();
      Serial.print("TOO CLOSE: ");
   } else{
      noTone(speaker);
    
    }
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  Serial.println();
  
  delay(250);
  
}
