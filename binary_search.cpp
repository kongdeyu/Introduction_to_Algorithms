
#include <iostream>

template <typename InputIterator, typename T>
bool binary_search(InputIterator begin,
        InputIterator end,
        const T &element,
        InputIterator &res)
{
    if(begin >= end)
        return false;
    InputIterator middle = begin + (end - begin) / 2;
    if(element == *middle)
    {
        res = middle;
        return true;
    }
    if(element < *middle)
    {
        return binary_search(begin, middle, element, res);
    }
    return binary_search(middle + 1, end, element, res);
}

int32_t main()
{
    const int32_t size = 10;
    int32_t array[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int32_t *p = NULL;
    std::cout << binary_search(array, array + size, 5, p) << std::endl;
    std::cout << binary_search(array, array + size, 30, p) << std::endl;
    return 0;
}
