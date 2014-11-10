
#include <iostream>
#include <algorithm>

template <typename T>
void print(T element)
{
    std::cout << element << " ";
}

template <typename InputIterator>
void selection_sort(InputIterator begin, InputIterator end)
{
    for(InputIterator it = begin; it != end - 1; it++)
    {
        InputIterator min = it;
        for(InputIterator sub = it + 1; sub != end; sub++)
        {
            if(*sub < *min)
            {
                min = sub;
            }
        }
        std::swap(*it, *min);
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
    selection_sort(array, array + size);
    std::cout << "after sort:";
    std::for_each(array, array + size, print<int32_t>);
    std::cout << std::endl;

    return 0;
}
