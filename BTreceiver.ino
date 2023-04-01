#include <SoftwareSerial.h>

SoftwareSerial BTSerial(0, 1); // RX | TX

void setup()
{
  pinMode(9, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(9, HIGH);
  Serial.begin(115200);
  Serial.println("Enter AT commands:");
  BTSerial.begin(38400);  // HC-05 default speed in AT command more

  BTSerial.println("AT+ORGL");  //reset
  delayAndRead();
  BTSerial.println("AT+ROLE=1");  //set to master
  delayAndRead();
  BTSerial.println("AT+RESET");   //clear mem
  delayAndRead();
  BTSerial.println("AT+INIT");    //initialize
  delayAndRead();
  BTSerial.println("AT+INQ");     //MAC adddress
  delayAndRead();
  Serial.print("bind");
  BTSerial.println("AT+BIND=943c,c6,3877f6");//bind
  delayAndRead();
  Serial.print("pair");
  BTSerial.println("AT+PAIR=943c,c6,3877f6,20");//controller 1 MAC, 20 second timeout
  delay(15000); //paring takes a long time
  delayAndRead();
  Serial.print("link");
  BTSerial.println("AT+LINK=943c,c6,3877f6");//connect
  delayAndRead();
  BTSerial.println("AT+STATE");//start data stream
}

void loop()
{
  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BTSerial.available())
    Serial.write(BTSerial.read());

  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
    BTSerial.write(Serial.read());
}

void delayAndRead(){
  delay(5000);
  if (BTSerial.available())
    Serial.write(BTSerial.read());
}
