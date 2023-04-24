#include "Question.h"
#include "dohoa.h"
#include<fstream>

using namespace std;

bool stop = true;

//hien thi dap an
void Display_DapAn( char dsDapAn, int color )
{
	if( dsDapAn == 'A')
	{
		color_rectangle(16,19,2,4,color);
	}
	else if( dsDapAn == 'B')
	{
		color_rectangle(71,19,2,4,color);
	}
	if( dsDapAn == 'C')
	{
		color_rectangle(16,25,2,4,color);
	}
	if( dsDapAn == 'D')
	{
		color_rectangle(71,25,2,4,color);
	}
}

//khoi tao lai menu
void Display_Init( )
{
	color_rectangle(16,9,100,8,Black);
	color_rectangle(16,20,45,3,Black);
	color_rectangle(71,20,45,3,Black);
	color_rectangle(16,25,45,3,Black);
	color_rectangle(71,25,45,3,Black);
}

//giao dien
void menu()
{
	ShowConsoleCursor(0);
	show_rectangle(1,1,130,32,Purple);
	show_rectangle(15,8,100,9,Aqua);
    show_rectangle(107, 5, 8, 2, Red); //clock
    gotoxy(111,6);
    cout << ":";
    show_rectangle(2,2,10,2,White); //nut lui
    color_rectangle(3,3,10,1,White);
    insert_title(3,3,Red,White,10,1,"<= A  ");
    show_rectangle(120,2,10,2,White); // nut toi
    color_rectangle(121,3,10,1,White);
    insert_title(121,3,Red,White,10,1,"D =>");
}

//hien thi va luu dap an
char Display( int &counter , char *dsDapAn)
{
	show_rectangle(15,19,45,4,White); //A
	show_rectangle(70,19,45,4,Purple); // B
	show_rectangle(15,24,45,4,Purple); // C
	show_rectangle(70,24,45,4,Purple); // D
	int catkey;
	char choose = 'A';
	while( true )
	{
		catkey = getch();
		if( !stop ) return 'E';
		switch( catkey )
		{
				case DOWN :
				{
					if( choose == 'A' )
					{
						choose = 'C';
						show_rectangle(15,19,45,4,Purple);
						show_rectangle(15,24,45,4,White);
					}
					else if( choose == 'B' )
					{
						choose = 'D';
						show_rectangle(70,19,45,4,Purple);
						show_rectangle(70,24,45,4,White);
					}
					break;
				}
			case UP:
				{
						if( choose == 'C' )
					{
						choose = 'A';
						show_rectangle(15,19,45,4,White);
						show_rectangle(15,24,45,4,Purple);
					}
					else if( choose == 'D' )
					{
						choose = 'B';
						show_rectangle(70,19,45,4,White);
						show_rectangle(70,24,45,4,Purple);
					}
					break;
				}
			case RIGHT:
				{
					if( choose == 'A')
					{
						choose = 'B';
						show_rectangle(15,19,45,4,Purple);
						show_rectangle(70,19,45,4,White);
					}
					if( choose == 'C')
					{
						choose = 'D';
						show_rectangle(15,24,45,4,Purple);
						show_rectangle(70,24,45,4,White);
					}
					break;
				}
			case LEFT:
				{
					if( choose == 'B')
					{
						choose = 'A';
						show_rectangle(15,19,45,4,White);
						show_rectangle(70,19,45,4,Purple);
					}
					if( choose == 'D')
					{
						choose = 'C';
						show_rectangle(15,24,45,4,White);
						show_rectangle(70,24,45,4,Purple);
					}
					break;
				}
			case 'a':
			case 'A':
				{
					if( counter == 1 )
					{
						counter--;
						return dsDapAn[counter+1];
					}
					else
					{
						counter -= 2;
						return dsDapAn[counter+2];
					}
				}
			case 'd':
			case 'D':
				{                          
					return dsDapAn[counter];
				}
			case ENTER:
				{               
					return choose;
				}
		}
	}
}

//khoi tao mang
void Init_ds( char *dsDapAn, int socau )
{
	for( int i = 1; i <= socau ; i++ )
	{
		dsDapAn[i] = 'E';
	}
}

bool control_warning( bool quit,string op1, string op2 )
{
	char catkey;
	quit = true;
	while( true )
	{
		catkey = getch();
		switch( catkey )
		{
			case RIGHT:
				{
					quit = false;
					color_rectangle(50,20,11,1,Black);
					insert_title(50,20,Green,Black,11,1,op1);
					color_rectangle(72,20,11,1,Green);
					insert_title(72,20,Aqua,Green,11,1,op2);
					break;
				}
			case LEFT:
				{
					quit = true;
					color_rectangle(50,20,11,1,Green);
					insert_title(50,20,Aqua,Green,11,1,op1);
					color_rectangle(72,20,11,1,Black);
					insert_title(72,20,Green,Black,11,1,op2);
					break;
				}
			case ENTER:
				{
					return quit;
				}
		}
	}
}

//thong bao nop
void waring( int &counter , string title, string op1, string op2)
{
	color_rectangle(46,16,40,6,Black);
	show_rectangle(45,15,40,7,Red);
	insert_title(46,17,Green,Black,40,1,title);
	show_rectangle(49,19,11,2,Green);
	color_rectangle(50,20,11,1,Green);
	insert_title(50,20,Aqua,Green,11,1,op1);
	show_rectangle(71,19,11,2,Green);
	insert_title(71,20,Green,Black,11,1,op2);
	bool quit = control_warning( quit ,op1, op2);
	if( quit )
	{
		counter++;
	}
	color_rectangle(45,15,42,8,Black);
}

void Display_KetQua( int socau, CauHoi *dsCau, char *dsDapAn )
{
	int hang = socau < 10 ? socau : socau/10;
	for( int row = 1 ; row <= hang ; row++ )
	{
		int cot = socau > 10 ? 10 : socau;
		socau -= 10;
		for( int col = 1 ; col <= cot ; col++ )
		{
			gotoxy(37+col*5,row*3+10);
			cout << (row-1)*10+col;
			gotoxy(37+col*5,row*3+11);
			if( equal(&dsCau[(row-1)*10+col].dapan[0], &dsCau[(row-1)*10+col].dapan[0] + 1, &dsDapAn[(row-1)*10+col]) )
			{
				SetColor(Green);
			}
			else SetColor(Red);
			cout << dsDapAn[(row-1)*10+col];
			show_rectangle(40,row*3+9,col*5,3,Aqua);
		}
	}
}

bool Again_Exam( bool quit )
{
	quit = false;
	int catkey;
	while( true )
	{
		catkey = getch();
		switch( catkey )
		{
			case UP:
				{
					quit = false;
					color_rectangle(111,16,10,1,Green);
					insert_title(111,16,White,Green,10,1,"XEM LAI");
					color_rectangle(111,21,10,1,Black);
					insert_title(111,21,Green,Black,10,1,"LUU");	
					break;
				}
			case DOWN:
				{
					quit = true;
					color_rectangle(111,16,10,1,Black);
					insert_title(111,16,Green,Black,10,1,"XEM LAI");
					color_rectangle(111,21,10,1,Green);
					insert_title(111,21,White,Green,10,1,"LUU");
					break;
				}
			case ENTER:
				{
					return quit;
				}
		}
	}
}

void Show_Points( CauHoi *dsCau, char* dsDapAn, int socau )
{
	system("cls");
	show_rectangle(1,1,130,32,Purple);
	show_rectangle(55,5,20,6,Red);
	insert_title(46,7,Green,Black,40,1,"DIEM");
	show_rectangle(110,15,10,2,Green);
	color_rectangle(111,16,10,1,Green);
	insert_title(111,16,White,Green,10,1,"XEM LAI");
	show_rectangle(110,20,10,2,Green);
	insert_title(111,21,Green,Black,10,1,"LUU");
	float diem = 0;
	for( int i = 1 ; i <= socau ; i++ )
	{
		if( equal(&dsCau[i].dapan[0], &dsCau[i].dapan[0] + 1, &dsDapAn[i]) )
		{
			diem ++;
		}
	}
	diem = diem*10/socau;
	 char myPoint[5];
    snprintf(myPoint, 5, "%4.2f", diem);
    insert_title(46,9,Red,Green,40,1,myPoint);
    Display_KetQua(socau,dsCau,dsDapAn);
    int quit;
    quit = Again_Exam(quit);
    if( !quit )
    {
    	system("cls");
    	int counter = 1;
		menu();
	while( counter <= socau )
	{
		Display_Init();
		gotoxy(20,9);
		cout << "QUESTION " << counter << " : ";
		gotoxy(34,9);
		cout << dsCau[counter].noidung;
		gotoxy(20,21);
		cout << "A. " << dsCau[counter].A;
		gotoxy(75,21);
		cout << "B. "<< dsCau[counter].B;
		gotoxy(20,26);
		cout <<"C. " << dsCau[counter].C;
		gotoxy(75,26);
		cout <<"D. "<< dsCau[counter].D;
		show_rectangle(15,8,100,9,Aqua);
		Display_DapAn(dsDapAn[counter],Red);
		Display_DapAn(dsCau[counter].dapan[0],Green);
	show_rectangle(15,19,45,4,Purple); //A
	show_rectangle(70,19,45,4,Purple); // B
	show_rectangle(15,24,45,4,Purple); // C
	show_rectangle(70,24,45,4,Purple); // D
	int key;
	bool active = true;
	while(active)
	{
		key = getch();
		switch( key )
		{
			case 'a':
			case 'A':
				{
				 if (counter == 1 ) counter--;
				 else counter -= 2;
				 active = false;
				 break;
				}
			case 'd':
			case 'D':
				{        
			 		active = false;
						 break;                  
				}
			case ENTER:
				{          
						  active = false;   
					break;
				}
		}
	}
	if( counter == socau )
		{
			waring( counter,"SAVE AS","SAVE","BACK");
		} 
	else counter++;  
	}
	}
}

//lam bai
void Do_Exam(  NODEPTRCH root, int socau, string mmh)
{
	ShowConsoleCursor(0);
	int counter = 1;
	char dsDapAn[200];
	Init_ds(dsDapAn, socau );
	menu();
	CauHoi *dsCau = Create_Exam( root, socau, "toan");
	while( counter <= socau && stop )
	{
		Display_Init();
		gotoxy(20,9);
		cout << "QUESTION " << counter << " : ";
		gotoxy(34,9);
		cout << dsCau[counter].noidung;
		gotoxy(20,21);
		cout << "A. " << dsCau[counter].A;
		gotoxy(75,21);
		cout << "B. "<< dsCau[counter].B;
		gotoxy(20,26);
		cout <<"C. " << dsCau[counter].C;
		gotoxy(75,26);
		cout <<"D. "<< dsCau[counter].D;
		show_rectangle(15,8,100,9,Aqua);
		Display_DapAn(dsDapAn[counter],Red);
		dsDapAn[counter] = Display( counter, dsDapAn);
		if( counter == socau && stop )
		{
			waring( counter,"SUBMIT","OK","QUIT");
		}
		else counter++;
	}
	if( !stop )
		{
			waring( counter,"HET GIO","OK","QUIT");
		}
	stop = false;
	Show_Points( dsCau,dsDapAn,socau );
}

void startTimerJob(int time){
	int p = 0, s = 0;
	while( (time != 0 || p != 0 || s != 0) && stop)
	{
		if( time == 0 && p == 0 && s == 1) stop = false;
		if( time >= 10 )
		{
			gotoxy(109,6);
		}
		else{
			gotoxy(109,6);
			cout <<0;
			gotoxy(110,6);
		}
		cout << time;
		gotoxy(112,6);
		cout << p;
		gotoxy(113,6);
		cout << s;
		if( p == 0 && s == 0 )
		{
			time --;
			p = 5;
			s = 9;
		}
		else if( s == 0)
		{
			p--;
			s = 9;
		}
		else s--;
		Sleep(980);
	}
}

void startTimer(NODEPTRCH root, int socau,int minute, string mmh){
	stop = true;
	thread timer;
	timer=thread(startTimerJob,minute);
	Do_Exam(root,socau,mmh);  
	timer.join();
}
