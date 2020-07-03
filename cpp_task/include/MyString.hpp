class MyString
{

public:
	//
						MyString( size_t capacity = 1, size_t expensive = 2 );
						MyString( const MyString& other );
						MyString( MyString&& other );
						MyString( const char* other );
	
	//
	MyString&			operator=( const MyString& other );
	MyString&			operator=( MyString&& other );

	friend MyString 	operator+( const MyString& leftSting, const MyString& rightString );
	friend MyString 	operator+( MyString&& leftSting, const MyString& rightString );
	friend MyString 	operator+( const MyString& leftSting, MyString&& rightString );
	friend MyString     operator+( MyString&& leftSting, MyString&& rightString );

	size_t 				GetSize() const 				{	return m_size;					}
	size_t				GetCapacity() const				{	return m_capacity				}
	bool				IsEmpty() const					{	return m_size					}

private:
	//
	char *				data;

	size_t				m_size;
	size_t				m_capacity;

	// to get new m_capacity, when m_capacity equal m_size
	static const double	EXPENSIVE; /// !!!!!!!!!!!!!!!!!!

	//
	size_t 				GetNewCapacity() const 			{	return EXPENSIVE * m_capacity	}
}
