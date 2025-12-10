#include <gtest.h>
#include "MathEq.h"

TEST(MathEq, can_create_math_equation) {
	ASSERT_NO_THROW(MathEq("2+3"));
}
TEST(MathEq, cant_create_empty_math_equation) {
	ASSERT_ANY_THROW(MathEq(""));
}
TEST(MathEq, throws_when_lexeminate)
{
	string s = "a";
	ASSERT_ANY_THROW(MathEq a(s));
}
TEST(MathEq, throws_when_syntaxinate)
{
	string s = "--";
	ASSERT_ANY_THROW(MathEq a(s));
}
TEST(MathEq, can_make_unar) 
{
	string s = "1-(-1)";
	MathEq a(s);
	EXPECT_EQ(a.getRes(), 2);
}
TEST(MathEq, can_sum)
{
	string s = "1+2";
	MathEq a(s);
	EXPECT_EQ(a.getRes(), 3);
}
TEST(MathEq, can_sub)
{
	string s = "1-2";
	MathEq a(s);
	EXPECT_EQ(a.getRes(), -1);
}
TEST(MathEq, can_mult)
{
	string s = "1*2";
	MathEq a(s);
	EXPECT_EQ(a.getRes(), 2);
}
TEST(MathEq, can_div)
{
	string s = "1/2";
	MathEq a(s);
	EXPECT_EQ(a.getRes(), 0);
}