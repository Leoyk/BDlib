#include"BDYT.h"
#include <Wire.h>
#include <Arduino.h>

#define YTAddress 0X50 

void setSerX(unsigned char dat)
{
	Wire.beginTransmission(YTAddress);//对lcdAddress设备进行控制
	Wire.write(0xfe);   
	Wire.write(1);   
	Wire.write(dat);      
	Wire.write(0xfe);  
	Wire.endTransmission(); //结束通讯
	
	Wire.beginTransmission(YTAddress);//对lcdAddress设备进行控制
	Wire.write(0xfe);   
	Wire.write(1);   
	Wire.write(dat);      
	Wire.write(0xfe);  
	Wire.endTransmission(); //结束通讯
}


void setSerY(unsigned char dat)
{
	Wire.beginTransmission(YTAddress);//对lcdAddress设备进行控制
	Wire.write(0xfe);   
	Wire.write(2);   
	Wire.write(dat);      
	Wire.write(0xfe);  
	Wire.endTransmission(); //结束通讯
	Wire.beginTransmission(YTAddress);//对lcdAddress设备进行控制
	Wire.write(0xfe);   
	Wire.write(2);   
	Wire.write(dat);      
	Wire.write(0xfe);  
	Wire.endTransmission(); //结束通讯
	
}
