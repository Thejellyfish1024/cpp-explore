#include <stdio.h>


void bubbleSortDescending(float arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void showAll(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);
    float arr[size];

    printf("Enter %d elements of the array: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%f", &arr[i]);
    }
    bubbleSortDescending(arr, size);

    printf("Array sorted in descending order using Bubble Sort: ");
    showAll(arr, size);

    return 0;
}
