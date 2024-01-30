#include <iostream>

int main() {
    double num1, num2, result;
    char operation;

    // Input two numbers
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    // Choose an operation
    std::cout << "Choose an operation (+, -, *, /): ";
    std::cin >> operation;

    // Perform the selected operation
    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            // Check for division by zero
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                std::cout << "Error: Division by zero is not allowed.\n";
                return 1; // Exit with an error code
            }
            break;
        default:
            std::cout << "Invalid operation. Please choose +, -, *, or /.\n";
            return 1; // Exit with an error code
    }

    // Display the result
    std::cout << "Result: " << result << std::endl;

    return 0;
}
