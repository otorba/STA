#ifndef INTEGER_LINKED_LIST_HPP
#define INTEGER_LINKED_LIST_HPP

#include <tuple> 

class IntegerLinkedList
{
private:
	class Node
	{
	public:
		int m_Value;
		Node *m_pNext;

		// ctor
		Node(int value);
	};

	Node *m_pFirst;
	Node *m_pLast;
	int m_Size;

	std::tuple<Node *, Node *> FindBefore(int index);
	std::tuple<Node *, Node *> FindAfter(int index);

public:
	IntegerLinkedList();
	~IntegerLinkedList();

	// Accessors
	int Size() const;
	bool Empty() const;
	void Print() const;

	// Modifier
	void PushBack(int value);
	void PushFront(int value);

	void InsertBefore(int index, int value);
	void InsertAfter(int index, int value);

	void PopBack();

	void DeleteAfter(int index);
	void DeleteBefore(int index);

	void Clear();
};

#endif // INTEGER_LINKED_LIST_HPP