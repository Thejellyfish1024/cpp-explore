#include <stdio.h>

int isSorted(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int size;
    printf("Enter the total number of elements: ");
    scanf("%d", &size);
    int arr[size];

    printf("Enter %d elements (make sure they are sorted): ", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    if (!isSorted(arr, size))
    {
        printf("The array is not sorted. Please enter a sorted array.\n");
        return 1;
    }

    int value;
    printf("Enter the number to search: ");
    scanf("%d", &value);

    int left = 0, right = size - 1;
    int foundIndex = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == value)
        {
            foundIndex = mid;
            break;
        }
        else if (arr[mid] < value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (foundIndex != -1)
    {
        printf("Number %d found at index %d.\n", value, foundIndex);
    }
    else
    {
        printf("Number %d not found in the array.\n", value);
    }

    return 0;
}
