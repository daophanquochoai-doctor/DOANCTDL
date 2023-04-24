#include<iostream>
#include<fstream>
#include "background.h"
//#include "ReadFile.h"


using namespace std;




void sig_in()
{
	int end = 1;
	while( end != 0 )
	{
		Disable_Resize_Window();
		string user, pass;
		console_loggin();
		Load(user,pass,end);
	}
}
											 
int main()
{
	Load_First(root);
	sig_in();
//	Disable_Resize_Window();
//	resizeConsole(1100, 630);
//	disPlaycauHoi(root, "toan", 1);
	getch();
	return 0;
}

