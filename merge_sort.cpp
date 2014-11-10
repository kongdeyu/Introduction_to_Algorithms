
#include <iostream>
#include <vector>

template <typename T>
void print(T element)
{
    std::cout << element << " ";
}

template <typename InputIterator>
void merge_sort(InputIterator begin, InputIterator end)
{
    if(begin + 1 >= end)
    {
        return;
    }

    InputIterator middle = begin + (end - begin) / 2;
    merge_sort(begin, middle);
    merge_sort(middle, end);

    std::vector<typename std::iterator_traits<InputIterator>::value_type> temp;
    InputIterator left = begin;
    InputIterator right = middle;
    while(left != middle && right != end)
    {
        if(*left < *right)
        {
            temp.push_back(*left);
            left++;
        }
        else
        {
            temp.push_back(*right);
            right++;
        }
    }
    if(left != middle)
    {
        temp.insert(temp.end(), left, middle);
    }
    if(right != end)
    {
        temp.insert(temp.end(), right, end);
    }
    std::copy(temp.begin(), temp.end(), begin);
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
    merge_sort(array, array + size);
    std::cout << "after sort:";
    std::for_each(array, array + size, print<int32_t>);
    std::cout << std::endl;

    return 0;
}
