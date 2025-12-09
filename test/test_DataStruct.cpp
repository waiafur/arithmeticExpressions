#include <gtest.h>
#include "dataStruct.h"

TEST(dataStruct, can_create_queue) {
	ASSERT_NO_THROW(queue<int>(2));
}

