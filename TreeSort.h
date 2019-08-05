//
// Created by mycoa on 05/08/2019.
//

#ifndef SORTING_TREESORT_H
#define SORTING_TREESORT_H

#include <set>
#include <typeinfo>


namespace sorting
{

class TreeSort {
public:
    void Sort(std::vector<int>& vec)
    {
        std::multiset<int> tree_set;
        for (auto i = vec.begin(); i < vec.end(); ++i)
        {
            tree_set.insert(*i);
        }
        if (tree_set.size() == (std::distance(vec.begin(), vec.end())))
        {
            std::copy(tree_set.begin(), tree_set.end(), vec.begin());
        }

    }
};

}
#endif //SORTING_TREESORT_H
