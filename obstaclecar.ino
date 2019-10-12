#include<Servo.h>

#define in1 2
#define in2 3
#define in3 4
#define in4 5

const int trigpin = 10;
const int echopin = 11;

long duration=0 ;
long distancecm=0 ;

int distanceright=0;
int distanceleft=0; 
int far=0;
//here we use harse of e car
Servo servo_test;  

void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

  pinMode(10,OUTPUT);
  pinMode(11,INPUT);
  Serial.begin(9600);
  

servo_test.attach(9);
}
void loop()
{
far = distance();
if(far<=20)
{
  Stop();
  delay(200);
  movebackward();
  delay(1000);
  Stop();
  delay(500);
 distanceright=seeright();
 delay(200);
 distanceleft=seeleft();
 delay(200);
 if(distanceright>=distanceleft)
 {
  moveright();
 }
 else
 {
  moveleft();
 }
}
 else
 {
 moveforward();
 delay(2000);
 Stop();
 delay(500);
 seeleft();
 delay(200);
 seeright();
 delay(200);
 }
}
int distance()
{
digitalWrite(trigpin,LOW);
delayMicroseconds(2);
digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin,LOW);

duration = pulseIn(echopin,HIGH);
distancecm = duration*0.034/2 ; //340m/s or 0.034cm/us
Serial.println(distancecm);
return distancecm;
}

int seeleft()
{
  int angle;
 for(angle=89;angle>=0;angle--)
 {
  servo_test.write(angle);
  delay(10);
 }
 distance();
 delay(100);
 for(angle=0;angle<89;angle++)
{
  servo_test.write(angle);
  delay(10);
 }
 delay(100);
}

int seeright()
{
  int angle;
for(angle=89;angle<178;angle++)
{
  servo_test.write(angle);
  delay(10);
}
 distance();
 delay(100);

for(angle=178;angle>=89;angle--)
{
  servo_test.write(angle);
  delay(10);
}
  delay(100);
}

void moveforward()
{
 digitalWrite(2,HIGH);
 digitalWrite(3,LOW);
 
 digitalWrite(4,HIGH);
 digitalWrite(5,LOW);

}
void movebackward()
{
 digitalWrite(2,LOW);
 digitalWrite(3,HIGH);
 
 digitalWrite(4,LOW);
 digitalWrite(5,HIGH);

}
void Stop()
{
 digitalWrite(2,LOW);
 digitalWrite(3,LOW);
 
 digitalWrite(4,LOW);
 digitalWrite(5,LOW);

}
void moveleft()
{
 digitalWrite(2,HIGH);
 digitalWrite(3,LOW);
 
 digitalWrite(4,LOW);
 digitalWrite(5,HIGH);

}
void moveright()
{
 digitalWrite(2,LOW);
 digitalWrite(3,HIGH);
 
 digitalWrite(4,HIGH);
 digitalWrite(5,LOW);
 
}
