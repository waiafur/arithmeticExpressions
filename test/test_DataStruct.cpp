#include <gtest.h>
#include "dataStruct.h"

TEST(dataStruct, can_create_queue_with_positive_length) {
	ASSERT_NO_THROW(queue<int>(2));
}

TEST(dataStruct, cant_create_queue_negative_length)
{
	ASSERT_ANY_THROW(queue<int>q(-1));
}
TEST(dataStruct, can_create_copied_queue)
{
	queue<int> q(10);

	ASSERT_NO_THROW(queue<int> q1(q));
}
TEST(dataStruct, queue_can_be_full)
{
	queue<int> q(2);
	q.push(1);
	q.push(2);
	EXPECT_EQ(q.IsFull(), true);
}
TEST(dataStruct, queue_can_be_empty)
{
	queue<int> q(2);
	EXPECT_EQ(q.IsEmpty(), true);
}
TEST(dataStruct, queue_can_push)
{
	queue<int> q(2);
	ASSERT_NO_THROW(q.push(0));
}
TEST(dataStruct, queue_can_pop)
{
	queue<int> q(2);
	q.push(0);
	ASSERT_NO_THROW(q.pop());
}
TEST(dataStruct, copied_queue_is_equal_to_source_one)
{
	queue<int> q(2);
	q.push(1);
	q.push(2);
	queue<int> q1(q);
	EXPECT_EQ(q.pop(), q1.pop());
	EXPECT_EQ(q.pop(), q1.pop());
}
TEST(dataStruct, copied_queue_has_its_own_memory)
{
	queue<int> q(2);
	q.push(1);
	q.push(1);
	queue<int> q1(q);
	q.pop();
	q.pop();
	q.push(0);
	q.push(0);
	EXPECT_NE(q.pop(), q1.pop());
	EXPECT_NE(q.pop(), q1.pop());
}
TEST(dataStruct, queue_can_top)
{
	queue<int> q(2);
	q.push(0);
	ASSERT_NO_THROW(q.top());
}
TEST(dataStruct, queue_cant_push_when_full)
{
	queue<int> q(2);
	q.push(0);
	q.push(0);
	ASSERT_ANY_THROW(q.push(0));
}
TEST(dataStruct, queue_cant_pop_when_empty)
{
	queue<int> q(2);
	ASSERT_ANY_THROW(q.pop());
}
TEST(dataStruct, queue_cant_top_when_empty)
{
	queue<int> q(2);
	ASSERT_ANY_THROW(q.top());
}
TEST(dataStruct, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(stack<int>s(5));
}
TEST(dataStruct, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(stack<int>s(-1));
}
TEST(dataStruct, can_create_copied_stack)
{
	stack<int> s(10);

	ASSERT_NO_THROW(stack<int> s1(s));
}
TEST(dataStruct, stack_can_push)
{
	stack<int> s(2);
	ASSERT_NO_THROW(s.push(0));
}
TEST(dataStruct, stack_can_pop)
{
	stack<int> s(2);
	s.push(0);
	ASSERT_NO_THROW(s.pop());
}
TEST(dataStruct, copied_stack_is_equal_to_source_one)
{
	stack<int> s(2);
	s.push(1);
	s.push(2);
	stack<int> s1(s);
	EXPECT_EQ(s.pop(), s1.pop());
	EXPECT_EQ(s.pop(), s1.pop());
}
TEST(dataStruct, copied_stack_has_its_own_memory)
{
	stack<int> s(2);
	s.push(1);
	s.push(2);
	stack<int> s1(s);
	s.pop();
	s.pop();
	s.push(0);
	s.push(0);
	EXPECT_NE(s.pop(), s1.pop());
	EXPECT_NE(s.pop(), s1.pop());
}
TEST(dataStruct, can_be_full)
{
	stack<int> s(2);
	s.push(1);
	s.push(2);
	EXPECT_EQ(s.IsFull(), true);
}
TEST(dataStruct, stack_can_be_empty)
{
	stack<int> s(2);
	EXPECT_EQ(s.IsEmpty(), true);
}

TEST(dataStruct, stack_can_top)
{
	stack<int> s(2);
	s.push(0);
	ASSERT_NO_THROW(s.top());
}
TEST(dataStruct, stack_cant_push_when_full)
{
	stack<int> s(2);
	s.push(0);
	s.push(0);
	ASSERT_ANY_THROW(s.push(0));
}
TEST(dataStruct, stack_cant_pop_when_empty)
{
	stack<int> s(2);
	ASSERT_ANY_THROW(s.pop());
}

TEST(dataStruct, stack_cant_top_when_empty)
{
	stack<int> s(2);
	ASSERT_ANY_THROW(s.top());
}
