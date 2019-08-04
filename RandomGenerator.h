//
// Created by mycoa on 02/08/2019.
//

#ifndef SORTING_RANDOMGENERATOR_H
#define SORTING_RANDOMGENERATOR_H

#include <cstddef>
#include <vector>
#include <algorithm>
#include <random>

namespace sorting {
template <typename T>
class RandomGenerator
{
public:
    std::shared_ptr<std::vector<T>> operator()(size_t n) const
    {
        std::shared_ptr<std::vector<T>> res(new std::vector<T>(n));
        std::generate((*res).begin(), (*res).end(), std::rand);
        return res;
    }
};
} // namespace


#endif //SORTING_RANDOMGENERATOR_H
