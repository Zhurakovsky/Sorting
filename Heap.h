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

    void push(int v)
    {
        hp.emplace_back(v);
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

    int operator[] (int v)
    {
        return hp[v];
    }


private:
    std::vector<int>hp{};
    int n{0};

    void SiftUp(int v)
    {
        while (v)
        {
            if (hp[(v - 1) / 2] <= hp[v])
            {
                return;
            }
            std::swap(hp[(v - 1) / 2], hp[v]);
            //v -= 1;
            --v /= 2;
        }
    }

    void SiftDown(int v)
    {
        while( 2 * v + 1 < n)
        {
            int left = 2 * v + 1;
            int right = 2 * v + 2;
            if (right == n)
            {
                if (hp[left] < hp[v])
                {
                    std::swap(hp[left], hp[v]);
                }
                return;
            }
            else if (hp[left] <= hp[right])
            {
                if (hp[left] > hp[v])
                {
                    return;
                }
                std::swap(hp[left], hp[v]);
                v = left;
            }
            else if (hp[right] < hp[v])
            {
                std::swap(hp[right], hp[v]);
                v = right;
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
