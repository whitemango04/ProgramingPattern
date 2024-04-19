#include "MSList.h"

template<typename T>
int MSList<T>::get_size()
{
    return _size;
}

template<typename T>
void MSList<T>::push_back(T data)
{
    MSNode<T>* node = new MSNode<T>(data);
    node->next_node = nullptr;

    if (_head == nullptr)
    {
        _head = node;
        _tail = node;
        return;
    }
    else
    {
        _tail->next_node = node;
        _tail = node;
    }
    _size++;
}

template<typename T>
void MSList<T>::pop()
{

}

template<typename T>
T& MSList<T>::operator[](int index)
{
    MSNode<T>* cursor = _head;
    for (int i = 0; i < index; i++)
    {
        cursor = cursor->next_node;
    }
    return cursor->_data;
}