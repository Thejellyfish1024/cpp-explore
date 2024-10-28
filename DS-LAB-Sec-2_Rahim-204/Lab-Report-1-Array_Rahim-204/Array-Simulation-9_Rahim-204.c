#include <stdio.h>

int countEven(int arr[], int size)
{
    int evenCount = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            evenCount++;
        }
    }
    return evenCount;
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int size, i;

    printf("Enter size of the array: ");
    scanf("%d", &size);

    int arr[100];

    printf("Enter %d elements of the array: \n", size);
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int evenCount = countEven(arr, size);
    int mid = size / 2;

    if (evenCount >= 2)
    {
        printf("There are %d even numbers, so removing the last two even numbers.\n", evenCount);
        int removed = 0;
        int i = size - 1; 

        while (i >= 0 && removed < 2)
        {
            if (arr[i] % 2 == 0)
            {
                for (int j = i; j < size - 1; j++)
                {
                    arr[j] = arr[j + 1];
                }
                size--;
                removed++;
            }
            i--;
        }
        printf("Array after removing 2 even elements: ");
        printArray(arr, size);
    }
    else if (evenCount == 1)
    {
        printf("There is only 1 even number, so inserting 2 elements at the middle and the next position.\n");
        int firstNewElement, secondNewElement;
        
        printf("Enter two new elements to insert: ");
        scanf("%d %d", &firstNewElement, &secondNewElement);

        for (i = size - 1; i >= mid ; i--)
        {
            arr[i+2] = arr[i];
        }
        arr[mid] = firstNewElement;
        arr[mid + 1] = secondNewElement;
        size = size + 2;

        printf("Array after inserting 2 elements in the middle: ");
        printArray(arr, size);
    }
    else
    {
        printf("No even numbers found, so deleting the middle element and inserting a new element to the next index of the middle index.\n");
        int newElement;
        printf("Enter a new element to insert: ");
        scanf("%d", &newElement);

        for (i = mid; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--; 

        for (i = size; i > mid; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[mid + 1] = newElement;
        size++;

        printf("Array after deleting middle element and inserting new one: ");
        printArray(arr, size);
    }

    return 0;
}
