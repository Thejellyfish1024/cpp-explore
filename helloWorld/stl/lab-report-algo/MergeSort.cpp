#include <bits/stdc++.h>
using namespace std;

// Function to merge two halves
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    // Merge process
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy remaining elements
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Merge Sort function
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);      // Sort first half
        mergeSort(arr, mid + 1, right); // Sort second half
        merge(arr, left, mid, right);   // Merge both halves
    }
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    cout << "Original Array: ";
    for (int num : arr)
        cout << num << " ";

    mergeSort(arr, 0, arr.size() - 1);

    cout << "\nSorted Array using Merge Sort: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;
    return 0;
}
