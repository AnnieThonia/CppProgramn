// Assessment_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "queue.h"
#include "stack.h"

using namespace std;

int main()
{
	stack stack_stock;
	queue queue_stock;

	int choice = 0;
	int q = 0; string n; double p; int exit_p = 1;

	do {
		cout << "\n What Operation do you want to perform? select option number. enter 0 to exit. \n" << endl;

		cout << "\t Enter 1 to Enter a purchase" << endl;
		cout << "\t Enter 2 to Find the LIFO and FIFO price" << endl;
		cout << "\t Enter 3 to Make a sale" << endl;
		cout << "\t Enter 4 to Display all purchase entered" << endl;
		cout << "\t Enter 5 to Clear screen" << endl;
		cout << "\t Enter 0 to Exit programm \n" << endl;

		cin >> choice;
		cout << endl;

		switch (choice) {

		case 0:
			exit(0);
			break;

		case 1:
			cout << "Enter name, quantity and price of stock and press enter: ";
			cin >> n >> q >> p;
			
			//data type validation
			while (cin.fail()) {
				cout << "\n\t Enter valid inputs: stockname and quantity and price please :";
				cin.clear();
				cin.ignore();
				cin >> n >> q >> p;
			}

			//pushing stock item to stack and queue respectively
			stack_stock.enterstock(n, q, p);
			queue_stock.enterstock(n, q, p);

			break;

		case 2:
			cout << "Enter name and quantity of stock to see LIFO/FIFO prices and press enter : " << endl;
			cin >> n >> q;
			//data type validation
			while (cin.fail()) {
				cout << "\n\t Enter valid inputs: stockname and quantity : ";
				cin.clear();
				cin.ignore();
				cin >> n >> q;
			}
			//Displaying stock price of provided stock name and quantity			
			stack_stock.showprice(n, q);
			queue_stock.showprice(n, q);
			break;

		case 3:
			cout << "Enter name, quantity of stock to be sold and press enter: ";
			cin >> n >> q;

			//data type validation
			while (cin.fail()) {
				cout << "\n\t Enter valid inputs: stockname and quantity : ";
				cin.clear();
				cin.ignore();
				cin >> n >> q;
			}

			//selling a stock item
			stack_stock.sellstock(n, q);
			queue_stock.sellstock(n, q);

			//stack_stock.pop();
			//queue_stock.dequeue();

			break;

		case 4:
			//displaying all records entered
			stack_stock.print();
			queue_stock.print();

			break;

		case 5:
			//clears screen
			system("cls");

			break;

		default:
			cout << "Enter numbers between 1 and 5" << endl;
			break;
		}
	} while
		(choice !=0);
	return 0;
}


