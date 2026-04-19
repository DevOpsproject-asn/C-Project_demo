#include "math_utils.h"
#include <stdexcept>
#include <cmath>

namespace MathUtils {

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0.0) {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    return a / b;
}

double power(double base, int exponent) {
    return std::pow(base, exponent);
}

}  // namespace MathUtils
