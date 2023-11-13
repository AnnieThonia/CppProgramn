
#include "Bintree.h"
#include <fstream>

//! Binary Search Trees & Sorting  Program

/*! \Algorithm
     \brief  The algorithm starts by creating an instance of the Bintree class, reads in a text file and stores all 
     the unique words  in the binary search tree (Bintree).If a word already exists in the Bintree, its frequency
     is incremented.

    In the event that the file cannot be read, an error message is generated and the program terminates.

    Once all the words are inserted, the program enters a do-while loop presenting the user with a menu where they can 
    choose to print the words in the tree in different orders.

    To print the words in alphabetical order, the tree is traversed in-order, printing each node's word and whether 
    it is a palindrome or not.

    To print the words by frequency, the tree is traversed in-order, storing each node's word and frequency in a vector 
    of pairs. Once all nodes have been added to the vector, the vector is then sorted in descending  order of frequency 
    using the quicksort algorithm, and the words are printed in that order along with their reversed form.

    The user can also choose to print the entire tree in its current state, in which case the tree is traversed in-order
    and each node's word and frequency is printed.

    Finally, the program ends by deleting the binary search tree to free up memory.
 */

 /*! \file main.cpp
      \brief  creates a Bintree object, reads words from the input file, inserts them into the
      tree, and prints the tree structure, in alphabetical order with palindrom status, and by
      frequency in descending order.
  */

int main() {

    string input_file = "Text.txt", word;
    int choice = 0;
    Bintree tree;
  

    ifstream fin(input_file);

    if (!fin) {
        cerr << "Error: Could not open file " << input_file << endl;
        return 1;
    }

    // Read the file and build the BST
    while (fin >> word) {
        // Clean the word by removing punctuation marks and converting to lowercase
        word = tree.clean_word(word);
        if (!word.empty()) { // Ignore empty strings
            tree.insert(word);
        }
    }
    fin.close();

    do {
            cout << "\n What Operation do you want to perform? select option number or enter 0 to exit. \n" << endl;

            cout << "\t Enter 1 to Print all words alphabetically alongside palindrome status" << endl;
            cout << "\t Enter 2 to Print all words in descending order of occurence alongside word in reverse" << endl;
            cout << "\t Enter 3 for Tree structure" << endl;
            cout << "\t Enter 4 to to Clear screen" << endl;
            cout << "\t Enter 0 to Exit programm \n" << endl;

            cin >> choice;
            cout << endl;

            switch (choice) {

            case 0:
                exit(0);
                break;
            case 1:
                // Print all word counts alphabetically
                cout << "Word count in alphabetical order with frequency and palindrome status:" << endl;
                tree.printAlphabetical();
                break;
            case 2:
                // Print word counts by frequency
                cout << "Word count (sorted by frequency) along with reverse order and count:" << endl;
                tree.printByFrequency();
                break;
            case 3:
                cout << "Tree structure:" << endl;
                tree.print();
                break;
            case 4:
                //clears screen
                system("cls");
                break;
            default:
                cout << "Enter numbers between 1 and 4" << endl;
                break;
            }
    } while
        (choice != 0);
}

