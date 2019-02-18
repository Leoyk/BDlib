#include"BDZT.h"
#include <Wire.h>
#include <Arduino.h>

#include"BD12864.h"

#define ZTAddress 0X10  


long _AX,_AY,_AZ,_GX,_GY,_GZ,_MX,_MY,_MZ,_PRE;

double _LAT,_LON,_HDP,_SEA,_GSP;
long _SAT,_BDC,_UTYY,_UTMM,_UTDD,_UTHH,_UTMI,_UTSS,_UTMC;


#define fliterNumber 20


double smoothFliterAX(double newRcVal){//参数为元素个数
//创建滑动窗口数组并启用更新

  static double arr[fliterNumber];//窗口数组
  static double sum;//N个数值的总和
  double outVal;//滤波后的输出值
 
  sum = sum - arr[fliterNumber - 1];//去除最后一位的总和
  
  for(int i = fliterNumber - 1;i > 0;i --){
        arr[i]=arr[i - 1];//从最后一位开始向右滑动一次，最后一位被丢弃；
  }
  
  arr[0] = newRcVal;//首位存入新的数据
  
  sum = sum + arr[0];//新的总和
  
  outVal = sum / fliterNumber;//求算数平均值

 return outVal;
    }
	
	double smoothFliterAY(double newRcVal){//参数为元素个数
//创建滑动窗口数组并启用更新

  static double arr[fliterNumber];//窗口数组
  static double sum;//N个数值的总和
  double outVal;//滤波后的输出值
 
  sum = sum - arr[fliterNumber - 1];//去除最后一位的总和
  
  for(int i = fliterNumber - 1;i > 0;i --){
        arr[i]=arr[i - 1];//从最后一位开始向右滑动一次，最后一位被丢弃；
  }
  
  arr[0] = newRcVal;//首位存入新的数据
  
  sum = sum + arr[0];//新的总和
  
  outVal = sum / fliterNumber;//求算数平均值

 return outVal;
    }
	
	double smoothFliterAZ(double newRcVal){//参数为元素个数
//创建滑动窗口数组并启用更新

  static double arr[fliterNumber];//窗口数组
  static double sum;//N个数值的总和
  double outVal;//滤波后的输出值
 
  sum = sum - arr[fliterNumber - 1];//去除最后一位的总和
  
  for(int i = fliterNumber - 1;i > 0;i --){
        arr[i]=arr[i - 1];//从最后一位开始向右滑动一次，最后一位被丢弃；
  }
  
  arr[0] = newRcVal;//首位存入新的数据
  
  sum = sum + arr[0];//新的总和
  
  outVal = sum / fliterNumber;//求算数平均值

 return outVal;
    }
	double smoothFliterGX(double newRcVal){//参数为元素个数
//创建滑动窗口数组并启用更新

  static double arr[fliterNumber];//窗口数组
  static double sum;//N个数值的总和
  double outVal;//滤波后的输出值
 
  sum = sum - arr[fliterNumber - 1];//去除最后一位的总和
  
  for(int i = fliterNumber - 1;i > 0;i --){
        arr[i]=arr[i - 1];//从最后一位开始向右滑动一次，最后一位被丢弃；
  }
  
  arr[0] = newRcVal;//首位存入新的数据
  
  sum = sum + arr[0];//新的总和
  
  outVal = sum / fliterNumber;//求算数平均值

 return outVal;
    }
	
	double smoothFliterGY(double newRcVal){//参数为元素个数
//创建滑动窗口数组并启用更新

  static double arr[fliterNumber];//窗口数组
  static double sum;//N个数值的总和
  double outVal;//滤波后的输出值
 
  sum = sum - arr[fliterNumber - 1];//去除最后一位的总和
  
  for(int i = fliterNumber - 1;i > 0;i --){
        arr[i]=arr[i - 1];//从最后一位开始向右滑动一次，最后一位被丢弃；
  }
  
  arr[0] = newRcVal;//首位存入新的数据
  
  sum = sum + arr[0];//新的总和
  
  outVal = sum / fliterNumber;//求算数平均值

 return outVal;
    }
	double smoothFliterGZ(double newRcVal){//参数为元素个数
//创建滑动窗口数组并启用更新

  static double arr[fliterNumber];//窗口数组
  static double sum;//N个数值的总和
  double outVal;//滤波后的输出值
 
  sum = sum - arr[fliterNumber - 1];//去除最后一位的总和
  
  for(int i = fliterNumber - 1;i > 0;i --){
        arr[i]=arr[i - 1];//从最后一位开始向右滑动一次，最后一位被丢弃；
  }
  
  arr[0] = newRcVal;//首位存入新的数据
  
  sum = sum + arr[0];//新的总和
  
  outVal = sum / fliterNumber;//求算数平均值

 return outVal;
    }
	double smoothFliterMX(double newRcVal){//参数为元素个数
//创建滑动窗口数组并启用更新

  static double arr[fliterNumber];//窗口数组
  static double sum;//N个数值的总和
  double outVal;//滤波后的输出值
 
  sum = sum - arr[fliterNumber - 1];//去除最后一位的总和
  
  for(int i = fliterNumber - 1;i > 0;i --){
        arr[i]=arr[i - 1];//从最后一位开始向右滑动一次，最后一位被丢弃；
  }
  
  arr[0] = newRcVal;//首位存入新的数据
  
  sum = sum + arr[0];//新的总和
  
  outVal = sum / fliterNumber;//求算数平均值

 return outVal;
    }
	double smoothFliterMY(double newRcVal){//参数为元素个数
//创建滑动窗口数组并启用更新

  static double arr[fliterNumber];//窗口数组
  static double sum;//N个数值的总和
  double outVal;//滤波后的输出值
 
  sum = sum - arr[fliterNumber - 1];//去除最后一位的总和
  
  for(int i = fliterNumber - 1;i > 0;i --){
        arr[i]=arr[i - 1];//从最后一位开始向右滑动一次，最后一位被丢弃；
  }
  
  arr[0] = newRcVal;//首位存入新的数据
  
  sum = sum + arr[0];//新的总和
  
  outVal = sum / fliterNumber;//求算数平均值

 return outVal;
    }
	double smoothFliterMZ(double newRcVal){//参数为元素个数
//创建滑动窗口数组并启用更新

  static double arr[fliterNumber];//窗口数组
  static double sum;//N个数值的总和
  double outVal;//滤波后的输出值
 
  sum = sum - arr[fliterNumber - 1];//去除最后一位的总和
  
  for(int i = fliterNumber - 1;i > 0;i --){
        arr[i]=arr[i - 1];//从最后一位开始向右滑动一次，最后一位被丢弃；
  }
  
  arr[0] = newRcVal;//首位存入新的数据
  
  sum = sum + arr[0];//新的总和
  
  outVal = sum / fliterNumber;//求算数平均值

 return outVal;
    }



long dirAcc(long a){
  if(a > 16384*2)//2g
  a =  -(65536 - a);

  
  if(a < -16384*2)
   a = (65536 + a) ;

  return a;
  }
  
long dirGro(long a){
  if(a > 16384*2)//250
  a =  -(65536 - a);

  
  if(a < -16384*2)
   a = (65536 + a) ;

  return a;
  }
  
long dirMag(long a){
  if(a > 5000)//250
  a =  -(65535 - a);

;

  return a;
  }
  



 void getIMUData(){
  int i = 0;//用于计数的变量
  unsigned int data[46];//用于缓存数据数据
 
	 
	 
  Wire.requestFrom(0X10, 46);   
  while (Wire.available()) { 
    data[i ++] = Wire.read(); // 缓存
  }
  

    switch(data[21])
    {
        case 0:      
                  _LAT  = data[22] * 100 + data[23] + (double)data[24] / 100 + (double)data[25] / 10000;
                  _LON  = (double)data[26] * 1000 + data[27] * 10 + (double)data[28] / 10 + (double)data[29] / 1000;
                  _SAT  = data[30];
                  break;
        case 1:   
                  _HDP  = data[22] * 10 + (double)data[23] / 10;
                  _BDC  = data[24];
                  _SEA  = (double)data[25] * 1000 + data[26] * 10 + (double)data[27] / 10;
                  _GSP  = data[28] * 10 + (double)data[29] / 10;
                  break;
        case 2:      
				_UTYY = data[28];
				_UTMM = data[27];
				_UTDD = data[26];
				_UTHH = data[22];
				_UTMI = data[23];
				_UTSS = data[24];
				_UTMC = data[25];
                  break;  
    }

//将得到的数据进行运算
_AX = ((data[0] << 8)| data[1]);
_AY = ((data[2] << 8)| data[3]);
_AZ = ((data[4] << 8)| data[5]);

_AX = dirAcc(_AX);
_AY = dirAcc(_AY);
_AZ = dirAcc(_AZ); 

// _AX = smoothFliterAX(_AX);
// _AY = smoothFliterAY(_AY);
// _AZ = smoothFliterAZ(_AZ);

_GX = ((data[6] << 8)| data[7]);
_GY = ((data[8] << 8)| data[9]);
_GZ = ((data[10] << 8)| data[11]);

_GX = dirGro(_GX);
_GY = dirGro(_GY);
_GZ = dirGro(_GZ); 

// _GX = smoothFliterGX(_GX);
// _GY = smoothFliterGY(_GY);
// _GZ = smoothFliterGZ(_GZ);


_MX = ((data[13] << 8)| data[12]);
_MY = ((data[15] << 8)| data[14]);
_MZ = ((data[17] << 8)| data[16]);

// _MX = smoothFliterMX(_MX);
// _MY = smoothFliterMY(_MY);
// _MZ = smoothFliterMZ(_MZ);

_MX = dirMag(_MX);
_MY = dirMag(_MY);
_MZ = dirMag(_MZ);  

_PRE = ((data[18] << 8)| data[19]);

_PRE =  65536 + _PRE;
}

// Altitude =(44330.0 * (1.0-pow((float)(pressure) / 101325, 1.0/5.255)) ); 
double PVH(double baseline){
  
  double pre2;
  pre2 = (double)_PRE/baseline;
  pre2 = pow(pre2,0.19029496);
  
  return 44330*(1-pre2); 
}

int sYY(){
	return _UTYY;	
}
int sMM(){
	return _UTMM;	
}
int sDD(){
	return _UTDD;	
}
int sHH(){
	return _UTHH;	
}
int sMI(){
	return _UTMI;	
}
int sSS(){
	return _UTSS;	
}
int sMC(){
	return _UTMC;	
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
/*****************     GPS数据    ****************************/
double lonVal()
{
	return _LON;
}
double latVal()
{
	return _LAT;
}
double HdpVal()
{
	return _HDP;
}	
double SeaVal()
{
	return _SEA;
}
double GspVal()
{
	return _GSP;
}


long SatVal(){
	return _SAT;	
}
long BdcVal(){
	return _BDC;	
}






double rad(double d) {
    return d * PI / 180.0;
 }
 
double CalGPSDistance(double lat1, double lng1, double lat2, double lng2) {
    double radLat1 = rad(lat1);
    double radLat2 = rad(lat2);
    double a = radLat1 - radLat2;
    double b = rad(lng1) - rad(lng2);
    double s = 2 * asin(sqrt(pow(sin(a/2),2) +
     cos(radLat1)*cos(radLat2)*pow(sin(b/2),2)));
    s = s * 6371393;
    return s;
 } 




double DM2DD(double a){
  return (int)a/100 + fmod(a,100)/60;
  }
double DD2DM(double a){
  return (int)a*100 + (a -(int)a)*60;
  }

void showLAT(int z,int x,int y,double lat){

int lat_whole = lat/100;
double lat_decimal  =  (fmod(lat,100))/0.00006;
char L_H[3] = {'0','0'};
char L_D[8] = {'0','0','0','0','0','0'};
String buff = "";



  buff = (String)lat_decimal;
  for(int i = 0;i < 6;i ++){
    if(buff[i] == '.');
    else
      L_D[i] = buff[i];
    } 
    
  buff = (String)lat_whole;
  for(int i = 0;i < 4;i ++){
      L_H[i] = buff[i];
    } 

  
//显示在液晶上
  showStr(z,x,y,L_H); 
  showStr(z,x,y,".");  
  showStr(z,x,y,L_D);  
 }


 
void showLON(int z,int x,int y,double lon){

int lon_whole = (int)(lon)/100;
double lon_decimal  =  (fmod(lon,100))/0.00006;

//Serial1.println("*");
//Serial1.println(lon);
//Serial1.print(lon_whole);
//Serial1.print(".");
//Serial1.print(lon_decimal);
//Serial1.println("*");


char L_H[3] = {'0','0'};
char L_D[8] = {'0','0','0','0','0','0'};
String buff = "";



  buff = (String)lon_decimal;
  for(int i = 0;i < 6;i ++){
    if(buff[i] == '.');
    else
      L_D[i] = buff[i];
    } 
    
  buff = (String)lon_whole;
  for(int i = 0;i < 4;i ++){
      L_H[i] = buff[i];
    } 

  
//显示在液晶上
  showStr(z,x,y,L_H); 
  showStr(z,x,y,".");  
  showStr(z,x,y,L_D);  
 }









































