/**
 * Author: Leonardo Vallejos <leonardofabian.hernandezvallej@smail.rasmussen.edu>
 * Date: 10/08/2017
 * FileName: main.cpp
 * Purpose: Infix, Prefix, Postfix demo with Stacks.
 *          Module 01 Lab Assignment for COP2570C Programming Data Structures course at Rasmussen College.
 * Description: main program
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "MathExpression.h"

using namespace std;

//enum notations_t {infix, prefix, postfix};
const string OPTIONS[3] = {"Infix", "Prefix", "Postfix"};

/**
 * Print menu options
 */
void printMenuOptions() {
    cout << endl << "------------------" << endl;
    cout << "Notation Type" << endl;
    cout << "------------------" << endl;
    cout << "1. " << OPTIONS[0] << endl;
    cout << "2. " << OPTIONS[1] << endl;
    cout << "3. " << OPTIONS[2] << endl;
    cout << endl << "Select an option: ";
}

/**
 * main function
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char** argv) {
    // declare & initialize required variables
    int from = 0;
    int to = 0;
    bool choiceOk = false;
    string expression = "";
    double evalExpression = 0;
    double evalResult = 0;
    
    MathExpression *mathExpression;
    
    // select the option to pick between infix, prefix, or postfix
    while (!choiceOk) {
        printMenuOptions();
        cin >> from;

        // make sure the options are correct
        choiceOk = from >= 1 && from <= 3;
        if (!choiceOk) {
            cout << endl << "> Incorrect option. Try again." << endl;
        }
    }
    
    // enter math expression
    cout << "Type in your mathematical expression: ";
    cin.ignore();
    getline(cin, expression);

    // enter the option to pick between infix, prefix, or postfix
    choiceOk = false;
    while (!choiceOk) {
        printMenuOptions();
        cin >> to;
        
        // make sure the options are correct
        choiceOk = to >= 1 && to <= 3 && to != from;
        if (!choiceOk) {
            cout << endl << "> Incorrect option. Try again." << endl;
        }
    }

    // show what's going to happen
    cout << "Converting " << OPTIONS[from - 1] << " => " << OPTIONS[to - 1] << "..." << endl;

    try {
        // create MathExpression object
        mathExpression = new MathExpression(expression, OPTIONS[from - 1]);
    } catch (const std::invalid_argument& e) {
        // error detected
        cout << endl << "ERROR: " << e.what() << endl;
    }

    // check if expression is valid
    if (!mathExpression->isValidSource()) {
        cout << endl << "ERROR: Expression is not valid and cannot be parsed." << endl;
        return 10; // return status code 10 for invalid expression
    }

    try {
        // convert expression to target notation
        mathExpression->convert(OPTIONS[to - 1]);
    } catch (const std::invalid_argument& e) {
        // error detected
        cout << endl << "ERROR: " << e.what() << endl;
    }
    
    try {
        // evaluate entered expression
        evalExpression = mathExpression->evaluateSource();
    } catch (const std::invalid_argument& e) {
        // error detected
        cout << endl << "ERROR: " << e.what() << endl;
    }
    
    try {
        // evaluate converted expression
        evalResult = mathExpression->evaluateTarget();        
    } catch (const std::invalid_argument& e) {
        // error detected
        cout << endl << "ERROR: " << e.what() << endl;
    }

    // show results
    cout << "Entered Expression: " << mathExpression->getSourceExpression() << endl;
    cout << "Converted Expression: " << mathExpression->getTargetExpression() << endl;
    cout << "Evaluation of Entered Expression: " << evalExpression << endl;
    cout << "Evaluation of Converted Expression: " << evalResult << endl;
    
    return 0;
}

    