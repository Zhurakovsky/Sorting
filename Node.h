//
// Created by mycoa on 05/08/2019.
//

#ifndef SORTING_NODE_H
#define SORTING_NODE_H

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

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

    Node* deleteTree(Node* node)
    {
        if (!node)
        {
            return nullptr;
        }

        node->left = deleteTree(node->left);
        node->right = deleteTree(node->right);
        std::cout << node->data << " ";
        node = nullptr;
        delete node;
        return nullptr;
    }

    Node* deleteCertain(Node* node, int key)
    {
        if (!node) return nullptr;
        if (!node->left && !node->right)
        {
            if (node->data == key)
            {
                std::cout << "Found and delete Node " << key << "." << std::endl;
                return nullptr;
            }
            else
            {
                std::cout << "Node " << key << " not found." << std::endl;
                return node;
            }
        }
        if (key < node->data)
        {
            std::cout << "Looking left." << std::endl;
            node->left = deleteCertain(node->left, key);

        }
        else if (key > node->data)
        {
            std::cout << "Looking right." << std::endl;
            node->right = deleteCertain(node->right, key);
        }
        else if(key == node->data)
        {
            if (node->left)
            {
                std::cout << "Swapping left." << std::endl;
                std::swap(node->left, node);
                node->left = deleteCertain(node->left, key);
            }
            else if (node->right)
            {
                std::cout << "Swapping right." << std::endl;
                std::swap(node->right, node);
                node->right = deleteCertain(node->right, key);
            }
        }
        return node;
    }

    int treeDepth(Node* node)
    {
        if (!node) return 0;

        return (std::max(treeDepth(node->left), treeDepth(node->right)) + 1);
    }

    void printTreeByLevelsUpDown(Node* node, int depth)
    {
        if (!node) return;
        int curr_depth = 0;

        for (int i = 1; i <= depth; i++)
        {
            if (curr_depth < depth) {
                innerPrintTreeByLevelsUpDown(node, i, curr_depth);
            }
            std::cout << std::endl;
        }
    }

    void innerPrintTreeByLevelsUpDown(Node* node, int depth, int curr_depth)
    {
        if (!node) return;
        curr_depth += 1;
        if (curr_depth == depth)
        {
            std::cout << node->data << " ";
        }

        if (depth > curr_depth)
        {
            innerPrintTreeByLevelsUpDown(node->left, depth, curr_depth);
            innerPrintTreeByLevelsUpDown(node->right, depth, curr_depth);
        }
    }

    void findDeeps(Node* node, std::multimap<int, std::vector<int>>& branches, std::vector<int> current_vector)
    {
        if (!node) return;

        current_vector.emplace_back(node->data);
        if (!node->left && !node->right)
        {
            int sum = std::accumulate(current_vector.begin(), current_vector.end(), 0);
            branches.insert(std::pair<int, std::vector<int>>{sum, current_vector});
            return;
        }

        findDeeps(node->left, branches, current_vector);
        findDeeps(node->right, branches, current_vector);
    }
};

}
#endif //SORTING_NODE_H
