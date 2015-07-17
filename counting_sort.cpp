
#include <climits>

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void print(T element)
{
    std::cout << element << " ";
}

bool num_range(const std::vector<int32_t> &array, int32_t &min, int32_t &max)
{
    min = INT_MAX;
    max = INT_MIN;
    if(array.empty())
    {
        return false;
    }

    for(std::vector<int32_t>::const_iterator cit = array.begin();
            cit != array.end();
            cit++)
    {
        if(*cit > max)
        {
            max = *cit;
        }
        if(*cit < min)
        {
            min = *cit;
        }
    }
    return true;
}

void counting_sort(std::vector<int32_t> &array)
{
    if(array.empty())
    {
        return;
    }

    int32_t min = 0;
    int32_t max = 0;
    if(!num_range(array, min, max) || min == max)
    {
        return;
    }

    std::vector<int32_t> counts(max - min + 1, 0);
    for(std::vector<int32_t>::const_iterator cit = array.begin();
            cit != array.end();
            cit++)
    {
        counts[*cit - min]++;
    }

    for(std::vector<int32_t>::iterator it = counts.begin() + 1;
            it != counts.end();
            it++)
    {
        *it = *it + *(it - 1);
    }

    std::vector<int32_t> temp(array.size(), 0);
    for(int32_t idx = array.size() - 1; idx >= 0; idx--)
    {
        counts[array[idx] - min]--;
        temp[counts[array[idx] - min]] = array[idx];
    }
    array.swap(temp);
}

int32_t main()
{
    const int32_t size = 10;
    int32_t array[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int32_t> input(array, array + size);
    std::cout << "before shuffle:";
    std::for_each(input.begin(), input.end(), print<int32_t>);
    std::cout << std::endl;
    std::random_shuffle(input.begin(), input.end());
    std::cout << "after shuffle:";
    std::for_each(input.begin(), input.end(), print<int32_t>);
    std::cout << std::endl;
    counting_sort(input);
    std::cout << "after sort:";
    std::for_each(input.begin(), input.end(), print<int32_t>);
    std::cout << std::endl;
    return 0;
}
