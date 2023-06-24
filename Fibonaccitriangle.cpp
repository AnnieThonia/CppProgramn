/* asgnmnt1.cpp : a C++ program using functions which produces a series of triangles pointing to the right,drawn with a keyboard character such as the*
Busayo Fisuyi (100011948)
on 30/10/2022

PSEUDOCODE:
1. define variables and declare function
2. define function to print required triangle
	a. write a for loop to print the upper half of the triangle
	b. write another for loop to print the lower half of the triangle
	c. print out wave
3. call for user input for character to be printed, size and height of triangle.
4. write a while loop to count down wave size  and call the function
*/

#include <iostream>
#include<time.h>

using namespace std;

void print_triangle(int height, char symbol);
void printWave(int wave_length, int wave_height, char character);

const int MILLISECONDS = 100; // time-delay in seconds


int main() {

	int wave_height, wave_size;
	char character;
	bool answer;

	cout << "******************************************\n"
		<< "*    Printing a right pointed triangle     \n*"
		<< "*******************************************\n" << endl;
	cout << "\n";
	cout << "What character would you like printed? ";
	cin >> character;
	cout << "\n";
	cout << "Enter wave height and Number of waves :" << endl;
	cin >> wave_height >> wave_size;
	cout << "Do you require wave of same length? (1 for YES, 0 for NO): " << endl;
	cin >> answer;
	cout << "\n";

	if (answer == 1) {

		printWave(wave_size, wave_height, character);

		cout << "\n";
	}
	else {
		cout << "***************************************************\n"
			<< "             !!!!!!! SORRY !!!!!!!                   \n"
			<< "Do not know how to print triangles of varying lengths \n"
			<< "*******************************************************\n" << endl;
		cout << "\n";
	}
	
	return 0;
}

void print_triangle(int wave_height, char character) {

	clock_t goal = MILLISECONDS + clock();

	while (goal > clock());

	// loop to print triangle

	for (int i = 1; i <= wave_height; i++) { //print rows

		for (int j = 0; j < i; j++) {//print columns
			cout << character;
		}
		cout << "\n";
	}
	// reverse the previous loop to complete the triangle
	for (int i = 1; i <= wave_height - 1; i++) {
		for (int j = 0; j < wave_height - i; j++) {
			cout << character;
		}
		cout << "\n";
	}

}
void printWave(int wave_size, int wave_height, char character) {

	// for loop for wave length
	for (int j = 1; j <= wave_size; j++) {

		print_triangle(wave_height, character);
	}

}