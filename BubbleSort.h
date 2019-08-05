//
// Created by mycoa on 02/08/2019.
//

#ifndef SORTING_BUBBLESORT_H
#define SORTING_BUBBLESORT_H

namespace sorting
{
template<typename T>
class BubbleSort {
public:
    template<typename Iterator>
    void Sort(Iterator First, Iterator Last)
    {
        while(First < --Last)
        {
            for (Iterator i = First; i < Last; ++i)
            {
                if (*(i+1) < *i)
                {
                    std::iter_swap(i, i+1);
                }
            }
        }
    }

    void Sort(int* arr, int n)
    {
        for (int i = n - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if(arr[j] > arr[j+1])
                {
                    int tmp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = tmp;
                }
            }
        }
    }
};

} // namespace

#endif //SORTING_BUBBLESORT_H
