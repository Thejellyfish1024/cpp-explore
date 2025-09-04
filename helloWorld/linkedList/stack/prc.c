#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int number;
    struct Node *next;
} *top = NULL;

struct Node *createNewNode(int number)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->number = number;
    newNode->next = NULL;
    return newNode;
}

int isEmpty()
{
    return top == NULL;
}

void push()
{
    printf("Enter the value to push: ");
    int value;
    scanf("%d", &value);
    struct Node *newNode = createNewNode(value);
    newNode->next = top;
    top = newNode;
    printf("Pushed %d in the stack.\n", value);
}

void pop()
{
    if (isEmpty())
    {
        printf("Stack underflow!\n");
        return;
    }
    else
    {
        struct Node *temp = top;
        int popped = temp->number;
        top = top->next;
        printf("Popped element: %d\n", popped);
        free(temp);
    }
}

void peek()
{
    if (isEmpty())
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Top element: %d\n", top->number);
    }
}

void showAll()
{
    if (isEmpty())
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements are: ");
    struct Node *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->number);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. display\n");
        printf("5. isEmpty\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            showAll();
            break;

        case 5:
            if (isEmpty())
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
            break;
        case 6:
            exit(0);

        default:
            printf("Invalid choice! Please enter a valid choice.\n");
        }
    }

    return 0;
}
