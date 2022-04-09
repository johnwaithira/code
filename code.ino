#include <Servo.h>

Servo myservo;  
int pos_1 = 140, pos_2 = 20, pos_start = 90;

int URECHO = 3;         
int URTRIG = 5;         

unsigned int DistanceMeasured = 0;

void setup()
{
  //Serial initialization
  Serial.begin(9600);                       
  pinMode(URTRIG, OUTPUT);                   
  digitalWrite(URTRIG, HIGH);                
  pinMode(URECHO, INPUT);     
  myservo.attach(11);   
  myservo.write(90);            
  delay(500);
  Serial.println("weCode .... ");

}
void loop()
{
  
  digitalWrite(URTRIG, LOW);
  digitalWrite(URTRIG, HIGH);              

  unsigned long LowLevelTime = pulseIn(URECHO, LOW) ;
  if (LowLevelTime >= 50000)              
  {
    Serial.println("Invalid");
  }
  else
  {
    DistanceMeasured = LowLevelTime / 50;
    if(DistanceMeasured <=20)
    {
     myservo.write(pos_1);
     delay(1000);
     myservo.write(pos_start);
     delay(1000);
     myservo.write(pos_2);
     delay(1000);
     myservo.write(pos_start);
     
     
     Serial.print("Distance=");
     Serial.print(DistanceMeasured);
     Serial.println("cm");   
    }
    
  }

  delay(200);
}
