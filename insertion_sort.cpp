
#include <iostream>
#include <vector>
#include <algorithm>

template <typename InputIterator>
void print(InputIterator begin, InputIterator end)
{
    for(InputIterator it = begin;
            it != end;
            it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename InputIterator>
void insertion_sort(InputIterator begin, InputIterator end)
{
    InputIterator it = begin + 1;
    for(;it != end; it++)
    {
        typename std::iterator_traits<InputIterator>::value_type temp = *it;
        InputIterator sub = it - 1;
        while(sub >= begin && *sub > temp)
        {
            *(sub + 1) = *sub;
            sub--;
        }
        *(sub + 1) = temp;
    }
}

int32_t main()
{
    const int32_t size = 10;
    int32_t array[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "before shuffle:";
    print(array, array + size);
    std::random_shuffle(array, array + size);
    std::cout << "after shuffle:";
    print(array, array + size);
    insertion_sort(array, array + size);
    std::cout << "after sort:";
    print(array, array + size);

    return 0;
}
