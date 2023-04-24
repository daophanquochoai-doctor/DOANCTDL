#include "khaibaobien.h"
#include<time.h>
#include<random>
#include<string.h>

string filecauhoi = "cauhoi.txt";

//khoi tao nut
void Initlize( NODEPTRCH &root ){
	root = NULL;
}

//random
int Random( int Array[], int Soluong, int &dem )
{
	int	ID = rand() % (Soluong-dem) + dem;
	swap(Array[dem] , Array[ID]);
	dem++;
	return Array[dem-1];
}

//swap
void swap( int &a, int &b )
{
	int temp = a;
	a = b;
	b = temp;	
}

// tao node
CauHoi Create_CauHoi( string mmh, string noidung, string A, string B, string C, string D, string dapan )
{
	CauHoi p;
	p.ID = Random(Array_ID, MAX, counter);
	p.mmh = mmh;
	p.noidung = noidung;
	p.A = A;
	p.B = B;
	p.C = C;
	p.D = D;
	p.dapan = dapan;
	return p;
}

//them vao nut
void Insert_node( NODEPTRCH &root, CauHoi cauhoi ){
	if( root == NULL )
	{
		root = new nodeCH;
		root->cauhoi = cauhoi;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		if( cauhoi.ID < root->cauhoi.ID )	Insert_node(root->left, cauhoi);
		else if( cauhoi.ID > root->cauhoi.ID ) Insert_node(root->right, cauhoi);
	}
}

//tao 1 cau hoi vao tree
void Create_node( NODEPTRCH &root, string mmh)
{
	string noidung, A, B, C, D, dapan;
	cout << "Nhap noi dung cau hoi: ";
	getline(cin,noidung);
	cout << "Nhap dap an A: ";
	getline(cin,A);
	cout << "Nhap dap an B: ";
	getline(cin,B);
	cout << "Nhap dap an C: ";
	getline(cin,C);
	cout << "Nhap dap an D: ";
	getline(cin,D);
	cout << "Nhap dap an: ";
	getline(cin, dapan);
	CauHoi cauhoi = Create_CauHoi(mmh,noidung,A,B,C,D,dapan);
	Insert_node(root, cauhoi);
}

//doc cau hoi tu file
void Read_File_CauHoi(NODEPTRCH& root, string filecauhoi) {
    InitArray_ID(Array_ID, MAX);
    ifstream fin(filecauhoi);
    if (!fin.is_open()) {
        cout << "Khong the mo file" << endl;
        return;
    }
    string line;
    while (getline(fin, line)) {
        istringstream iss(line);
        string mmh, noidung, A, B, C, D, dapan;
        getline(iss, mmh, '|');
        getline(iss, noidung, '|');
        getline(iss, A, '|');
        getline(iss, B, '|');
        getline(iss, C, '|');
        getline(iss, D, '|');
        getline(iss, dapan, '|');

        CauHoi cauhoi = Create_CauHoi(mmh, noidung, A, B, C, D, dapan);
        Insert_node(root, cauhoi);
    }

    fin.close();
}

//in tree theo left node right
void Traverse_LNR( NODEPTRCH root )
{
	NODEPTRCH p = root;
	if( p != NULL )
	{
		Traverse_LNR(p->left);
		cout << p->cauhoi.ID << endl << p->cauhoi.mmh << endl << p->cauhoi.noidung << endl << p->cauhoi.A << endl << p->cauhoi.B << endl << p->cauhoi.C << endl << p->cauhoi.D << endl << p->cauhoi.dapan << endl << "==================" << endl;
		Traverse_LNR(p->right);
	}
}

//viet cau hoi vao file
void Write_File_CauHoi( NODEPTRCH root, string filecauhoi ){
	ofstream ofn(filecauhoi, ios::out );
    if (!ofn.is_open()) {
        cout << "Khong the mo file!";
        return;
    }
	const int STACKSIZE = MAX;
    NODEPTRCH Stack[STACKSIZE];
    int sp=  -1;	// Khoi tao Stack rong
    NODEPTRCH p=root;
    while (p!=NULL )
    {   
        ofn << p->cauhoi.mmh << '|'<< p->cauhoi.noidung << '|' << p->cauhoi.A << '|' << p->cauhoi.B << '|' << p->cauhoi.C << '|' << p->cauhoi.D << '|' << p->cauhoi.dapan << '|' << endl;   // “xu ly nút p”
        if (p->right != NULL)
        Stack[++sp]= p->right;
        if (p->left != NULL)
        p=p->left;
        else  if (sp==-1)        break;
	    else	p=Stack[sp--];
    }
	ofn.close();
}

//search mmh
void Search( NODEPTRCH root, string mmh)
{
   	 CauHoi Cau[100];
    int dem = 1;
   	const int STACKSIZE = MAX;
    NODEPTRCH Stack[STACKSIZE];
    int sp=  -1;	// Khoi tao Stack rong
    NODEPTRCH p=root;
    while (p!=NULL )
    {   
        if( mmh == p->cauhoi.mmh)
        {
            Cau[dem].ID = p->cauhoi.ID;
            Cau[dem].mmh = p->cauhoi.mmh;
            Cau[dem].noidung = p->cauhoi.noidung;
            Cau[dem].A = p->cauhoi.A;
            Cau[dem].B = p->cauhoi.B;
            Cau[dem].C = p->cauhoi.C;
            Cau[dem].D = p->cauhoi.D;
            Cau[dem].dapan = p->cauhoi.dapan;
            dem ++;
        }
        if (p->right != NULL)
        Stack[++sp]= p->right;
        if (p->left != NULL)
        p=p->left;
        else  if (sp==-1)        break;
	    else	p=Stack[sp--];
    }
    for( int i = 1 ; i < dem ; i++ )
    {
        cout << Cau[i].noidung;
    }
}

int totalQues( NODEPTRCH root, string mmh )
{
    int dem = 0;
   	const int STACKSIZE = MAX;
    NODEPTRCH Stack[STACKSIZE];
    int sp=  -1;	// Khoi tao Stack rong
    NODEPTRCH p=root;
    while (p!=NULL )
    {   
        if( mmh == p->cauhoi.mmh)
        {
            dem ++;
        }
        if (p->right != NULL)
        Stack[++sp]= p->right;
        if (p->left != NULL)
        p=p->left;
        else  if (sp==-1)        break;
	    else	p=Stack[sp--];
    }	
    return dem;
}

//xuat cau hoi
CauHoi* Create( NODEPTRCH root, int socau, string mmh)
{
    CauHoi Cau[200];
    int dem = 1;
   	const int STACKSIZE = MAX;
    NODEPTRCH Stack[STACKSIZE];
    int sp=  -1;	// Khoi tao Stack rong
    NODEPTRCH p=root;
    while (p!=NULL )
    {   
        if( mmh == p->cauhoi.mmh)
        {
            Cau[dem].ID = p->cauhoi.ID;
            Cau[dem].mmh = p->cauhoi.mmh;
            Cau[dem].noidung = p->cauhoi.noidung;
            Cau[dem].A = p->cauhoi.A;
            Cau[dem].B = p->cauhoi.B;
            Cau[dem].C = p->cauhoi.C;
            Cau[dem].D = p->cauhoi.D;
            Cau[dem].dapan = p->cauhoi.dapan;
            dem ++;
        }
        if (p->right != NULL)
        Stack[++sp]= p->right;
        if (p->left != NULL)
        p=p->left;
        else  if (sp==-1)        break;
	    else	p=Stack[sp--];
    }
    return Cau;
}

// tao de thi
CauHoi* Create_Exam( NODEPTRCH root, int socau, string mmh)
{
    CauHoi Cau[200];
    CauHoi dsCau[200];
    int dem = 1;
   	const int STACKSIZE = MAX;
    NODEPTRCH Stack[STACKSIZE];
    int sp=  -1;	// Khoi tao Stack rong
    NODEPTRCH p=root;
    while (p!=NULL )
    {   
        if( mmh == p->cauhoi.mmh)
        {
            Cau[dem].ID = p->cauhoi.ID;
            Cau[dem].mmh = p->cauhoi.mmh;
            Cau[dem].noidung = p->cauhoi.noidung;
            Cau[dem].A = p->cauhoi.A;
            Cau[dem].B = p->cauhoi.B;
            Cau[dem].C = p->cauhoi.C;
            Cau[dem].D = p->cauhoi.D;
            Cau[dem].dapan = p->cauhoi.dapan;
            dem ++;
        }
        if (p->right != NULL)
        Stack[++sp]= p->right;
        if (p->left != NULL)
        p=p->left;
        else  if (sp==-1)        break;
	    else	p=Stack[sp--];
    }
    int Array_mmh[dem];
    InitArray_ID(Array_mmh, dem-1);
    int counter_mmh = 1;
    srand((int)time(0));
    for( int i = 1; i <= socau ; i++ )
    {
        int ID = Random(Array_mmh, dem,counter_mmh );
       	dsCau[i] = Cau[ID];
    }
    return dsCau;
}
