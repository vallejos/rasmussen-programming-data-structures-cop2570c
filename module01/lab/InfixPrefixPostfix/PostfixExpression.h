/**
 * Author: Leonardo Vallejos <leonardofabian.hernandezvallej@smail.rasmussen.edu>
 * Date: 10/08/2017
 * FileName: PostfixExpression.h
 * Purpose: Infix, Prefix, Postfix demo with Stacks.
 *          Module 01 Lab Assignment for COP2570C Programming Data Structures course at Rasmussen College.
 * Description: PostfixExpression class
 */

#ifndef POSTFIXEXPRESSION_H
#define POSTFIXEXPRESSION_H

#include <string>
#include <stack>
#include "AbstractExpression.h"

using namespace std;

class PostfixExpression : public AbstractExpression {
public:
    PostfixExpression(string _expression);
    PostfixExpression(const PostfixExpression& orig);
    virtual ~PostfixExpression();

    double evaluate();
    string convert(string notation);
//    bool isValid();

private:
    stack<double> opStack;
    stack<double> evalStack;
    string infix;
    string prefix;

//    evalOp(char op);
    string toInfix();
    string toPrefix();

};

#endif /* POSTFIXEXPRESSION_H */

