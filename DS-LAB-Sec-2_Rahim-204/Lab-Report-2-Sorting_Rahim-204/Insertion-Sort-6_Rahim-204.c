#include <stdio.h>
#include <string.h>


struct Student {
    char name[50];
    int id;
};

void insertionSort(struct Student arr[], int size) {
    for (int i = 1; i < size; i++) {
        struct Student value = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].id > value.id) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = value;
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

    insertionSort(students, size);
    showAllStudents(students, size);

    return 0;
}
