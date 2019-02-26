#ifndef _BDLCD_H
#define _BDLCD_H
#include <Arduino.h>

void goToPage(int a);
void drawLine(char a1,unsigned int data);
void sendEnd();
void sendStart();
void send2YJ(String str);

void changeTxt(int id,String txt);//修订ID 字符串
void changeTxtColor(int id,long color);//修订字符串颜色

void showTxt(int id,char* txt);//在ID出显示“字符串 ”
void showTxtNum(int id,char* txt,double num);//在ID处显示“字符串”+数据
void setRange(double min,double max);//修订范围
#endif