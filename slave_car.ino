// SLAVE CAR


#include <VirtualWire.h>
char inputviaBT;
char *store;

void setup ()
{
  pinMode (5, OUTPUT); 
  pinMode (6, OUTPUT); 
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);

  Serial.begin(9600);

  set_rxd_pin(3);
  vw_setup (2000);
  pinMode(3,inputviaBT);
  start();
}

void loop()
{
  uint8_t buf[length_rx];
  uint8_t buflen=length_rx;
  Serial.println(buf[0]);
  if(vw_get_message(buf,&buflen)){
    if(buf[0]=='f')
    {
      forward();
    }
    else if(buf[0]=='g')
    {
      backward();
    }
    else if(buf[0]=='l')
    {
      left(); 
    }
    else if(buf[0]=='r')
    {
      right();  
    }
    else if(buf[0]=='s')
    { 
      stop(); 
    }
  }
}

void forward()
  {
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void stop()
  {
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

void backward()
  {
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}

void right()
  {
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void left()
  {
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}