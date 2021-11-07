#pragma once

#include <string>

#define CALL_STACK_LIB_VISIBILITY __attribute__((visibility("default")))


CALL_STACK_LIB_VISIBILITY uint32_t fibonacci(uint32_t n);

