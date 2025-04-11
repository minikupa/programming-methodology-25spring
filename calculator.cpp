#include "calculator.h"
#include <stdexcept>

int Calculator::add(int a, int b) {
    if ((b > 0) && (a > INT_MAX - b)) {
        throw std::overflow_error("Integer overflow");
    }
    if ((b < 0) && (a < INT_MIN - b)) {
        throw std::overflow_error("Integer underflow");
    }
    return a + b;
    // TODO
}

int Calculator::sub(int a, int b) {
    if ( (b < 0) && a > INT_MAX + b) {
        throw std::overflow_error("sub overflow");
    }
    if ( (b  > 0) && a < INT_MIN + b) {
        throw std::overflow_error("sub underflow");
    }

    return a - b;
    // TODO
}

int Calculator::mul(int a, int b) {
    if ( a > INT_MAX / b) {
        throw std::overflow_error("mul overflow");
    }
    if ( a < INT_MIN / b) {
        throw std::overflow_error("mul underflow");
    }

    return a * b;
    // TODO
}

int Calculator::div(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    if ( a == INT_MIN && b == -1) {
        throw std::overflow_error("div overflow");
    }
    return a / b;
    // TODO
}
