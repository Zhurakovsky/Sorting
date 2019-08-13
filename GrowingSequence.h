//
// Created by mycoa on 13/08/2019.
//

#ifndef SORTING_GROWINGSEQUENCE_H
#define SORTING_GROWINGSEQUENCE_H

#include <vector>
#include <iostream>

namespace sorting {
class GrowingSequence {
public:
    int FindLongestGrowingPath(const std::vector<int>& a, int k)
    {
        int m = 0;
        for (int i = 0; i < k - 1; i++)
        {
            if (a[i] < a[k])
            {
                int p = FindLongestGrowingPath(a, i);
                m = (p > m) ? p : m;
            }
        }
        //std::cout << m << std::endl;
        return (m + 1);
    }

};

} // namespace sorting
#endif //SORTING_GROWINGSEQUENCE_H
