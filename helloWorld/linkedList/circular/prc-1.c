#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node *next;
} *head;

void showAll(struct node *ptr)
{
    struct node *firstNode = NULL;
    int count = 0;
    while (ptr != firstNode)
    {
        printf("%d ", ptr->number);
        count++;
        if (count == 1)
        {
            firstNode = ptr;
        }
        ptr = ptr->next;
    }
}
int main()
{
    struct node *first, *second, *third, *fourth;
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    first->number = 60;
    first->next = second;

    head = first;

    second->number = 560;
    second->next = third;

    third->number = 300;
    third->next = fourth;

    fourth->number = 12;
    fourth->next = first;

    showAll(head);
    return 0;
}