#include <stdio.h>

int top = -1;

int isFull(int size) {
    if (top == size - 1)
        return 1;
    else
        return 0;
}

int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

void push(int stack[], int size) {
    if (isFull(size)) {
        printf("Stack overflow\n");
        return;
    } else {
        int value;
        printf("Enter the new value: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("%d has been pushed in the stack.\n", value);
    }
}

void pop(int stack[]) {
    if (isEmpty()) {
        printf("Stack underflow\n");
        return;
    } else {
        printf("%d has been removed from the stack.\n", stack[top]);
        top--;
    }
}

int peek(int stack[]) {
    if (isEmpty()) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return stack[top];
    }
}

void display(int stack[]) {
    int i = 0;
    if (isEmpty()) {
        printf("Stack underflow\n");
        return;
    }
    printf("Current stack values: ");
    while (i <= top) {
        printf("%d ", stack[i]);
        i++;
    }
    printf("\n");
}

int main() {
    int size;
    printf("Please enter the size of the stack: ");
    scanf("%d", &size);
    int stack[size];

    int choice = 1;
    printf("\nOption 1: Push");
    printf("\nOption 2: Pop");
    printf("\nOption 3: Peek");
    printf("\nOption 4: Display");
    printf("\nOption 5: Exit\n");

    while (1) { 
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push(stack, size);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                printf("Top value: %d\n", peek(stack));
                break;
            case 4:
                display(stack);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}
