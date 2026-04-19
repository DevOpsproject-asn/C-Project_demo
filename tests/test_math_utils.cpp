#include "math_utils.h"
#include <iostream>
#include <cmath>
#include <cassert>
#include <sstream>

/**
 * @file test_math_utils.cpp
 * @brief Unit tests for math utilities
 */

// Custom assertion with error reporting
#define ASSERT_EQUAL(actual, expected, tolerance) \
    do { \
        if (std::abs(actual - expected) > tolerance) { \
            std::cerr << "FAIL: Expected " << expected << " but got " << actual << std::endl; \
            throw std::runtime_error("Test failed"); \
        } \
    } while(0)

#define ASSERT_THROW(expr, exception_type) \
    do { \
        bool threw = false; \
        try { \
            expr; \
        } catch (const exception_type&) { \
            threw = true; \
        } \
        if (!threw) { \
            std::cerr << "FAIL: Expected exception but none was thrown" << std::endl; \
            throw std::runtime_error("Test failed"); \
        } \
    } while(0)

int test_count = 0;
int passed_count = 0;
int failed_count = 0;

void run_test(const std::string& test_name, void (*test_func)()) {
    test_count++;
    try {
        test_func();
        passed_count++;
        std::cout << "[PASS] " << test_name << std::endl;
    } catch (const std::exception& e) {
        failed_count++;
        std::cout << "[FAIL] " << test_name << " - " << e.what() << std::endl;
    }
}

// ===== Addition Tests =====
void test_add_positive_numbers() {
    double result = MathUtils::add(5.0, 3.0);
    ASSERT_EQUAL(result, 8.0, 1e-9);
}

void test_add_negative_numbers() {
    double result = MathUtils::add(-5.0, -3.0);
    ASSERT_EQUAL(result, -8.0, 1e-9);
}

void test_add_mixed_numbers() {
    double result = MathUtils::add(10.5, -3.2);
    ASSERT_EQUAL(result, 7.3, 1e-9);
}

void test_add_with_zero() {
    double result = MathUtils::add(5.0, 0.0);
    ASSERT_EQUAL(result, 5.0, 1e-9);
}

// ===== Subtraction Tests =====
void test_subtract_positive_numbers() {
    double result = MathUtils::subtract(10.0, 3.0);
    ASSERT_EQUAL(result, 7.0, 1e-9);
}

void test_subtract_negative_numbers() {
    double result = MathUtils::subtract(-5.0, -3.0);
    ASSERT_EQUAL(result, -2.0, 1e-9);
}

void test_subtract_same_number() {
    double result = MathUtils::subtract(5.0, 5.0);
    ASSERT_EQUAL(result, 0.0, 1e-9);
}

void test_subtract_with_zero() {
    double result = MathUtils::subtract(5.0, 0.0);
    ASSERT_EQUAL(result, 5.0, 1e-9);
}

// ===== Multiplication Tests =====
void test_multiply_positive_numbers() {
    double result = MathUtils::multiply(4.0, 5.0);
    ASSERT_EQUAL(result, 20.0, 1e-9);
}

void test_multiply_negative_numbers() {
    double result = MathUtils::multiply(-4.0, -5.0);
    ASSERT_EQUAL(result, 20.0, 1e-9);
}

void test_multiply_mixed_signs() {
    double result = MathUtils::multiply(4.0, -5.0);
    ASSERT_EQUAL(result, -20.0, 1e-9);
}

void test_multiply_by_zero() {
    double result = MathUtils::multiply(5.0, 0.0);
    ASSERT_EQUAL(result, 0.0, 1e-9);
}

void test_multiply_decimal_numbers() {
    double result = MathUtils::multiply(2.5, 4.0);
    ASSERT_EQUAL(result, 10.0, 1e-9);
}

// ===== Division Tests =====
void test_divide_positive_numbers() {
    double result = MathUtils::divide(10.0, 2.0);
    ASSERT_EQUAL(result, 5.0, 1e-9);
}

void test_divide_negative_numbers() {
    double result = MathUtils::divide(-10.0, -2.0);
    ASSERT_EQUAL(result, 5.0, 1e-9);
}

void test_divide_mixed_signs() {
    double result = MathUtils::divide(10.0, -2.0);
    ASSERT_EQUAL(result, -5.0, 1e-9);
}

void test_divide_decimal_result() {
    double result = MathUtils::divide(7.0, 2.0);
    ASSERT_EQUAL(result, 3.5, 1e-9);
}

void test_divide_by_zero() {
    ASSERT_THROW(MathUtils::divide(10.0, 0.0), std::invalid_argument);
}

// ===== Power Tests =====
void test_power_positive_exponent() {
    double result = MathUtils::power(2.0, 3);
    ASSERT_EQUAL(result, 8.0, 1e-9);
}

void test_power_zero_exponent() {
    double result = MathUtils::power(5.0, 0);
    ASSERT_EQUAL(result, 1.0, 1e-9);
}

void test_power_large_exponent() {
    double result = MathUtils::power(2.0, 10);
    ASSERT_EQUAL(result, 1024.0, 1e-9);
}

void test_power_negative_base() {
    double result = MathUtils::power(-2.0, 2);
    ASSERT_EQUAL(result, 4.0, 1e-9);
}

void test_power_negative_base_odd_exponent() {
    double result = MathUtils::power(-2.0, 3);
    ASSERT_EQUAL(result, -8.0, 1e-9);
}

int main() {
    std::cout << std::endl;
    std::cout << "===== Math Utilities Unit Tests =====" << std::endl;
    std::cout << std::endl;

    // Run addition tests
    std::cout << "--- Addition Tests ---" << std::endl;
    run_test("add positive numbers", test_add_positive_numbers);
    run_test("add negative numbers", test_add_negative_numbers);
    run_test("add mixed numbers", test_add_mixed_numbers);
    run_test("add with zero", test_add_with_zero);
    std::cout << std::endl;

    // Run subtraction tests
    std::cout << "--- Subtraction Tests ---" << std::endl;
    run_test("subtract positive numbers", test_subtract_positive_numbers);
    run_test("subtract negative numbers", test_subtract_negative_numbers);
    run_test("subtract same number", test_subtract_same_number);
    run_test("subtract with zero", test_subtract_with_zero);
    std::cout << std::endl;

    // Run multiplication tests
    std::cout << "--- Multiplication Tests ---" << std::endl;
    run_test("multiply positive numbers", test_multiply_positive_numbers);
    run_test("multiply negative numbers", test_multiply_negative_numbers);
    run_test("multiply mixed signs", test_multiply_mixed_signs);
    run_test("multiply by zero", test_multiply_by_zero);
    run_test("multiply decimal numbers", test_multiply_decimal_numbers);
    std::cout << std::endl;

    // Run division tests
    std::cout << "--- Division Tests ---" << std::endl;
    run_test("divide positive numbers", test_divide_positive_numbers);
    run_test("divide negative numbers", test_divide_negative_numbers);
    run_test("divide mixed signs", test_divide_mixed_signs);
    run_test("divide decimal result", test_divide_decimal_result);
    run_test("divide by zero throws exception", test_divide_by_zero);
    std::cout << std::endl;

    // Run power tests
    std::cout << "--- Power Tests ---" << std::endl;
    run_test("power positive exponent", test_power_positive_exponent);
    run_test("power zero exponent", test_power_zero_exponent);
    run_test("power large exponent", test_power_large_exponent);
    run_test("power negative base", test_power_negative_base);
    run_test("power negative base odd exponent", test_power_negative_base_odd_exponent);
    std::cout << std::endl;

    // Summary
    std::cout << "======================================" << std::endl;
    std::cout << "Total Tests: " << test_count << std::endl;
    std::cout << "Passed: " << passed_count << std::endl;
    std::cout << "Failed: " << failed_count << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << std::endl;

    return (failed_count == 0) ? 0 : 1;
}
