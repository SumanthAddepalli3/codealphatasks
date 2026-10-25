#include <stdio.h>

int main() {
    char operator;
    double num1, num2, result;

    // Step 1: Prompt the user to select an arithmetic operation
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);

    // Step 2: Prompt the user to enter two numeric values
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    // Step 3: Evaluate the selection using a switch-case statement
    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '-':
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '*':
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '/':
            // Edge-case check: Prevent runtime error from division by zero
            if (num2 != 0.0) {
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            } else {
                printf("Error! Division by zero is not allowed.\n");
            }
            break;

        // Default block handles invalid operations
        default:
            printf("Error! '%c' is an invalid operator.\n", operator);
    }

    return 0;
}