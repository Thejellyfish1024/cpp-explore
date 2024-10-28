#include <stdio.h>

int front = -1;
int rear = -1;

int isFull(int size)
{
    if (rear == size - 1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

void enqueue(int queue[], int size)
{
    if (isFull(size))
    {
        printf("Queue overflow\n");
        return;
    }
    else
    {
        int value;
        printf("Enter the new value: ");
        scanf("%d", &value);
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("%d has been enqueued in the queue.\n", value);
    }
}

void dequeue(int queue[])
{
    if (isEmpty())
    {
        printf("Queue underflow\n");
        return;
    }
    else
    {
        printf("%d has been dequeued from the queue.\n", queue[front]);
        front++;
    }
}

int peek(int queue[])
{
    if (isEmpty())
    {
        printf("Queue underflow\n");
        return -1;
    }
    else
    {
        return queue[front];
    }
}

void display(int queue[])
{
    if (isEmpty())
    {
        printf("Queue underflow\n");
        return;
    }
    printf("Current queue values: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int size;
    printf("Please enter the size of the queue: ");
    scanf("%d", &size);
    int queue[size];

    int choice = 1;
    printf("\nOption 1: Enqueue");
    printf("\nOption 2: Dequeue");
    printf("\nOption 3: Peek");
    printf("\nOption 4: Display");
    printf("\nOption 5: Exit\n");

    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(queue, size);
            break;
        case 2:
            dequeue(queue);
            break;
        case 3:
            printf("Front value: %d\n", peek(queue));
            break;
        case 4:
            display(queue);
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
