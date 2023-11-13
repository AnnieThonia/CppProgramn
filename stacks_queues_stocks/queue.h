#pragma once
#include<iostream>
#include "purchase.h"

class queue
{
private:
	purchase stock[maxsize];
	int frontindex;
	int rearindex;
	
public:
	queue();
	~queue();

	bool isEmpty();//checks if queue is empty
	bool isFull();//checks if queue is full

	void enterstock(string n, int q, double p); //inserts new record
	void print();// prints all records in the queue
	void showprice(string n, int  q);
	void sellstock(string n, int  q);
	
	void dequeue(); // pops top record
	int count();
	void change(int pos, int qty);
};

