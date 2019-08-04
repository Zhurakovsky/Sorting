//
// Created by mycoa on 03/08/2019.
//

#ifndef SORTING_BINARYSEARCH_H
#define SORTING_BINARYSEARCH_H

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

namespace sorting {
class BinarySearch {
public:
    template<typename Container, typename T>
    const typename Container::const_iterator binarySearch(const Container& container, T element)
    {
        auto endIt = container.cend();
        auto left = container.begin();
        auto right = endIt;

        if (container.size() == 0 || container.front() > element || container.back() < element)
        {
            return endIt;
        }

        while(std::distance(left, right) > 0)
        {
            const auto mid = left + std::distance(left, right) / 2;
            std::cout << "Element = " << element;
            if (element <= *mid)
            {
                std::cout << " Go Left" << std::endl;
                right = mid;
            }
            else
            {
                std::cout << " Go right" << std::endl;
                left = mid + 1;
            }
        }
        //std::cout << "Binary Search Completed" << std::endl;
        std::cout << " After search right = " << *right << std::endl;
        if (*right == element)
        {
            std::cout << "Returning right" << std::endl;
            return right;
        }
        std::cout << "Returning end" << std::endl;
        return endIt;
    }
};
} // namespace sorting

#endif //SORTING_BINARYSEARCH_H
