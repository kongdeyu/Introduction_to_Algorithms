
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

template <typename T>
void print(T element)
{
    std::cout << element << " ";
}

template <typename InputIterator>
void permute_by_sorting(InputIterator begin, InputIterator end)
{
    ptrdiff_t size = end - begin;
    int32_t model = static_cast<int32_t>(pow(size, 3));
    std::vector<int32_t> keys;
    for(InputIterator it = begin; it != end; it++)
    {
        keys.push_back(rand() % model);
    }

    std::vector<bool> symbol(model, false);
    std::vector<int32_t> temp(model, 0);
    InputIterator it_in = begin;
    for(std::vector<int32_t>::iterator it = keys.begin();
            it != keys.end();
            it++)
    {
        temp.at(*it) = *it_in++;
        symbol.at(*it) = true;
    }

    size_t index = 0;
    it_in = begin;
    for(std::vector<int32_t>::iterator it = temp.begin();
            it != temp.end();
            it++)
    {
        if(symbol.at(index++))
            *it_in++ = *it;
    }
}

template <typename InputIterator>
void permute_in_place(InputIterator begin, InputIterator end)
{
    ptrdiff_t size = end - begin;
    size_t index = 0;
    for(InputIterator it = begin; it != end; it++)
    {
        ptrdiff_t temp = rand() % (size - index);
        std::swap(*it, *(it + temp));
        index++;
    }
}

int32_t main()
{
    std::vector<int32_t> array;
    const int32_t size = 10;
    for(int32_t i = 0; i < size; i++)
    {
        array.push_back(i);
    }
    permute_by_sorting(array.begin(), array.end());
    std::cout << "permute by sorting:";
    for_each(array.begin(), array.end(), print<int32_t>);
    std::cout << std::endl;

    array.clear();
    for(int32_t i = 0; i < size; i++)
    {
        array.push_back(i);
    }
    permute_in_place(array.begin(), array.end());
    std::cout << "permute in place:";
    for_each(array.begin(), array.end(), print<int32_t>);
    std::cout << std::endl;
    return 0;
}