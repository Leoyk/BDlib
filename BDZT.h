#ifndef _BDZT_H
#define _BDZT_H

 void getIMUData();
 
 long AXV();
 long AYV();
 long AZV();
 
 long GXV();
 long GYV();
 long GZV();
 
 long MXV();
 long MYV();
 long MZV();
 
 
 long PREV();
 double PVH(double baseline);
 
 int gateX();
 int gateY();
 int gateZ();
 
/***************
u8 LAT[10];   //纬度
u8 LON[10];   //经度
u8 SAT[3];    //星数
u8 HDP[5];    //水平定位精度
u8 BDC[2];    //北斗星数
u8 SEA[7];    //海拔
u8 GSP[6];    //地面速率
u8 UTT[10];   //UTC时间
u8 UTD[10];   //UTC日期
*****************************/
 
double lonVal();
double latVal();
double HdpVal();
double SeaVal();
double GspVal();

long SatVal();
long BdcVal();

int sYY();
int sMM();
int sDD();
int sHH();
int sMI();
int sSS();
int sMC();

//转为弧度
double rad(double d);

//计算坐标间距
double CalGPSDistance(double lat1, double lng1, double lat2, double lng2);

//度分格式转度度格式
double DM2DD(double a);

//度度格式转度分格式
double DD2DM(double a);

//显示纬度
void showLAT(int z,int x,int y,double lat);

//显示经度
void showLON(int z,int x,int y,double lon);
#endif