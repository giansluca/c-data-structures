#include "modules/array_test.h"
#include "unity/unity.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void) {
    // Add any necessary setup code here
}

void tearDown(void) {
    // Add any necessary teardown code here
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_one);
    return UNITY_END();
}