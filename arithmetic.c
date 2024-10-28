#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Global pointer for the expression
const char* expr;

// Function to evaluate the expression
double evaluateExpression() {
    double result = 0;       // Overall result
    double currentTerm = 0;  // Current term for multiplication and division
    char operator = '+';     // Initialize with '+'
    
    while (*expr) {
        // Skip spaces
        while (isspace(*expr)) expr++;

        // Check for the next character being a digit or decimal point
        if (isdigit(*expr) || *expr == '.') {
            currentTerm = 0;

            // Read the number
            while (isdigit(*expr) || *expr == '.') {
                if (*expr == '.') {
                    expr++;
                    double decimalPlace = 0.1;
                    while (isdigit(*expr)) {
                        currentTerm += (*expr - '0') * decimalPlace;
                        decimalPlace /= 10;
                        expr++;
                    }
                } else {
                    currentTerm = currentTerm * 10 + (*expr - '0');
                    expr++;
                }
            }

            // Apply the previous operator based on precedence
            if (operator == '*' || operator == '/') {
                if (operator == '*') {
                    result *= currentTerm;  // Multiply
                } else {
                    result /= currentTerm;   // Divide
                }
            } else {
                // For '+' and '-', we need to handle current result
                if (operator == '+') {
                    result += currentTerm;  // Add
                } else if (operator == '-') {
                    result -= currentTerm;   // Subtract
                }
            }
        }

        // Check for new operators
        if (*expr == '+' || *expr == '-' || *expr == '*' || *expr == '/') {
            operator = *expr;  // Update the operator
            expr++;            // Move past the operator
        } else {
            expr++;            // Move past any other characters
        }
    }

    return result;
}

int main() {
    char expression[100];

    printf("Enter an arithmetic expression (e.g., 5*5+5*9): ");
    fgets(expression, sizeof(expression), stdin);  // Read the input using fgets

    expr = expression;  // Assign the global pointer to the input string
    double result = evaluateExpression();
    printf("Result = %lf\n", result);

    return 0;
}
