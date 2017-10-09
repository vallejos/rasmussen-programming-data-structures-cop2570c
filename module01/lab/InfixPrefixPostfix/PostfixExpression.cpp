/**
 * Author: Leonardo Vallejos <leonardofabian.hernandezvallej@smail.rasmussen.edu>
 * Date: 10/08/2017
 * FileName: PostfixExpression.cpp
 * Purpose: Infix, Prefix, Postfix demo with Stacks.
 *          Module 01 Lab Assignment for COP2570C Programming Data Structures course at Rasmussen College.
 * Description: PostfixExpression class
 */

#include "PostfixExpression.h"
#include <string>
#include <iostream>
#include <limits>
#include <stack>
#include <sstream>
#include <cctype>

using namespace std;

PostfixExpression::PostfixExpression(string _expression) : AbstractExpression() {
    expression = _expression;
}

PostfixExpression::PostfixExpression(const PostfixExpression& orig) {
}

PostfixExpression::~PostfixExpression() {
}

double PostfixExpression::evaluate() {
    // make sure we start with an empty stack
    while (!evalStack.empty()) {
        evalStack.pop();
    }

    double result = 0;
    
    // Process each token
    istringstream tokens(expression);
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

string PostfixExpression::convert(string notation) {
    string result = "";

    // check valid notation
    if (notation == "Infix") {
        result = toInfix();
    } else if (notation == "Prefix") {
        result = toPrefix();
    } else {
        throw std::invalid_argument("Invalid notation: " + notation);
    }    

    return result;
}

string PostfixExpression::toInfix() {
    stack<string> tempStack;
    string result = "";
    
    // Process each token
    istringstream tokens(expression);
    string next;
    
    while (tokens >> next) {
        if (isOperator(next[0])) {
            string op = tempStack.top();
            tempStack.pop();
            string op1 = tempStack.top();
            tempStack.pop();
            
            string expr = "( " + op1 + " " + next[0] + " " + op + " )";
            tempStack.push(expr);
        } else {
            string chs = "";
            chs += next[0];
            tempStack.push(chs);
        }
    }
    
    result = tempStack.top();
    tempStack.pop();
    
    return result;
}

string PostfixExpression::toPrefix() {
    return reverse(expression);
}
