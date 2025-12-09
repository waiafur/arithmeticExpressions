#include <gtest.h>
#include "MathEq.h"

TEST(MathEq, can_create_math_equation) {
	ASSERT_NO_THROW(MathEq("2+3"));
}