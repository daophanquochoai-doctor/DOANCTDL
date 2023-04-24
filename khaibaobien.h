#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<windows.h>
#define MonMax 300
#define LopMax 500
#define TRUE 1
#define FALSE 0
#define MAX 100000
//#define ENTER 13
//#define BACKSPACE 8
#define SPACE 32
#define CHU_A 65
#define CHU_Z 90
#define	CHU_a 97
#define CHU_z 142
#define SO_0 48
#define SO_957

int Array_ID[MAX];
int counter = 1;

//khoi tao mang ID
void InitArray_ID(int a[], int soluong )
{
	for( int i = 1 ; i <= soluong ; i++ )
	{
		a[i] = i;
	}
}

using namespace std;
struct MonHoc;
struct ListMH;
struct Lop;
struct ListL;
struct SinhVien;
struct nodesSV;
struct DiemThi;
struct nodeDT;
struct CauHoi;
struct nodeCH;
//=============================
struct DiemThi{
	string MMH;
	float Diem;
};
struct nodeDT{
	DiemThi dt;
	nodeDT *next;
};
typedef nodeDT *PTRDT;
//=============================
struct MonHoc{
	string MAMH, TENMH;
};
 struct ListMH{
	int n=0;
	MonHoc nodeMH[MonMax];
};
typedef ListMH dsmon;
//=============================

struct SinhVien{
	string MASV, HO, TEN, PHAI;	
	string password;
	PTRDT contro_dsdiem;
};
struct nodeSV{
	SinhVien sv;
	nodeSV *next;
};
typedef nodeSV *PTRSV;
//PTRSV FistSV=NULL;
//=============================
struct Lop{
	string MALOP,TENLOP;
	string NIENKHOA;
	PTRSV contro_dssv;
};
struct ListL{
	int n=0;
	Lop *nodeL[LopMax];
};
typedef ListL dslop;
//=============================

PTRDT FirstDT=NULL;
struct CauHoi{
	int ID;
	string mmh, noidung;
	string A,B,C,D,dapan;
};
struct nodeCH{
//	int	key;
	CauHoi cauhoi;
	nodeCH *left;
	nodeCH *right;
};
typedef nodeCH* NODEPTRCH;
NODEPTRCH root=NULL;//khoi tao
//=============================
//diem sinh vien mon hoc
