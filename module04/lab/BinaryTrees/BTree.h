/**
 * Author: Leonardo Vallejos <leonardofabian.hernandezvallej@smail.rasmussen.edu>
 * Date: October 28, 2017
 * File: BTree.h
 * Purpose: Binary Tree BFS Traversal.
 *          Module 04 Lab Assignment for COP2570C Programming Data Structures course at Rasmussen College.
 * Description: BTree class
 */

#ifndef BTREE_H
#define BTREE_H

#include "Node.h"

class BTree {
public:
    BTree();
    BTree(const BTree& orig);
    virtual ~BTree();
    void insert(int _data);
    void destroy();
    Node* getRoot();
    
private:
    Node* root;
    
    void insert(Node* _node, int _data);
    void destroy(Node* _node);

};

#endif /* BTREE_H */

