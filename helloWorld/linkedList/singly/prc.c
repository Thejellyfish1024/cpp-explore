#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node *next;
};

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->number = 45;
    head->next = NULL;

    struct node *current = (struct node *)malloc(sizeof(struct node));
    current->number = 60;
    current->next = NULL;
    head->next = current;

    current = (struct node *)malloc(sizeof(struct node));
    current->number = 560;
    current->next = NULL;
    head->next->next = current;

    printf("%d\n", head->number);
    printf("%d\n", head->next->number);
    printf("%d\n", head->next->next->number);
    printf("%d\n", head->next->next->next->number);
    return 0;
}