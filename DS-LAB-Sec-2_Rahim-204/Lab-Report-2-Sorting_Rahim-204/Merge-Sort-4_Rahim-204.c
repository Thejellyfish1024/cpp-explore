#include <stdio.h>
#include <string.h>

struct Student
{
    char name[50];
    int id;
};

// Function to merge two halves of the array
void merge(struct Student arr[], int mid, int left, int right)
{
    int i = left, j = mid + 1, k = 0;
    struct Student temp[right - left + 1]; // Temporary array for merging

    while (i <= mid && j <= right)
    {
        if (arr[i].id < arr[j].id)
        { // Sort in ascending order
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of the left subarray, if any
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements of the right subarray, if any
    while (j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy the merged elements back into the original array
    for (int p = 0; p < k; p++)
    {
        arr[left + p] = temp[p];
    }
}

void mergeSort(struct Student arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, mid, left, right);
}

void showAllStudents(struct Student arr[], int size)
{
    printf("Sorted list of students by ID:\n");
    for (int i = 0; i < size; i++)
    {
        printf("ID: %d, Name: %s\n", arr[i].id, arr[i].name);
    }
}

int main()
{
    int size;

    printf("Enter the total number of students: ");
    scanf("%d", &size);
    struct Student students[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter ID for student %d: ", i + 1);
        scanf("%d", &students[i].id);
        printf("Enter name for student %d: ", i + 1);
        scanf(" %[^\n]%*c", students[i].name);
    }

    mergeSort(students, 0, size - 1);
    showAllStudents(students, size);

    return 0;
}
