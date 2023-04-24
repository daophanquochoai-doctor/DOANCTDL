#include"functionLop.h"
#include<cmath>
//===================================
// kich thuoc console
#define NGANG_CONSOLE 1000
#define DAI_CONSOLE 600
//===================================
//Toa do khung lop
#define Y_TREN 1
#define Y_DUOI 30
#define ROW1 5
#define ROW2 7
#define ROW3 28
#define ROW4 29 // vi tri chua thong bao
//-------------------
#define X_TRAI 5
#define X_PHAI 85
#define COLUMN1 13
#define COLUMN2 29
#define COLUMN3 65
//====================================
//Toa do khung menu lop
#define y_tren 5
#define y_duoi 25
#define x_trai 92
#define x_phai 130
#define row1 6
#define row2 7
//====================================
//Phim 
#define ALT 18
#define BACKSPACE 8
#define CAPSLOCK 20
#define CTRL 17
#define DLT 46//DELETE
#define END 35
#define ENTER 13
#define ESC 27
#define HOME 36
#define SHIFT 16
#define SPACE 32
#define TAB 9
//===================================
//phim di chuyen
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
// chu in-thuong/so
#define CHU_A 65
#define CHU_Z 90
#define	CHU_a 97
#define CHU_z 142
#define SO_0 48
#define SO_9 57

//================================
int trang = 1;
int vi_tri_x;
int vi_tri_y;
char khung=177;
//=================================
void Row();
void Column();
void Khung_Lop();
void Chu_Thich_Lop();
void Trang_Thai_Lop();
void Clear_Khung_Lop();
void Dau_Trang();

void In_Lop(int n,Lop lop);
void In_Danh_Sach_Lop(int trang,DSLOP dslop);//in theo trang

void Hightlight_Lop(int n,DSLOP dslop);//Inds lop de xoa
//================================
void Khung_Menu_Lop();
void Ten_Menu(string chuoi);
void Chu_Thich_Menu_Lop();
void Clear_Khung_Menu_Lop();
void Huong_Dan_Menu_Lop(int dong,string chuoi);
void Remove_Huong_Dan_Menu_Lop(int dong);

void Hightlight(int x,int y,string chuoi);
void Remove_Hightlight(int x,int y,string chuoi);
//================================
//================================
void Chu_Thich_Cap_Nhat_Lop(Lop lop);
void Cap_Nhat_Thong_Tin_Lop(Lop &lop);
void Chu_Thich_Thay_Doi_Lop();
void Thay_Doi_Lop(DSLOP &dslop);
//================================
void Chu_Thich_Tim_Kiem_Lop();
void Tim_Kiem_Lop(DSLOP dslop);
//================================
int Dieu_Kien_Xoa_Lop(Lop lop);
void Chu_Thich_Them_Lop();
void Them_Lop(DSLOP &dslop);
void Chu_Thich_Xoa_Lop();
void Xoa_Lop(DSLOP &dslop);

//================================
void Chu_Thich(int x,int y){

	gotoxy(1,10);
	SetColor(2);
	cout<<"Chu thich:";
	cout<<setw(10)<<"Backspace: xoa 1 ky tu.";
	SetColor(15);
	gotoxy(x,y);
}
void Do_Hoa_Backspace(){
	gotoxy(wherex()-1,wherey());
	cout<<" ";
	gotoxy(wherex()-1,wherey());
}
string Xu_Ly_Ma(){
	char chu;
	string chuoi;
	do{
		chu=getch();
		if((chu>=65&&chu<=90)||(chu>=48&&chu<=57)){
			cout<<chu;
			chuoi=chuoi+chu;
			
		}else if(chu>=97&&chu<=142){
			chu=chu-32;
			cout<<chu;
			chuoi=chuoi+chu;
			
		}else if(chu==8&&chuoi.size()!=0){
			chuoi.pop_back();
			Do_Hoa_Backspace();
		}	
	}while(chu!=13);
//	if(chuoi.size()<=15){
//		cout<<"\nMa hop le.\n";
//	}else{
//		cout<<"\nMa khong hop le.\n";
//		chuoi="";
//	}
	return chuoi;
}
void Xu_Ly_TenL(int x,int y,string &chuoi1){
	char chu;
	string chuoi=chuoi1;
	gotoxy(x+chuoi1.size(),y);
	do{
		chu=getch();
		if(chu==32&&(chuoi[chuoi.size()-1]!=32)&&chuoi.size()!=0){
			cout<<chu;
			chuoi=chuoi+chu;
			
		}else if(chu>=CHU_A &&chu<=CHU_Z){
			
			if(chuoi[chuoi.size()-1]!=32&&chuoi.size()!=0){
				chu=chu+32;	
			}
			cout<<chu;
			chuoi=chuoi+chu;
			
		}else if(chu>=CHU_a &&chu<=CHU_z){
			
			if(chuoi.size()==0)	chu=chu-32;	
			
			cout<<chu;
			chuoi=chuoi+chu;	
			
		}else if(chu==BACKSPACE&&chuoi.size()!=0){
			
			chuoi.pop_back();
			Do_Hoa_Backspace();
		}
	}while(chu!=13);
	chuoi1=chuoi;
}
void Xu_Ly_Nien_KhoaL(int x,int y,string &chuoi1){// goi ham backspace rieng de chu thich
	char chu;
	string chuoi=chuoi1;
	gotoxy(x+chuoi1.size(),y);
	do{
		chu=getch();
		if(chuoi.size()<9){
			if(chuoi.size()==4){
				if(chu==SPACE||chu=='/'||chu=='-'){
					chu='-';
					chuoi=chuoi+chu;
					cout<<chu;
				}
			}else if(chu>=SO_0&&chu<=SO_9){
					chuoi=chuoi+chu;
					cout<<chu;
			}
		}
		if(chu==BACKSPACE&&chuoi.size()!=0){
			
			chuoi.pop_back();
			Do_Hoa_Backspace();
		}

	}while(chu!=13);
	chuoi1=chuoi;
}
//================================
//Ham copy de test
void Row(int x_left,int x_right,int y,char ky_tu){
	
	gotoxy(x_left,y);	
	for(int x=x_left;x<=x_right;x++)   cout<<ky_tu;	
}
void Column(int x, int y_top,int y_bottom,char ky_tu){
	
	for(int y=y_top;y<=y_bottom;y++)
	{
		gotoxy(x,y);
		cout<<ky_tu;
	}
}
void Disable_Resize_Window(){
	HWND hWnd=GetConsoleWindow();
	SetWindowLong(hWnd,GWL_STYLE,GetWindowLong(hWnd,GWL_STYLE)& ~WS_SIZEBOX);
}
//===================================
//Khai trien ham
void Chu_Thich_Lop(){
	gotoxy(X_TRAI+(X_PHAI-X_TRAI-12)/2,Y_TREN+2);
	cout<<"DANH SACH LOP";
	gotoxy(X_TRAI+(COLUMN1-X_TRAI-2)/2,ROW1+1);
	cout<<"STT";
	gotoxy(COLUMN1+(COLUMN2-COLUMN1-6)/2,ROW1+1);
	cout<<"MA LOP";
	gotoxy(COLUMN2+(COLUMN3-COLUMN2-6)/2,ROW1+1);
	cout<<"TEN LOP";
	gotoxy(COLUMN3+(X_PHAI-COLUMN3-8)/2,ROW1+1);
	cout<<"NIEN KHOA";
	gotoxy(0,Y_DUOI+1);
}
void Khung_Lop(){
	SetColor(15);
	Row(X_TRAI,X_PHAI,Y_TREN,khung);
	Row(X_TRAI,X_PHAI,ROW1,khung);
	Row(X_TRAI,X_PHAI,ROW2,khung);
	Row(X_TRAI,X_PHAI,ROW3,khung);
	Row(X_TRAI,X_PHAI,ROW4,khung);
	Row(X_TRAI,X_PHAI,Y_DUOI,khung);
	Column(X_TRAI-1,Y_TREN,Y_DUOI,khung);
	Column(X_TRAI,Y_TREN,Y_DUOI,khung);
	Column(COLUMN1,ROW1,Y_DUOI,khung);
	Column(COLUMN2,ROW1,Y_DUOI,khung);
	Column(COLUMN3,ROW1,Y_DUOI,khung);
	Column(X_PHAI,Y_TREN,Y_DUOI,khung);
	Column(X_PHAI+1,Y_TREN,Y_DUOI,khung);
	Chu_Thich_Lop();
}
void Clear_Khung_Lop(){

	for(int y=ROW2+1;y<ROW3;y++){
		for(int x=X_TRAI+1;x<X_PHAI;x++){
			if(x!=COLUMN1&&x!=COLUMN2&&x!=COLUMN3){
				gotoxy(x,y);
				cout<<" ";
			}
		}
	}
}
void Trang_Thai_Lop(string chuoi){
	
	gotoxy(X_TRAI+1,ROW3+1);
	cout<<chuoi;
	for(int i=wherex();i<50;i++){
		cout<<khung;
	}
}
void In_Lop(int n,Lop lop){
	int y=n%20;
	gotoxy(X_TRAI+(COLUMN1-X_TRAI)/2,ROW2+y+1);
	cout<<n+1;
	gotoxy(COLUMN1+((COLUMN2-COLUMN1)-lop.MALOP.size()+1)/2,ROW2+y+1);
	cout<<lop.MALOP;
	gotoxy(COLUMN2+4,ROW2+y+1);
	cout<<lop.TENLOP;
	gotoxy(COLUMN3+(X_PHAI-COLUMN3-8)/2,ROW2+y+1);
	cout<<lop.NIENKHOA;
}// co the dung In_Lop nhu ham xoa Hightlight
void Dau_Trang(int trang,DSLOP dslop){
	int tong_trang=dslop.n/(ROW3-ROW2-1);
	gotoxy(X_PHAI-15,ROW4);
	cout<<" < ";
	gotoxy(X_PHAI-10,ROW4);
	cout<<" "<<trang<<"/"<<tong_trang<<" ";
	gotoxy(X_PHAI-3,ROW4);
	cout<<" > ";
}
void In_Danh_Sach_Lop(int trang,DSLOP dslop){
	Dau_Trang(trang,dslop);
		for(int i=(trang-1)*20;i<dslop.n&&i<trang*20;i++){
			In_Lop(i,*dslop.nodeL[i]);
	}
}
void Hightlight_Lop(int n,DSLOP dslop){
	SetBGColor(15);
	SetColor(0);
	In_Lop(n,*dslop.nodeL[n]);
	SetBGColor(0);
	SetColor(15);
}

void Ten_Menu(string chuoi){
	SetColor(15);
	for(int x=x_trai;x<x_phai;x++){
		gotoxy(x,row1);
		cout<<khung;
	}
	Row(x_trai,x_phai,row1,khung);
	gotoxy(x_trai+(x_phai-x_trai-chuoi.size())/2-1,y_tren+1);
	cout<<" "<<chuoi<<" ";
}
void Chu_Thich_Menu_Lop(){
	Ten_Menu("MENU CHUC NANG");
	SetColor(2);
		gotoxy(x_trai+1,row2+2);
		cout<<setw(8)<<left<<" 1:"<<"Cap nhat thong tin";	
		gotoxy(x_trai+1,wherey()+2);
		cout<<setw(8)<<left<<" 2:"<<"Tim kiem";
		gotoxy(x_trai+1,wherey()+2);
		cout<<setw(8)<<left<<" 3:"<<"Them";
		gotoxy(x_trai+1,wherey()+2);
		cout<<setw(8)<<left<<" 4:"<<"Xoa";
		gotoxy(x_trai+1,wherey()+2);
		cout<<setw(8)<<left<<" 0:"<<"Quay lai";
		gotoxy(x_trai+1,wherey()+2);
		cout<<setw(8)<<left<<" ESC:"<<"Thoat CT";
	SetColor(15);
}
void Khung_Menu_Lop(){
	Row(x_trai,x_phai,y_tren,khung);
	Row(x_trai,x_phai,row1,khung);
	Row(x_trai,x_phai,row2,khung);
	Row(x_trai,x_phai,y_duoi,khung);
	Column(x_trai,y_tren,y_duoi,khung);
	Column(x_trai-1,y_tren,y_duoi,khung);
	Column(x_phai,y_tren,y_duoi,khung);
	Column(x_phai+1,y_tren,y_duoi,khung);
}
void Clear_Khung_Menu_Lop(){
		for(int x=x_trai+1;x<x_phai;x++){
		for(int y=row2+1;y<y_duoi;y++){
			gotoxy(x,y);
			cout<<" "; 
		}
	}
}
void Huong_Dan_Menu_Lop(int dong,string chuoi){
	SetColor(2);
	int y=y_duoi-5;
	gotoxy(x_trai+2,y+dong);
	cout<<chuoi;
	SetColor(15);
}
void Remove_Huong_Dan_Menu_Lop(int dong){
	int y=y_duoi-5;
	gotoxy(x_trai+1,y+dong);
	for(int x=x_trai+1;x<x_phai;x++){
		cout<<" ";
	}
}

void Hightlight(int x,int y,string chuoi){
		SetBGColor(15);
	SetColor(0);

	gotoxy(x,y);
	cout<<chuoi;
	SetBGColor(0);
	SetColor(15);
}
void Remove_Hightlight(int x,int y,string chuoi){
	gotoxy(x,y);
	cout<<chuoi;
}
//====================================================
void Chu_Thich_Cap_Nhat_Lop(Lop lop){

	int y=row1+2;

	Clear_Khung_Menu_Lop();
	gotoxy(x_trai+2,y++);
	cout<<setw(12)<<left<<"Ma so lop: "<<lop.MALOP;
	gotoxy(x_trai+2,y++);
	cout<<setw(12)<<left<<"Ten lop: "<<lop.TENLOP;
	gotoxy(x_trai+2,y++);
	cout<<setw(12)<<left<<"Nien khoa: "<<lop.NIENKHOA;
	gotoxy(x_trai+2,y++);
	cout<<"------------------------------";
	SetColor(2);
	gotoxy(x_trai+2,y++);
	cout<<"Chon thong tin muon thay doi.";
	Huong_Dan_Menu_Lop(3,"ENTER: cap nhat thong tin.");
	Huong_Dan_Menu_Lop(4,"Tab: quay lai Bang chuc nang.");
	SetColor(3);
	gotoxy(x_trai+5,y_duoi-6);
	cout<<"1: Luu";
	gotoxy(x_phai-15,y_duoi-6);
	cout<<"0: Huy";
	SetColor(15);

	vi_tri_x=x_trai+13;
	vi_tri_y=y;
	gotoxy(x_trai+2,y);
	cout<<"Ten lop: ";
	y+=2;
	gotoxy(x_trai+2,y);
	cout<<"Nien khoa: ";

}
void Cap_Nhat_Thong_Tin_Lop(Lop &lop){
	
	char chucnang;
	string chuoi[2];
	string chuoi1[2];
	chuoi[0]="Ten lop:";
	chuoi[1]="Nien khoa:";
	int n=0;

	Chu_Thich_Cap_Nhat_Lop(lop);
	Hightlight(x_trai+2,vi_tri_y+n,chuoi[n]);
	do{
		chucnang=getch();
		switch(chucnang){
			case UP:
			 	Remove_Hightlight(x_trai+2,vi_tri_y+2*n,chuoi[min(n,1)]);
				n--;
				if(n<0) n=1;
				Hightlight(x_trai+2,vi_tri_y+2*n,chuoi[min(n,1)]);
				break;
			case DOWN:
				Remove_Hightlight(x_trai+2,vi_tri_y+2*n,chuoi[min(n,1)]);
				n++;
				if(n>1) n=0;
				Hightlight(x_trai+2,vi_tri_y+2*n,chuoi[min(n,1)]);
				break;
			case ENTER:
				gotoxy(vi_tri_x,vi_tri_y+2*n);// vi tri dong hightlight
				if(n==0){
						cout<<chuoi1[0];
						Huong_Dan_Menu_Lop(2,"Backspace: xoa 1 ky tu.");
						Xu_Ly_TenL(vi_tri_x,vi_tri_y,chuoi1[0]);
						Remove_Huong_Dan_Menu_Lop(2);
						gotoxy(vi_tri_x,vi_tri_y+2*n);
				}else{
					cout<<chuoi1[1];
					Huong_Dan_Menu_Lop(2,"Backspace: xoa 1 ky tu.");
					Xu_Ly_Nien_KhoaL(vi_tri_x,vi_tri_y+2*n,chuoi1[1]);
					Remove_Huong_Dan_Menu_Lop(2);
					gotoxy(vi_tri_x,vi_tri_y+2*n);
				}
				break;
			case '1':
				lop.NIENKHOA=chuoi1[0];
				lop.TENLOP=chuoi1[1];
				Clear_Khung_Menu_Lop();
				Huong_Dan_Menu_Lop(1,"Luu hoan tat.");
				Huong_Dan_Menu_Lop(2,"Nhan phim bat ky de quay lai.");
				getch();
				chucnang='0';
				break;
			case '0':
				Clear_Khung_Menu_Lop();
				Huong_Dan_Menu_Lop(1,"Da huy cap nhat.");
				Huong_Dan_Menu_Lop(2,"Nhan phim bat ky de quay lai.");
				getch();
				break;

			default :
			break;	
		}
	}while (chucnang!='0');
}
void Chu_Thich_Thay_Doi_Lop(){
	Clear_Khung_Menu_Lop();
	Ten_Menu("CAP NHAT THONG TIN");
	SetColor(2);
	Huong_Dan_Menu_Lop(1,"Nhan phim mui ten de di chuyen.");
	Huong_Dan_Menu_Lop(2,"Nhan Enter de chon.");
	Huong_Dan_Menu_Lop(4,"Nhan phim 0 de quay lai.");
	SetColor(15);
	
}
void Thay_Doi_Lop(DSLOP &dslop){//con sai(xu li hightlight)
	char chucnang;
	int MAX=dslop.n;
	int n=0,trang=1;
	string chuoi;
	Chu_Thich_Thay_Doi_Lop();
	Hightlight_Lop(n,dslop);
	do{
		chucnang=getch();
		switch(chucnang){
			case UP:
			
				In_Lop(n,*dslop.nodeL[n]);
				n--;
				if(n==-1) n=MAX-1;
				Hightlight_Lop(n,dslop);
				break;
			case DOWN:
				n++;
				if(n==MAX) n=0;
				In_Danh_Sach_Lop(trang,dslop);
				Hightlight_Lop(n,dslop);
				break;
			case LEFT:
				trang--;
				if(trang==0) trang=(dslop.n-1)/(ROW3-ROW2)+1;
				if(dslop.n-n>0)
				Clear_Khung_Lop();
				In_Danh_Sach_Lop(trang,dslop);
				Hightlight_Lop(n,dslop);
				break;
			case RIGHT:
				trang++;
				if(trang>(dslop.n-1)/(ROW3-ROW2)+1) trang=1;
				//n+=20;
				Clear_Khung_Lop();
				In_Danh_Sach_Lop(trang,dslop);
				Hightlight_Lop(n,dslop);
				break;
			case ENTER:
				Cap_Nhat_Thong_Tin_Lop(*dslop.nodeL[n]);
				Chu_Thich_Thay_Doi_Lop();
				break;
			case ESC:
				system("cls");
				break;
			case '0':
				break;
			default:
				break;
		}
	}while(chucnang!='0'&&chucnang!=ESC);
	Clear_Khung_Menu_Lop();
}
//====================================================

//=====================================================
//Ham chua hoan chinh
void Chu_Thich_Tim_Kiem_Lop(){
	Clear_Khung_Menu_Lop();
	SetColor(2);
		gotoxy(x_trai+1,row1+2);
		cout<<" Tim kiem theo: ";
		gotoxy(x_trai+1,wherey()+2);
		cout<<" 1. Ma lop ";
		gotoxy(x_trai+1,wherey()+2);
		cout<<" 2. Ten lop ";
		gotoxy(x_trai+1,wherey()+2);
		cout<<" 3. Nien Khoa ";
		gotoxy(x_trai+1,wherey()+2);
		cout<<" 0. Quay lai ";	
	SetColor(15);
}
void Tim_Kiem_Lop(DSLOP dslop){
	char chucnang;
	int stop=FALSE;
	string chuoi;
	Chu_Thich_Tim_Kiem_Lop();
	do{
		
		chucnang=getch();
		switch(chucnang){
			case '1':
				Clear_Khung_Menu_Lop();
				gotoxy(x_trai+2,row1+1);
				cout<<"Nhap ma lop: ";
				chuoi=Xu_Ly_Ma();
				Chu_Thich_Tim_Kiem_Lop();
				break;
			case '2':
				Clear_Khung_Menu_Lop();
				gotoxy(x_trai+2,row1+1);
				cout<<"Nhap ten lop: ";
				Xu_Ly_TenL(wherex(),wherey(),chuoi);
				Chu_Thich_Tim_Kiem_Lop();
				break;
			case '3':
				Clear_Khung_Menu_Lop();
				gotoxy(x_trai+2,row1+1);
				cout<<"Nhap nien khoa: ";
				Xu_Ly_Nien_KhoaL(wherex(),wherey(),chuoi);
				Chu_Thich_Tim_Kiem_Lop();
			
				break;
			default:
				break;	
		}
	}while(chucnang!='0');
		Clear_Khung_Menu_Lop();
}
void Chu_Thich_Them_Lop(){
	Clear_Khung_Menu_Lop();
	SetColor(2);
	gotoxy(x_trai+1,row1+2);
	cout<<" Nhap ten lop ";
	gotoxy(x_trai+1,wherey()+2);
	cout<<" Nhap nien khoa ";
	gotoxy(x_trai+1,wherey()+2);
	cout<<" 0.Quay lai ";
	SetColor(15);
}
void Them_Lop(DSLOP &dslop){
	char chucnang;
	int chon=1;
	int stop=FALSE;
	string chuoi;
	Lop lop;
	Chu_Thich_Them_Lop();
	do{
		chucnang=getch();
		do{
			switch(chucnang){
			case UP:
				chon--;
				if(chon==0) chon=2;
				break;
			case DOWN:
				chon++;
				if(chon==3) chon=1;
				break;
			case '0':
				stop=TRUE;
				break;
			default: 
			break;
			}
		// 	if(stop!=TRUE){
		// 		switch(chon){
		// 			case 1:
		// 				Xu_Ly_TenL(lop.TENLOP);
		// 				break;
		// 			case 2:
		// 				Xu_Ly_Nien_KhoaL(lop.NIENKHOA);
		// 				break;
		// 			default:
		// 				break;	
		// 	}
		// }
		}while(chucnang!=ENTER&&stop!=TRUE);
	}while(chucnang!='0');
		Clear_Khung_Menu_Lop();
}
void Chu_Thich_Xoa_Lop(){
	Clear_Khung_Menu_Lop();
	SetColor(2);
	gotoxy(x_trai+1,row1+2);
	cout<<" 1.Xoa theo ma lop";
	gotoxy(x_trai+1,wherey()+2);
	cout<<" 2.Xoa theo ten lop";
	gotoxy(x_trai+1,wherey()+2);
	cout<<" 0.Quay lai ";
	SetColor(15);
}
void Xoa_Lop(DSLOP &dslop){
	char chucnang;
	int stop=FALSE;
	string chuoi;
	Chu_Thich_Xoa_Lop();
	do{
		chucnang=getch();
		switch(chucnang){
			case '1':
				Clear_Khung_Menu_Lop();
				chuoi=Xu_Ly_Ma();
				Chu_Thich_Xoa_Lop();
				break;
			case '2':
				Clear_Khung_Menu_Lop();
				Xu_Ly_TenL(wherex(),wherey(),chuoi);
				Chu_Thich_Xoa_Lop();
				break;
			case '0':
				break;
			default:
				break;	
		}
	}while(chucnang!='0');
		Clear_Khung_Menu_Lop();
}
void Run_Menu_Lop(DSLOP dslop){
	Khung_Lop();
	Khung_Menu_Lop();
	Chu_Thich_Lop();
	Chu_Thich_Menu_Lop();
	In_Danh_Sach_Lop(trang,dslop);
	
	char chucnang;
	gotoxy(0,35);
	int trang=1;
	do{
		chucnang=getch();
		switch(chucnang){
			case ESC:
				system("cls");
				gotoxy(0,10);
				cout<<"Ket thuc chuong trinh.";
				break;
			case '0'://quay lai
				system("cls");
				break;
			case '1'://quay lai
				Thay_Doi_Lop(dslop);
				Chu_Thich_Menu_Lop();
				break;
			case '2': //Tim kiem
				Tim_Kiem_Lop(dslop);
					Chu_Thich_Menu_Lop();
				break;
			case '3': //Them thong tin
				Them_Lop(dslop);
					Chu_Thich_Menu_Lop();
				break;
			case '4': //Them thong tin
				Xoa_Lop(dslop);
				Chu_Thich_Menu_Lop();
				break;
			default:
				break;
		}
	}while(chucnang!=ESC&&chucnang!='0');
}

//==========================================================
int main(){
	
	system("cls");
	resizeConsole(NGANG_CONSOLE,DAI_CONSOLE);//chinh kich thuoc console
	Disable_Resize_Window();// co dinh kich thuoc console

	Lop lop;
	DSLOP dslop;
	
	Read_File_ListL(dslop,"danhsachlop.txt");
//	Khung_Lop();
//	Khung_Menu_Lop();
	Run_Menu_Lop(dslop);
//	Cap_Nhat_Thong_Tin_Lop(lop);
	return 0;
}

