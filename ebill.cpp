/* asgnmnt2.cpp : a C++ program which enables the user to calculate their monthly mobile phone bill.
Busayo Fisuyi (100011948)
on 30/10/2022

RSEUDOCODE:
1. set variables for the fixed current rate and discounts
2. create a function to call for uer input on account details, plan and total minutes
3. create another function to apply discounts using if loop and calculate total bills
4. create another function to output bill
*/

#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

void getPlan_Minutes(char& plan, int& minutes);
void geteBill(char PLAN, int MINUTES, double& F, double& M, double& B);
void printBill(char PLAN, int MINUTES, double F, double M, double B, int account);

//constants
double const PLAN_F = 150.00;      //F - monthly charge for fixed rate plan
double const PLAN_M = 1.00;         //M - monthly base charge for per minute charge plan
double const PLAN_B = 1.50;         //B - monthly base charge for Per minute plus customer plan
double const discount1 = 0.00;      // no refund for up to first 100mins
double const discount2 = 0.05;      // 5% discount for minutes between 100 and 200
double const discount3 = 0.10;      // 10% discount for minutes between 200 and 400
double const discount4 = 0.15;      // 15% discount for minutes over 400
double const per_minute_rate = 0.15;      // 15pence per minute call rate


int main()
{
    int account;
    char plan;
    int minutes;
    char getPlan;
    int getMinutes;
    double billF;
    double billM;
    double billB;
   
    cout << "This program will calculate and show you your cellular phone bill for the month." << endl << endl;

    do {
        cout << "Please input last 5 digit of your mobile number: ";
        cin >> account;
        cout << endl;
        if ((account < 10000) || (account > 99999))
            cout << "Your account number is not valid" << endl << endl;
    } while ((account < 10000) || (account > 99999));

    getPlan_Minutes(plan, minutes);
    geteBill(plan, minutes, billF, billM, billB);
    printBill(plan, minutes, billF, billM,billB, account);

  
    return 0;
}

void getPlan_Minutes(char& plan, int& minutes)
{
    cout << "AVAILABLE PLANS:" << endl;
    cout << "F - Fixed Rate Plan" << endl;
    cout << "M - Per Minute Charge Plan " << endl;
    cout << "B - Per Minute Charge Plus plan" << endl << endl;
    cout << "Please choose the letter of your plan from above (F/M/B): ";
    cin >> plan;
    plan = toupper(plan);
    cout << endl << "Your chosen plan is: " << endl;


    // Read letter of plan and output description

    switch (plan) { //start switch plan
    case 'F':
        cout << "F - A Fixed rate plan with flat service charge of 150 Pounds and comes with unlimited minutes. *** NO DISCOUNT AVAILABLE ***" << endl
            << " " << endl;
           
        break;

    case 'M':
        cout << "M - A Per minute plan with a monthly base charge of One pound at 15 pence per minute. *** NO DISCOUNT AVAILABLE ***" << endl;
        cout << " " << endl;
        cout << "Please enter your minutes used: ";
        cin >> minutes;
        for (; minutes < 0; )
        {
            cout << "Invalid number, please enter a number above 0: ";
            cin >> minutes;
        }
        cout << endl;
        break;

    case 'B':
        cout << "B - A Per minute plus plan with a monthly base charge of 1.50 Pound at 15 pence per minute. *** WITH DISCOUNT UP TO 15% ***" << endl;
        cout << " " << endl;
        cout << "Please input your minutes used: ";
        cin >> minutes;
        if (minutes >=100 && minutes <200)
        {
            cout << "A 5% discount will be applied to your total bill" << endl;
        }
        else if (minutes >= 200 && minutes < 400)
        {
            cout << "A 10% discount will be applied to your total bill" << endl;
        }
        else if (minutes >= 400)
        {
            cout << "A 15% discount will be applied to your total bill" << endl;
        }
        
        for (; minutes < 0; )
        {
            cout << "Invalid number, please enter a number above 0: ";
            cin >> minutes;
        }
        cout << endl;
        break;

    default:
        cout << "Please enter a valid plan letter from above: ";
        cin >> plan;
        break;

    }  //end switch plan
    cout << " " << endl;
}    //end function


void geteBill(char PLAN, int MINUTES, double& F, double& M, double& B)
{
    double billB = PLAN_B + (per_minute_rate * MINUTES);
    double discount = 0.00;

    if (PLAN == 'F')
        F = double(PLAN_F);
    else if (PLAN == 'M')
        M = double(PLAN_M + (per_minute_rate * MINUTES));
    else if (PLAN == 'B')
        if (MINUTES <= 100)
            B = billB; //no discount
        else if (MINUTES > 100 || MINUTES <200)
            B = billB - (discount2 * billB);// applyimg 5% discount

        else if (MINUTES >= 200 || MINUTES < 400)
            B = billB - (discount3 * billB);// applyimg 10% discount

        else if (MINUTES >= 400)
            B = billB - (discount4 * billB);// applyimg 15% discount

    cout << " " << endl;
}

void printBill(char PLAN, int MINUTES, double F, double M,  double B, int account)
{
    double total=0.00;
    cout << "***** Your Monthly Bill *****" << endl << endl;
    cout << "Your Mobile number ending: ******" << account << endl;
    cout << "Monthly Plan:" << PLAN << endl;
        if (PLAN != 'F')
        cout << "Your minutes:" << fixed << showpoint << setprecision(2) << setw(3) << MINUTES << endl;
    cout << "Total Amount Due in Pounds: " ;

    switch (PLAN) {               //start switch plan

    case 'F':
         total = F;
        break;

    case 'M':
         total = M;
        break;
    case 'B':
        total = B;
        break;
    }
    cout << total << endl;
    cout << " " << endl;
}

