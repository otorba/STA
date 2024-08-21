#include "integer_vector.hpp"
#include <cstring>
#include <stdexcept>
#include <iostream>

// Constructors
IntegerVector::IntegerVector()
{
	this->n_Allocated = BASE_SIZE;
	this->n_Used = 0;
	this->m_data = new int[this->n_Allocated];
}

IntegerVector::IntegerVector(int size)
{
	this->n_Allocated = size;
	this->n_Used = 0;
	this->m_data = new int[this->n_Allocated];
}

// Destructor
IntegerVector::~IntegerVector()
{
	delete[] this->m_data;
}

// Copy constructor
IntegerVector::IntegerVector(const IntegerVector &other)
{
	this->n_Allocated = other.n_Allocated;
	this->n_Used = other.n_Used;
	this->m_data = new int[this->n_Allocated];
	std::memcpy(this->m_data, other.m_data, other.n_Used * sizeof(int));
}

// Accessors
int IntegerVector::size() const
{
	return this->n_Used;
}

bool IntegerVector::empty() const
{
	return this->n_Used == 0;
}

int &IntegerVector::at(int index)
{
	// Check if the index is out of bounds
	if (index < 0 || index >= this->n_Used)
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
	for (int i = 0; i < this->n_Used; i++)
	{
		std::cout << this->m_data[i] << " ";
	}
	std::cout << std::endl;
}

// Modifiers
void IntegerVector::push_back(int value)
{
	// grow logic
	if (this->n_Used == this->n_Allocated)
	{
		int newSize = n_Allocated * 2;
		int *pNewArray = new int[newSize];

		std::memcpy(pNewArray, this->m_data, this->n_Used * sizeof(int));

		this->n_Allocated = newSize;
		delete[] this->m_data;
		this->m_data = pNewArray;
	}

	this->m_data[this->n_Used++] = value;
}

void IntegerVector::pop_back()
{
	if (this->n_Used == 0)
	{
		throw std::out_of_range("Cannot pop from an empty vector");
	}

	this->m_data[this->n_Used - 1] = 0;
	this->n_Used--;

	// shrink logic
	if (this->n_Used < this->n_Allocated / 2 && this->n_Allocated > this->BASE_SIZE)
	{
		int newSize = n_Allocated / 2;
		int *pNewArray = new int[newSize];

		std::memcpy(pNewArray, this->m_data, this->n_Used * sizeof(int));

		this->n_Allocated = newSize;
		delete[] this->m_data;
		this->m_data = pNewArray;
	}
}

void IntegerVector::clear()
{
	this->n_Used = 0;
	this->n_Allocated = BASE_SIZE;
}

IntegerVector &IntegerVector::operator=(const IntegerVector &other)
{
	if (this != &other)
	{
		delete[] this->m_data;

		this->n_Allocated = other.n_Allocated;
		this->n_Used = other.n_Used;
		this->m_data = new int[this->n_Allocated];
		std::memcpy(this->m_data, other.m_data, other.n_Used * sizeof(int));
	}

	return *this;
}
