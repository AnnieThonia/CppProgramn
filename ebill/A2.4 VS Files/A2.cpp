// A2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Busayo Fisuyi (100011948) on 17 / 12 / 2022

#include "e_bill.h"
#include <stdlib.h>

int main() // Driver Body

{
 cout << "\n\n\t            ";
 cout << " C++ Project On Electricity Bill Calculation" << endl;
    e_bill b1;
    b1.get();

    b1.calc_bill();
    b1.put();

    b1.print_bill();

    cout << "\n";

    return 0;
}