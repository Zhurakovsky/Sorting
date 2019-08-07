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

using namespace sorting;

static const bool BUBBLE_SORT = false;
static const bool TREE_SORT = false;
static const bool BINARY_SEARCH = false;
static const bool NODE_TREE = false;
static const bool HEAP_SORT = false;
static const bool QUICK_SORT = false;

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
        Node* root = new Node(3);
        root->insert(root, 1);
        root->insert(root, 2);
        root->insert(root, 4);
        root->insert(root, 5);

        // Depth First Traversals:
        root->printInorder(root); // 1 2 3 4 5
        std::cout << std::endl;
        root->printPreorder(root); // 3 1 2 4 5
        std::cout << std::endl;
        root->printPostorder(root); // 2 1 5 4 3
        std::cout << std::endl;

        // TODO: delete certain node
        std::cout << "Try to delete Node 42:" << std::endl;
        root = root->deleteCertain(root, 42); // Node 42 not found.

        // Depth First Traversals:
        std::cout << "Control traversal: ";
        root->printInorder(root); //
        std::cout << std::endl;

        std::cout << "Try to delete Node 2:" << std::endl;
        root = root->deleteCertain(root, 2); // Deleting node 2.

        // Depth First Traversals:
        std::cout << "Control traversal after Deleting Node: ";
        root->printInorder(root); // 1 2 3 4 5
        std::cout << std::endl;

        std::cout << "Deleting Tree: ";
        root = root->deleteTree(root);
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