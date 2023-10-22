
   #include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

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

std::string infixToPostfix(const std::string& infix) {
    std::stack<char> operatorStack;
    std::string postfix;
    std::unordered_map<char, int> precedenceMap;

    precedenceMap['+'] = 1;
    precedenceMap['-'] = 1;
    precedenceMap['*'] = 2;
    precedenceMap['/'] = 2;
    precedenceMap['^'] = 3;

    for (char c : infix) {
        if (isalnum(c) || isdigit(c)) {
            postfix += c;
        } else if (c == '(') {
            operatorStack.push(c);
        } else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Pop the '('
        } else if (isOperator(c)) {
            while (!operatorStack.empty() && precedenceMap[operatorStack.top()] >= precedenceMap[c]) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    std::string infixExpression = "A+B*C-D/E^F";
    std::string postfixExpression = infixToPostfix(infixExpression);

    std::cout << "Infix Expression: " << infixExpression << std::endl;
    std::cout << "Postfix Expression: " << postfixExpression << std::endl;

    return 0;
}
