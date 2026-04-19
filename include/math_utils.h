#ifndef MATH_UTILS_H
#define MATH_UTILS_H

/**
 * @file math_utils.h
 * @brief Math utility functions for basic arithmetic operations
 */

namespace MathUtils {

/**
 * Adds two numbers
 * @param a First number
 * @param b Second number
 * @return Sum of a and b
 */
double add(double a, double b);

/**
 * Subtracts two numbers
 * @param a First number
 * @param b Second number
 * @return Difference of a and b
 */
double subtract(double a, double b);

/**
 * Multiplies two numbers
 * @param a First number
 * @param b Second number
 * @return Product of a and b
 */
double multiply(double a, double b);

/**
 * Divides two numbers
 * @param a Dividend
 * @param b Divisor (must not be zero)
 * @return Quotient of a divided by b
 * @throws std::invalid_argument if b is zero
 */
double divide(double a, double b);

/**
 * Calculates the power of a number
 * @param base Base number
 * @param exponent Exponent
 * @return base raised to the power of exponent
 */
double power(double base, int exponent);

}  // namespace MathUtils

#endif  // MATH_UTILS_H
