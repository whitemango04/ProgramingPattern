#pragma once

template <typename T>
class MSNode
{
public:
    MSNode() {};
    MSNode(T data) { _data = data; }
    ~MSNode() {};

    T _data;
    MSNode* next_node;
};

// 단순 연결리스트
template <typename T>
class MSList
{
public:
    MSList()
    {
        _head = nullptr;
        _tail = nullptr;
        _size = 0;
    };
    ~MSList() {};

    int get_size();
    void push_back(T data);
    void pop();
    T& operator[](int index);
private:
    MSNode<T>* _head;
    MSNode<T>* _tail;
    int _size;
};
