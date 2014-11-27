
#include <iostream>
#include <vector>

template <typename InputIterator>
int32_t inversion_num(InputIterator begin, InputIterator end)
{
    if(begin + 1 >= end)
    {
        return 0;
    }

    InputIterator middle = begin + (end - begin) / 2;
    int32_t left_num = inversion_num(begin, middle);
    int32_t right_num = inversion_num(middle, end);

    int32_t cur_num = 0;
    std::vector<typename std::iterator_traits<InputIterator>::value_type> temp;
    InputIterator left = begin;
    InputIterator right = middle;
    while(left != middle && right != end)
    {
        if(*left > *right)
        {
            temp.push_back(*right);
            cur_num += middle - left;
            right++;
        }
        else
        {
            temp.push_back(*left);
            left++;
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
    return left_num + right_num + cur_num;
}

int32_t main()
{
    const int32_t size = 10;
    int32_t array[size] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::cout << inversion_num(array, array + 10) << std::endl;
    return 0;
}