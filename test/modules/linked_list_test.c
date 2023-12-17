#include "../unity/unity.h"
#include <stdio.h>

void it_should_pass() {
}

int main() {
    UNITY_BEGIN();

    RUN_TEST(it_should_pass);

    return UNITY_END();
}

void setUp(void) {
    //
}

void tearDown(void) {
    //
}
