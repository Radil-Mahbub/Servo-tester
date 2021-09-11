#include <Arduino.h>
#include <Servo.h>

Servo servo;

#define b1 6
#define b2 5
#define b3 4

#define pot A0
int val;

int pos = 0;

void setup() 
{
 servo.attach(9);
 
  for (int i=b1; i<=b3; i++)
  {
    pinMode (i, INPUT);
  }
}

void loop()
{
 zeroing();
 sweep();
 knob();
}

void zeroing() 
{
  
  int button = digitalRead(b1);

  if (button == HIGH)
  {
    servo.write (90);
    delay (10000);
  }

}

void sweep()
{
  int button2 = digitalRead (b2);

  if (button2 == HIGH)
  {
   
  for (pos = 0; pos <= 180; pos += 1) 
  { 
    servo.write(pos);  
    delay(15);            
   }
  
  for (pos = 180; pos >= 0; pos -= 1)
  { 
    servo.write(pos);  
    delay(15);                      
  }

  }
}

void knob()
{
  int button3 = digitalRead (b3);

  if (button3 == HIGH)
  {
  val = analogRead(pot);           
  val = map(val, 0, 1023, 0, 180); // scale it to use it with the servo (value between 0 and 180)
  servo.write(val);          
  delay(15); 
  }
}
