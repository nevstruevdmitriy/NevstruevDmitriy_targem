#include <MyString.hpp>

#include <algorithm>
#include <cstring>
#include <stdexcept>

//
MyString::MyString() : m_size( 0 ), m_data( nullptr ) {}


//
MyString::MyString( const MyString& other ) : m_size( 0 ), m_data( nullptr ) 
{
	(*this) = other;
}


//
MyString::MyString( MyString&& other ) : m_size( 0 ), m_data( nullptr ) 
{
	(*this) = std::move( other );
}


//
MyString::MyString( const char* other )
{
	m_size = std::strlen( other );

	m_data = new char[ m_size ];
	std::copy( other, other + m_size, m_data );
}


//
MyString::~MyString()
{
	delete[] m_data;	
}


//
MyString& MyString::operator=( const MyString& other ) 
{
	if ( m_data ) 
	{
		delete[] m_data;
	}

	m_size = other.m_size;

	m_data = new char[ m_size ];
	std::copy( other.m_data, other.m_data + other.m_size, m_data );
	return *this;
}


//
MyString& MyString::operator=( MyString&& other )
{
	if ( m_data ) 
	{
		delete[] m_data;
	}

	m_size = other.m_size;
	m_data = other.m_data;

	other.m_size = 0;
	other.m_data = nullptr;

	return *this;
}

//
bool operator==( const MyString& leftString, const MyString& rightString )
{
	if ( leftString.GetSize() != rightString.GetSize() )
	{
		return false;
	}

	for ( size_t i = 0; i < leftString.GetSize(); ++i ) {
		if ( leftString.At(i) != rightString.At( i ) ) 
		{
			return false;
		}
	}

	return true;
}

//
MyString operator+( const MyString& leftString, const MyString& rightString )
{
	size_t resultSize = leftString.m_size + rightString.m_size;
	MyString result;

	result.m_data = new char[ resultSize ];
	result.m_size = resultSize;
	
	std::copy( leftString.m_data, leftString.m_data + leftString.m_size, result.m_data );
	std::copy( rightString.m_data, rightString.m_data + rightString.m_size, result.m_data + leftString.m_size );
	
	return result;
}

//
char MyString::At(size_t pos) const 
{
	if( pos >= m_size )
	{
		throw std::out_of_range( "In MyString::At pos >= m_size\n" );
	}

	return m_data[ pos ];
}

//
void MyString::Print() const
{
	for( size_t i = 0; i < m_size; ++i ) 
	{
		printf( "%c", m_data[ i ] );
	}
	printf( "\n" );
}
