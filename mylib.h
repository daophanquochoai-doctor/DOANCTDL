#include <conio.h>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <windows.h>
#include<thread>


void gotoxy(short x,short y)
{
        HANDLE hConsoleOutput;
        COORD Cursor_an_Pos = { x,y};
        hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}  

int wherex( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.X;
}

int wherey( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.Y;
}
void clreol( ) {
COORD coord;
DWORD written;
CONSOLE_SCREEN_BUFFER_INFO info;
GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
coord.X = info.dwCursorPosition.X;
coord.Y = info.dwCursorPosition.Y;
FillConsoleOutputCharacter (GetStdHandle(STD_OUTPUT_HANDLE), ' ',
  info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
gotoxy (info.dwCursorPosition.X + 1, info.dwCursorPosition.Y + 1);
}

void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void ShowConsoleCursor(bool showFlag)

{

    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);

    cursorInfo.bVisible = showFlag; // set the cursor visibility

    SetConsoleCursorInfo(out, &cursorInfo);

}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void Disable_Resize_Window(){
	HWND hWnd=GetConsoleWindow();
	SetWindowLong(hWnd,GWL_STYLE,GetWindowLong(hWnd,GWL_STYLE)& ~WS_SIZEBOX);
}

////////////////////////////////////////////// KEYBOARD /////////////////////////////////////////


const int LEFT = 75;
const int RIGHT = 77;
const int UP = 72;
const int DOWN = 80;
const int ENTER = 13;
const int BACKSPACE = 8;
const int ESC = 27;
const int DEL = 83;
const int INSERT = 82;
const int HOME = 96;
const int EDIT = 65; // f7
const int FINISH = 66;
const int F1 = 112;
const int F2 = 113;
const int F3 = 114;
//
//////////////////////////////////////////////// KEYBOARD ///////////////////////////////////////


//////////////////////////////////////////////// COLOR ///////////////////////////////////////
//

const int Black = 0;
const int Blue = 1;
const int Green = 2;
const int Aqua = 3;
const int Red = 4;
const int Purple = 5;
const int Yellow = 6;
const int White = 7;
const int Gray = 8;
const int Light_Blue = 9;
const char Light_Green = 'A';
const char Light_Aqua = 'B';
const char Light_Red = 'C';
const char Light_Purple = 'D';
const char Light_Yellow = 'E';
const char Bright_White = 'F';
//
//////////////////////////////////////////////// COLOR ///////////////////////////////////////

//////////////////////////////////////////////// MAX VALUE ///////////////////////////////////////
//

const int MAXCLASS = 200;
const int MAXSTUDENT = 24;
const int MAXSUBJECT = 10;
const int MAXTEST = 100;

const int MAX_LINE = 20;
const int MAX_CHAR_LINE1 = 46; // use for input question
const int MAX_CHAR_LINE2 = 84; // show short question
const int MAX_CHAR_LINE3 = 14; // use for input, id, name, etc.

const int MAX_CHAR_Q = 164; // max length string question
const int MAX_N_QUESTION = 100; // max number question
const int MAX_N_EXAM = 100;
//const int MAX_LINEQ = 

const int MAXID = 12;
const int MAXMIDDLE = 17;
const int MAXNAME = 7;
const int N_OPTION = 4;
const int MAX_WAIT_TIME = 15;
//
//////////////////////////////////////////////// MAX VALUE ///////////////////////////////////////

//////////////////////////////////////////////// SIZE ///////////////////////////////////////
//

const int VERTICAL1 = 40;
const int VERTICAL2 = 61;
const int VERTICAL3 = 91;
const int VERTICAL4 = 117;

const int BUTTON_WIDTH = 13;
const int BUTTON_HIGHT = 5;

const int ONLYNUM = 1;
const int ONLYLETTERS = 2;
const int MIX = 3;

//////////////////////////////////////////////// SIZE ///////////////////////////////////////

//////////////////////////////////////////////// TREE ///////////////////////////////////////
//

const int RH = 1;		// cay con phai cao hon (RIGHT HIGHT)
const int EH = 0;		// 2 cay con bang nhau (EQUAL HIGHT)
const int LH = -1;	// cay con trai cao hon (LEFT HIGHT)

//
//////////////////////////////////////////////// TREE ///////////////////////////////////////
