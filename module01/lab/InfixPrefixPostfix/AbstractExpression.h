/**
 * Author: Leonardo Vallejos <leonardofabian.hernandezvallej@smail.rasmussen.edu>
 * Date: 10/08/2017
 * FileName: AbstractExpression.h
 * Purpose: Infix, Prefix, Postfix demo with Stacks.
 *          Module 01 Lab Assignment for COP2570C Programming Data Structures course at Rasmussen College.
 * Description: AbstractExpression class
 */

#ifndef ABSTRACTEXPRESSION_H
#define ABSTRACTEXPRESSION_H

#include <string>
#include <stack>

using namespace std;

class AbstractExpression {
public:
    // getter for expression property
    string getExpression();
    
    // evaluates expression and return calculated value
    virtual double evaluate() = 0;
    
    // convert expression to target notation
    virtual string convert(string notation) = 0;
    
    // returns whether the expression is valid or not
//    virtual bool isValid() = 0;

    bool isBalanced();

protected:
    // expression
    string expression;

    // allowed operators
    static const string OPERATORS;
    
    // evaluation priorities for operators
    static const int PRECEDENCE[];

    const string OPEN = "([{";
    const string CLOSE = ")]}";

    // calculates
    double doMath(char op, double op1, double op2);

    // check if a char is an operator or not
    bool isOperator(char ch);
    
    int precedence(char op);
    
    bool isOpen(char ch);
    bool isClose(char ch);
    string reverse(string _expression);

};

#endif /* ABSTRACTEXPRESSION_H */

