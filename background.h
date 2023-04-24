#include<iostream>
#include<string.h>
#include "ReadFile.h"
#include "clock.h"
char ky_tu_khung=177;
#define Y_TREN 3
#define Y_DUOI 33
#define X_TRAI 5
#define X_PHAI 125
#define NGANG_KHUNG 1000
#define DAI_KHUNG 650
#define LINE1 7
#define LINE2 11
#define COLUMN1 15
#define COLUMN2 45
#define COLUMN3 85
using namespace std;

string fileaccount = "Account.txt";
string fileaccountgv = "AccountGV.txt";

//ve khung login
void console_loggin()
{
	resizeConsole(1100, 630);
	system("cls");
	show_tittle(22,4);
	show_rectangle(1,1,130,32,Purple);
	show_rectangle(85,13,40,17, Purple);
	color_rectangle(86,14,40,3,Purple);
	insert_title(86,14,Aqua,Black,40,4," DANG NHAP ");
	show_rectangle(86,17,38,4,Purple);
	show_rectangle(86,22,38,4,Purple);
	SetColor(Blue);
	gotoxy(88, 19);
	cout << "User:";
	gotoxy(88, 24);
	cout << "Pass:";
	color_rectangle(96,27,20,3,Purple);
	insert_title(96,27,Aqua,Black,20,4,"LOGIN");
	SetColor(Green);
	gotoxy(85,31);
	cout << "*Vui long khong nhap ki tu";
	SetColor(White);
}
void Khung_Lop(){
	resizeConsole(NGANG_KHUNG,DAI_KHUNG);
	for(int y=Y_TREN;y<=Y_DUOI;y++){
		//SetBGColor(15);
		//SetColor(0);
		SetColor(15);
		for(int x=X_TRAI-1;x<=X_PHAI+1;x++){
 			if(y==Y_TREN||y==Y_DUOI||y==LINE1||y==LINE2){
				gotoxy(x,y);
				cout<<ky_tu_khung;
			}
			else if(x<=X_TRAI||x>=X_PHAI){
				gotoxy(x,y);
				cout<<ky_tu_khung;
			}
			if((x==COLUMN1||x==COLUMN2||x==COLUMN3)&&y>LINE1){
				gotoxy(x,y);
				cout<<ky_tu_khung;
			}
		}
	}
	gotoxy(60,5);
	cout<<"DANH SACH LOP";
	gotoxy(X_TRAI+(COLUMN1-X_TRAI)/2+2-3,LINE1+2);
	cout<<"STT";
	gotoxy(COLUMN1+(COLUMN2-COLUMN1)/2+2-6,LINE1+2);
	cout<<"MA LOP";
	gotoxy(COLUMN2+(COLUMN3-COLUMN2)/2+2-6,LINE1+2);
	cout<<"TEN LOP";
	gotoxy(COLUMN3+(X_PHAI-COLUMN3)/2+2-6,LINE1+2);
	cout<<"NIEN KHOA";
}


void Load_First(NODEPTRCH &root)
{
	Initlize(root);
	Read_File_CauHoi(root,filecauhoi);
}

void Display_Info_SV()
{
	show_rectangle(1,1,130,32,Purple);
	show_rectangle(2,2,128,5,Aqua);
	show_rectangle(3,8,10,3,Aqua);
	show_rectangle(3,12,10,20,Aqua);
	show_rectangle(15,8,60,3,Aqua);
	show_rectangle(15,12,60,20,Aqua);
	show_rectangle(76,8,30,3,Aqua);
	show_rectangle(76,12,30,20,Aqua);
	show_rectangle(107,8,22,3,Aqua);
	show_rectangle(107,12,22,20,Aqua);
	ShowConsoleCursor(0);
	gotoxy(10,4);
	cout << "TEN : ";
	gotoxy(70,4);
	cout << "GIOI TINH : ";
	gotoxy(10,5);
	cout << "MSSV : ";
	gotoxy(70,5);
	cout << "LOP : ";
}
 
void hienTHiCauHoi(CauHoi *dsCau, int total, int start)
{
	//khoi tao
	color_rectangle(4,7,71,20,Black);
	color_rectangle(78,7,9,20,Black);
	color_rectangle(89,7,9,20,Black);
	color_rectangle(100,7,9,20,Black);
	color_rectangle(111,7,9,20,Black);
	color_rectangle(122,7,9,20,Black);
	
	int i = 1;
	if( start > total )
	{
		//canh bao
	}
	else
	{
		for( int counter = start ; counter <= start+9 ; counter++ )
	{
		if( counter <= total )
		{
		gotoxy(7,5+(i)*2);
		cout << dsCau[counter].noidung;
		gotoxy(81,5+i*2);
		cout << dsCau[counter].A;
		gotoxy(92,5+i*2);
		cout << dsCau[counter].B;
		gotoxy(103,5+i*2);
		cout << dsCau[counter].C;
		gotoxy(114,5+i*2);
		cout << dsCau[counter].D;
		gotoxy(124,5+i*2);
		cout << dsCau[counter].dapan;
		i++;
		}
	}
	}
}

void In_Lai_Noi_Dung( string noidung )
{
	int x = 37, y = 13;
	for( int i = 0 ; i < noidung.length() ; i++ )
	{
		gotoxy(x++,y);
		cout << noidung[i];
		if( x == 94 && y != 20)
		{
			x = 37;
			y++;
		}
	}
}

string Nhap_Noi_Dung(NODEPTRCH &root, string mmh, int &number, int &x, int &y, string title, string &noidung)
{
 	color_rectangle(37,11,57,1,Black); //khoi tao
	color_rectangle(37,13,58,11,Black);
	ShowConsoleCursor(1);
	color_rectangle(39,11,10,1,Black);
 	insert_title(39,11,Red,Aqua,10,1,title);
	gotoxy(x,y);
	In_Lai_Noi_Dung(noidung);
	char kitu;
	while(true)
	{
		ShowConsoleCursor(1);
		kitu = getch();
		if( kitu == '\r' )
		{
			number++;
			break;
 		}            
	 	if( kitu == BACKSPACE )
		{
			if( x == 37 && y == 13 )
			{
				continue;
			}                
				if( x == 37 )
				{
					x = 94;
					y--;
				}
				gotoxy(--x,y);
				cout << " ";  
				noidung.erase(noidung.length()-1,1);
		}
		else if( kitu == ESC )
		{
			number = 7;
		 	break;
		}
		else if( kitu == DOWN )
		{
			gotoxy(--x,y);
			cout << " ";
			noidung.erase(noidung.length()-1,1);
			continue;
		}
		else if( kitu == UP )
		{
			gotoxy(--x,y);
			cout << " ";
			noidung.erase(noidung.length()-1,1);
			continue;
		}
		else if( kitu == LEFT)
		{
			gotoxy(--x,y);
			cout << " ";
			noidung.erase(noidung.length()-1,1);
			number--;
			break;
		}
		else if(kitu == RIGHT)
		{
			gotoxy(--x,y);
			cout << " ";
			noidung.erase(noidung.length()-1,1);
			number++;
			break;
		}
		else if( x != 37 || y != 24)
        {
        	noidung += kitu;
        	gotoxy(x++,y);
        	cout << kitu;
		}
		if(x == 94)
		{
			x=37;
			y++;	
		}
	}
	ShowConsoleCursor(0);
	return noidung;
 	 
}

void control_Sua_CauHoi(NODEPTRCH &root, string mmh)
{
	int x = 37, y = 13;
	int x1 = 37, y1 = 13;
	int x2 = 37, y2 = 13;
	int x3 = 37, y3 = 13;
	int x4 = 37, y4 = 13;
	int x5 = 37, y5 = 13;
	string noidung,A,B,C,D,dapan;
	string title;
	int number = 1;
	show_rectangle(35,10,60,15,Aqua);
 	show_rectangle(36,12,58,12,Aqua);
	while( number <= 6 )
	{
		if( number == 1 )
		{
			title = "NHAP NOI DUNG:";
			noidung = Nhap_Noi_Dung(root,mmh,number,x,y,title,noidung);
		}
		else if( number == 2 )
		{
			title = "NHAP DAP AN A:";
			A =  Nhap_Noi_Dung(root,mmh,number,x1,y1,title,A);
		}
		else if( number == 3 )
		{
			title = "NHAP DAP AN B:";
			B =  Nhap_Noi_Dung(root,mmh,number,x2,y2,title,B);
		}
		else if( number == 4 )
		{
			title = "NHAP DAP AN C:";
			C =  Nhap_Noi_Dung(root,mmh,number,x3,y3,title,C);
		}
		else if( number == 5 )
		{
			title = "NHAP DAP AN D:";
			D =  Nhap_Noi_Dung(root,mmh,number,x4,y4,title,D);
		}
		else if( number == 6 )
		{
			title = "NHAP DAP AN :";
			dapan =  Nhap_Noi_Dung(root,mmh,number,x5,y5,title,dapan);
		}
	}
	CauHoi cauhoi = Create_CauHoi(mmh,noidung,A,B,C,D,dapan);
	Insert_node(root, cauhoi);
}


void controldisPlaycauHoi(NODEPTRCH &root, string mmh, int &start,CauHoi *&dsCau, int &total)
{
	int kitu;
	int x = 3, y = 7;
	gotoxy(x,y);
	SetColor(Red);
	cout << "->";
	SetColor(White);
	while(true)
	{
		kitu = getch();
		switch( kitu )
		{
			case LEFT:
				{
			 	 	if( start - 10 >= 0 )
			 	 	{
			 	 		start -= 10;
		  			}
		  			return;
				}
			case RIGHT:
				{
					if( start + 10 <= total )
					{
						start += 10;
					}
					return;
				}
			case 'a':
					{
						ShowConsoleCursor(0);
						control_Sua_CauHoi(root,"toan");
						show_rectangle(35,10,60,15,Black);    //khoi tao console
					 	show_rectangle(36,12,58,12,Black);
						show_rectangle(2,2,72,25,Purple);
						show_rectangle(76,2,10,25,Purple);
						show_rectangle(87,2,10,25,Purple);
						start = 0;   
						return;
					}
		}
	}
}

void disPlaycauHoi(NODEPTRCH &root, string mmh, int start)
{
	show_rectangle(1,1,130,32,Purple);    // khung 
	show_rectangle(2,2,72,25,Purple);
	show_rectangle(76,2,10,25,Purple);
	show_rectangle(87,2,10,25,Purple);
	show_rectangle(98,2,10,25,Purple);
	show_rectangle(109,2,10,25,Purple);
	show_rectangle(120,2,10,25,Purple);
	
	color_rectangle(3,3,72,3,Aqua);                //tieu de
	color_rectangle(77,3,10,3,Aqua);
	color_rectangle(88,3,10,3,Aqua);
	color_rectangle(99,3,10,3,Aqua);
	color_rectangle(110,3,10,3,Aqua);
	color_rectangle(121,3,10,3,Aqua);
	insert_title(3,3,Red,Aqua,72,3," CAU HOI");             // title
	insert_title(77,3,Red,Aqua,10,3,"A");
	insert_title(88,3,Red,Aqua,10,3,"B");
	insert_title(99,3,Red,Aqua,10,3,"C");
	insert_title(110,3,Red,Aqua,10,3,"D");
	insert_title(121,3,Red,Aqua,10,3,"DAP AN");
	show_rectangle(2,28,128,4,Purple);    //chuc nang
	show_rectangle(4,29,11,2,Green);
	color_rectangle(5,30,11,1,Green);
	insert_title(5,30,White,Green,11,1,"F1 : SUA");
	show_rectangle(20,29,11,2,Green);
	color_rectangle(21,30,11,1,Green);
	insert_title(21,30,White,Green,11,1,"F2 : XOA");
	show_rectangle(36,29,12,2,Green);
	color_rectangle(37,30,12,1,Green);
	insert_title(37,30,White,Green,12,1,"A : THEM");
	show_rectangle(120,29,4,2,Green);   //nut prev
	color_rectangle(121,30,4,1,Green);
	insert_title(121,30,White,Green,4,1,"<"); 
	show_rectangle(125,29,4,2,Green);             // nut next
	color_rectangle(126,30,4,1,Green);
	insert_title(126,30,White,Green,4,1,">");
    ShowConsoleCursor(0);     
    int total;
    CauHoi *dsCau;  
	while(true)
	{      
		total = totalQues(root,mmh );
 		dsCau =	Create(root,total,mmh);
		hienTHiCauHoi(dsCau,total,start);
		controldisPlaycauHoi(root,mmh,start,dsCau,total);
	}
}


bool Check_Account( string user, string pass, string fileaccount )
{
	Init_DanhSach();
	Read_File_Account(fileaccount);
	bool check = false;
	acc p = NULL;
	switch( user[0] )
	{
		case 'a':
		case 'A':
			{
				p = A;
				break;
			}
		case 'b':
		case 'B':
			{
				p = B;
				break;
			}
		case 'c':
		case 'C':
			{
				p = C;
				break;
			}
		case 'd':
		case 'D':
			{
				p = D;
				break;
			}
		case 'e':
		case 'E':
			{
				p = E;
				break;
			}
		case 'f':
		case 'F':
			{
				p = F;
				break;
			}
		case 'g':
		case 'G':
			{
				p = G;
				break;
			}
		case 'h':
		case 'H':
			{
				p = H;
				break;
			}
		case 'i':
		case 'I':
			{
				p = I;
				break;
			}
		case 'j':
		case 'J':
			{
				p = J;
				break;
			}
		case 'k':
		case 'K':
			{
				p = K;
				break;
			}
		case 'l':
		case 'L':
			{
				p = L;
				break;
			}
		case 'm':
		case 'M':
			{
				p = M;
				break;
			}
		case 'n':
		case 'N':
			{
				p = N;
				break;
			}
		case 'o':
		case 'O':
			{
				p = O;
				break;
			}
		case 'p':
		case 'P':
			{
				p = P;
				break;
			}
		case 'q':
		case 'Q':
			{
				p = Q;
				break;
			}
		case 'r':
		case 'R':
			{
				p = R;
				break;
			}
		case 's':
		case 'S':
			{
				p = S;
				break;
			}
		case 't':
		case 'T':
			{
				p = T;
				break;
			}
		case 'u':
		case 'U':
			{
				p = U;
				break;
			}
		case 'v':
		case 'V':
			{
				p = V;
				break;
			}
		case 'w':
		case 'W':
			{
				p = W;
				break;
			}
		case 'x':
		case 'X':
			{
				p = X;
				break;
			}
		case 'y':
		case 'Y':
			{
				p = Y;
				break;
			}
		case 'z':
		case 'Z':
			{
				p = Z;
				break;
			}
	}
	while( p != NULL )
	{
		if( !user.compare(p->user) && !pass.compare(p->pass) )
		{
			check = true;
			break;
		}
		p = p->next;
	}
	return check;
}

void Insert_pass( string &pass, int &x, int &y )
{
	char kitu;
	gotoxy(x,y);
	ShowConsoleCursor(1);
	while (true) {
        kitu = getch();
        if( kitu == '\r' ) break;
        ShowConsoleCursor(0);
        if( kitu == BACKSPACE )
		{
			if( x == 94 )
			{
				ShowConsoleCursor(1);
				continue;
			}
				gotoxy(--x,y);
				cout << " ";
				pass.erase(pass.length()-1,1);
		}
		else if( kitu == ESC )	return;
		else if( kitu == DOWN )
		{
			gotoxy(--x,y);
			cout << " ";
			pass.erase(pass.length()-1,1);
			break;
		}
		else if( kitu == LEFT || kitu == RIGHT || kitu == UP )
		{
			gotoxy(--x,y);
			cout << " ";
			pass.erase(pass.length()-1,1);
			continue;
		}
		else if( kitu != ' ' && kitu != '|' && kitu != '\\' && kitu != '~' && kitu != '!' )
        {
        	pass += kitu;
        	gotoxy(x++,y);
        	cout << '*';
		}
    }
    color_rectangle(96,27,20,3,Light_Green);
	insert_title(96,27,Bright_White,Light_Green,20,4,"LOGIN");
}

void Insert_user( string &user,string &pass, int &x, int &y,int &v,int &t )
{
	gotoxy(x,y);
	char kitu;
	ShowConsoleCursor(1);
	while( true )
	{
		kitu = getch();
		if( kitu == '\r' ) break;
		ShowConsoleCursor(0);
		if( kitu == BACKSPACE )
		{
			if( x == 94 )
			{
				ShowConsoleCursor(1);
				continue;
			}
				gotoxy(--x,y);
				cout << " ";
				user.erase(user.length()-1,1);
		}
		else if( kitu == ESC )	return;
		else if( kitu == DOWN )
		{
			gotoxy(--x,y);
			cout << " ";
			user.erase(user.length()-1,1);
			break;
		}
		else if( kitu == UP || kitu == LEFT || kitu == RIGHT)
		{
			gotoxy(--x,y);
			cout << " ";
			user.erase(user.length()-1,1);
			continue;
		}
		else if( kitu != ' ' && kitu != '|' && kitu != '\\' && kitu != '~' && kitu != '!')
        {
        	user += kitu;
        	gotoxy(x++,y);
        	cout << kitu;
		}
	}
	Insert_pass(pass,v,t);
}

void Insert_Loggin( string &user, string &pass,int &x,int &y,int &v,int &t)
{
	Insert_user(user,pass,x,y,v,t);
}

//note
void Note_Acc( int x, int y, int width, int height, string note, int color,int &end)
{
	show_rectangle(x,y,width,height,color);
	color_rectangle(x+1,y+1,width,height-1,color);
	insert_title(x,y,color,Black,width,height+1,note);
	int key;
	key = getch();
	switch(key)
	{
		case ENTER: break;
		case ESC: end=0;
					break;
	}
}

void menuGV( string user )
{
	ShowConsoleCursor(0);
	show_tittle(22,4);
	show_rectangle(1,1,130,32,Purple);
	insert_title(45,10,Bright_White ,Black,40,4,"TEACHER : " + user);
	show_rectangle(45,12,40,4,White);
	color_rectangle(46,13,40,3,White);
	insert_title(45,12,Aqua,White,40,5,"XEM LOP");
	show_rectangle(45,17,40,4,Purple);
	insert_title(45,17,Red,Black,40,5,"XEM DIEM");
	show_rectangle(45,22,40,4,Purple);
	insert_title(45,22,Red,Black,40,5,"MONHOC");
	show_rectangle(45,27,40,4,Purple);
	insert_title(45,27,Red,Black,40,5,"THOAT");
	char catkey;
	int number = 1;
	while( true )
	{
		catkey = getch();
	switch(catkey)
	{
		case UP:
			{
				if( number == 1 )
				{
					number = 4;
					show_rectangle(45,12,40,4,Purple);
					color_rectangle(46,13,40,3,Black);
					insert_title(45,12,Red,Black,40,5,"XEM LOP");
					show_rectangle(45,27,40,4,White);
					color_rectangle(46,28,40,3,White);
					insert_title(45,27,Aqua,White,40,5,"THOAT");
					
				}
				else if( number == 2 )
				{
					number = 1;
					show_rectangle(45,12,40,4,White);
					color_rectangle(46,13,40,3,White);
					insert_title(45,12,Aqua,White,40,5,"XEM LOP");
					show_rectangle(45,17,40,4,Purple);
					color_rectangle(46,18,40,3,Black);
					insert_title(45,17,Red,Black,40,5,"XEM DIEM");
				}
				else if( number == 3 )
				{
					number = 2;
					show_rectangle(45,17,40,4,White);
					color_rectangle(46,18,40,3,White);
					insert_title(45,17,Aqua,White,40,5,"XEM DIEM");
					show_rectangle(45,22,40,4,Purple);
					color_rectangle(46,23,40,3,Black);
					insert_title(45,22,Red,Black,40,5,"MONHOC");
				}
				else if( number == 4 )
				{
					number = 3;
					show_rectangle(45,22,40,4,White);
					color_rectangle(46,23,40,3,White);
					insert_title(45,22,Aqua,White,40,5,"MONHOC");
					show_rectangle(45,27,40,4,Purple);
					color_rectangle(46,28,40,3,Black);
					insert_title(45,27,Red,Black,40,5,"THOAT");
				}
				break;
			}
		case DOWN:
			{
				if( number == 4 )	
				{
					number = 1;
					show_rectangle(45,27,40,4,Purple);
					color_rectangle(46,28,40,3,Black);
					insert_title(45,27,Red,Black,40,5,"THOAT");
					show_rectangle(45,12,40,4,White);
					color_rectangle(46,13,40,3,White);
					insert_title(45,12,Aqua,White,40,5,"XEM LOP");
				}
				else if( number == 1 )
				{
					number = 2;
					show_rectangle(45,12,40,4,Purple);
					color_rectangle(46,13,40,3,Black);
					insert_title(45,12,Red,Black,40,5,"XEM LOP");
					show_rectangle(45,17,40,4,White);
					color_rectangle(46,18,40,3,White);
					insert_title(45,17,Aqua,White,40,5,"XEM DIEM");
				}
				else if( number == 2 )
				{
					number = 3;
					show_rectangle(45,17,40,4,Purple);
					color_rectangle(46,18,40,3,Black);
					insert_title(45,17,Red,Black,40,5,"XEM DIEM");
					show_rectangle(45,22,40,4,White);
					color_rectangle(46,23,40,3,White);
					insert_title(45,22,Aqua,White,40,5,"MONHOC");
				}
				else if(number == 3)
				{
					number = 4;
					show_rectangle(45,22,40,4,Purple);
					color_rectangle(46,23,40,3,Black);
					insert_title(45,22,Red,Black,40,5,"MONHOC");
					show_rectangle(45,27,40,4,White);
					color_rectangle(46,28,40,3,White);
					insert_title(45,27,Aqua,White,40,5,"THOAT");
				}
				break;
			}
			
		case ENTER:
			{
				if( number == 4 )
				{
					system("cls");
					return;
				}
				else if( number == 3 )
				{
					system("cls");
					disPlaycauHoi(root, "toan", 1);
					return;
				}
			}
	}
	}
}

void Display_menuSV( int &counter, string user )
{
	ShowConsoleCursor(0);
	show_tittle(22,4);
	show_rectangle(1,1,130,32,Purple);
	insert_title(45,10,Bright_White ,Black,40,4,"STUDENT : " + user);
	show_rectangle(45,14,40,4,White);
	color_rectangle(46,15,40,3,White);
	insert_title(45,14,Aqua,White,40,5,"Lam Bai Thi");
	show_rectangle(45,19,40,4,Purple);
	insert_title(45,19,Red,Black,40,5,"XEM DIEM");
	show_rectangle(45,24,40,4,Purple);
	insert_title(45,24,Red,Black,40,5,"THOAT");
	counter = 1;
}

void Input_Minute( int &minute , int &number, int &v , int &t )
{
	int width = 56;
	int height = 19;
	show_rectangle(width,height,18,2,Red);
	gotoxy(v,t);
	char kitu;
	while( true)
	{
		ShowConsoleCursor(0);
		if( minute < 10 )	show_rectangle(width,height,18,2,Red);
		else show_rectangle(width,height,18,2,Green);
		kitu = getch();
		int int_kitu = int(kitu) - 48;
		if( int_kitu >= 0 && int_kitu <= 9 && minute < 10 )
		{
			if( int_kitu == 0 )
			{
				if( minute != 0 )
				{
					minute = minute*10 + int_kitu;
					gotoxy(v++,t);
					cout << kitu;
				}
			}
			else 
			{
				minute = minute*10 + int_kitu;
				gotoxy(v++,t);
				cout << kitu;
			}
		}
		else
		{
			if( kitu == BACKSPACE )
			{
				if( v == 64 )
				{
					continue;
				}
					gotoxy(--v,t);
					cout << " ";
					minute = (minute)/10;
			}
			else if( kitu == ESC )
				return;
			else if( kitu == DOWN || kitu == '\r')
			{
				show_rectangle(width,height,18,2,Black);
				number = 3;
				return;
			}
			else if(  kitu == UP)
			{
				show_rectangle(width,height,18,2,Black);
				number = 1;
				return;
			}
			else if(kitu == LEFT || kitu == RIGHT)
			{
				continue;
			}
		}	
		
	}
}

void Input_Question( int &socau , int &number , int &x, int &y )
{
	int width = 56;
	int height = 13;
	show_rectangle(width,height,18,2,Red);
	gotoxy(x,y);
	char kitu;
	int int_kitu;
	while(true)
	{
		ShowConsoleCursor(0);
		if( socau < 10 ) show_rectangle(width,height,18,2,Red);
		else show_rectangle(width,height,18,2,Green);
		kitu = getch();
		int int_kitu = int(kitu) - 48;
		if( int_kitu >= 0 && int_kitu <= 9 && socau < 10 )
		{
			if( int_kitu == 0 )
			{
				if( socau != 0 )
				{
					socau = socau*10 + int_kitu;
					gotoxy(x++,y);
					cout << kitu;
				}
			}
			else 
			{
				socau = socau*10 + int_kitu;
				gotoxy(x++,y);
				cout << kitu;
			}
		}
		else
		{
			if( kitu == BACKSPACE )
			{
				if( x == 64 )
				{
					continue;
				}
					gotoxy(--x,y);
					cout << " ";
					socau = (socau)/10;
			}
			else if( kitu == ESC )
				return;
			else if( kitu == DOWN || kitu == '\r')
			{
				show_rectangle(width,height,18,2,Black);
				number = 2;
				return;
			}
			else if( kitu == UP || kitu == LEFT || kitu == RIGHT)
			{
				continue;
			}
		}	
	}
}

void Next_Exam( int socau, int minute, int &number, int counter, string user)
{
	color_rectangle(130/2-4,32/2+7,9,1,White);
	insert_title(130/2-4,32/2+7,Red,White,9,1,"-NEXT- ");
	char kitu;
	while( true )
	{
		kitu = getch();
		if( kitu = '\r' )
		{
			if( minute < 10 )
			{
				color_rectangle(130/2-4,32/2+7,9,1,Green);
			insert_title(130/2-4,32/2+7,Red,Green,9,1,"-NEXT-");
				number = 2;
				return;
			}
			if( socau < 10 )
			{
				color_rectangle(130/2-4,32/2+7,9,1,Green);
			insert_title(130/2-4,32/2+7,Red,Green,9,1,"-NEXT-");
				number = 1;
				return;
			}
   			int total = totalQues( root, "toan" );
   			if( socau > total )
   			{
   				number = 1;
   			}
   			else
   			{
				  system("cls");
			startTimer( root, socau, minute, "toan");
			system("cls");
			Display_menuSV(counter, user);
			number = 4;
   			}
			return;
		}
		if( kitu == UP )
		{
			color_rectangle(130/2-4,32/2+7,9,1,Green);
			insert_title(130/2-4,32/2+7,Red,Green,9,1,"-NEXT-");
			number = 2;
			return;
		}
	}
}

void Input_Minute_Counter( int counter, string user )
{
	show_rectangle(130/2-10,32/2-7,20,13,Green);
	color_rectangle(130/2-9,32/2-6,20,3,Green);
	insert_title(130/2-9,32/2-6,Red,Green,20,3,"-QUESTION-");
	color_rectangle(130/2-9,32/2,20,3,Green);
	insert_title(130/2-9,32/2,Red,Green,20,3,"-TIME-");
	color_rectangle(130/2-4,32/2+7,9,1,Green);
	insert_title(130/2-4,32/2+7,Red,Green,9,1,"-NEXT- ");
	int number = 1;
	int socau = 0;
	int minute = 0;
	int x = 130/2-1 , y = 32/2-2;
	int v = 130/2-1 , t = 32/2+4;
	while( number != 4 )
	{
		if(number == 1 )
		{
			Input_Question( socau , number , x, y );
		}
		if( number == 2 )
		{
			Input_Minute( minute , number, v , t );
		}
		if( number == 3 )
		{
			Next_Exam( socau, minute , number, counter, user);
		}
	}
}

void menuSV( string user )
{
	int number;
	Display_menuSV(number,user);
	char catkey;
	while( true )
	{
		catkey = getch();
	switch(catkey)
	{
		case UP:
			{
				if( number == 1 )
				{
					number = 3;
					show_rectangle(45,14,40,4,Purple);
					color_rectangle(46,15,40,3,Black);
					insert_title(45,14,Red,Black,40,5,"Lam Bai Thi");
					show_rectangle(45,24,40,4,White);
					color_rectangle(46,25,40,3,White);
					insert_title(45,24,Aqua,White,40,5,"THOAT");
				}
				else if( number == 2 )
				{
					number = 1;
					show_rectangle(45,14,40,4,White);
					color_rectangle(46,15,40,3,White);
					insert_title(45,14,Aqua,White,40,5,"Lam Bai Thi");
					show_rectangle(45,19,40,4,Purple);
					color_rectangle(46,20,40,3,Black);
					insert_title(45,19,Red,Black,40,5,"XEM DIEM");
				}
				else if( number == 3 )
				{
					number = 2;
					show_rectangle(45,19,40,4,White);
					color_rectangle(46,20,40,3,White);
					insert_title(45,19,Aqua,White,40,5,"XEM DIEM");
					show_rectangle(45,24,40,4,Purple);
					color_rectangle(46,25,40,3,Black);
					insert_title(45,24,Red,Black,40,5,"THOAT");
				}
				break;
			}
		case DOWN:
			{
				if( number == 3 )	
				{
					number = 1;
					show_rectangle(45,24,40,4,Purple);
					color_rectangle(46,25,40,3,Black);
					insert_title(45,24,Red,Black,40,5,"THOAT");
					show_rectangle(45,14,40,4,White);
					color_rectangle(46,15,40,3,White);
					insert_title(45,14,Aqua,White,40,5,"Lam Bai Thi");
				}
				else if( number == 2 )
				{
					number = 3;
					show_rectangle(45,19,40,4,Purple);
					color_rectangle(46,20,40,3,Black);
					insert_title(45,19,Red,Black,40,5,"XEM DIEM");
					show_rectangle(45,24,40,4,White);
					color_rectangle(46,25,40,3,White);
					insert_title(45,24,Aqua,White,40,5,"THOAT");
				}
				else if( number == 1 )
				{
					number = 2;
					show_rectangle(45,14,40,4,Purple);
					color_rectangle(46,15,40,3,Black);
					insert_title(45,14,Red,Black,40,5,"Lam Bai Thi");
					show_rectangle(45,19,40,4,White);
					color_rectangle(46,20,40,3,White);
					insert_title(45,19,Aqua,White,40,5,"XEM DIEM");
				}
				break;
			}
			
		case ENTER:
			{
				system("cls");
				if( number == 3 )
				{
					return;
				}
				else if (number == 1 )
				{
					Input_Minute_Counter(  counter,  user );
					break;
				}
			}
	}
	}
}

//load 
void Load( string user, string pass, int &end)
{
	int x = 94, y = 19;
	int v = 94, t = 24;
	Insert_Loggin(user,pass,x,y,v,t);
	int catkey;
	while( catkey != ENTER )
	{
		catkey = getch();
		switch( catkey )
		{
			case ENTER:
			{
						if( Check_Account(user,pass,fileaccount) )
						{
							system("cls");
							menuSV(user);
						}
						else if( Check_Account(user,pass,fileaccountgv) )
						{
							system("cls");
							menuGV(user);
						}
						else Note_Acc(40,16,40,4,"TAI KHOAN KHONG TON TAI!",Red,end);
					break;
			}
			case ESC : 
			{
				end = 0;
				break;
			}
			case UP:
				{
					color_rectangle(96,27,20,3,Purple);
					insert_title(96,27,Aqua,Black,20,4,"LOGIN");
					Insert_pass(pass,v,t);
					break;
				}
			case DOWN:
				{
					color_rectangle(96,27,20,3,Purple);
					insert_title(96,27,Aqua,Black,20,4,"LOGIN");
					Insert_user(user,pass,x,y,v,t);
					break;
				}
		}
	}
}
