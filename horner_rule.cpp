
#include <iostream>
#include <vector>

template <typename InputIterator, typename K>
double horner_rule(InputIterator begin, InputIterator end, K factor)
{
    double res = 0.0;
    for(InputIterator it = end - 1;
            it != begin - 1;
            it--)
    {
        res = factor * res + *it;
    }
    return res;
}

int32_t main()
{
    const int32_t size = 10;
    int32_t array[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << horner_rule(array, array + 3, 3) << std::endl;
    return 0;
}
