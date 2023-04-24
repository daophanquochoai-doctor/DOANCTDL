#include "mylib.h"

using namespace std;

//ke khung rong
void show_rectangle( int x, int y, int width, int height, int color )
{
	SetColor(color);
	gotoxy(x,y);
	cout << char(201);
	gotoxy(x, y+height);
	cout << char(200);
	gotoxy(x+width, y+height);
	cout << char(188);
	gotoxy(x+width, y);
	cout << char(187);
	for( int i = 1 ; i < width ; i++ )
	{
		gotoxy(x+i, y);
		cout << char(205);
	}
	for( int i = 1 ; i < width ; i++ )
	{
		gotoxy(x+i, y+ height);
		cout << char(205);
	}
	for( int i = 1 ; i < height ; i++ )
	{
		gotoxy(x, y + i);
		cout << char(186);
	}
	for( int i = 1 ; i < height ; i++ )
	{
		gotoxy(x + width, y + i);
		cout << char(186);
	}
	SetColor(White);
}

//ke khung khong rong
void color_rectangle(int x, int y, int width, int height, int color)
{
	SetBGColor(color);
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width - 1; j++)
		{
			gotoxy(x + j, y + i); cout << " ";
		}
		gotoxy(x + 1, y + i) ; cout << " ";
	}
	SetBGColor(Black);
}

// in tittle
void show_tittle( int x, int y)
{
	gotoxy(x,y);
	cout << " _______ __     __   _______                    _______         __     __                   \n";
	gotoxy(x,y+1);
	cout << "|_     _|  |--.|__| |_     _|.----.---.-.----.  |    |  |.-----.|  |--.|__|.-----.--------. \n";
	gotoxy(x,y+2);
	cout << "  |   | |     ||  |   |   |  |   _|  _  |  __|  |       ||  _  ||     ||  ||  -__|        | \n";
	gotoxy(x,y+3);
	cout << "  |___| |__|__||__|   |___|  |__| |___._|____|  |__|____||___  ||__|__||__||_____|__|__|__| \n";
	gotoxy(x,y+4);
	cout << "                                                        |_____|							 \n";
}

//them tu vao dia chi
void insert_title(int x,int y,int color,int bgcolor, int width, int hight, string title)
{
	SetColor(color);
	SetBGColor(bgcolor);
	gotoxy(x + (width- title.length())/2 ,y + (hight - 1)/2);
	cout << title;
	SetColor(White);
	SetBGColor(Black);
}
