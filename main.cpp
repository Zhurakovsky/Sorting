#include <iostream>
#include <random>
#include <iterator>

#include "RandomGenerator.h"
#include "BubbleSort.h"
#include "BinarySearch.h"
#include "TreeSort.h"
#include "Node.h"
#include "Heap.h"
#include "QuickSort.h"
#include "Routes.h"
#include "GrowingSequence.h"
#include "RadixSort.h"

using namespace sorting;

static const bool BUBBLE_SORT = false;
static const bool TREE_SORT = false;
static const bool BINARY_SEARCH = false;
static const bool NODE_TREE = false;
static const bool HEAP_SORT = false;
static const bool QUICK_SORT = false;
static const bool FIND_ROUTES = false;
static const bool GROWING_SEQUENCES = false;
static const bool RADIX_SORT = false;


template<typename V>
void printArray(const V& v)
{
    for (auto i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    if (BUBBLE_SORT)
    {
        std::vector<int> v = *(RandomGenerator<int>()(10));
        std::cout << "Initial array: " << std::endl;
        printArray(v);

        // Bubble sort with templates
        BubbleSort<int> bs;
        bs.Sort(v.begin(), v.end());
        printArray(v);

        v = *(RandomGenerator<int>()(10));
        std::cout << "Array 2: " << std::endl;
        printArray(v);

        // Bubble sort without templates
        bs.Sort(&v[0], v.size());
        printArray(v);
    } // if (BUBBLE_SORT)

    if (TREE_SORT)
    {
        std::vector<int> v = *(RandomGenerator<int>()(10));
        std::cout << "Array 3: " << std::endl;
        printArray(v);

        // Tree sort section
        TreeSort ts;
        ts.Sort(v);
        std::cout << "Array sorted with Tree Sort: " << std::endl;
        printArray(v);
    } // if (TREE_SORT)

    if (BINARY_SEARCH)
    {
        // Binary search section
        std::vector<int> data_vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        std::cout << "Array For Binary search: " << std::endl;
        printArray(data_vector);
        std::cout << "Sort arr Array For Binary search: " << std::endl;

        BubbleSort<int> bs;
        bs.Sort(data_vector.begin(), data_vector.end());
        printArray(data_vector);

        BinarySearch bin_searcher;
        int try1 = 3;
        int try2 = 12;
        std::cout << "Element " << try1
                  << ((bin_searcher.binarySearch(data_vector, try1) == data_vector.cend()) ? " NOT FOUND" : " FOUND")
                  << std::endl;
        std::cout << "Element " << try2
                  << ((bin_searcher.binarySearch(data_vector, try2) == data_vector.cend()) ? " NOT FOUND" : " FOUND")
                  << std::endl;
    } // if (BINARY_SEARCH)

    if (NODE_TREE)
    {
        Node* root = new Node(6);
        root->insert(root, 4);
        root->insert(root, 8);
        root->insert(root, 2);
        root->insert(root, 3);
        root->insert(root, 1);
        root->insert(root, 9);
        root->insert(root, 7);
        root->insert(root, 5);

        // Get max depth of tree
        int depth = root->treeDepth(root);
        std::cout << "Max depth of tree = " << depth << std::endl;

        root->printTreeByLevelsUpDown(root, depth);
        std::cout << "After deep print" << std::endl;

        // Depth First Traversals:
        std::cout << "Depth First Traversal Inorder: ";
        root->printInorder(root); // 1 2 3 4 5 6 7 8 9
        std::cout << std::endl;

        std::cout << "Depth First Traversal Preorder: ";
        root->printPreorder(root); // 6 4 2 1 3 5 8 7 9
        std::cout << std::endl;

        std::cout << "Depth First Traversal Postorder: ";
        root->printPostorder(root); // 1 3 2 5 4 7 9 8 6
        std::cout << std::endl;

        // Find branch with max / min summ of nodes.
        std::multimap<int, std::vector<int>> branches{};
        std::vector<int> current_vector{};

        root->findDeeps(root, branches, current_vector);
        for (const auto& branch : branches)
        {
            std::cout << "Branch deep: " << branch.first << ". Children: ";
            for (const auto& node : branch.second)
            {
                std::cout << node << " ";
            }
            std::cout << std::endl;
        }

        std::cout << "Try to delete Node 42:" << std::endl;
        root = root->deleteCertain(root, 42); // Node 42 not found.

        // Depth First Traversals:
        std::cout << "Control traversal: ";
        root->printInorder(root); // 1 2 3 4 5 6 7 8 9
        std::cout << std::endl;

        std::cout << "Try to delete Node 2:" << std::endl;
        root = root->deleteCertain(root, 2); // Deleting node 2.

        // Depth First Traversals:
        std::cout << "Control traversal after Deleting Node: ";
        root->printInorder(root); // 1 4 5 6 7 8 9
        std::cout << std::endl;

        std::cout << "Deleting Tree: ";
        root = root->deleteTree(root); // 1 5 4 7 9 8 6
        std::cout << std::endl;

        // Depth First Traversals:
        std::cout << "Control traversal: ";
        root->printInorder(root); //
        std::cout << std::endl;
    }

    if (HEAP_SORT)
    {
        std::vector<int> v = *(RandomGenerator<int>()(10));
        std::cout << "Initial array for heap sort: " << std::endl;
        printArray(v);

        Heap hp;
        std::for_each (v.begin(), v.end(), [&](const auto& i)
        {
            hp.push(i);
        });
        std::for_each (v.begin(), v.end(), [&](auto& i)
        {
            i = hp.top();
            hp.pop();
        });

        std::cout << "Sorted array by heap sort: " << std::endl;
        printArray(v);

    }

    if (QUICK_SORT)
    {
        std::vector<int> v = *(RandomGenerator<int>()(10));
        std::cout << "Initial array for quick sort: " << std::endl;
        printArray(v);

        QuickSort qs;
        qs.Sort(v.begin(), v.end());

        std::cout << "Array sorted by quick sort: " << std::endl;
        printArray(v);
    }

    if (FIND_ROUTES)
    {
        // Need to find number of routes from A to G
        // Considering i-th point of route getting from:  F(i) = F(i - 3) + F(i - 2) + F(i - 1)
        Routes routes;

        // Recursive solution
        /*
        for (int i = 1; i < 37; i++)
        {
            std::cout << "For i == " << i << ", number of routes == " << routes.GetRoutesRecursively(i) << std::endl;
        }

         // For i == 37, number of routes == 2082876103
         // For i == 38, number of routes == -463960867
         // For i == 39, number of routes == -1543615208
        */

        // Iterative solution
        for (int i = 1; i < 40; i++)
        {
            std::cout << "For i == " << i << ", number of routes == " << routes.GetRoutesIterative(i) << std::endl;
        }

        //  For i == 37, number of routes == 2082876103
        //  For i == 38, number of routes == -463960867
        //  For i == 39, number of routes == -1543615208

    }

    if (GROWING_SEQUENCES)
    {
        std::vector<int> v = *(RandomGenerator<int>()(20));
        std::cout << "Growing sequence array: " << std::endl;
        printArray(v);

        GrowingSequence gs;
        int longest_path = gs.FindLongestGrowingPath(v, 17);
        std::cout << "Longest path == " << longest_path << std::endl;
    }

    if (RADIX_SORT)
    {
        std::vector<int> v = *(RandomGenerator<int>()(20));
        std::cout << "Before Radix Sort array: " << std::endl;
        printArray(v);

        RadixSort rs;
        rs.SortLsd(v);

        std::cout << "After Radix Sort array: " << std::endl;
        printArray(v);
    }
    std::cout << "Hello World!" << std::endl;
    return 0;
}

/*
 *                  	TIME COMPLEXITY	S                       PACE COMPLEXITY
                    BEST CASE	    AVERAGE CASE	WORST CASE	WORST CASE
Bubble Sort	        Ω(N)	        Θ(N2)	        O(N2)	    O(1)
Selection Sort	    Ω(N2)	        Θ(N2)	        O(N2)	    O(1)
Insertion Sort	    Ω(N)	        Θ(N2)	        O(N2)	    O(1)
Merge Sort	        Ω(N log N)	    Θ(N log N)	    O(N log N)	O(N)
Heap Sort	        Ω(N log N)	    Θ(N log N)	    O(N log N)	O(1)
Quick Sort	        Ω(N log N)	    Θ(N log N)	    O(N2)	    O(N log N)
Radix Sort	        Ω(N k)	        Θ(N k)	        O(N k)	    O(N + k)
Count Sort	        Ω(N + k)	    Θ(N + k)	    O(N + k)	O(k)
Bucket Sort	        Ω(N + k)	    Θ(N + k)	    O(N2)	    O(N)
 *******************************************************************
 Resources:
 https://codelab.ru/t/array_sort_benchmark/

 https://habr.com/ru/post/335920/

 */