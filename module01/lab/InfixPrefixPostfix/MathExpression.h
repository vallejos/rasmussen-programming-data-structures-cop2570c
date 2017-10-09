/**
 * Author: Leonardo Vallejos <leonardofabian.hernandezvallej@smail.rasmussen.edu>
 * Date: 10/08/2017
 * FileName: MathExpression.h
 * Purpose: Infix, Prefix, Postfix demo with Stacks.
 *          Module 01 Lab Assignment for COP2570C Programming Data Structures course at Rasmussen College.
 * Description: MathExpression class
 */

#ifndef MATHEXPRESSION_H
#define MATHEXPRESSION_H

#include <string>
#include <stack>
#include "AbstractExpression.h"

using namespace std;

class MathExpression {
public:
    // constructors
    MathExpression(string expression, string notation);
    MathExpression(const MathExpression& orig);
    
    // destructor
    virtual ~MathExpression();

    // convert expression from source to target notation
    void convert(string notation);

    // return evaluation of original expression
    double evaluateSource();
    
    // return evaluation of converted expression
    double evaluateTarget();
    
    // return original source expression
    string getSourceExpression();
    
    // return converted expression
    string getTargetExpression();
    
    // return whether the source expression is well balanced or not
    bool isValidSource();
    
    // return whether the target expression is well balanced or not
    bool isValidTarget();

private:
    // entered expression
    AbstractExpression *source;
    
    // converted expression
    AbstractExpression *target;
    
    // notations
    const string NOTATIONS[3] = {"Infix", "Prefix", "Postfix"};

};

#endif /* MATHEXPRESSION_H */

