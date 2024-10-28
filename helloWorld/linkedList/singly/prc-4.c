#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int number;
    struct Node *next;
};

void traverse(struct Node *ptr)
{
    if (!ptr->number)
    {
        printf("Linked List is Empty\n");
        return;
    }

    while (ptr != NULL)
    {
        printf("%d ", ptr->number);
        ptr = ptr->next;
    }
    printf("\n");
}

void insertAtTheBeginning(struct Node **ptr)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("No memory is assigned\n");
        return;
    }
    int newValue;
    printf("Enter the value: ");
    scanf("%d", &newValue);
    newNode->number = newValue;
    newNode->next = *ptr;
    *ptr = newNode;
}

struct Node *insertAtTheBeginning2(struct Node *ptr)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("No memory is assigned\n");
        return ptr;
    }
    int newValue;
    printf("Enter the value: ");
    scanf("%d", &newValue);
    newNode->number = newValue;
    newNode->next = ptr;
    return newNode;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    head->number = 10;
    head->next = second;
    second->number = 20;
    second->next = third;
    third->number = 30;
    third->next = NULL;
    traverse(head);
    // insertAtTheBeginning(&head);
    head = insertAtTheBeginning2(head);
    traverse(head);
}