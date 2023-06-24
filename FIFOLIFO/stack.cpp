#include "stack.h"


int q; string n; double p;


stack::stack() : topindex(-1) {} //Constructor

stack::~stack() { delete[] stock; } //Destructor

// Check if the stack is empty
bool stack::isEmpty() {
	return (topindex == -1) ? true : false;
}

bool stack::isFull() {
	return (topindex == maxsize - 1) ? true : false;
}

// Add purchased stock into stack
void stack::enterstock(string n, int q, double p) {
	if (isFull()) {
		cout << "\n\t stack overflow \n" << endl;
	}
	else {
		topindex++;
		stock[topindex].quantity = q;
		stock[topindex].name = n;
		stock[topindex].price = p;
		cout << "\n\t Record added to Stack : " << q << " shares of " << n << " at " << p << " per share" << endl;
	}
}

// sell most recent stock in the stack
void stack::pop() {
	if (isEmpty()) {
		cout << "\n\t Empty Stack!! \n" << endl;
	}
	else {
		cout << "\n\t Element sold from stack is: " << stock[topindex].quantity << "Shares "
			<< stock[topindex].name << " at " << stock[topindex].price << endl;
		topindex--;
	}
}

// Print all records entered in the stack
void stack::print() {

	if (topindex == -1)
	{
		cout << "\n Empty Stack!! \n" << endl;
	}
	else {
		cout << "\n Total Stock entered in stack = " << count() << endl;
		for (int i = topindex; i >= 0; i--) {
			cout << "\t " << stock[i].quantity << " shares of " << stock[i].name
				<< " at " << stock[i].price << " per share \n" ;
		}
	}
}

// Searching a price for a particular record in the stack
void stack::showprice(string n, int q)
{
	if (topindex == -1)
	{
		cout << "\n Empty Stack!! \n" << endl;
	}

	else if (q <= stock[topindex].quantity)
	{
		cout << "\n\t LIFO Price for  " << q << " Share of " << n << " = ";
		for (int i = topindex; i >=0; i--) {
			if ((stock[i].name == n && q <= stock[i].quantity))
			{//LIFO Formulation
				cout << (q * stock[i].price / q) << " per share "
					<< "\t **** NOT SURE I GOT THE CORRECT LOGIC**** " << endl;
				break;
			}
		}
	}
	else if (q > stock[topindex].quantity) {
		cout << "\n\t LIFO Price for  " << q << " Shares of " << n << " = ";
		int sum = 0;
		for (int i = topindex; i >= 0; i--) {
			if (stock[i].name == n) {
					sum = sum + stock[i].quantity;
			}
		}
		for (int i = 0; i < maxsize; i++) {
			if ((stock[i].name == n && q < sum))
				{//LIFO Formulation
				cout << (q * stock[i].price / q) << " per share" 
				 << "\t **** NOT SURE I GOT THE CORRECT LOGIC**** " << endl;
					break;
			}
		}
		for (int i = 0; i < maxsize; i++) {
			if ((stock[i].name == n && q > sum))
			{
				cout << "Stock cannot be found in stack!!" << endl;
				break;
			}
		}
	}
}
	
//stack size
int stack::count() {
	return (topindex + 1);
}

//change stock quantity at a provided index
void stack::change(int pos, int qty) {
	stock[pos].quantity = qty;
}

// selling stock of certain name n and quantity q
void stack::sellstock(string n, int q)
{
	if (topindex == -1)
	{
		cout << "\n\t Empty Stack!! \n" << endl;
	}
	else if (q<= stock[topindex].quantity)
	{
		cout << "\n " << q << " Share of " << n << " sold at LIFO price of: ";
		for (int i = topindex; i >= 0; i--) {
			if ((stock[i].name == n && q <= stock[i].quantity))
			{
				int newqty =  stock[topindex].quantity-q;
				 change(i, newqty);
				 //LIFO Formulation
				 cout << ((q * stock[i].price) / q) << " per share "
				 << "\t **** NOT SURE I GOT THE CORRECT LOGIC **** " << endl;
				break;
			}
		}
	}
	else if (q > stock[topindex].quantity) {
		cout << "\n " << q << " Shares of " << n << " sold at LIFO price of : ";
		int sum = 0;
		for (int i = 0; i < maxsize; i++) {
			if (stock[i].name == n) {
				sum = sum + stock[i].quantity;
			}
		}
		for (int i = 0; i < maxsize; i++) {
			if ((stock[i].name == n && q < sum))
			{
				int newqty = (sum - stock[topindex].quantity - q);
				change(i++, 0);
				change(i, newqty);
				//LIFO Formulation
				cout << (q * stock[i].price / q) << " per share \n "
				 << "\t **** NOT SURE I GOT THE CORRECT LOGIC**** " << endl;
				break;
			}
		}
		for (int i = 0; i < maxsize; i++) {
			if ((stock[i].name == n && q > sum))
			{
				cout << "Stock cannot be found in stack !!" << endl;
				break;
			}
		}
	}
}
