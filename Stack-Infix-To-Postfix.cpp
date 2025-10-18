#include <stdio.h>
#include <ctype.h>   // for isalpha, isdigit
#include <string.h>  

#define MAX 100

// Stack structure
char stack[MAX];
int top = -1;

// Push operation
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

// Pop operation
char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

// Peek top element
char peek() {
    if (top >= 0)
        return stack[top];
    return '\0';
}

// Check if operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Precedence of operators
int precedence(char c) {
    switch (c) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        // If operand, add to postfix output
        if (isalnum(c)) {
            postfix[j++] = c;
            postfix[j++] = ' '; // space for clarity
        }
        // If '(', push to stack
        else if (c == '(') {
            push(c);
        }
        // If ')', pop until '('
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
                postfix[j++] = ' ';
            }
            pop(); 
        }
      
        else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[j++] = pop();
                postfix[j++] = ' ';
            }
            push(c);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
        postfix[j++] = ' ';
    }

    postfix[j - 1] = '\0'; 
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    gets(infix); 

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
