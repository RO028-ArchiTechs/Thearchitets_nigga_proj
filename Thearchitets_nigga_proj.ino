#include <IRremote.h>

#define M1P1 2
#define M1P2 3
#define M2P1 4
#define M2P2 5

#define SP1 9
#define SP2 10

bool state_m1 = false;
bool state_m2 = false;

// false backwards
// true forwards


void setup() 
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(M1P1, OUTPUT);
  pinMode(M1P2, OUTPUT);
  pinMode(M2P1,   OUTPUT);
  pinMode(M2P2, OUTPUT);

  pinMode(9,   OUTPUT); 
  pinMode(10, OUTPUT);
}

void change_dir_m1()
{
  if(state_m1)
  {
    digitalWrite(M1P1, HIGH);
    digitalWrite(M1P2, LOW);
  }
  if(!state_m1)
  {
    digitalWrite(M1P1, LOW);
    digitalWrite(M1P2, HIGH);
  }

  state_m1 ^= 1;
}

void change_dir_m2()
{
  if(state_m2)
  {
    digitalWrite(M2P1, HIGH);
    digitalWrite(M2P2, LOW);
  }
  if(!state_m2)
  {
    digitalWrite(M2P1, LOW);
    digitalWrite(M2P2, HIGH);
  }

  state_m2 ^= 1;
}

void forward_move(int _speed) // in one timpi
{
  if(!state_m1) change_dir_m1();
  if(!state_m2) change_dir_m2();

  analogWrite(SP1, _speed);
  analogWrite(SP2, _speed);
}


void back_move(int _speed) // in one timpi
{
  if(state_m1) change_dir_m1();
  if(state_m2) change_dir_m2();

  analogWrite(SP1, _speed);
  analogWrite(SP2, _speed);
}

void left_move(int _speed) // in one timpi
{
  if(!state_m1) change_dir_m1();
  if(state_m2) change_dir_m2();

  analogWrite(SP1, _speed);
  analogWrite(SP2, _speed);
}

void right_move(int _speed) // in one timpi
{
  if(state_m1) change_dir_m1();
  if(!state_m2) change_dir_m2();

  analogWrite(SP1, _speed);
  analogWrite(SP2, _speed);
}

void loop() 
{
  Serial.write("Hello?\n");
  digitalWrite(LED_BUILTIN, HIGH);
  delay(50);
  digitalWrite(LED_BUILTIN, LOW);
  delay(50);


  for(int i = 0;i < 500;i++)
  {
    forward_move(i);
    delay(100);
  }

  for(int i = 500;i >= 0;i--)
  {
    forward_move(i);
    delay(100);
  }


  for(int i = 0;i < 500;i++)
  {
    back_move(i);
    delay(100);
  }

  for(int i = 500;i >= 0;i--)
  {
    back_move(i);
    delay(100);
  }


  for(int i = 0;i < 500;i++)
  {
    left_move(i);
    delay(100);
  }

  for(int i = 500;i >= 0;i--)
  {
    left_move(i);
    delay(100);
  }

  for(int i = 0;i < 500;i++)
  {
    right_move(i);
    delay(100);
  }

  for(int i = 500;i >= 0;i--)
  {
    right_move(i);
    delay(100);
  }

}
