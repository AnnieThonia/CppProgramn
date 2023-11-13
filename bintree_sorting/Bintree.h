#ifndef BINTREE_H
#define BINTREE_H
#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//#include "node.h"
/*! \file Bintree.h
     \brief A binary search tree data structure that stores strings as its nodes.
     
     Provides methods for inserting new strings, printing the strings in different orders, 
     and deleting the tree, removes punctuation and converts all words to
*/

class Bintree {

protected:
    struct Treenode {
        string word;
        int freq;
        Treenode* left;
        Treenode* right;
        Treenode(const string& k) : word(k), freq(1), left(nullptr), right(nullptr) {}
    };
    Treenode* root;
    vector<pair<string, int>> pairs;

    void deleteTree(Treenode* node);
    void insertHelper(Treenode*& node, string word);
    void printHelper(Treenode* node) const;
    void printAlphaHelper(Treenode* node);
    void printByFreqHelper(Treenode* node);
    bool isPalindrome(const string& str);
    string reverseString(const string& str);
    int partition(vector<pair<string, int>>& vec, int left, int right);
    void quicksort(vector<pair<string, int>>& vec, int left, int right);

  

public:
    Bintree();
    ~Bintree();
    string clean_word(const string& word);
    void insert(string word);
    void print() const;
    void printAlphabetical();
    void printByFrequency();
};

#endif /* BINTREE_H */



