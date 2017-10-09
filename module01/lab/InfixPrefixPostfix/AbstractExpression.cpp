/**
 * Author: Leonardo Vallejos <leonardofabian.hernandezvallej@smail.rasmussen.edu>
 * Date: 10/08/2017
 * FileName: AbstractExpression.cpp
 * Purpose: Infix, Prefix, Postfix demo with Stacks.
 *          Module 01 Lab Assignment for COP2570C Programming Data Structures course at Rasmussen College.
 * Description: AbstractExpression class
 */

#include "AbstractExpression.h"
#include <string>
#include <iostream>
#include <limits>
#include <stack>
#include <sstream>
#include <cctype>

// allowed operators
const string AbstractExpression::OPERATORS = "+-*/()";

// evaluation priorities for operators
const int AbstractExpression::PRECEDENCE[] = { 2, 2, 3, 3, 1, 1 };

string AbstractExpression::getExpression() {
    return expression;
}

/**
 * 
 * @param op
 * @param vals
 * @return 
 */
double AbstractExpression::doMath(char op, double op1, double op2) {
    double result = 0;
    
    switch (op) {
        case '+':
            result = op1 + op2;
            break;
        case '-':
            result = op1 - op2;
            break;
        case '*':
            result = op1 * op2;
            break;
        case '/':
            result = op1 / op2;
            break;
    }
    
    return result;
}

/**
 * Returns whether the char ch is an operator or not.
 * @param {char} ch
 * @return {bool}
 */
bool AbstractExpression::isOperator(char ch) {
    return OPERATORS.find(ch) != std::string::npos;
}

int AbstractExpression::precedence(char op) {
    return PRECEDENCE[OPERATORS.find(op)];
}

bool AbstractExpression::isOpen(char ch) {
    return OPEN.find(ch) != string::npos;
}

bool AbstractExpression::isClose(char ch) {
    return CLOSE.find(ch) != string::npos;
}

bool AbstractExpression::isBalanced() {
    stack<char> s;
    bool balanced = true;
    string::const_iterator iter = expression.begin();
    
    while (balanced && (iter != expression.end())) {
        char next = *iter;
        if (isOpen(next)) {
            s.push(next);
        } else if (isClose(next)) {
            if (s.empty()) {
                balanced = false;
            } else {
                char top = s.top();
                s.pop();
                balanced = OPEN.find(top) == CLOSE.find(next);
            }
        }
            ++iter;
    }

    return balanced && s.empty();
}

string AbstractExpression::reverse(string _expression) {
    stack<char> reversed;
    string result = "";
    
    // Process each token
    istringstream tokens(_expression);
    string next;
    
    while (tokens >> next) {
        reversed.push(next[0]);
    }
    
    while (!reversed.empty()) {
        result += reversed.top();
        result += " ";
        reversed.pop();
    }
    
    return result;
}
