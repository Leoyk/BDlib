#include"BDZT.h"
#include <Wire.h>
#include <Arduino.h>


#define ZTAddress 0X10  


long _AX,_AY,_AZ,_GX,_GY,_GZ,_MX,_MY,_MZ,_PRE,_LAT,_LON,_SEAH,_BDC,_SAT,_HDOP,_GSPD;






long dirAcc(long a){
  if(a > 17000)
  a =  -(65536 - a);

  
  if(a < -17000)
   a = -(65536 + a) ;

  return a;
  }




 void getIMUData(){
  int i = 0;//用于计数的变量
  unsigned int data[34];//用于缓存数据数据
 
	 
	 
  Wire.requestFrom(0X10, 34);   
  while (Wire.available()) { 
    data[i ++] = Wire.read(); // 缓存
  }

//将得到的数据进行运算
_AX = ((data[0] << 8)| data[1]);
_AY = ((data[2] << 8)| data[3]);
_AZ = ((data[4] << 8)| data[5]);
_AX = dirAcc(_AX);
_AY = dirAcc(_AY);
_AZ = dirAcc(_AZ);






_GX = ((data[6] << 8)| data[7]);
_GY = ((data[8] << 8)| data[9]);
_GZ = ((data[10] << 8)| data[11]);

_MX = ((data[12] << 8)| data[13]);
_MY = ((data[14] << 8)| data[15]);
_MZ = ((data[16] << 8)| data[17]);

_PRE = ((data[18] << 8)| data[19]);
_PRE += (65536 - 16384 - 4096);

_LAT = ((data[20] << 8)| data[21]);
_LON = ((data[22] << 8)| data[23]);
_SEAH = ((data[24] << 8)| data[25]);
_BDC =  ((data[26] << 8)| data[27]);
_SAT =  ((data[28] << 8)| data[29]);
_HDOP =  ((data[30] << 8)| data[31]);
_GSPD =  ((data[32] << 8)| data[33]);
}




int gateZ(){
	int a = 0;
	
	if(_AZ > 14000)//竖直向下
		a = 1;
	else  if(_AZ < -14000)
		a = -1;//竖直向上

	else a = 0;

	return a;
}


int gateX(){
	int a = 0;

	if(_AX > 13000)//竖直向下
		a = 1;
		
	else  if(_AX < -13000)
		a = -1;//竖直向上
    
	else a = 0;

return a;
}

int gateY(){
	int a = 0;
	if(_AY > 14000)//竖直向下
		a = 1;
	else  if(_AY < -14000)
		a = -1;//竖直向上
	
	else a = 0;

	return a;
}










long AXV(){
	return _AX;	
}

long AYV(){
	return _AY;	
}

long AZV(){
	return _AZ;	
}

long GXV(){
	return _GX;	
}

long GYV(){
	return _GY;	
}

long GZV(){
	return _GZ;	
}

long MXV(){
	return _MX;	
}

long MYV(){
	return _MY;	
}

long MZV(){
	return _MZ;	
}


long PREV(){
	return _PRE;	
}


















































