#include"BDLCD.h"
#include "BD12864.h"//控制0x45单色液晶
#include <Wire.h>



void goToPage(int a){

String sBuf = "page page" + (String)a; 

 sendStart();
 send2YJ(sBuf);
 sendEnd();
 }
 
 
 
 void drawLine(char a1,unsigned int data){

String sBuf = ""; 
	 
	 
sendStart();

switch(a1){
case 'B':sBuf = "add 1,0," + (String)data;break;
case 'Y':sBuf = "add 1,1," + (String)data;break;
case 'R':sBuf = "add 1,2," + (String)data;break;
case 'G':sBuf = "add 1,3," + (String)data;break;
default:break;
} 

send2YJ(sBuf);
sendEnd();
 }
 



void sendEnd(){

    Wire.beginTransmission(0x35);//对0x35设备进行控制
      Wire.write(0xff);    //发出学习指令 
      Wire.write(0xff);    //发出学习指令 
      Wire.write(0xff);    //发出学习指令 
     Wire.endTransmission(); //结束通讯
  }

void sendStart(){
delay(10);  
sendEnd();
delay(10); 
}

void send2YJ(String str){
	
   int sci = 0;
   
  if(str.length() < 32){
    Wire.beginTransmission(0x35);//对0x35设备进行控制
    for(sci = 0;sci < str.length();sci ++){     
      Wire.write(str[sci]);    //发出学习指令 
    }
     Wire.endTransmission(); //结束通讯
  }
   else if(str.length() < 64){
      Wire.beginTransmission(0x35);//对0x35设备进行控制
      for(sci = 0;sci < 32;sci ++){
       Wire.write(str[sci]);    //发出学习指令 
      }
       Wire.endTransmission(); //结束通讯
     Wire.beginTransmission(0x35);//对0x35设备进行控制
      for(sci = 32;sci < 64;sci ++){
       Wire.write(str[sci]);    //发出学习指令 
      }
       Wire.endTransmission(); //结束通讯
    }
}


char cbuf[32];
void changeTxt(int id,String txt){
	
String sBuf = "";


sBuf = "t" + (String)id + ".txt=\"" + txt + "\"";



 sendStart();
 send2YJ(sBuf);
 sendEnd();
}



void showTxt(int id,char* txt){
  String t = txt;
  changeTxt(id,t);
  }

void showTxtNum(int id,char* txt,double num){
  String t = txt + (String)num;
  changeTxt(id,t);
  }

  
  double minV,maxV,stepV;

void setRange(double min,double max){



double step = (max - min)/10;
double ii;
String sii;

minV = min;
maxV = max;
stepV = step;

for (int i = 0; i < 11; i ++){
  ii= min + i * step; 
  
 if((ii - (long)ii)  != 0){
   sii = (String)ii;
  }
 else
   sii = (String)((long)ii);
   
char cii[10];
 for(int j = 0;j < 10;j++){
   cii[j] = sii[j];
    }
  showTxt(i,cii);
  }
}