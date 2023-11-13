#include "queue.h"


// Constructor

queue::queue() : frontindex(-1), rearindex(-1) {}

// Destructor
queue::~queue()
{
	delete[]stock;
}

// Tests
bool queue::isEmpty()
{
	return (frontindex == -1 || frontindex > rearindex) ? true : false;
}

bool queue::isFull()
{
	return (rearindex== maxsize-1) ? true : false;
}


// Add purchased stock into queue
void queue::enterstock(string n, int q, double p)
{
	if (isFull())
		cout << "\n\t Queue overflow \n" << endl;

	else {
		if (frontindex == -1)
			frontindex = 0;
		rearindex++;
		stock[rearindex].quantity = q;
		stock[rearindex].name = n;
		stock[rearindex].price = p;
		cout << "\n\t Record added to Queue : " << q << " shares of " << n << " at " << p << " per share \n" << endl;
	}
}

// Sells most recent stock in the queue
void queue::dequeue()
{
	if (isEmpty()) {
		cout << "\n\t Empty Queue!! ";
		return;
	}
	else
	{
		cout << "\n\t Element sold from queue is: " << stock[frontindex].quantity << "Shares "
			<< stock[frontindex].name << " at " << stock[frontindex].price << endl;
		frontindex++;
	}
}

// Print all records entered in the queue
void queue::print()
{
	if (frontindex == -1)
	{
		cout << "\n Queue is Empty!!! No records to show \n" << endl;
	}
	else {
		cout << "\n Total Stock entered in Queue = " << count() << endl;
			for (int i = frontindex; i <= rearindex; i++) {
			cout << "\t " << stock[i].quantity << " shares of " << stock[i].name
				<< " at " << stock[i].price << " per share \n";
			}
	}
}

void queue::showprice(string n, int q)
{

	if (isEmpty())
	{
		cout << "\n Empty Queue!! " << endl;
	}
	else if (q <= stock[frontindex].quantity)
	{
		cout << "\n\t FIFO Price for  " << q << " Shares of " << n << " = ";
		for (int i = frontindex; i <= rearindex; i++) {
			if ((stock[i].name == n && q <= stock[i].quantity))
			{//FIFO Formulation
				cout << (((stock[frontindex].quantity * stock[frontindex].price) +
					((stock[frontindex].quantity + (stock[frontindex + 1].quantity) - q) * stock[i + 1].price)) / q) 
					<< " per share \n " << endl;
				break;
			}
		}
	}

	else if (q > stock[frontindex].quantity)
	{
		int sum = 0;
		for (int i = frontindex; i <= rearindex; i++) {
			if (stock[i].name == n) {
				sum = sum + stock[i].quantity;
			}
		}
			cout << "\n\t FIFO Price for  " << q << " Shares of " << n << " = ";
		for (int i = frontindex; i <= rearindex; i++) {
			if ((stock[i].name == n && q <= sum))
			{//FIFO Formulation
				cout << (((stock[i].quantity * stock[i].price) +
					((stock[i].quantity + (stock[i + 1].quantity) - q) * stock[i + 1].price)) / q)
					<< " per share \n " << endl;
				break;
			}
		}
		for (int i = frontindex; i <= rearindex; i++) {
			if ((stock[i].name == n && q > sum))
			{
				cout << "Stock cannot be found in queue!!" << endl;
				break;
			}
		}
	}
}

//queue size
int queue::count() {
	return (rearindex - frontindex + 1);
}

//change stock quantity at a provided index
void queue::change(int pos, int qty) {
	stock[pos].quantity = qty;
}


// selling stock of certain name n and quantity q
void queue::sellstock(string n, int q)
{
	if (isEmpty()) {
		cout << "\t Empty Queue!! ";
		return;
	}

	else if (q <= stock[frontindex].quantity)
	{
		cout << "\n" << q << " Shares of " << n << "Sold at FIFO price of:  ";
		for (int i = frontindex; i <= rearindex; i++) {
			if ((stock[frontindex].name == n && q <= stock[frontindex].quantity))
			{//FIFO Formulation
				cout << (((stock[frontindex].quantity * stock[frontindex].price) +
					((stock[frontindex].quantity + (stock[frontindex + 1].quantity) - q) * stock[i + 1].price)) / q) << " per share "
				 << "\t **** NOT SURE I GOT THE CORRECT LOGIC**** " << endl;
				int newqty = stock[frontindex].quantity - q;
				change(frontindex, newqty);
				break;
			}
		}
	}

	else if (q > stock[frontindex].quantity)
	{
		int sum = 0;
		for (int i = frontindex; i <= rearindex; i++) {
			if (stock[i].name == n) {
				sum = sum + stock[i].quantity;
			}
		}
		cout << "\n" << q << " Shares of " << n << "Sold at FIFO price of:  ";
		for (int i = frontindex; i <= rearindex; i++) {
			if ((stock[i].name == n && q <= sum))
			{//FIFO Formulation
				cout << (((stock[i].quantity * stock[i].price) +
					((stock[i].quantity + (stock[i + 1].quantity) - q) * stock[i + 1].price)) / q)
					<< " per share "
				 << "\t **** NOT SURE I GOT THE CORRECT LOGIC**** " << endl;
				int newqty = stock[i].quantity - q;
				change(i--, 0);
				change(i, newqty);
				break;
			}
		}
		for (int i = frontindex; i <= rearindex; i++) {
			if ((stock[i].name == n && q > sum))
			{
				cout << "Stock cannot be found in queue !!" << endl;
				break;
			}
		}
	}
}

