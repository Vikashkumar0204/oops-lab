#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Reverses the order of words
void reverseWords(stringstream &ss) {
    string word;
    if (!(ss >> word))          // base case: no more words
        return;
    reverseWords(ss);           // recurse first
    cout << word << " ";        // print on the way back
}

// Reverses every character
void reverseChars(const string &s, int i) {
    if (i == (int)s.length())   // base case: end of string
        return;
    reverseChars(s, i + 1);     // recurse first
    cout << s[i];               // print on the way back
}

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    stringstream ss(sentence);
    cout << "\nWords reversed     : ";
    reverseWords(ss);

    cout << "\nCharacters reversed: ";
    reverseChars(sentence, 0);
    cout << endl;

    return 0;
}
