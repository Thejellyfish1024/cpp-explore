// Input : 10, 11
// Output : 101

#include <bits/stdc++.h>
// #include <climits>
using namespace std;

void ascendingSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int minVal = arr[i];
        int minIndex = i;
        for (int j = i; j < size; j++)
        {
            if (arr[j] < minVal)
            {
                minVal = arr[j];
                minIndex = j;
            };
        }
        if (minIndex != i)
        {
            arr[minIndex] = arr[i];
            arr[i] = minVal;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void descendingSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int maxVal = arr[i];
        int maxIndex = i;
        for (int j = i; j < size; j++)
        {
            if (arr[j] > maxVal)
            {
                maxVal = arr[j];
                maxIndex = j;
            };
        }
        if (maxIndex != i)
        {
            arr[maxIndex] = arr[i];
            arr[i] = maxVal;
        }
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