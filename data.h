#include <iostream>
#include <fstream>
#include "list.h"
#pragma once
using namespace std;
void readFile(List &l)
{
    cout << "Da doc file" << endl;
    int data;
    ifstream myfile("input.txt");
    while (!myfile.eof())
    {
        myfile >> data;
        l.push_back(data);
    }
    myfile.close();
}