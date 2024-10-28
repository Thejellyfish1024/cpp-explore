#include <stdio.h>


void selectionSortDescending(float arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            float temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
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
    selectionSortDescending(arr, size);
    printf("Array sorted in descending order using Selection Sort: ");
    showAll(arr, size);

    return 0;
}
