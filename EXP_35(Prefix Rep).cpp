#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

// Function to check if a character is an operator (+, -, *, /, ^).
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to determine the precedence of an operator.
int precedence(char op) {
    if (op == '^') {
        return 3;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    }
    return 0;
}

// Function to convert an infix expression to a prefix expression.
std::string infixToPrefix(const std::string& infix) {
    std::stack<char> operators;
    std::stack<std::string> operands;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isalnum(c) || isdigit(c)) {
            // If the character is an operand, push it onto the operands stack.
            std::string operand(1, c);
            operands.push(operand);
        } else if (c == '(') {
            // If it's an opening parenthesis, push it onto the operators stack.
            operators.push(c);
        } else if (c == ')') {
            // If it's a closing parenthesis, pop operators and operands to build the prefix expression.
            while (!operators.empty() && operators.top() != '(') {
                std::string operand2 = operands.top();
                operands.pop();
                std::string operand1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();

                std::string newOperand = op + operand1 + operand2;
                operands.push(newOperand);
            }
            operators.pop(); // Pop the corresponding opening parenthesis.
        } else if (isOperator(c)) {
            // If it's an operator, pop operators and operands to build the prefix expression.
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                std::string operand2 = operands.top();
                operands.pop();
                std::string operand1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();

                std::string newOperand = op + operand1 + operand2;
                operands.push(newOperand);
            }
            operators.push(c);
        }
    }

    // Pop any remaining operators and operands to build the final prefix expression.
    while (!operators.empty()) {
        std::string operand2 = operands.top();
        operands.pop();
        std::string operand1 = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();

        std::string newOperand = op + operand1 + operand2;
        operands.push(newOperand);
    }

    return operands.top();
}

int main() {
    std::string infixExpression = "(A+B)*C-D/E^F";
    std::string prefixExpression = infixToPrefix(infixExpression);

    // Reverse the prefix expression to get the correct order.
    std::reverse(prefixExpression.begin(), prefixExpression.end());

    std::cout << "Infix Expression: " << infixExpression << std::endl;
    std::cout << "Prefix Expression: " << prefixExpression << std::endl;

    return 0;
}
