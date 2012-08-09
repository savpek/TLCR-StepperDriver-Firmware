/* These tests require visua inspection from output!
 * Theres two categories: test which should pass and which should fail. */
#include "./utest/utest.h"

TEST_GROUP(utest);
TEST_SETUP(utest) {
}

TEST_TEAR_DOWN(utest) {
}

TEST(utest, all_asserts_should_fail) {
	TEST_ASSERT(NULL);
	TEST_ASSERT_EQUAL_UINT8(100, 12);
	TEST_ASSERT_EQUAL_UINT32(10000, 12);
	TEST_ASSERT_EQUAL_INT32(-10000, 10000);
	TEST_ASSERT_EQUAL_INT8(-100, 100);
	TEST_ASSERT_EQUAL_STRING("ab", "ii");
}

TEST(utest, all_asserts_should_pass) {
	TEST_ASSERT(1);
	TEST_ASSERT_EQUAL_UINT8(100, 100);
	TEST_ASSERT_EQUAL_UINT32(10000, 10000);
	TEST_ASSERT_EQUAL_INT32(-10000, -10000);
	TEST_ASSERT_EQUAL_INT8(-100, -100);
	TEST_ASSERT_EQUAL_STRING("ab", "ab");
}

TEST_GROUP_RUNNER(utest) {
	RUN_TEST_CASE(utest, all_asserts_should_pass);
	RUN_TEST_CASE(utest, all_asserts_should_fail);
}