#include <SoftwareSerial.h>
// Create a SoftwareSerial object to communicate with the SIM800L module
SoftwareSerial mySerial(8, 7); // SIM800L Tx & Rx connected to Arduino pins #3 & #2
void setup()
{
  // Initialize serial communication with Arduino and the Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  // Initialize serial communication with Arduino and the SIM800L module
  mySerial.begin(9600);
  Serial.println("Initializing..."); 
  delay(1000);
  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();

  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
 mySerial.println("AT+CMGS=\"+63947XXXXXXX\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  mySerial.print("Test from Bubble Dryer"); //text content
  updateSerial();
  mySerial.write(26);
}
void loop()
{
}
void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read()); // Forward data from Serial to Software Serial Port
  }
  while (mySerial.available()) 
  {
    Serial.write(mySerial.read()); // Forward data from Software Serial to Serial Port
  }
}