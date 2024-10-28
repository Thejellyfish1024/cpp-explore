#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node *next;
} *header = NULL;

void showData()
{
    struct node *ptr = header;
    if (ptr == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }
    while (ptr != NULL)
    {
        printf("%d ", ptr->number);
        ptr = ptr->next;
    }
    printf("\n");
}

void insertInTheEndNode()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Unable to allocate memory.\n");
        return;
    }

    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("%d has been added.\n", num);
    newNode->number = num;
    newNode->next = NULL;

    if (header == NULL)
    {
        header = newNode;
    }
    else
    {
        struct node *temp = header;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertInTheBeginning()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Unable to allocate memory.\n");
        return;
    }

    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("%d has been added.\n", num);

    newNode->number = num;
    newNode->next = header;
    header = newNode;
}

void insertInTheMiddle()
{
    struct node *ptr = header;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Unable to allocate memory.\n");
        return;
    }
    int num1, num2;
    printf("Enter the number after which you want to insert: ");
    scanf("%d", &num1);

    printf("Enter the number you want to insert: ");
    scanf("%d", &num2);
    printf("%d has been added.\n", num2);
    newNode->number = num2;

    while (ptr->number != num1)
    {
        ptr = ptr->next;
    }
    struct node *temp = ptr->next;
    ptr->next = newNode;
    newNode->next = temp;
}

void deleteFirst()
{
    struct node *ptr = header;
    header = header->next;
    printf("%d has been deleted.\n", ptr->number);
    free(ptr);
}

void deleteMiddle()
{
    struct node *ptr = header;
    if (ptr == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    int index, i;
    printf("Enter the index number: ");
    scanf("%d", &index);

    if (index == 0)
    {
        header = ptr->next;
        printf("%d has been deleted.\n", ptr->number);
        free(ptr);
        return;
    }

    struct node *prev = NULL;
    for (i = 0; ptr != NULL && i < index; i++)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    // Check if the index is out of bounds
    if (ptr == NULL)
    {
        printf("Index out of bounds.\n");
        return;
    }
    prev->next = ptr->next;
    printf("%d has been deleted.\n", ptr->number);
    free(ptr);
}

int main()
{
    int operator;
    printf("Option: Display = 1\n");
    printf("Option: Insert in the end = 2\n");
    printf("Option: Insert in the beginning = 3\n");
    printf("Option: Insert in the middle = 4\n");
    printf("Option: Delete first item = 5\n");
    printf("Option: Delete middle item = 6\n");
    printf("Option: exit = 0\n");

    while (1)
    {
        printf("Choose operator: ");
        scanf("%d", &operator);

        switch (operator)
        {
        case 1:
            showData();
            break;

        case 2:
            insertInTheEndNode();
            break;

        case 3:
            insertInTheBeginning();
            break;

        case 4:
            insertInTheMiddle();
            break;

        case 5:
            deleteFirst();
            break;

        case 6:
            deleteMiddle();
            break;

        case 0:
            exit(0);

        default:
            printf("!! please enter valid operation");
        }
    }
}
