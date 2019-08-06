//
// Created by mycoa on 06/08/2019.
//

#ifndef SORTING_QUICKSORT_H
#define SORTING_QUICKSORT_H

#include <iostream>

namespace sorting {

class QuickSort {
public:
    template<typename Iterator>
    void Sort(Iterator First, Iterator Last)
    {
        if (std::distance(First, Last) <= 1) return;

        auto mid = *(First + (Last - First) / 2); // Pivot

        Iterator left = First;
        Iterator right = (Last - 1);

        while (left <= right)
        {
            while (*left < mid) left++;
            while (*right > mid) right--;

            if (left <= right)
            {
                std::swap(*left, *right);
                left++;
                right--;
            }
        }
        if (First < right) Sort(First, (right + 1));
        if (left < Last) Sort(left, Last);
    }
};

} // namespace sorting


#endif //SORTING_QUICKSORT_H
