#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int id;
};

void selectionSort(struct Student arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j].id < arr[minIndex].id) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            struct Student temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void showAllStudents(struct Student arr[], int size) {
    printf("Sorted list of students by ID:\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s\n", arr[i].id, arr[i].name);
    }
}

int main() {
    int size;

    printf("Enter the total number of students: ");
    scanf("%d", &size);
    struct Student students[size];
    
    for (int i = 0; i < size; i++) {
        printf("Enter ID for student %d: ", i + 1);
        scanf("%d", &students[i].id);
        printf("Enter name for student %d: ", i + 1);
        scanf(" %[^\n]%*c", students[i].name);
    }

    selectionSort(students, size);
    showAllStudents(students, size);

    return 0;
}
