
#include <iostream>

template <typename InputIterator, typename T>
bool find_sum(InputIterator begin,
        InputIterator end,
        const T &sum)
{
    if(begin >= end)
    {
        return false;
    }
    if(*begin + *end < sum)
    {
        return find_sum(begin + 1, end, sum);
    }
    else if(*begin + *end > sum)
    {
        return find_sum(begin, end - 1, sum);
    }
    else
    {
        return true;
    }
}

int32_t main()
{
    const int32_t size = 10;
    int32_t array[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int32_t *p = NULL;
    std::cout << find_sum(array, array + size, 7.0) << std::endl;
    std::cout << find_sum(array, array + size, 16) << std::endl;
    return 0;
}
