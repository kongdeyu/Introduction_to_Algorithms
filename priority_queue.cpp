
#include <climits>
#include <iostream>
#include <vector>

class Priority_Queue
{
public:
    bool insert(int32_t key);
    bool maximum(int32_t& key);
    bool extract_max(int32_t& key);
    bool increase_key(size_t index, int32_t key);

private:
    void _max_heapify(size_t index);

    std::vector<int32_t> _max_heap;
    size_t _heap_size;
};

bool Priority_Queue::insert(int32_t key)
{
    _heap_size += 1;
    _max_heap.push_back(INT_MIN);
    increase_key(_heap_size - 1, key);
    return true;
}

bool Priority_Queue::maximum(int32_t& key)
{
    if(0 == _heap_size)
    {
        return false;
    }
    key = _max_heap.at(0);
    return true;
}

bool Priority_Queue::extract_max(int32_t& key)
{
    if(0 == _heap_size)
    {
        return false;
    }
    key = _max_heap.at(0);
    _heap_size -= 1;
    if(2 <= _heap_size)
    {
        std::swap(_max_heap.at(0), _max_heap.at(_heap_size - 1));
        _max_heapify(0);
    }
    return true;
}

bool Priority_Queue::increase_key(size_t index, int32_t key)
{
    if(_heap_size == 0
            || index < 0
            || index >= _heap_size
            || _max_heap.at(index) >= key)
    {
        return false;
    }
    while(true)
    {
        size_t parent = (index + 1) / 2 - 1;
        if(parent < 0 || _max_heap.at(index) <= _max_heap.at(parent))
        {
            break;
        }
        _max_heap.at(index) = _max_heap.at(parent);
        index = parent;
    }
    _max_heap.at(index) = key;
    return true;
}

void Priority_Queue::_max_heapify(size_t index)
{
    size_t left = (index + 1) * 2 - 1;
    size_t right = (index + 1) * 2;
    size_t max = index;
    if(left < _heap_size && _max_heap.at(max) < _max_heap.at(left))
    {
        max = left;
    }
    if(right < _heap_size && _max_heap.at(max) < _max_heap.at(right))
    {
        max = right;
    }
    if(max != index)
    {
        std::swap(_max_heap.at(max), _max_heap.at(index));
        return _max_heapify(max);
    }
}

int32_t main()
{
    return 0;
}
