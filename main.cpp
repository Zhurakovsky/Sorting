#include <iostream>
#include <random>

//#include "Sorting.h"
#include "BubbleSort.h"
#include "RandomGenerator.h"
#include "BinarySearch.h"

using namespace sorting;

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
    std::vector<int> v = *(RandomGenerator<int>()(10));
    std::cout << "Initial array: " << std::endl;
    printArray(v);

    BubbleSort<int> bs;
    bs.Sort(v.begin(), v.end());
    printArray(v);

    v = *(RandomGenerator<int>()(10));
    std::cout << "Array 2: " << std::endl;
    printArray(v);
    bs.Sort(&v[0], v.size());
    printArray(v);

    //v = *(RandomGenerator<int>()(10));
    std::vector<int>data_vector{1,2,3,4,5,6,7,8,9,0};
    std::cout << "Array For Binary search: " << std::endl;
    printArray(data_vector);
    std::cout << "Sort arr Array For Binary search: " << std::endl;
    bs.Sort(data_vector.begin(), data_vector.end());
    printArray(data_vector);

    BinarySearch bin_searcher;
    int try1 = 3;
    int try2 = 12;
    std::cout << "Element " << try1 << ((bin_searcher.binarySearch(data_vector, try1) == data_vector.cend()) ? " NOT FOUND" : " FOUND" )<< std::endl;
    std::cout << "Element " << try2 << ((bin_searcher.binarySearch(data_vector, try2) == data_vector.cend()) ? " NOT FOUND" : " FOUND" )<< std::endl;



    //std::cout << "Hello, World!" << std::endl;
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