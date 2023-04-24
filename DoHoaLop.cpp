#include"functionLop.h"
#define Y_TREN 2
#define Y_DUOI 35
#define X_TRAI 5
#define X_PHAI 120
#define NGANG_KHUNG 1000
#define DAI_KHUNG 650
#define LINE1 6
#define LINE2 8
#define LINE3 33
#define LINE4 34
#define COLUMN1 15
#define COLUMN2 45
#define COLUMN3 85
//=================================
#define ALT 18
#define BACKSPACE 8
#define CAPSLOCK 20
#define CTRL 17
#define DEL 46
#define END 35
#define ENTER 13
#define ESC 27
#define FINISH  66
#define INSERT 45
#define HOME  36
#define SHIFT 16
#define SPACE 32
#define TAB 9
//=================================
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
//=================================
#define F1 112
#define F2 113
#define F3 114
#define F4 115
#define F5 116
#define F6 117
#define F7 118
#define F8 119
#define F9 120
#define F10 121
#define F11 122
#define F12 123
//=================================
#define CHU_A 65
#define CHU_Z 90
#define	CHU_a 97
#define CHU_z 142
#define SO_0 48
#define SO_957

//==============================================
char n=177;
DSLOP dslop;
void Disable_Resize_Window(){
	HWND hWnd=GetConsoleWindow();
	SetWindowLong(hWnd,GWL_STYLE,GetWindowLong(hWnd,GWL_STYLE)& ~WS_SIZEBOX);
}
void Chu_Thich_Lop(){
	SetColor(2);
	gotoxy(X_TRAI+1,LINE4);
	cout<<" ESC: Thoat CT ";
	gotoxy(wherex()+2,LINE4);
	cout<<" F1: Quay lai ";
	gotoxy(wherex()+2,LINE4);
	cout<<" F2: Tim kiem ";
	gotoxy(wherex()+2,LINE4);
	cout<<" F3: Them/Xoa ";
	gotoxy(wherex()+2,LINE4);
	cout<<" ENTER: Thay doi";
	SetColor(15);
}
void Dau_Trang(DSLOP dslop,int trang_hien_tai){
	int tong_trang=dslop.n/(LINE2-LINE3-1)+1;
	gotoxy(X_PHAI-15,LINE4);
	cout<<" < ";
	gotoxy(X_PHAI-10,LINE4);
	cout<<" "<<trang_hien_tai<<"/"<<tong_trang<<" ";
	gotoxy(X_PHAI-3,LINE4);
	cout<<" > ";
}
void In_dsL(DSLOP dslop){
	Dau_Trang(dslop,1);
	for(int i=0;i<dslop.n;i++){
		gotoxy(X_TRAI+(COLUMN1-X_TRAI)/2,LINE2+i+1);
		cout<<i+1;
		gotoxy(COLUMN1+((COLUMN2-COLUMN1)-dslop.nodeL[i]->MALOP.size())/2,LINE2+i+1);
		cout<<dslop.nodeL[i]->MALOP;
		gotoxy(COLUMN2+((COLUMN3-COLUMN2)-dslop.nodeL[i]->TENLOP.size())/2,LINE2+i+1);
		cout<<dslop.nodeL[i]->TENLOP;
		gotoxy(COLUMN3+(X_PHAI-COLUMN3-8)/2,LINE2+i+1);
		cout<<dslop.nodeL[i]->NIENKHOA;
	}
	gotoxy(0,36);
}
void Khung_Lop(){
	resizeConsole(NGANG_KHUNG,DAI_KHUNG);
	Disable_Resize_Window();
	for(int y=Y_TREN;y<=Y_DUOI;y++){
		//SetBGColor(15);
		//SetColor(0);
		SetColor(15);
		for(int x=X_TRAI-1;x<=X_PHAI+1;x++){
 			if(y==Y_TREN||y==Y_DUOI||y==LINE1||y==LINE2||y==LINE3||y==LINE4){
				gotoxy(x,y);
				cout<<n;
			}
			else if(x<=X_TRAI||x>=X_PHAI){
				gotoxy(x,y);
				cout<<n;
			}
			if((x==COLUMN1||x==COLUMN2||x==COLUMN3)&&y>LINE1){
				gotoxy(x,y);
				cout<<n;
			}
		}
	}
	gotoxy(X_TRAI+(X_PHAI-X_TRAI-13)/2,Y_TREN+2);
	cout<<"DANH SACH LOP";
	gotoxy(X_TRAI+(COLUMN1-X_TRAI-2)/2,LINE1+1);
	cout<<"STT";
	gotoxy(COLUMN1+(COLUMN2-COLUMN1-6)/2,LINE1+1);
	cout<<"MA LOP";
	gotoxy(COLUMN2+(COLUMN3-COLUMN2-6)/2,LINE1+1);
	cout<<"TEN LOP";
	gotoxy(COLUMN3+(X_PHAI-COLUMN3-8)/2,LINE1+1);
	cout<<"NIEN KHOA";
	Chu_Thich_Lop();
	In_dsL(dslop);
	gotoxy(0,36);
}

int main (){
	Read_File_ListL(dslop,"danhsachlop.txt");
	
	Khung_Lop();
	
	return 0;
}
