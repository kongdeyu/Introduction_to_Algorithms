
#include <algorithm>
#include <iostream>

void max_heapify_1(int32_t array[], int32_t length, int32_t index)
{
    assert(length > index);

    int32_t left = (index + 1) * 2 - 1;
    int32_t right = (index + 1) * 2;
    int32_t max_index = index;
    if(left < length && array[max_index] < array[left])
    {
        max_index = left;
    }
    if(right < length && array[max_index] < array[right])
    {
        max_index = right;
    }
    if(max_index != index)
    {
        std::swap(array[index], array[max_index]);
        max_heapify_1(array, length, max_index);
    }
}

void max_heapify_2(int32_t array[], int32_t length, int32_t index)
{
    assert(length > index);

    while(true)
    {
        int32_t left = (index + 1) * 2 - 1;
        int32_t right = (index + 1) * 2;
        int32_t max_index = index;
        if(left < length && array[max_index] < array[left])
        {
            max_index = left;
        }
        if(right < length && array[max_index] < array[right])
        {
            max_index = right;
        }
        if(max_index == index)
        {
            break;
        }
        std::swap(array[index], array[max_index]);
        index = max_index;
    }
}

void build_max_heap(int32_t array[], int32_t length)
{
    assert(length > 1);
    for(int32_t i = length / 2 - 1; i >= 0; i--)
    {
        max_heapify_2(array, length, i);
    }
}

void heap_sort(int32_t array[], int32_t length)
{
    assert(length > 1);
    for(int32_t i = 0; i < length - 1; i++)
    {
        std::swap(array[0], array[length - i - 1]);
        max_heapify_1(array, length - i - 1, 0);
    }
}

int32_t main()
{
    int32_t array[] = {1,2,3,4,5,6,7,8,9,10};
    for(int32_t i = 0; i < 10; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
    build_max_heap(array, 10);
    for(int32_t i = 0; i < 10; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
    heap_sort(array, 10);
    for(int32_t i = 0; i < 10; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
    return 0;
}
