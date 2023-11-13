
#include "Bintree.h"

/**
    Constructor that initializes the 'root' pointer to nullptr
*/
Bintree::Bintree() : root(nullptr) {}

/**
    Destructor that deallocates the memory used by the Bintree. using the deleteTree function 
*/
Bintree::~Bintree() {
    deleteTree(root);
}

/**
    @brief  helper function for the destructor. It recursively deallocates Bintree memory.
    @param n The starting node for deletion
*/
void Bintree::deleteTree(Treenode* n) {
    if (n != nullptr) {
        deleteTree(n->left);
        deleteTree(n->right);
        delete n;
    }
}
/**
    @brief inserts a new node into the tree with the given word. If the word exists, it counts up.
    @param word The string to be inserted
    @return true if word does not exist, count up if otherwise.
*/

void Bintree::insertHelper(Treenode*& node, string word) {
    if (node == nullptr) {
        node = new Treenode(word);
        return;
    }
    if (word == node->word) {
        node->freq++;
        return;
    }
    if (word < node->word) {
        insertHelper(node->left, word);
    }
    else {
        insertHelper(node->right, word);
    }
}

/**
    @brief a wrapper function for insertHelper. It inserts a new node into the tree
    with the given word.
    @param word to be inserted
*/
void Bintree::insert(string word) {
    insertHelper(root, word);
}

/**
    @brief removes punctuation marks and convert words to lowercase.
    @param word The word to be cleaned.
    @return the cleaned word as lowercase with no punctuation.
*/
string Bintree::clean_word(const string& word) {
    string cleaned_word;
    for (char c : word) {
        if (isalnum(c) || isspace(c)) {
            cleaned_word += tolower(c);
        }
    }
    return cleaned_word;
}

/**
    @brief recursively prints all the nodes in the tree in alphabetical order.
    @param node The starting node for printing
*/
void Bintree::printHelper(Treenode* node) const {
    if (node == nullptr) {
        return;
    }
    printHelper(node->left);
    cout << node->word << ": " << node->freq << endl;
    printHelper(node->right);
}

/**
    @brief a wrapper function for printHelper. It prints all the nodes in the tree in
    alphabetical order.
*/
void Bintree::print() const {
    printHelper(root);
}

/**
    @brief returns `true` if a given word is a palindrome.
    @param word : The word to be checked .
    @return true if the given word is a palindrome, and false otherwise
*/
bool Bintree::isPalindrome(const string& word){
    int n = word.length();
    for (int i = 0; i < n / 2; i++) {
        if (word[i] != word[n - i - 1]) {
            return false;
        }
    }
    return true;
}

/**
    @brief a function that  prints all the words in alphabetical order along with frequency and palindrome status.
    @param node The starting node for printing
    @return word, frequency and palindrome status of the word at the node pointer
*/
void Bintree::printAlphaHelper(Treenode* node) {
    if (node == nullptr) {
        return;
    }
    printAlphaHelper(node->left);
    bool is_palindrome = isPalindrome(node->word);
    cout << node->word << " " << node->freq << " " <<
        (is_palindrome ? "palindrome" : "not palindrome") << endl;
    printAlphaHelper(node->right);
}

/**
    @brief a wrapper function for printAlphaHelper. it recursively prints all the nodes in the
    tree in alphabetical order, along with their palindrom status.
*/
void Bintree::printAlphabetical() {
    printAlphaHelper(root);
}

/**
    @brief a helper function for quicksort that partitions the vector around a pivot element
    @param vector<pair<string : The word to be checked .
    @return index of pivot
*/
int Bintree::partition(vector<pair<string, int>>& vec, int left, int right) {
    int pivot = vec[right].second;
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (vec[j].second > pivot) {  // Sort in descending order of frequency
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[right]);
    return i + 1;
}

/**
    @brief algorithm to sort a vector of pairs by frequency in descending order.
    @param vec The vector to be sorted
    @param left The leftmost index of the vector
    @param right The rightmost index of the vector
*/
void Bintree::quicksort(vector<pair<string, int>>& vec, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = partition(vec, left, right);
    quicksort(vec, left, pivot - 1);
    quicksort(vec, pivot + 1, right);
}

/**
    @brief a function that returns the reverse of the given string str
    @param str The word to be reversed
    @return the reverse of the given string str.
*/
string Bintree::reverseString(const string& str) {
    string reversed_str = str;
    reverse(reversed_str.begin(), reversed_str.end());
    return reversed_str;
}
/**
    @brief a helper function that recursively prints all the nodes in the tree in descending order of frequency,
      along with their reversed word. 
      It uses the quicksort function to sort the nodes by frequency before printing them.
    @param node The starting node for printing
    @return word, frequency and reversed word of the word at the node pointer
*/
void Bintree::printByFreqHelper(Treenode* node) {
    if (node == nullptr) {
        return;
    }
    printByFreqHelper(node->left);
    pairs.push_back({ node->word, node->freq });
    printByFreqHelper(node->right);
    if (node == root) {
        quicksort(pairs, 0, pairs.size() - 1);
        for (int i = 0; i < pairs.size(); i++) {
            cout << pairs[i].first << " " << pairs[i].second << " " << reverseString(pairs[i].first) << endl;
        }
        pairs.clear();
    }
}
/**
    @brief a wrapper function for printByFreqHelper. It recursively prints all the nodes in the
    tree in descending order of frequency, along with their reversed word
*/
void Bintree::printByFrequency() {
    printByFreqHelper(root);
}
