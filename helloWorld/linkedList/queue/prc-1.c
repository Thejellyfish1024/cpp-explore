#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int number;
    struct Node *next;
} *front = NULL, *rear = NULL;

struct Node *createNewNode(int number)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->number = number;
    newNode->next = NULL;
    return newNode;
}

int isEmpty()
{
    return front == NULL;
}

void enqueue()
{
    printf("Enter the value to enqueue: ");
    int value;
    scanf("%d", &value);
    struct Node *newNode = createNewNode(value);
    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d in the queue.\n", value);
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue underflow!\n");
        return;
    }
    struct Node *temp = front;
    int dequeued = temp->number;
    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    printf("Dequeued element: %d\n", dequeued);
    free(temp);
}

void peek()
{
    if (isEmpty())
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Front element: %d\n", front->number);
    }
}

void showAll()
{
    if (isEmpty())
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are: ");
    struct Node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->number);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. isEmpty\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
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
