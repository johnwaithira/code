#include <Servo.h>

Servo myservo;  
int pos_1 = 140, pos_2 = 20, pos_start = 90;

int URECHO = 3;         
int URTRIG = 2;        
 
int duration ,distance;
unsigned int DistanceMeasured = 0;

int swipeData = 0;

int dist = 100;


int E1 = 5;     //M1 Speed Control
int E2 = 6;     //M2 Speed Control
int M1 = 4;    //M1 Direction Control
int M2 = 7;    //M1 Direction Control

void stop(void)                    //Stop
{
  digitalWrite(E1,LOW);
  digitalWrite(E2,LOW);
}


void advance(char a,char b)          //Move forward
{
  analogWrite (E1,a);      //PWM Speed Control
  digitalWrite(M1,HIGH);
  analogWrite (E2,b);
  digitalWrite(M2,HIGH);
}
void back_off (char a,char b)          //Move backward
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);
  analogWrite (E2,b);
  digitalWrite(M2,LOW);
}
void turn_L (char a,char b)             //Turn Left
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);
  analogWrite (E2,b);
  digitalWrite(M2,HIGH);
}
void turn_R (char a,char b)             //Turn Right
{
  analogWrite (E1,a);
  digitalWrite(M1,HIGH);
  analogWrite (E2,b);
  digitalWrite(M2,LOW);
}




void setup()
{
  Serial.begin(9600);                       
  pinMode(URTRIG, OUTPUT);     
  digitalWrite(URTRIG, HIGH);                
  pinMode(URECHO, INPUT);
  digitalWrite (URTRIG ,LOW );
  delayMicroseconds(4);
  digitalWrite (URTRIG ,HIGH );
  delayMicroseconds(100);   
  myservo.attach(11);
  delay(100);   
  myservo.write(90);            
  delay(500);
  
  Serial.println("weCode .... ");

}


void loop()
{


  int distanceR = 0;
  int distanceL = 0;
  delay(100);
  Serial.println(distance_test());

  if(distance_test() < 50)
  {

      stop();
      delay(200);
      back_off(100, 100);
      delay(100);
      stop();
      distanceR = lookRight();
      delay(500);
      distanceL = lookLeft();
      delay(300);

      if(distanceR >= distanceL)
      {
        Serial.println("turn right");
        turn_R(100, 100);
        delay(500);
      }
      else
      {
       Serial.println("turn left"); 
        turn_L(100, 100);
        delay(500);
      }
          

    
  }
  else
  {
    advance(200, 200);
  }
  Serial.print("R ");
  Serial.println(distanceR);
  Serial.print("L ");
  Serial.println(distanceL);
  Serial.println(distance_test());
 
  
}

int distance_test()
{

  digitalWrite (URTRIG ,LOW );
  delayMicroseconds(4);
  digitalWrite (URTRIG ,HIGH );
  delayMicroseconds(100);
  
  digitalWrite (URTRIG,HIGH);
  
  duration=pulseIn (URECHO ,HIGH );
  
  distance =(duration *.0343)/2;

  return distance;

  
}

int lookRight()
{
  

  myservo.write(10);
  delay(500);
  digitalWrite (URTRIG ,LOW );
  delayMicroseconds(4);
  digitalWrite (URTRIG ,HIGH );
  delayMicroseconds(100);
  
  digitalWrite (URTRIG,HIGH);
  
  duration=pulseIn (URECHO ,HIGH );
  
  distance =(duration *.0343)/2;
  delay(100);
  myservo.write(90);

  return distance;
  
}

int lookLeft()
{


  myservo.write(170);
  delay(500);
  digitalWrite (URTRIG ,LOW );
  delayMicroseconds(4);
  digitalWrite (URTRIG ,HIGH );
  delayMicroseconds(100);
  
  digitalWrite (URTRIG,HIGH);
  
  duration=pulseIn (URECHO ,HIGH );
  
  distance =(duration *.0343)/2;
  delay(100);
  myservo.write(90);

  return distance;
  
}

