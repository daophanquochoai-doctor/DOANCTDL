#include<iostream>
#include<fstream>
#include "clock.h"
#include<thread>
//#include "ReadFile.h"


using namespace std;

int main()
{
	Disable_Resize_Window();
	resizeConsole(1100, 630);
	NODEPTRCH root;
    system("cls");
    Initlize(root);
    Read_File_CauHoi(root,filecauhoi);
	startTimer( root, 10, "toan");
	getch();
	return 0;
}

