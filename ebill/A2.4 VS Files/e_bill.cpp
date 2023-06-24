
//***************************************************************
//    	FUNCTION DECLARATION
//****************************************************************

#include "e_bill.h"

void e_bill::get() //secondary constructors: get inputs from user

{
    cout << "\n\nFollow below prompts to calculate your bill:: \n" << endl;
    cout << "Enter Customer Number. :: ";
    cin >> customer_no;
    cout << "\nEnter Customer First Name :: ";
    cin >> customer_name;
    cout << "\nEnter No. of Units used :: ";
    cin >> units;
    cout << endl;

    system("pause");
    system("cls");
}
// Driver Function : takes in user input and assigns to variables

void e_bill::put()
{
    cout << "\n**** Customer Details and Calculated Bill is :: " << endl;
    cout << "\nCustomer Number. is : " << customer_no;
    cout << "\n\nCustomer First Name is : " << customer_name;
    cout << "\n\nNumber of Units Consumed = " << units;
    cout << "\n\nTotal Bill Payable = " << bill << endl;
 
    system("pause");
    system("cls");
}

void e_bill::calc_bill() //  Driver functions to  calculate bill of units consumed
{
    
    if (units <= 100)
        bill = units * 1.20;
    else if (units <= 300)
        bill = 100 * 1.20 + (units - 100) * 2;
    else
        bill = 100 * 1.20 + 200 * 2 + (units - 300) * 3;

    
}
void e_bill::print_bill() {

    ofstream out("Electricity_bill.txt");

    out << "Hello " << customer_name << ", " << "\n\n\tCustomer ID: " << customer_no <<
        "\n\tUnits Consumed: " << units <<
        "\n\tTotal Amount Payable: " << bill
        << "\nThank You." << endl;
    out.close();

    cout << "\n\n\n*****Receipt can now be collected at the counter" << "\n!!!Thank You";
}
