#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define STACK_SIZE 50

char stack[STACK_SIZE];
int top = -1;

void push(char c) {
    if (top == STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char c;

    while (infix[i] != '\0') {
        if (isalnum(infix[i])) { 
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {  
            push(infix[i]);
        } else if (infix[i] == ')') {  
            while (top != -1 && (c = pop()) != '(') {
                postfix[j++] = c;
            }
        } else {  
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';  
}

int main() {
    char infix[50], postfix[50];

    printf("Enter a valid infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    return 0;
}



