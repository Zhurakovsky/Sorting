//
// Created by mycoa on 05/08/2019.
//

#ifndef SORTING_NODE_H
#define SORTING_NODE_H

#include <iostream>

namespace sorting {
class Node
{
private:
    int data;
    Node* left{nullptr};
    Node* right{nullptr};
public:
    Node(int data) : data(data) {}

    Node* insert(Node* node, int key)
    {
        if (node == nullptr)
        {
            return new Node(key);
        }
        if (key < node->data)
        {
            node->left = insert(node->left, key);
        }
        else if (key > node->data)
        {
            node->right = insert(node->right, key);
        }
        return  node;
    }
    /*
     * Uses of Inorder
     * In case of binary search trees (BST), Inorder traversal gives nodes in non-decreasing order.
     * To get nodes of BST in non-increasing order, a variation of Inorder traversal where Inorder
     * traversal reversed can be used.
     * */
    void printInorder(Node* node)
    {
        if (!node)
        {
            return;
        }

        printInorder(node->left);
        std::cout << node->data << " ";
        printInorder(node->right);
    }

    /*
     * Uses of Preorder
     * Preorder traversal is used to create a copy of the tree.
     * Preorder traversal is also used to get prefix expression on of an expression tree.
     * Please see http://en.wikipedia.org/wiki/Polish_notation to know why prefix expressions are useful
     * */
    void printPreorder(Node* node)
    {
        if (!node)
        {
            return;
        }

        std::cout << node->data << " ";
        printPreorder(node->left);
        printPreorder(node->right);
    }

    /*
     * Uses of Postorder
     * Postorder traversal is used to delete the tree. Please see the question for deletion of tree for details.
     * Postorder traversal is also useful to get the postfix expression of an expression tree.
     * Please see http://en.wikipedia.org/wiki/Reverse_Polish_notation to for the usage of postfix expression.
     * */
    void printPostorder(Node* node)
    {
        if (!node)
        {
            return;
        }
        printPostorder(node->left);
        printPostorder(node->right);
        std::cout << node->data << " ";
    }

    void deleteTree(Node* node)
    {
        if (!node)
        {
            return;
        }

        deleteTree(node->left);
        deleteTree(node->right);
        std::cout << node->data << " ";
        node = nullptr;
        delete node;
    }
};


}
#endif //SORTING_NODE_H
