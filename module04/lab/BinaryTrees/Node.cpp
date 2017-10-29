/**
 * Author: Leonardo Vallejos <leonardofabian.hernandezvallej@smail.rasmussen.edu>
 * Date: October 28, 2017
 * File: Node.cpp
 * Purpose: Binary Tree BFS Traversal.
 *          Module 04 Lab Assignment for COP2570C Programming Data Structures course at Rasmussen College.
 * Description: Node class
 */

#include <iostream>
#include "Node.h"

Node::Node(int _data) {
    data = _data;
    left = NULL;
    right = NULL;
}

Node::Node(const Node& orig) {
}

Node::~Node() {
}

/**
 * Returns node data
 * @return 
 */
int Node::getData() {
    return data;
}

/**
 * Returns node's left node
 * @return 
 */
Node* Node::getLeft() {
    return left;
}

/**
 * Returns node's right node
 * @return 
 */
Node* Node::getRight() {
    return right;
}

/**
 * Sets node's left node
 * @param _node
 */
void Node::setLeft(Node* _node) {
    left = _node;
}

/**
 * Sets node's right node
 * @param _node
 */
void Node::setRight(Node* _node) {
    right = _node;
}
