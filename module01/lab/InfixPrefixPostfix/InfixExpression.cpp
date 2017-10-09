/**
 * Author: Leonardo Vallejos <leonardofabian.hernandezvallej@smail.rasmussen.edu>
 * Date: 10/08/2017
 * FileName: InflixExpression.cpp
 * Purpose: Infix, Prefix, Postfix demo with Stacks.
 *          Module 01 Lab Assignment for COP2570C Programming Data Structures course at Rasmussen College.
 * Description: InflixExpression class
 */

#include "InfixExpression.h"
#include <string>
#include <iostream>
#include <limits>
#include <stack>
#include <sstream>
#include <cctype>

using namespace std;

InfixExpression::InfixExpression(string _expression) : AbstractExpression() {
    expression = _expression;
}

InfixExpression::InfixExpression(const InfixExpression& orig) {
}

InfixExpression::~InfixExpression() {
}
       
double InfixExpression::evaluate() {
    // make sure we start with an empty stack
    while (!evalStack.empty()) {
        evalStack.pop();
    }

    double result = 0;
    
    // Process each token
    istringstream tokens(toPostfix());
    string next;
    
    while (tokens >> next) {
        if (isdigit(next[0])) {
            evalStack.push((int)next[0] - 48); // ascii starts at 48
        } else {
            double op1 = evalStack.top();
            evalStack.pop();

            double op2 = evalStack.top();
            evalStack.pop();

            result = doMath(next[0], op1, op2);
            
            evalStack.push(result);
        }
    }
    
    result = evalStack.top();
    evalStack.pop();
    
    return result;
    
}

string InfixExpression::convert(string notation) {
    string result = "";

    // check valid notation
    if (notation == "Prefix") {
        result = toPrefix();
    } else if (notation == "Postfix") {
        result = toPostfix();
    } else {
        throw std::invalid_argument("Invalid notation: " + notation);
    }    

    return result;
}

string InfixExpression::toPrefix() {
    string post = toPostfix();
    string pre = reverse(post);
    return pre;
}

string InfixExpression::toPostfix() {
    postfix = "";

    // make sure we start with an empty stack
    while (!opStack.empty()) {
        opStack.pop();
    }
    
    // Process each token
    istringstream tokens(expression);
    string next;
    
    while (tokens >> next) {

        if (isalnum(next[0])) {
            postfix += next[0];
            postfix += " ";
        } else if (isOpen(next[0])) {
            opStack.push(next[0]);
        } else if (isClose(next[0])) {
            char top = opStack.top();
            opStack.pop();
            while (!isOpen(top)) {
                postfix += top;
                postfix += " ";
                top = opStack.top();
                opStack.pop();
            }
        } else {
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(next[0])) {
                postfix += opStack.top();
                postfix += " ";
                opStack.pop();
            }

            opStack.push(next[0]);

        }
    } // while
    
    while (!opStack.empty()) {
        char op = opStack.top();
        opStack.pop();
        
        if (isOpen(op)) {
            cout << "Unmatched open parenthesis" << endl;
//            throw SyntaxError("Unmatched open parenthesis");
        }

        postfix += op;
        postfix += " ";
    }
    
    return postfix;
    
}
