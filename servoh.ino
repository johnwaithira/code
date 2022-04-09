
#include <Servo.h>

Servo myservo;  
int pos = 140;


void setup(void) {

  myservo.attach(11);
  myservo.write(90);
  delay(1000);
  myservo.write(140);
  delay(1000);
  myservo.write(20);
  delay(1000);
  myservo.write(90);
  
  
}


void loop(void)
{
  

   


}
