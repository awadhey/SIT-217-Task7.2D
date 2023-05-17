#include <VirtualWire.h>

char *store;

char inputFBluetooth;     // to store input from the bluetooth.

void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  Serial.begin(9600);  
  set_txd_pin (3);
  vw_setup (2000);

  pinMode(5, LOW);
  pinMode(6, LOW);
  pinMode(10, LOW);
  pinMode(11, LOW);


void loop()
{
  while(Serial.available())
  {
    inputFBluetooth =Serial.read();
    Serial.println(inputFBluetooth);

    if(inputFBluetooth == 'F')
    {
      store="f";
      vw_send((uint8_t *)store, strlen (store)); //returns the length of store
      vw_wait_tx();
      forward();
    }

    else if (inputFBluetooth == 'R')
    {
      store="r";
      vw_send((uint8_t *)store, strlen (store));
      vw_wait_tx();//turn right (left side motors rotate in forward direction, right side motors doesn't rotate)

      right();
    }

    else if (inputFBluetooth== 'L')
    {
      store="l";
      vw_send((uint8_t *)store, strlen (store));
      vw_wait_tx();
      left();    
    }  

    else if (inputFBluetooth== 'G')
    {
      store="g";
      vw_send((uint8_t *)store, strlen (store));
      vw_wait_tx();
      backward();

    }  
    else if (inputFBluetooth== 'S')
    {
      store="s";
      vw_send((uint8_t *)store, strlen (store));
      vw_wait_tx();//STOP (all motors stop)
      stop();

    }  
  }
}  

void forward()
  {
  digitalWrite(6, LOW	);
  digitalWrite(5, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void stop()
  {
  digitalWrite(6, LOW	);
  digitalWrite(5, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

void backward()
  {
  digitalWrite(6, HIGH	);
  digitalWrite(5, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}

void right()
  {
  digitalWrite(6, HIGH	);
  digitalWrite(5, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void left()
  {
  digitalWrite(6, LOW	);
  digitalWrite(5, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}