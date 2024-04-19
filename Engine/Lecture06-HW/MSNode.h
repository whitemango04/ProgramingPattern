#pragma once

template <typename T>
class MSNode
{
public:
	MSNode(T data);
	~MSNode();

	T _data;
	MSNode* next_node;
};