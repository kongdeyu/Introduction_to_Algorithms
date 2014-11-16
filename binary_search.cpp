
#include <iostream>

template <typename InputIterator>
bool binary_search(InputIterator begin,
        InputIterator end,
        typename std::iterator_traits<InputIterator>::value_type element)
{
    if(begin >= end)
        return false;
    InputIterator middle = begin + (end - begin) / 2;
    if(element == *middle)
    {
        return true;
    }
    if(element < *middle)
    {
        return binary_search(begin, middle, element);
    }
    return binary_search(middle + 1, end, element);
}

int32_t main()
{
    const int32_t size = 10;
    int32_t array[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << binary_search(array, array + size, 50) << std::endl;
    std::cout << binary_search(array, array + size, 30) << std::endl;
    return 0;
}
