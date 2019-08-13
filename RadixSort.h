//
// Created by mycoach on 13/08/2019.
//

#ifndef SORTING_RADIXSORT_H
#define SORTING_RADIXSORT_H

#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

namespace sorting
{
    class RadixSort
    {
    public:
        // LSD (least significant digit):
        void SortLsd(std::vector<int>& A)
        {
            int max_a = *(std::max_element(A.begin(), A.end()));
            int digits = 1; // Max number of digits == number of sorting iterations
            std::vector<std::multiset<int>>digits_casse(10, std::multiset<int>{});
            std::vector<int> tmp_result{};

            for (int i = max_a; i /=10; ) digits += 1;
            //std::cout << "Max_A == " << max_a << ", Digits == " << digits << std::endl;
            for (int i = 1; i <= digits; i++ )
            {
                int current_divider = static_cast<int>(std::pow(10, (i-1)));
                int curr_idx;
                for (auto& number : A)
                {
                    int div_num = number / current_divider;
                    curr_idx = div_num % 10;
                    digits_casse.at(curr_idx).insert(number);
                }

                for (const auto& casse : digits_casse)
                {
                    // Possible optimization by memory:
                    // Copy numbers just to A without temp array tmp_result
                    std::copy(casse.begin(), casse.end(), back_inserter(tmp_result));
                }

                A.clear();
                std::copy(tmp_result.begin(), tmp_result.end(), back_inserter(A));
                tmp_result.clear();

                for (auto& casse : digits_casse)
                {
                    casse.clear();
                }
            }
        }
    };
} // namespace sorting

#endif //SORTING_RADIXSORT_H
