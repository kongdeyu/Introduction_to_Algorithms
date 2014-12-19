
#include <cstdlib>
#include <cassert>
#include <vector>
#include <iostream>

int32_t random0_or_1()
{
    return rand() % 2;
}

int32_t randoma2b(int32_t a, int32_t b)
{
    assert(a <= b);

    int32_t temp = b;
    int32_t bits_of_b = 0;
    while(0 < temp)
    {
        temp >>= 1;
        bits_of_b++;
    }
    int32_t num = 0;
    for(int32_t i = 0; i < bits_of_b; i++)
    {
        num |= (random0_or_1() << i);
    }
    if(num >= a && num <= b)
        return num;
    else
        return randoma2b(a, b);
}

int32_t main()
{
    int32_t a = 3;
    int32_t b = 9;
    std::vector<int32_t> counts_of_num(b - a + 1, 0); 
    for(int32_t i = 0; i < 1000; i++)
    {
        int32_t num = randoma2b(a, b);
        counts_of_num.at(num - a)++;
    }
    int32_t offset = 0;
    for(std::vector<int32_t>::const_iterator cit = counts_of_num.begin();
            cit != counts_of_num.end();
            cit++)
    {
        std::cout << a + offset
            << ':'
            <<*cit
            << std::endl;
        offset++;
    }
    return 0;
}
