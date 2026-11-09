//Grphic.h
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <graphics.h>
#include <vector>
#include <direct.h>
#include <fstream>
#include <ctime>
#include <mmsystem.h>
#include <thread>
#include <map>

using namespace std;
bool isButtonDown(int ButtonType,int left,int top,int right,int down,MOUSEMSG MouseMsg) {
	if (MouseMsg.x >= left && MouseMsg.x <= right && MouseMsg.y >= top && MouseMsg.y <= down && MouseMsg.uMsg == UINT(ButtonType)) {
		return true;
	}
	return false;
}
bool button(int ButtonType,int left,int top,int right,int down,string text,MOUSEMSG MouseMsg,int colorRed = 10,int colorBlue = 100,int colorGreen = 5) {
	if (MouseMsg.x >= left && MouseMsg.x <= right && MouseMsg.y >= top && MouseMsg.y <= down) {
		setfillcolor(RGB(colorRed,colorGreen,colorBlue));
		fillrectangle(left,top,right,down);
		setfillcolor(RGB(255,255,255));
	}
	rectangle(left,top,right,down);
	outtextxy(left+4,top+4,text.c_str());
	if (isButtonDown(ButtonType,left,top,right,down,MouseMsg)) {
		return 1;
	}
	return 0;
}
void logIn(ofstream& log,int logLevel,string message) {
	std::time_t currentTimestamp = std::time(nullptr);
    const std::tm* localTime = std::localtime(&currentTimestamp);
    if (localTime == nullptr) {
        std::cerr << "转换本地时间失败！"  << std::endl;
        return;
    }
    int year = localTime->tm_year + 1900;
    int month = localTime->tm_mon + 1;
    int day = localTime->tm_mday;
    int hour = localTime->tm_hour;
    int minute = localTime->tm_min;
    int second = localTime->tm_sec;
    log<<year<<"-"<<month<<"-"<<day<<" "<<hour<<":"<<minute<<":"<<second;
	string loglv;
	switch(logLevel) {
		case -1:loglv="DEBUG";break;
		case 0:loglv="INFO";break;
		case 1:loglv="WARNING";break;
		case 2:loglv="ERROR";break;
	}
	log<<" ["<<loglv<<"] "<<message<<endl<<endl;
}
