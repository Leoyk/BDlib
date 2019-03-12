#include"BDSC.h"
#include <Arduino.h>

#define GSMs Serial1
void SendMsgChar(char * PhoneNum,char *str)
{
  Serial.begin(115200);
  GSMs.begin(9600);
  delay(50);
  Serial.print((char)26);
  delay(50);
  
  GSMs.println("AT+CMGF=1");
  delay(50);
  while(GSMs.available())
  Serial.print((char)GSMs.read());
  
/*   GSMs.print("at+csca=\"");
  GSMs.print(CentreNum);
  GSMs.println("\""); */
  
  GSMs.println("AT+CSCS=\"GSM\"");
  delay(50);
  while(GSMs.available())
  Serial.print((char)GSMs.read());
  

  GSMs.println("AT+CMGF=1");
  delay(50);
  while(GSMs.available())
  Serial.print((char)GSMs.read());


  GSMs.print("AT+CMGS=\"");
  GSMs.print(PhoneNum);
  GSMs.println("\"");
  
  delay(50);
  while(GSMs.available())
  Serial.print((char)GSMs.read());
  
  GSMs.print(str);
  delay(300);
  
  
  
  
  GSMs.print((char)26);
  GSMs.println();
  delay(50);
  while(GSMs.available())
  Serial.print((char)GSMs.read());
}
void SendMsgNum(char * PhoneNum,int str)
{
  Serial.begin(115200);
  GSMs.begin(9600);
  delay(50);
  Serial.print((char)26);
  delay(50);
  
  GSMs.println("AT+CMGF=1");
  delay(50);
  while(GSMs.available())
  Serial.print((char)GSMs.read());
  
/*   GSMs.print("at+csca=\"");
  GSMs.print(CentreNum);
  GSMs.println("\""); */
  
  GSMs.println("AT+CSCS=\"GSM\"");
  delay(50);
  while(GSMs.available())
  Serial.print((char)GSMs.read());
  

  GSMs.println("AT+CMGF=1");
  delay(50);
  while(GSMs.available())
  Serial.print((char)GSMs.read());


  GSMs.print("AT+CMGS=\"");
  GSMs.print(PhoneNum);
  GSMs.println("\"");
  
  delay(50);
  while(GSMs.available())
  Serial.print((char)GSMs.read());
  
  GSMs.print(str);
  delay(300);
  
  
  
  
  GSMs.print((char)26);
  GSMs.println();
  delay(50);
  while(GSMs.available())
  Serial.print((char)GSMs.read());
}



















