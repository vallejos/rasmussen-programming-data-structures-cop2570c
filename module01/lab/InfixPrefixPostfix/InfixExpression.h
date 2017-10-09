/**
 * Author: Leonardo Vallejos <leonardofabian.hernandezvallej@smail.rasmussen.edu>
 * Date: 10/08/2017
 * FileName: InfixExpression.h
 * Purpose: Infix, Prefix, Postfix demo with Stacks.
 *          Module 01 Lab Assignment for COP2570C Programming Data Structures course at Rasmussen College.
 * Description: InflixExpression class
 */

#ifndef INFIXEXPRESSION_H
#define INFIXEXPRESSION_H

#include <string>
#include <string>
#include "AbstractExpression.h"

using namespace std;

class InfixExpression : public AbstractExpression {
public:
    InfixExpression(string _expression);
    InfixExpression(const InfixExpression& orig);
    virtual ~InfixExpression();
    
    double evaluate();
    string convert(string notation);
//    bool isValid();
    
private:
    stack<double> opStack;
    stack<double> evalStack;
    string postfix;
    string prefix;

    string toPrefix();
    string toPostfix();
    
};

#endif /* INFIXEXPRESSION_H */

