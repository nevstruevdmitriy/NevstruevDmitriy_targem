#include <curl/curl.h>
#include <nlohmann/json.hpp>

#include <stdexcept>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <cstring>

using nlohmann::json;

std::string readBuffer;

size_t WriteCallback( void* contents, size_t size, size_t nmemb, void* )
{ 
    size_t realsize = size * nmemb;
    readBuffer.append( ( char* )contents, realsize );

    return realsize;
}

std::string GetTimeWeekAgo() 
{
	const long long WEEK_TIME_STEP = 604800;
	std::time_t result = std::time( nullptr );
	std::stringstream toString;
	
	result -= WEEK_TIME_STEP;
	toString << std::put_time( std::localtime( &result ), "%FT%TZ" );

	return toString.str();
}

std::string GetUrl( const std::string& url )
{
	std::string result( url );

	result += "/commits?since=" + GetTimeWeekAgo();

	return result;
}

bool Setopt( CURL* curl, const std::string& url)
{
	CURLcode result;
	
	result = curl_easy_setopt( curl, CURLOPT_URL, GetUrl( url ).c_str() );
	if( result != CURLE_OK )
	{
		return false;
	}

	result = curl_easy_setopt( curl, CURLOPT_USERAGENT, "Nevstruev Dmitriy" );
	if( result != CURLE_OK ) 
	{
		return false;
	}

	curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, WriteCallback );
	if( result != CURLE_OK )
	{
		return false;
	}

	result = curl_easy_setopt( curl, CURLOPT_SSL_VERIFYPEER, 0L );
	if( result != CURLE_OK )
	{
		return false;
	}

	return true;
}

std::string GetCommits( const std::string& url ) 
{
	CURL* curl;
	CURLcode result;
	
	curl = curl_easy_init();

	if( !curl )
	{
		throw std::runtime_error( "init failed" );
	}
	
	if( !Setopt( curl, url ) )
	{
		throw std::runtime_error( "setopt faild" );
	}

	result = curl_easy_perform( curl );

	if ( CURLE_OK != result ) 
	{
		curl_easy_cleanup( curl );
		throw std::runtime_error( "get data failed" );
	}

	curl_easy_cleanup( curl );

	return readBuffer;
}

int main()
{
	std::string github( "https://api.github.com/repos/curl/curl" );
	
	json commits = json::parse( GetCommits( github ) );

	for( auto& commit : commits.items() )
	{
		std::string data = commit.value()[ "commit" ][ "author" ][ "date" ].get< std::string >();
		std::string name = commit.value()[ "commit" ][ "author" ][ "name" ].get< std::string >();
		std::string message = commit.value()[ "commit" ][ "message" ].get< std::string>();

		printf( "data: %s\nname: %s:\nmessage:\n\n", data.c_str(), name.c_str() );
		printf( "%s\n", message.c_str() );
		printf( "------------------------------------------------------------------------\n\n\n\n" );
	}
	return 0;
}
