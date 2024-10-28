#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Global pointer for the expression
const char* expr;

// Function prototypes
double evaluateExpression();
double evaluateTerm();
double evaluateFactor();
double evaluateNumber();

int main() {
    char expression[100];

    printf("Enter an arithmetic expression (e.g., 5*5+5*(9+5)): ");
    scanf(" %[^\n]", expression);  // Accepts input with spaces

    expr = expression;  // Assign the global pointer to the input string
    double result = evaluateExpression();
    printf("Result = %lf\n", result);

    return 0;
}

// Function to evaluate an entire expression
double evaluateExpression() {
    double result = evaluateTerm();

    while (*expr == '+' || *expr == '-') {
        char operator = *expr++;
        double nextTerm = evaluateTerm();
        
        if (operator == '+') {
            result += nextTerm;
        } else {
            result -= nextTerm;
        }
    }

    return result;
}

// Function to evaluate terms in an expression (handles *, /)
double evaluateTerm() {
    double result = evaluateFactor();

    while (*expr == '*' || *expr == '/') {
        char operator = *expr++;
        double nextFactor = evaluateFactor();

        if (operator == '*') {
            result *= nextFactor;
        } else {
            result /= nextFactor;
        }
    }

    return result;
}

// Function to evaluate factors (handles parentheses and numbers)
double evaluateFactor() {
    double result;

    while (isspace(*expr)) expr++;  // Skip spaces

    if (*expr == '(') {
        expr++;  // Skip '('
        result = evaluateExpression();
        expr++;  // Skip ')'
    } else {
        result = evaluateNumber();
    }

    while (isspace(*expr)) expr++;  // Skip spaces

    return result;
}

double evaluateNumber() {
    double result = 0;

    while (isspace(*expr)) expr++;  

    while (isdigit(*expr) || *expr == '.') {
        if (*expr == '.') {
            expr++;
            double decimalPlace = 0.1;
            while (isdigit(*expr)) {
                result += (*expr - '0') * decimalPlace;
                decimalPlace /= 10;
                expr++;
            }
        } else {
            result = result * 10 + (*expr - '0');
            expr++;
        }
    }

    while (isspace(*expr)) expr++;  // Skip spaces

    return result;
}
