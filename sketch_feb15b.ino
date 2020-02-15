#include<Servo.h>
const int trigPin = 5;
const int echoPin = 6;
Servo servo_test; 
// defines variables
int duration;
int distance;

int avg[3];

void setup()
{
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
servo_test.attach(7); 
}
void loop() 
{
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
for(int i=0;i<=2;i++)
{
  avg[i]=distance;
}
distance=(avg[0]+avg[1]+avg[2])/3;
Serial.print("Distance: ");
Serial.println(distance);
delay(1000);
if(distance<15)
{
  servo_test.write(0);
  delay(1000);
  servo_test.write(120);
  delay(1000);
  
}
}
