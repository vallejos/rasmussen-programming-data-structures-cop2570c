/**
 * Author: Leonardo Vallejos <leonardofabian.hernandezvallej@smail.rasmussen.edu>
 * Date: October 28, 2017
 * File: Node.h
 * Purpose: Binary Tree BFS Traversal.
 *          Module 04 Lab Assignment for COP2570C Programming Data Structures course at Rasmussen College.
 * Description: Node class
 */

#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node(int _data);
    Node(const Node& orig);
    virtual ~Node();
    int getData();
    Node* getLeft();
    Node* getRight();
    void setLeft(Node* _node);
    void setRight(Node* _node);

private:
    int data;
    Node* left;
    Node* right;

};

#endif /* NODE_H */

