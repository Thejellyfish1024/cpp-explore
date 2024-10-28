#include <stdio.h>
int main()
{
    int size, n, newValue, index;
    printf("Please enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter how many numbers you want to insert in the array: ");
    scanf("%d", &n);
    printf("Enter the array values: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Array values are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Now enter the new value that you want to insert: ");
    scanf("%d", &newValue);
    printf("Enter the even index: ");
    scanf("%d", &index);

    for (int i = n; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = newValue;
    printf("Array values after the insertion: ");
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
