/**
 * Author: Leonardo Vallejos <leonardofabian.hernandezvallej@smail.rasmussen.edu>
 * Date: 10/08/2017
 * FileName: MathExpression.cpp
 * Purpose: Infix, Prefix, Postfix demo with Stacks.
 *          Module 01 Lab Assignment for COP2570C Programming Data Structures course at Rasmussen College.
 * Description: MathExpression class
 */

#include <string>
#include <iostream>
#include "MathExpression.h"
#include "InfixExpression.h"
#include "PrefixExpression.h"
#include "PostfixExpression.h"

using namespace std;

/**
 * Constructor
 * @param {string} _expression
 * @param {string} _source
 */
MathExpression::MathExpression(string expression, string notation) {
    // check valid notation
    if (notation == "Infix") {
        source = new InfixExpression(expression);
    } else if (notation == "Prefix") {
        source = new PrefixExpression(expression);
    } else if (notation == "Postfix") {
        source = new PostfixExpression(expression);
    } else {
        throw std::invalid_argument("Invalid notation: " + notation);
    }
}

/**
 * Copy Constructor
 * @param orig
 */
MathExpression::MathExpression(const MathExpression& orig) {
}

/**
 * Destructor
 */
MathExpression::~MathExpression() {
}

/**
 * Convert from "from" notation to "to" notation.
 * @param {string} _from
 * @param {string} _to
 * @return {string}
 * @throws {Exception} invalid_argument
 */
void MathExpression::convert(string notation) {
    string convertedExpression = source->convert(notation);
    
    // check valid to
    if (notation == "Infix") {
        target = new InfixExpression(convertedExpression);
    } else if (notation == "Prefix") {
        target = new PrefixExpression(convertedExpression);
    } else if (notation == "Postfix") {
        target = new PostfixExpression(convertedExpression);
    } else {
        throw std::invalid_argument("Invalid notation: " + notation);
    }

}

/**
 * Evaluates and returns the calculated result of source expression
 * @return {double}
 */
double MathExpression::evaluateSource() {
    return source->evaluate();
}

/**
 * Evaluates and returns the calculated result of target expression
 * @return {double}
 */
double MathExpression::evaluateTarget() {
    return target->evaluate();
}

/**
 * Returns original source expression
 * @return {string}
 */
string MathExpression::getSourceExpression() {
    return source->getExpression();
}

/**
 * Returns converted expression
 * @return {string}
 */
string MathExpression::getTargetExpression() {
    return target->getExpression();
}

// return whether the source expression is well balanced or not
bool MathExpression::isValidSource() {
    return source->isBalanced();
}

// return whether the target expression is well balanced or not
bool MathExpression::isValidTarget() {
    return target->isBalanced();
}
