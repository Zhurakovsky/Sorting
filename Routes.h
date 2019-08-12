//
// Created by mycoa on 12/08/2019.
//

#ifndef SORTING_ROUTES_H
#define SORTING_ROUTES_H

#include <vector>

namespace sorting {

class Routes
{
public:
    // Problem about number of routes
    int GetRoutesRecursively(size_t i)
    {
        if (i < 3) return 1;
        if (i == 3) return (GetRoutesRecursively(i - 1) + GetRoutesRecursively(i - 2));
        return (GetRoutesRecursively(i - 1) + GetRoutesRecursively(i - 2) + GetRoutesRecursively(i - 3));
    }

    int GetRoutesIterative(size_t n)
    {
        std::vector<int> data(n, -1);
        if (n < 3) return 1;
        if (n == 3) return 2;

        data[0] = 1;
        data[1] = 1;
        data[2] = data[0] + data[1];
        for (size_t i = 3; i < n; i++)
        {
            data[i] = data[i-3] + data[i-2] + data[i-1];
        }
        return data.back();
    }

};

} // namespace sorting
#endif //SORTING_ROUTES_H
