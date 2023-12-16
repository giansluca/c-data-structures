#include "unity/unity.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void) {
    // Add any necessary setup code here
}

void tearDown(void) {
    // Add any necessary teardown code here
}

void test_function_should_doBlahAndBlah(void) {
    // test stuff
}

void test_function_should_doAlsoDoBlah(void) {
    // more test stuff
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_function_should_doBlahAndBlah);
    RUN_TEST(test_function_should_doAlsoDoBlah);
    return UNITY_END();
}