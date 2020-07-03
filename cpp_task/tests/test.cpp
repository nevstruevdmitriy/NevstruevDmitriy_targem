#include <MyString.hpp>
#include <string>

#include <gtest/gtest.h>

TEST( MyString, ConstructorsAndOperators )
{
	MyString firstString( "dima" );
	
	MyString secondString( firstString );
	MyString thirdString;

	EXPECT_EQ( firstString, secondString );
	EXPECT_EQ( secondString, "dima" );
	
	thirdString = std::move( firstString );

	EXPECT_EQ( secondString, thirdString );

}

// it will be takes a lot of time, if move semantics doesn't work;
TEST( MyString, TimeMoveOperator )
{
	const size_t SIZE_STRING = 10000;
	size_t NUMBER_OF_ITERATIONS = 1000000;
	MyString firstString( "dima" );
	MyString secondString;

	for( size_t i = 0; i < SIZE_STRING; ++i ) {
		secondString = secondString + firstString;
	}

	for( size_t i = 0; i < NUMBER_OF_ITERATIONS; ++i ) {
		if ( i % 2 ) 
		{
			MyString thirdString( std::move( firstString ) );
			secondString = std::move( thirdString );
		}
		else
		{
			MyString thirdString(std::move( secondString ));
			firstString = std::move( thirdString );
		}
	}

	EXPECT_EQ( firstString.GetSize(), 0 );
	EXPECT_EQ( secondString.GetSize(), 4 * SIZE_STRING );	
	EXPECT_EQ( secondString.At( 0 ), 'd' );
}

TEST( MyString, addition )
{
	MyString ziro( "" );
	MyString one( "1" );
	MyString two( "11" );
	MyString three( "111" );
	
	MyString name( "Dima" );
	MyString surname( "Nevstruev" );

	EXPECT_EQ( one + one, two );
	EXPECT_EQ( one + two, three );
	EXPECT_EQ( one + one + one, three );
	EXPECT_EQ( two + ziro, two );
	EXPECT_EQ( ziro + ziro, ziro );

	EXPECT_EQ( name + surname, "DimaNevstruev" );
	EXPECT_EQ( surname + "Dima", "NevstruevDima" );
	EXPECT_EQ( "Dima" + surname, "DimaNevstruev" );
	EXPECT_EQ( one + "1", "1" + one );
}

