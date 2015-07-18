
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

template <typename InputIterator>
void print(InputIterator begin, InputIterator end)
{
    std::cout << "element number:" << end - begin << std::endl;
    for(InputIterator it = begin; it != end; it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int32_t ch2num(char ch)
{
    return ch - '0';
}

std::vector<int32_t> string2num(const std::string &num)
{
    std::vector<int32_t> res;
    std::string::const_iterator cit = num.begin();
    if(*cit != '-' && *cit != '+' && (*cit < '0' || *cit > '9'))
    {
        res.push_back(0);
        return res;
    }

    if(*cit == '-' || *cit == '+')
    {
        cit++;
    }

    for(; cit != num.end(); cit++)
    {
        if(*cit < '0' || *cit > '9')
        {
            break;
        }

        res.push_back(ch2num(*cit));
    }

    return res;
}

std::vector<int32_t> add(const std::vector<int32_t> &num1, const std::vector<int32_t> &num2)
{
    int32_t size = std::max(num1.size(), num2.size());
    std::vector<int32_t> res(size + 1, 0);
    int32_t idx1 = num1.size() - 1;
    int32_t idx2 = num2.size() - 1;
    int32_t carry = 0;
    int32_t idx = res.size() - 1;
    while(idx1 >=0 && idx2 >= 0)
    {
        int32_t temp = num1[idx1] + num2[idx2] + carry;
        if(temp >= 10)
        {
            temp -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        res[idx--] = temp;
        idx1--;
        idx2--;
    }

    while(idx1 >= 0)
    {
        int32_t temp = num1[idx1] + carry;
        if(temp >= 10)
        {
            temp -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        res[idx--] = temp;
        idx1--;
    }

    while(idx1 >= 0)
    {
        int32_t temp = num1[idx1] + carry;
        if(temp >= 10)
        {
            temp -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        res[idx--] = temp;
        idx1--;
    }
    res[idx] = carry;
    return res;
}

std::string multiply(const std::string &num1, const std::string &num2)
{
    if(num1.empty() || num2.empty())
    {
        return "0";
    }

    bool is_negative = false;
    if(num1.front() == '-')
    {
        is_negative = true;
    }

    if(num2.front() == '-' && is_negative)
    {
        is_negative = false;
    }
    else if(num2.front() == '-' && !is_negative)
    {
        is_negative = true;
    }

    std::vector<int32_t> vec_num1(string2num(num1));
    std::vector<int32_t> vec_num2(string2num(num2));
    std::vector<int32_t> res(vec_num1.size() + vec_num2.size(), 0);
    int32_t model1 = 0;
    for(int32_t idx1 = vec_num1.size() - 1; idx1 >= 0; idx1--)
    {
        int32_t model2 = 0;
        std::vector<int32_t> temp;
        for(int32_t idx2 = vec_num2.size() - 1; idx2 >= 0; idx2--)
        {
            int32_t digit = vec_num1[idx1] * vec_num2[idx2];
            std::stringstream ss;
            ss << digit;
            for(int32_t i = 0; i < model1 + model2; i++)
            {
                ss << '0';
            }
            temp = string2num(ss.str());
            res = add(res, temp);
            model2++;
        }
        model1++;
    }

    std::stringstream ss;
    if(is_negative)
    {
        ss << '-';
    }
    std::vector<int32_t>::const_iterator cit = res.begin();
    while(cit != res.end() && *cit == 0)
    {
        cit++;
    }
    for(; cit != res.end(); cit++)
    {
        ss << *cit;
    }
    return ss.str();
}

int32_t main()
{
    std::string str_num1("-123");
    std::string str_num2("+456");
    std::cout << multiply(str_num1, str_num2) << std::endl;
    return 0;
}
