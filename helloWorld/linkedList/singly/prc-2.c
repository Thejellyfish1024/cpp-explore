#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node *next;
};

void showData(struct node *ptr)
{
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

void insertInTheEndNode(struct node **header)
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

    newNode->number = num;
    newNode->next = NULL;

    if (*header == NULL)
    {
        *header = newNode;
    }
    else
    {
        struct node *temp = *header;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertInTheBeginning(struct node **header)
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

    newNode->number = num;
    newNode->next = *header;
    *header = newNode;
}

void insertInTheMiddle(struct node *header)
{
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
    newNode->number = num2;

    while (header->number != num1)
    {
        header = header->next;
    }
    struct node *temp = header->next;
    header->next = newNode;
    newNode->next = temp;
}

void deleteFirst(struct node **header)
{
    struct node *ptr = *header;
    *header = (*header)->next;
    free(ptr);
}

void deleteMiddle(struct node **header) {
    struct node *ptr = *header;
    if (ptr == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    int index, i;
    printf("Enter the index number: ");
    scanf("%d", &index);

    if (index == 0) {
        *header = ptr->next; 
        free(ptr);            
        return;
    }

    struct node *prev = NULL;
    for (i = 0; ptr != NULL && i < index; i++) {
        prev = ptr;  
        ptr = ptr->next;
    }

    // Check if the index is out of bounds
    if (ptr == NULL) {
        printf("Index out of bounds.\n");
        return;
    }
    prev->next = ptr->next;
    free(ptr);
}

int main()
{
    struct node *header = NULL;
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
            showData(header);
            break;

        case 2:
            insertInTheEndNode(&header);
            break;

        case 3:
            insertInTheBeginning(&header);
            break;

        case 4:
            insertInTheMiddle(header);
            break;

        case 5:
            deleteFirst(&header);
            break;

        case 6:
            deleteMiddle(&header);
            break;

        case 0:
            exit(0);

        default:
            printf("!! please enter valid operation");
        }
    }
}
