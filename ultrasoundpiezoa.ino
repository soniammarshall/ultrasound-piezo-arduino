/*This sketch will print out the distance to the nearest object
that the ultrasound module can detect.
It sends a pulse to the sensor to initiate a reading, then listens 
for a pulse to return.  The length of the returning pulse is 
proportional to the distance of the object from the sensor. 
       
The circuit: 
  * VCC connection of the sensor attached to +5V 
  * GND connection of the sensor attached to ground 
  * TRIG connection of the sensor attached to digital pin 2 
  * ECHO connection of the sensor attached to digital pin 4 

Source:
https://gist.github.com/flakas/3294829#file-hc-sr04-ino-L52

The piezo will emit sounds of different frequencies as
you move your hand in front of the ultrasound module.

Connect the piezo to pin 8.

*/

const int trigPin = 2;
const int echoPin = 4;
const int piezoPin = 8;

float prevCm = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float duration, cm;

  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  cm = microsecondsToCentimeters(duration);

  int note = (50 * cm) - 50;
  
  if (cm != prevCm) {
    Serial.print("Distance: ")
    Serial.print(cm);
    Serial.print("cm\t");
    Serial.print(Frequency:);
    Serial.print(note);
    Serial.println("Hz");
  }
 
 boolean inRange = 0 < cm && cm < 40;
 
 if (inRange) {
        tone(piezoPin, note);
 } else {
        noTone(piezoPin);
 }
 
  prevCm = cm;

  delay(100);
  
}

float microsecondsToCentimeters(float microseconds)
{
  return microseconds / 29 / 2;
}

