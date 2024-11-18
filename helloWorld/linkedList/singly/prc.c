#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node *next;
} *head;

void recursionPrint(struct node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    recursionPrint(ptr->next);
    printf("%d ", ptr->number);
}
int main()
{
    struct node *first, *second, *third;
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    first->number = 60;
    first->next = second;

    head = first;

    second->number = 560;
    second->next = third;

    third->number = 300;
    third->next = NULL;

    recursionPrint(head);
    return 0;
}