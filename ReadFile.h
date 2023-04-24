
#include<fstream>

using namespace std;

struct account
{
	string user;
	string pass;
	account *next;
};

typedef account *acc;
acc A=NULL,B=NULL,C=NULL,D=NULL,E=NULL,F=NULL,G=NULL,H=NULL,I=NULL,J=NULL,K=NULL,L=NULL,M=NULL,N=NULL,O=NULL,P=NULL,Q=NULL,R=NULL,S=NULL,T=NULL,U=NULL,V=NULL,W=NULL,X=NULL,Y=NULL,Z=NULL;

void Init_DanhSach()
{
	A=NULL;
	B=NULL;
	C=NULL;
	D=NULL;
	E=NULL;
	F=NULL;
	G=NULL;
	H=NULL;
	I=NULL;
	J=NULL;
	K=NULL;
	L=NULL;
	M=NULL;
	N=NULL;
	O=NULL;
	P=NULL;
	Q=NULL;
	R=NULL;
	S=NULL;
	T=NULL;
	U=NULL;
	V=NULL;
	W=NULL;
	X=NULL;
	Y=NULL;
	Z=NULL;
}

void Insert_First_Account( acc &ac, string user, string pass)
{
	acc p = new account;
	p->user = user;
	p->pass = pass;
	p->next = ac;
	ac = p;
}

void Read_File_Account( string filename )
{
	ifstream in(filename, ios::in);
	string user, pass;
	while( in >> user )
	{
		in >> pass;
		switch( user[0] )
		{
			case 'a':
			case 'A':
				{
					Insert_First_Account(A,user,pass);
					break;
				}
			case 'b':
			case 'B':
				{
					Insert_First_Account(B,user,pass);
					break;
				}
			case 'c':
			case 'C':
				{
					Insert_First_Account(C,user,pass);
					break;
				}
			case 'd':
			case 'D':
				{
					Insert_First_Account(D,user,pass);
					break;
				}
			case 'e':
			case 'E':
				{
					Insert_First_Account(E,user,pass);
					break;
				}
			case 'f':
			case 'F':
				{
					Insert_First_Account(F,user,pass);
					break;
				}
			case 'g':
			case 'G':
				{
					Insert_First_Account(G,user,pass);
					break;
				}
			case 'h':
			case 'H':
				{
					Insert_First_Account(H,user,pass);
					break;
				}
			case 'i':
			case 'I':
				{
					Insert_First_Account(I,user,pass);
					break;
				}
			case 'j':
			case 'J':
				{
					Insert_First_Account(J,user,pass);
					break;
				}
			case 'k':
			case 'K':
				{
					Insert_First_Account(K,user,pass);
					break;
				}
			case 'l':
			case 'L':
				{
					Insert_First_Account(L,user,pass);
					break;
				}
			case 'm':
			case 'M':
				{
					Insert_First_Account(M,user,pass);
					break;
				}
			case 'n':
			case 'N':
				{
					Insert_First_Account(N,user,pass);
					break;
				}
			case 'o':
			case 'O':
				{
					Insert_First_Account(O,user,pass);
					break;
				}
			case 'p':
			case 'P':
				{
					Insert_First_Account(P,user,pass);
					break;
				}
			case 'q':
			case 'Q':
				{
					Insert_First_Account(Q,user,pass);
					break;
				}
			case 'r':
			case 'R':
				{
					Insert_First_Account(R,user,pass);
					break;
				}
			case 's':
			case 'S':
				{
					Insert_First_Account(S,user,pass);
					break;
				}
			case 't':
			case 'T':
				{
					Insert_First_Account(T,user,pass);
					break;
				}
			case 'u':
			case 'U':
				{
					Insert_First_Account(U,user,pass);
					break;
				}
			case 'v':
			case 'V':
				{
					Insert_First_Account(V,user,pass);
					break;
				}
			case 'w':
			case 'W':
				{
					Insert_First_Account(W,user,pass);
					break;
				}
			case 'x':
			case 'X':
				{
					Insert_First_Account(X,user,pass);
					break;
				}
			case 'y':
			case 'Y':
				{
					Insert_First_Account(Y,user,pass);
					break;
				}
			case 'z':
			case 'Z':
				{
					Insert_First_Account(Z,user,pass);
					break;
				}
		}
	}
	in.close();
}


