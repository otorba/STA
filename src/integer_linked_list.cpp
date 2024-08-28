#include "integer_linked_list.hpp"
#include <iostream>

std::tuple<IntegerLinkedList::Node *, IntegerLinkedList::Node *> IntegerLinkedList::FindBefore(int index)
{
	Node *pPrevNode = nullptr;
	Node *pAtNode = this->m_pFirst;
	for (int i = 0; i < this->m_Size; i++)
	{
		if (i == index)
		{
			break;
		}
		pPrevNode = pAtNode;
		pAtNode = pAtNode->m_pNext;
	}

	return std::make_tuple(pPrevNode, pAtNode);
}

std::tuple<IntegerLinkedList::Node *, IntegerLinkedList::Node *> IntegerLinkedList::FindAfter(int index)
{
	Node *pAtNode = this->m_pFirst;
	Node *pNextNode = pAtNode->m_pNext;

	for (int i = 0; i < this->m_Size; i++)
	{
		if (i == index)
		{
			break;
		}
		pAtNode = pAtNode->m_pNext;
		pNextNode = pAtNode->m_pNext;
	}
	return std::make_tuple(pNextNode, pAtNode);
}

// Constructor
IntegerLinkedList::IntegerLinkedList()
{
	this->m_pFirst = this->m_pLast = nullptr;
	this->m_Size = 0;
}

IntegerLinkedList::~IntegerLinkedList()
{
	this->Clear();
	std::cout << "Destructor called\n";
}

// Accessors
int IntegerLinkedList::Size() const { return this->m_Size; }

bool IntegerLinkedList::Empty() const { return this->m_Size == 0; }

void IntegerLinkedList::Print() const
{
	Node *currentNode = this->m_pFirst;

	for (int i = 0; i < this->m_Size; i++)
	{
		if (currentNode == nullptr)
		{
			break;
		}

		std::cout << currentNode->m_Value << " ";
		currentNode = currentNode->m_pNext;
	}
}

// Modifiers
void IntegerLinkedList::PushBack(int value)
{
	Node *node = new Node(value);
	if (this->Empty())
	{
		this->m_pFirst = node;
	}
	else
	{
		this->m_pLast->m_pNext = node; // to get access to the next new element
	}
	this->m_pLast = node;
	this->m_Size++;
}

void IntegerLinkedList::PushFront(int value)
{
	Node *node = new Node(value);
	if (this->Empty())
	{
		this->m_pFirst = this->m_pLast = node;
	}
	else
	{
		node->m_pNext = this->m_pFirst;
		this->m_pFirst = node;
	}

	this->m_Size++;
}

void IntegerLinkedList::InsertBefore(int index, int value)
{
	if (this->Empty() || index >= this->m_Size)
	{
		PushBack(value);
		return;
	}

	auto [pPrevNode, pAtNode] = this->FindBefore(index);

	Node *newNode = new Node(value);
	newNode->m_pNext = pAtNode;
	if (pPrevNode != nullptr)
	{
		pPrevNode->m_pNext = newNode;
	}
	else
	{
		this->m_pFirst = newNode;
	}

	this->m_Size++;
}

void IntegerLinkedList::InsertAfter(int index, int value)
{
	if (this->Empty() || index >= this->m_Size)
	{
		PushBack(value);
		return;
	}

	auto [pNextNode, pAtNode] = this->FindAfter(index);

	Node *newNode = new Node(value);
	pAtNode->m_pNext = newNode;
	if (pNextNode != nullptr)
	{
		newNode->m_pNext = pNextNode;
	}
	else
	{
		this->m_pLast = newNode;
	}

	this->m_Size++;
}

void IntegerLinkedList::PopBack()
{
	DeleteAfter(this->m_Size - 2);
}

void IntegerLinkedList::DeleteAfter(int index)
{
	if (this->Empty() || index >= this->m_Size)
	{
		return;
	}

	auto [pNextNode, pAtNode] = this->FindAfter(index);

	if (pNextNode != nullptr)
	{
		pAtNode->m_pNext = pNextNode->m_pNext;
		if (pNextNode == this->m_pLast)
		{
			this->m_pLast = pAtNode;
		}

		delete pNextNode;
		this->m_Size--;
	}
}

void IntegerLinkedList::DeleteBefore(int index)
{
	if (this->Empty() || index <= 0 || index >= this->m_Size)
	{
		return;
	}

	auto [pPrevNode, pToDeleteNode] = this->FindBefore(index - 1);
	if (pToDeleteNode != nullptr)
	{
		if (pPrevNode != nullptr)
		{
			pPrevNode->m_pNext = pToDeleteNode->m_pNext;
		}
		else
		{
			this->m_pFirst = pToDeleteNode->m_pNext;
		}

		delete pToDeleteNode;
		this->m_Size--;
	}
}

void IntegerLinkedList::Clear()
{
	for (int i = 0; i < this->m_Size; i++)
	{
		Node *pNode = this->m_pFirst;
		this->m_pFirst = pNode->m_pNext;
		delete pNode;
	}

	this->m_Size = 0;
	this->m_pFirst = this->m_pLast = nullptr;
}

IntegerLinkedList::Node::Node(int value)
{
	this->m_Value = value;
	this->m_pNext = nullptr;
}
