#ifndef INTEGER_VECTOR_HPP
#define INTEGER_VECTOR_HPP

class IntegerVector
{
private:
	static const int BASE_SIZE = 4;
	int *m_data;
	int n_Allocated;
	int n_Used;

public:
	// Constructors
	IntegerVector();
	IntegerVector(int size);

	// Destructor
	~IntegerVector();

	// Copy constructor
	IntegerVector(const IntegerVector &other);

	// Accessors
	int size() const;
	bool empty() const;
	int &at(int index);
	const int &at(int index) const;
	void print() const;

	// Modifiers
	void push_back(int value);
	void pop_back();
	void clear();
	IntegerVector &operator=(const IntegerVector &other);
};

#endif // INTEGER_VECTOR_HPP