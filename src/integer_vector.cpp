#include "integer_vector.hpp"
#include <cstring>
#include <stdexcept>
#include <iostream>

// Constructors
IntegerVector::IntegerVector()
{
	this->m_nAllocated = BASE_SIZE;
	this->m_nUsed = 0;
	this->m_data = new int[this->m_nAllocated];
}

IntegerVector::IntegerVector(int size)
{
	this->m_nAllocated = size;
	this->m_nUsed = 0;
	this->m_data = new int[this->m_nAllocated];
}

// Destructor
IntegerVector::~IntegerVector()
{
	delete[] this->m_data;
}

// Copy constructor
IntegerVector::IntegerVector(const IntegerVector &other)
{
	this->m_nAllocated = other.m_nAllocated;
	this->m_nUsed = other.m_nUsed;
	this->m_data = new int[this->m_nAllocated];
	std::memcpy(this->m_data, other.m_data, other.m_nUsed * sizeof(int));
}

// Accessors
int IntegerVector::size() const
{
	return this->m_nUsed;
}

bool IntegerVector::empty() const
{
	return this->m_nUsed == 0;
}

int &IntegerVector::at(int index)
{
	// Check if the index is out of bounds
	if (index < 0 || index >= this->m_nUsed)
	{
		throw std::out_of_range("Index out of bounds");
	}

	return this->m_data[index];
}

const int &IntegerVector::at(int index) const
{
	return this->at(index);
}

void IntegerVector::print() const
{
	for (int i = 0; i < this->m_nUsed; i++)
	{
		std::cout << this->m_data[i] << " ";
	}
	std::cout << std::endl;
}

// Modifiers
void IntegerVector::push_back(int value)
{
	// grow logic
	if (this->m_nUsed == this->m_nAllocated)
	{
		int newSize = m_nAllocated * 2;
		int *pNewArray = new int[newSize];

		std::memcpy(pNewArray, this->m_data, this->m_nUsed * sizeof(int));

		this->m_nAllocated = newSize;
		delete[] this->m_data;
		this->m_data = pNewArray;
	}

	this->m_data[this->m_nUsed++] = value;
}

void IntegerVector::pop_back()
{
	if (this->m_nUsed == 0)
	{
		throw std::out_of_range("Cannot pop from an empty vector");
	}

	this->m_data[this->m_nUsed - 1] = 0;
	this->m_nUsed--;

	// shrink logic
	if (this->m_nUsed < this->m_nAllocated / 2 && this->m_nAllocated > this->BASE_SIZE)
	{
		int newSize = m_nAllocated / 2;
		int *pNewArray = new int[newSize];

		std::memcpy(pNewArray, this->m_data, this->m_nUsed * sizeof(int));

		this->m_nAllocated = newSize;
		delete[] this->m_data;
		this->m_data = pNewArray;
	}
}

void IntegerVector::clear()
{
	this->m_nUsed = 0;
	this->m_nAllocated = BASE_SIZE;
}

void IntegerVector::delete_at(int index)
{
	if (index < 0 || index >= this->m_nUsed)
	{
		throw std::out_of_range("Index out of bounds");
	}

	for (int i = index; i < this->m_nUsed - 1; i++)
	{
		this->m_data[i] = this->m_data[i + 1];
	}

	this->m_data[this->m_nUsed - 1] = 0;
	this->m_nUsed--;
}

IntegerVector &IntegerVector::operator=(const IntegerVector &other)
{
	if (this != &other)
	{
		delete[] this->m_data;

		this->m_nAllocated = other.m_nAllocated;
		this->m_nUsed = other.m_nUsed;
		this->m_data = new int[this->m_nAllocated];
		std::memcpy(this->m_data, other.m_data, other.m_nUsed * sizeof(int));
	}

	return *this;
}
