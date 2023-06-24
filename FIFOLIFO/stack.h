#pragma once
#include "purchase.h"

class stack
{
private:
	purchase stock[maxsize];
	int topindex;
public:
	stack();
	~stack();

	bool isEmpty();//checks if stack is empty
	bool isFull(); //checks if stack is full
	void enterstock(string n, int q, double p); //inserts new record
	void showprice(string n, int  q);
	void sellstock(string n, int q);
	void print(); //prints all records in the stack
	
	void pop();// pops top record
	int count();
	void change(int pos, int qty);
};

