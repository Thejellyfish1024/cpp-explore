#include <bits/stdc++.h>
using namespace std;

// Function to perform Insertion Sort
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i]; // The current element to be placed
        int j = i - 1;

        // Shift elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Insert key at its correct position
    }
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6};
    cout << "Original Array: ";
    for (int num : arr)
        cout << num << " ";

    insertionSort(arr);

    cout << "\nSorted Array using Insertion Sort: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;
    return 0;
}
