#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int id;
};

void bubbleSort(struct Student arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].id > arr[j + 1].id) {
                struct Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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

    bubbleSort(students, size);
    showAllStudents(students, size);

    return 0;
}
