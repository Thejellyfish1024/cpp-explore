// #Assignment:Take 6 positive even number.reverse them and print them.And Also print their sum.

#include <stdio.h>
int main()
{
    int size = 6;
    int arr[size], i;
    for (i = 0; i < size; i++)
    {
        int isEven;
        printf("Enter number %d = ", i + 1);
        scanf("%d", &isEven);
        if (isEven < 0 || isEven % 2 != 0)
        {
            printf("You can only enter positive even number");
            break;
        }
        else
        {
            arr[i] = isEven;
        }
    }
    if (i == size)
    {
        int sum = 0;
        for (int i = size - 1; i >= 0; i--)
        {
            printf("%d ", arr[i]);
            sum += arr[i];
        }
        printf("\nsum = %d", sum);
    }

    return 0;
};
