#include <stdio.h>

int main() {
    int size;

    printf("Enter the total number of elements: ");
    scanf("%d", &size);  
    int arr[size];

    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int value;
    printf("Enter the number to search: ");
    scanf("%d", &value);

    int foundIndex = -1; 
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            foundIndex = i; 
            break;
        }
    }

    if (foundIndex != -1) {
        printf("Number %d found at index %d.\n", value, foundIndex);
    } else {
        printf("Number %d not found in the array.\n", value);
    }

    return 0;
}
