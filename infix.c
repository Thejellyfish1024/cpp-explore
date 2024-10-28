#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Stack using linked list for characters
struct Node {
    char data;
    struct Node* next;
};

struct Node* top = NULL;

// Stack using linked list for strings
struct StringNode {
    char data[100];
    struct StringNode* next;
};

struct StringNode* stringTop = NULL;

// Push a character onto the stack
void push(char c) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = c;
    newNode->next = top;
    top = newNode;
}

// Pop a character from the stack
char pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    struct Node* temp = top;
    top = top->next;
    char poppedValue = temp->data;
    free(temp);
    return poppedValue;
}

// Peek the top element of the stack
char peek() {
    if (top != NULL) {
        return top->data;
    }
    return '\0'; // Return null character if stack is empty
}

// Check if the stack is empty
int isEmpty() {
    return top == NULL;
}

// Push a string onto the stack
void pushString(char* str) {
    struct StringNode* newNode = (struct StringNode*)malloc(sizeof(struct StringNode));
    strcpy(newNode->data, str);
    newNode->next = stringTop;
    stringTop = newNode;
}

// Pop a string from the stack
char* popString() {
    if (stringTop == NULL) {
        printf("String stack underflow\n");
        exit(1);
    }
    struct StringNode* temp = stringTop;
    stringTop = stringTop->next;
    char* poppedValue = temp->data;
    free(temp);
    return poppedValue;
}

// Utility function to get precedence of operators
int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

// Reverse a string
void reverseString(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Infix to Postfix conversion
// Infix to Postfix conversion
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, k = 0;
    while (infix[i]) {
        if (isspace(infix[i])) {
            i++;
            continue;
        }

        if (isalpha(infix[i]) || isdigit(infix[i])) { // Handle both letters and digits
            while (isalpha(infix[i]) || isdigit(infix[i])) {
                postfix[k++] = infix[i++];
            }
            postfix[k++] = ' '; // Add space after the operand
        }
        else if (infix[i] == '(') {
            push('(');
            i++;
        }
        else if (infix[i] == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop();
                postfix[k++] = ' '; // Add space after the operator
            }
            pop(); // Remove '(' from the stack
            i++;
        }
        else { // Operator
            while (!isEmpty() && precedence(peek()) >= precedence(infix[i])) {
                postfix[k++] = pop();
                postfix[k++] = ' '; // Add space after the operator
            }
            push(infix[i]);
            i++;
        }
    }

    while (!isEmpty()) {
        postfix[k++] = pop();
        postfix[k++] = ' '; // Add space after the operator
    }
    postfix[k - 1] = '\0'; // Replace the last space with null terminator
}

// Infix to Prefix conversion
void infixToPrefix(char* infix, char* prefix) {
    reverseString(infix);
    for (int i = 0; infix[i]; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    char postfix[100];
    infixToPostfix(infix, postfix);
    reverseString(postfix);
    strcpy(prefix, postfix);
}

// Postfix to Infix conversion
void postfixToInfix(char* postfix, char* infix) {
    for (int i = 0; postfix[i]; i++) {
        if (isspace(postfix[i])) {
            continue;
        }
        if (isdigit(postfix[i])) {
            char operand[10];
            int j = 0;
            while (isdigit(postfix[i])) {
                operand[j++] = postfix[i++];
            }
            operand[j] = '\0';
            pushString(operand);
        }
        else {
            char operand2[100], operand1[100];
            strcpy(operand2, popString());
            strcpy(operand1, popString());

            char expr[100];
            sprintf(expr, "(%s %c %s)", operand1, postfix[i], operand2);

            pushString(expr);
        }
    }
    strcpy(infix, popString());
}

int main() {
    int choice;
    char infix[100], postfix[100], prefix[100], convertedInfix[100];

    printf("\tScientific Calculator\n");
    while (1) {
        printf("\nMenu:\n");
        printf("1: Infix to Postfix\n");
        printf("2: Infix to Prefix\n");
        printf("3: Postfix to Infix\n");
        printf("4: Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after entering the number

        switch (choice) {
        case 1:
            printf("Enter an infix expression: ");
            fgets(infix, sizeof(infix), stdin);
            infix[strlen(infix) - 1] = '\0'; // Remove newline character
            infixToPostfix(infix, postfix);
            printf("Postfix: %s\n", postfix);
            break;

        case 2:
            printf("Enter an infix expression: ");
            fgets(infix, sizeof(infix), stdin);
            infix[strlen(infix) - 1] = '\0'; // Remove newline character
            infixToPrefix(infix, prefix);
            printf("Prefix: %s\n", prefix);
            break;

        case 3:
            printf("Enter a postfix expression: ");
            fgets(postfix, sizeof(postfix), stdin);
            postfix[strlen(postfix) - 1] = '\0'; // Remove newline character
            postfixToInfix(postfix, convertedInfix);
            printf("Infix: %s\n", convertedInfix);
            break;

        case 4:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}