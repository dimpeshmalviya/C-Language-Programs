#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;
int evalStack[MAX];
int evalTop = -1;

void push(char c) {
    if (top < MAX - 1)
        stack[++top] = c;
}

char pop() {
    if (top == -1)
        return '\0';
    return stack[top--];
}

char peek() {
    if (top == -1)
        return '\0';
    return stack[top];
}

void pushEval(int val) {
    if (evalTop < MAX - 1)
        evalStack[++evalTop] = val;
}

int popEval() {
    if (evalTop == -1) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return evalStack[evalTop--];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(char* infix, char* postfix) {
    int k = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (isdigit(c)) {
            while (isdigit(infix[i])) {
                postfix[k++] = infix[i++];
            }
            postfix[k++] = ' ';
            i--;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
                postfix[k++] = ' ';
            }
            pop();
        } else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
                postfix[k++] = ' ';
            }
            push(c);
        }
    }
    while (top != -1) {
        postfix[k++] = pop();
        postfix[k++] = ' ';
    }
    postfix[k] = '\0';
}

int evaluatePostfix(char* exp) {
    int i = 0;
    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            pushEval(num);
        } else if (isOperator(exp[i])) {
            int val2 = popEval();
            int val1 = popEval();
            switch (exp[i]) {
                case '+': pushEval(val1 + val2); break;
                case '-': pushEval(val1 - val2); break;
                case '*': pushEval(val1 * val2); break;
                case '/': pushEval(val1 / val2); break;
                case '^': {
                    int res = 1;
                    for (int j = 0; j < val2; j++) res *= val1;
                    pushEval(res);
                    break;
                }
            }
            i++;
        } else {
            i++;
        }
    }
    return popEval();
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%[^\n]", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    int result = evaluatePostfix(postfix);
    printf("Result = %d\n", result);
    return 0;
}
