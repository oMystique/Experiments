// TrimBlanksTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../TrimBlanks/TrimBlanks.h"

namespace
{
void VerifyResults(const std::string &resultStr, const std::string &expectedString)
{
	BOOST_CHECK_EQUAL(resultStr, expectedString);
}
}

BOOST_AUTO_TEST_SUITE(trim_blanks)
	BOOST_AUTO_TEST_CASE(empty_string)
	{
		VerifyResults(TrimBlanks(""), "");
	}
	BOOST_AUTO_TEST_CASE(string_of_characters_not_containing_spaces)
	{
		VerifyResults(TrimBlanks("SomeString"), "SomeString");
	}
	BOOST_AUTO_TEST_CASE(string_with_several_spaces_in_the_beggining)
	{
		VerifyResults(TrimBlanks("     SomeString"), "SomeString");
	}
	BOOST_AUTO_TEST_CASE(string_with_several_spaces_in_the_end)
	{
		VerifyResults(TrimBlanks("SomeString    "), "SomeString");
	}
	BOOST_AUTO_TEST_CASE(string_with_single_space_in_the_middle)
	{
		VerifyResults(TrimBlanks("Some String"), "Some String");
	}
	BOOST_AUTO_TEST_CASE(string_with_several_consecutive_spaces_in_the_middle)
	{
		VerifyResults(TrimBlanks("Some     String"), "Some     String");
	}
	BOOST_AUTO_TEST_CASE(string_with_spaces_at_the_beggining_middle_and_end)
	{
		VerifyResults(TrimBlanks("   Some String   "), "Some String");
	}
	BOOST_AUTO_TEST_CASE(string_of_spaces)
	{
		VerifyResults(TrimBlanks("       "), "");
	}
BOOST_AUTO_TEST_SUITE_END()