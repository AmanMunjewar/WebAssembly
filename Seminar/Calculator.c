#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

char operatorStack[MAX_STACK_SIZE];
int operatorTop = -1;

double operandStack[MAX_STACK_SIZE];
int operandTop = -1;

EMSCRIPTEN_KEEPALIVE
void pushOperator(char op) {
    if (operatorTop < MAX_STACK_SIZE - 1) {
        operatorStack[++operatorTop] = op;
    } else {
        printf("Operator stack is full.\n");
        exit(1);
    }
}

EMSCRIPTEN_KEEPALIVE
char popOperator() {
    if (operatorTop >= 0) {
        return operatorStack[operatorTop--];
    } else {
        printf("Operator stack is empty.\n");
        exit(1);
    }
}

EMSCRIPTEN_KEEPALIVE
void pushOperand(double num) {
    if (operandTop < MAX_STACK_SIZE - 1) {
        operandStack[++operandTop] = num;
    } else {
        printf("Operand stack is full.\n");
        exit(1);
    }
}

EMSCRIPTEN_KEEPALIVE
double popOperand() {
    if (operandTop >= 0) {
        return operandStack[operandTop--];
    } else {
        printf("Operand stack is empty.\n");
        exit(1);
    }
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

EMSCRIPTEN_KEEPALIVE
double evaluateOperation(char op, double left, double right) {
    switch (op) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/':
            if (right == 0) {
                printf("Division by zero is not allowed.\n");
                exit(1);
            }
            return left / right;
        default:
            printf("Invalid operator: %c\n", op);
            exit(1);
    }
}

EMSCRIPTEN_KEEPALIVE
double evaluateExpression(const char* expression) {
    for (int i = 0; expression[i]; i++) {
        if (isspace(expression[i])) {
            continue;
        } else if (isdigit(expression[i]) || (i == 0 && expression[i] == '-')) {
            char* endptr;
            double number = strtod(expression + i, &endptr);
            i = endptr - expression - 1;
            pushOperand(number);
        } else if (expression[i] == '(') {
            pushOperator(expression[i]);
        } else if (expression[i] == ')') {
            while (operatorTop >= 0 && operatorStack[operatorTop] != '(') {
                char op = popOperator();
                double right = popOperand();
                double left = popOperand();
                pushOperand(evaluateOperation(op, left, right));
            }
            popOperator();
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (operatorTop >= 0 && precedence(expression[i]) <= precedence(operatorStack[operatorTop])) {
                char op = popOperator();
                double right = popOperand();
                double left = popOperand();
                pushOperand(evaluateOperation(op, left, right));
            }
            pushOperator(expression[i]);
        } else {
            printf("Invalid character in the expression: %c\n", expression[i]);
            exit(1);
        }
    }

    while (operatorTop >= 0) {
        char op = popOperator();
        double right = popOperand();
        double left = popOperand();
        pushOperand(evaluateOperation(op, left, right));
    }

    return operandStack[0];
}

EMSCRIPTEN_KEEPALIVE
double eval(char* expression) {

    char *newline = strchr(expression, '\n');
    if (newline != NULL) {
        *newline = '\0';
    }

    double result = evaluateExpression(expression);
    return result;
}

EMSCRIPTEN_KEEPALIVE
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return 1;
    }

    char inputString[1000];
    inputString[0] = '\0';

    for (int i = 1; i < argc; i++) {
        strcat(inputString, argv[i]);
    }

    printf("Evaluation: %f\n", eval(inputString));

    return 0;
}
