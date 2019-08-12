//
// Created by mycoa on 05/08/2019.
//

#ifndef SORTING_HEAP_H
#define SORTING_HEAP_H

#include <iostream>
#include <vector>

namespace sorting
{
class Heap
{
public:
    int size() const
    {
        return n;
    }

    int top() const
    {
        return hp[0];
    }

    bool empty() const
    {
        return n == 0;
    }

    void push(int a)
    {
        hp.emplace_back(a);
        SiftUp(n);
        n++;
    }

    void pop()
    {
        n--;
        std::swap(hp[0], hp[n]);
        hp.pop_back();
        SiftDown(0);
    }

    void clear()
    {
        hp.clear();
        n = 0;
    }

    int operator[] (int a)
    {
        return hp[a];
    }


private:
    std::vector<int>hp{};
    int n{0};

    void SiftUp(int a)
    {
        while (a)
        {
            if (hp[(a - 1) / 2] <= hp[a])
            {
                return;
            }
            std::swap(hp[(a - 1) / 2], hp[a]);

            --a /= 2;
        }
    }

    void SiftDown(int a)
    {
        while( 2 * a + 1 < n)
        {
            int left = 2 * a + 1;
            int right = 2 * a + 2;
            if (right == n)
            {
                if (hp[left] < hp[a])
                {
                    std::swap(hp[left], hp[a]);
                }
                return;
            }
            else if (hp[left] <= hp[right])
            {
                if (hp[left] > hp[a])
                {
                    return;
                }
                std::swap(hp[left], hp[a]);
                a = left;
            }
            else if (hp[right] < hp[a])
            {
                std::swap(hp[right], hp[a]);
                a = right;
            }
            else
            {
                return;
            }
        }
    }
};
} // namespace sorting


#endif //SORTING_HEAP_H
