/**
 * Author: Leonardo Vallejos <leonardofabian.hernandezvallej@smail.rasmussen.edu>
 * Date: October 28, 2017
 * File: main.cpp
 * Purpose: Binary Tree BFS Traversal.
 *          Module 04 Lab Assignment for COP2570C Programming Data Structures course at Rasmussen College.
 * Description: main program
 */

#include <cstdlib>
#include <iostream>
#include <array>
#include <string>
#include <queue>
#include "BTree.h"

using namespace std;

// program name
const string APP_NAME = "Binary Tree Traversal";

// define main menu options
const array<string, 3> MENU_OPTIONS = {
    "Preload data",
    "Enter data",
    "Exit program"
};

/**
 * Print main menu options
 */
void printMenuOptions() {
    cout << endl << "---------------------------" << endl;
    cout << APP_NAME << endl;
    cout << "---------------------------" << endl;

    for (int i=0; i<MENU_OPTIONS.size(); i++) {
        cout << i+1 << ". " << MENU_OPTIONS[i] << endl;
    }

    cout << endl << "Select an option: ";
}

/**
 * Recursively prints subtree data in pre order.
 * @param node
 */
void print(Node* node) {
    if (node == NULL) {
        return;
    }
    
    // print left
    if (node->getLeft() != NULL) {
        print(node->getLeft());
    }
    
    // print current
    cout << " " << node->getData() << " ";

    // print right
    if (node->getRight() != NULL) {
        print(node->getRight());
    }
    
}

/**
 * Prints tree data in pre order
 * @param tree
 */
void printPreOrder(BTree* tree) {
    if (tree == NULL || tree->getRoot() == NULL) {
        cout << endl << "No data to display" << endl;
    }
    
    cout << endl << "Tree data: ";

    print(tree->getRoot());
    
}

/**
 * Print tree data in BFS
 * @param node
 */
void printBFS(Node* node){
    // use a queue to print the nodes
    queue<Node*> q;

    if (!node) {
        return;
    }

    // while there are nodes to visit in the tree
    for (q.push(node); !q.empty(); q.pop()) {
        Node* tempNode = q.front();

        if (tempNode != NULL) {
            // print node
            cout << " " << tempNode->getData() << " ";
        }

        if (tempNode->getLeft()) {
            q.push(tempNode->getLeft());
        }

        if (tempNode->getRight()) {
            q.push(tempNode->getRight());
        }
    }
}

/**
 * main function
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char** argv) {
    int choice, num;
    bool end = false;
    BTree* tree = new BTree();

    while (!end) {
        printMenuOptions();
        cin >> choice;
        
        switch (choice) {
            case 1:
                tree->destroy(); // destroy any previously created tree
                tree = new BTree();

                // root
                tree->insert(10);

                // level 1
                tree->insert(5);
                tree->insert(20);

                // level 2
                tree->insert(2);
                tree->insert(7);
                tree->insert(15);
                tree->insert(22);
                
                // level 3
                tree->insert(1);
                tree->insert(30);
                
                // level 4
                tree->insert(40);
                
                // level 5
                tree->insert(50);
                tree->insert(35);
                
                cout << endl << "BFS Traversal: ";
                printBFS(tree->getRoot());
                
                break;
            case 2:
                tree->destroy(); // destroy any previously created tree
                tree = new BTree();
                
                cout << endl << "Enter 15 integer numbers: " << endl;
                for (int i=0; i<15; i++) {
                    cout << "> Enter number " << i + 1 << ": ";
                    cin >> num;
                    tree->insert(num);
                }

                cout << endl << "BFS Traversal: ";
                printBFS(tree->getRoot());

                break;
            case 3:
                end = true;
                break;
            default:
                cout << endl << "Incorrect option. Try again." << endl;
        } // switch
    } // while
    
    cout << endl << "Bye!" << endl;
    
    return 0;
}

