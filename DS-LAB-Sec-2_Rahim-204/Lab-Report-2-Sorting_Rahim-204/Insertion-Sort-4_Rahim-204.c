#include <stdio.h>


void insertionSortDescending(float arr[], int size) {
    for (int i = 1; i < size; i++) {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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

    insertionSortDescending(arr, size);
    printf("Array sorted in descending order using Insertion Sort: ");
    showAll(arr, size);

    return 0;
}
