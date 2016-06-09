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

const int i = 20;

/*int notes[i] = {
  262, 277, 294, 311, 330, 349, 370, 392, 415, 440,
  466, 494, 523, 554, 587, 622, 659, 698, 740, 784
};*/

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

  if (cm != prevCm) {
    Serial.print("%4.1f", cm);
    Serial.print("cm");
    Serial.println();
  }
 
 int note;
 
  
  prevCm = cm;

  delay(100);
  
}

float microsecondsToCentimeters(float microseconds)
{
  return microseconds / 29 / 2;
}

