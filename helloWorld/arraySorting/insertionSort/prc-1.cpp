// insertion sort method

#include <bits/stdc++.h>
// #include <climits>
using namespace std;

void ascendingSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int current = arr[i]; 
        int j = i - 1;
        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void descendingSort(int arr[], int size)
{
   for (int i = 1; i < size; i++)
    {
        int current = arr[i]; 
        int j = i - 1;
        while (arr[j] < current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
    
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    int size;
    cin >> size;
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    ascendingSort(arr, size);
    cout << endl;
    descendingSort(arr, size);

    return 0;
};