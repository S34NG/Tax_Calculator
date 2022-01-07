/*
Note: Code here are copy some from Internet...
*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<stdlib.h>
#include<iomanip>
#include<cmath>
#include<ctype.h>
#include<windows.h>
#include<dir.h>
#include<string>
#include<fstream>
#include<string.h> 
#include<cctype> 
#include"bin\design.h"	// own header
using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

//Color
void color(int color){
	h;
	SetConsoleTextAttribute(h,color|FOREGROUND_INTENSITY);
}

//for get screenwidth
int getScreen(){
	h;
	CONSOLE_SCREEN_BUFFER_INFO csbi; //csbi = console screen buffer information
	GetConsoleScreenBufferInfo(h, &csbi);
	return csbi.srWindow.Right - csbi.srWindow.Left + 1;	
}

//FOR COORDINATE XY
void coordinate(int x, int y){
	h;
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(h,coord);
}

//DRAW
void line(int x, int y, int w, int color){ //x=coord x, y=coord y, w= width of line
	SetConsoleTextAttribute(h,color|FOREGROUND_INTENSITY);
	for(int i=0;i<w;i++){
		coordinate(x+i,y);
		cout<<(char)196;
	}
}

//EXIT Program
void exit(){
	exit(0);
}
