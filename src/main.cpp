#include <iostream>
#include "math_utils.h"

/**
 * @file main.cpp
 * @brief Main application demonstrating math utilities
 */

int main() {
    std::cout << "===== Math Utilities Application =====" << std::endl;
    std::cout << std::endl;

    // Example usage of math utilities
    double num1 = 10.5;
    double num2 = 3.0;

    std::cout << "Number 1: " << num1 << std::endl;
    std::cout << "Number 2: " << num2 << std::endl;
    std::cout << std::endl;

    // Addition
    double result = MathUtils::add(num1, num2);
    std::cout << "Addition: " << num1 << " + " << num2 << " = " << result << std::endl;

    // Subtraction
    result = MathUtils::subtract(num1, num2);
    std::cout << "Subtraction: " << num1 << " - " << num2 << " = " << result << std::endl;

    // Multiplication
    result = MathUtils::multiply(num1, num2);
    std::cout << "Multiplication: " << num1 << " * " << num2 << " = " << result << std::endl;

    // Division
    try {
        result = MathUtils::divide(num1, num2);
        std::cout << "Division: " << num1 << " / " << num2 << " = " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Power
    result = MathUtils::power(2.0, 8);
    std::cout << "Power: 2 ^ 8 = " << result << std::endl;

    std::cout << std::endl;
    std::cout << "======================================" << std::endl;

    return 0;
}
