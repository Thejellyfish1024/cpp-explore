#include <stdio.h>
int main()
{
    int size, index;
    printf("Please enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the array values: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Array values are: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the odd index which you want to delete: ");
    scanf("%d", &index);
    printf("%d has been deleted\n", arr[index]);
    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }

    printf("Array values after the deletion: ");
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
