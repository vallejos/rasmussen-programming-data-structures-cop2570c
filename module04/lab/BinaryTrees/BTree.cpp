/**
 * Author: Leonardo Vallejos <leonardofabian.hernandezvallej@smail.rasmussen.edu>
 * Date: October 28, 2017
 * File: BTree.cpp
 * Purpose: Binary Tree BFS Traversal.
 *          Module 04 Lab Assignment for COP2570C Programming Data Structures course at Rasmussen College.
 * Description: BTree class
 */

#include <sstream>
#include <iostream>
#include "BTree.h"

/**
 * Constructors
 */
BTree::BTree() {
    root = NULL;
}

BTree::BTree(const BTree& orig) {
}

/**
 * Destructor
 */
BTree::~BTree() {
    destroy();
}

/**
 * Destroy tree
 */
void BTree::destroy() {
    destroy(root);
}

/**
 * Recursively destroys a subtree
 * @param _node
 */
void BTree::destroy(Node* _node) {
    if (_node != NULL) {
        destroy(_node->getLeft());
        destroy(_node->getRight());
        delete(_node);
    }
}

/**
 * Returns tree root
 * @return 
 */
Node* BTree::getRoot() {
    return root;
}

/**
 * Add a new value to the tree
 * @param _data
 */
void BTree::insert(int _data) {
    if (root == NULL) {
        root = new Node(_data);
    } else if (root->getData() > _data) {
        if (root->getLeft() != NULL) {
            insert(root->getLeft(), _data);
        } else {
            root->setLeft(new Node(_data));
        }
    } else if (root->getData() < _data) {
        if (root->getRight() != NULL) {
            insert(root->getRight(), _data);
        } else {
            root->setRight(new Node(_data));
        }
    } else {
        // the value at root is the same as _data
    }

}

/**
 * Adds a new value into the given subtree
 * @param _node
 * @param _data
 */
void BTree::insert(Node* _node, int _data) {
    if (_node == NULL) {
        // do nothing, this should not happen
    } else if (_node->getData() > _data) {
        if (_node->getLeft() != NULL) {
            insert(_node->getLeft(), _data);
        } else {
            _node->setLeft(new Node(_data));
        }
    } else if (_node->getData() < _data) {
        if (_node->getRight() != NULL) {
            insert(_node->getRight(), _data);
        } else {
            _node->setRight(new Node(_data));
        }
    } else {
        // the value at root is the same as _data
    }
    
}
