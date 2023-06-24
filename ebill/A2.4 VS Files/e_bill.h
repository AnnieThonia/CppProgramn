#pragma once
#include <iostream>
#include<fstream>

using namespace std;


//***************************************************************
//    	CLASS DECLARATION
//****************************************************************

class e_bill
{
private: // defines custommers attributes
    int customer_no;
    char customer_name[50];
    int units;
    double bill;

public: //  call functions to get variables : Accessor Functions
    void get();
    void put();
    void calc_bill();
    void print_bill();
};
