#include<iostream>
#include<string.h>
#include<random>
#include<time.h>
#include<fstream>
#include "Question.h"

using namespace std;



int main()
{
    NODEPTRCH root;
    system("cls");
    Initlize(root);
    Read_File_CauHoi(root,filecauhoi);
    // Traverse_LNR(root);
    // Create_node(root);
    // Traverse_LNR(root);
    // Write_File_CauHoi(root, filecauhoi);
	Create_Exam(root, 10, "toan");
    return 0;
}

