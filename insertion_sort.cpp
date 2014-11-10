
#include <iostream>
#include <algorithm>

template <typename T>
void print(T element)
{
    std::cout << element << " ";
}

template <typename InputIterator>
void insertion_sort(InputIterator begin, InputIterator end)
{
    for(InputIterator it = begin + 1; it != end; it++)
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
    std::for_each(array, array + size, print<int32_t>);
    std::cout << std::endl;
    std::random_shuffle(array, array + size);
    std::cout << "after shuffle:";
    std::for_each(array, array + size, print<int32_t>);
    std::cout << std::endl;
    insertion_sort(array, array + size);
    std::cout << "after sort:";
    std::for_each(array, array + size, print<int32_t>);
    std::cout << std::endl;

    return 0;
}
