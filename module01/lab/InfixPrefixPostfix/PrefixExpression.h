/**
 * Author: Leonardo Vallejos <leonardofabian.hernandezvallej@smail.rasmussen.edu>
 * Date: 10/08/2017
 * FileName: PrefixExpression.h
 * Purpose: Infix, Prefix, Postfix demo with Stacks.
 *          Module 01 Lab Assignment for COP2570C Programming Data Structures course at Rasmussen College.
 * Description: PrefixExpression class
 */

#ifndef PREFIXEXPRESSION_H
#define PREFIXEXPRESSION_H

#include <string>
#include <stack>
#include "AbstractExpression.h"

using namespace std;

class PrefixExpression : public AbstractExpression {
public:
    PrefixExpression(string _expression);
    PrefixExpression(const PrefixExpression& orig);
    virtual ~PrefixExpression();

    double evaluate();
    string convert(string notation);
//    bool isValid();

private:
    stack<double> opStack;
    stack<double> evalStack;
    string postfix;
    string infix;

    string toInfix();
    string toPostfix();

};

#endif /* PREFIXEXPRESSION_H */

