
#include <cmath>

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void print(T element)
{
    std::cout << element << " ";
}

int32_t max_bits(const std::vector<int32_t> &array)
{
    if(array.empty())
    {
        return 0;
    }

    int32_t max = INT_MIN;
    for(std::vector<int32_t>::const_iterator cit = array.begin();
            cit != array.end();
            cit++)
    {
        if(*cit > max)
        {
            max = *cit;
        }
    }

    int32_t res = 0;
    while(max > 0)
    {
        max /= 10;
        res++;
    }
    return res;
}

void radix_sort(std::vector<int32_t> &array)
{
    int32_t bits = max_bits(array);
    int32_t radix = 1;
    for(int32_t i = 0; i < bits; i++)
    {
        std::vector<int32_t> counts(10, 0);
        for(std::vector<int32_t>::const_iterator cit = array.begin();
                cit != array.end();
                cit++)
        {
            std::vector<int32_t>::size_type idx = (*cit) / radix % 10;
            counts[idx]++;
        }

        for(std::vector<int32_t>::iterator it = counts.begin() + 1;
                it != counts.end();
                it++)
        {
            *it += *(it - 1);
        }

        std::vector<int32_t> temp(array.size(), 0);
        for(int32_t i = array.size() - 1; i >= 0; i--)
        {
            std::vector<int32_t>::size_type idx = array[i] / radix % 10;
            counts[idx]--;
            temp[counts[idx]] = array[i];
        }

        array.swap(temp);
        radix *= 10;
    }
}

int32_t main()
{
    const int32_t size = 10;
    int32_t array[size] = {123, 2353, 3332, 444541, 597855, 63175, 73, 8, 91341, 13850};
    std::vector<int32_t> input(array, array + size);
    std::cout << "before shuffle:";
    std::for_each(input.begin(), input.end(), print<int32_t>);
    std::cout << std::endl;
    std::random_shuffle(input.begin(), input.end());
    std::cout << "after shuffle:";
    std::for_each(input.begin(), input.end(), print<int32_t>);
    std::cout << std::endl;
    radix_sort(input);
    std::cout << "after sort:";
    std::for_each(input.begin(), input.end(), print<int32_t>);
    std::cout << std::endl;
    return 0;
}
