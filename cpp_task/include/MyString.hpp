#include <cwchar>

class MyString
{

public:
	//
						MyString();
						MyString( const MyString& other );
						MyString( MyString&& other );
						MyString( const char* other );
						~MyString();	
	
	//
	MyString&			operator=( const MyString& other );
	MyString&			operator=( MyString&& other );

	friend MyString 	operator+( const MyString& leftSting, const MyString& rightString );

	char				At( size_t pos ) const;

	void				Print() const;
	
	size_t 				GetSize() const 					{	return m_size;					}
	const char*			GetData() const						{	return m_data;					}
	char*				GetData() 							{	return m_data;					}

private:
	//
	size_t				m_size;
	char*				m_data;
};

bool operator==( const MyString& leftString, const MyString& rightString );
MyString operator+( const MyString& leftString, const MyString& rightString );
