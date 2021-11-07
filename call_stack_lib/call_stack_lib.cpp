#include "call_stack_lib.h"
#include <string>

uint32_t fibonacci(uint32_t n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}