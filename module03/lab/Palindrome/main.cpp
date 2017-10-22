/**
 * Author: Leonardo Vallejos <leonardofabian.hernandezvallej@smail.rasmussen.edu>
 * Date: October 21, 2017
 * File: main.cpp
 * Purpose: Recursive Palindrome checker. Checks whether a provided word is a palindrome or not.
 *          Module 03 Lab Assignment for COP2570C Programming Data Structures course at Rasmussen College.
 * Description: main program
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/**
 * Checks whether the word is a palindrome or not. Use recursion to check.
 * @param {string} word
 * @return {boolean}
 */
bool isPalindrome(string word) {
    // single letter words and empty words are palindromes
    if (word.length() <= 1) {
        return true;
    }

    // check first and last chars of the word
    if (word.front() == word.back()) {
        // chars are the same -> check the rest of the word
        return isPalindrome(word.substr(1, word.length() - 2));
    } else {
        // chars are different -> word is not a palindrome
        return false;
    }

}


/**
 * main function
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char** argv) {
    string word;

    // asks for the word to check
    cout << "Enter a Word to check: ";
    getline(cin, word);
    
    // check if it's a palindrome or not
    if (isPalindrome(word)) {
        cout << endl << word << " is a Palindrome" << endl;
    } else {
        cout << endl << word << " is not a Palindrome" << endl;
    }
    
    return 0;
}

