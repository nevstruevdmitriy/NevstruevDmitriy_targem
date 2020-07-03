#include <MyString.hpp>

#include <stdexcept>
#include <vector>
#include <algorithm>
#include <locale>
#include <cstdio>
#include <cstring>

bool MyCmp( const MyString& leftString, const MyString& rightString )
{
	size_t minSize = std::min( leftString.GetSize(), rightString.GetSize() );
	
	for( size_t i = 0; i < minSize; ++i ) 
	{
		char leftChar = std::tolower( leftString.At( i ), std::locale() );
		char rightChar = std::tolower( rightString.At( i ), std::locale() );

		if( leftChar == rightChar ) 
		{
			continue;
		}

		return leftChar > rightChar;
	}

	return leftString.GetSize() > rightString.GetSize();
}

//------------- note: ListString will be changed -------------//
//                    answer is in ListString
void Solution( std::vector< MyString >* ListString )
{
	std::sort( ListString->begin(), ListString->end(), MyCmp );
}

int main () 
{
	const size_t SIZE_BUFFER = 100000;

	std::vector< MyString > ListString;
	MyString string;
	char* buffer = new char[ SIZE_BUFFER ];


	while( std::fgets( buffer, SIZE_BUFFER - 1, stdin ) ) 
	{
		if( buffer[ 0 ] == '\n' ) 
		{
			continue;
		}

		buffer[ std::strlen(buffer) - 1 ] = '\0';

		ListString.push_back( MyString( buffer ) );
	}

	Solution( &ListString );


	for( size_t i = 0; i < ListString.size(); ++i )
	{
		ListString[ i ].Print();
	}

	delete[] buffer;
	
	return 0;
}
