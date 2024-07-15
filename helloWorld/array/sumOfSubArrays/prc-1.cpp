#include <iostream>
using namespace std;

int main()
{

    int size = 3, sum = 0;
    int arr[size] = {1, 2, 2}; // {1}, {1,2},{1,2,2}, {2},{2,2}, {2}

    // first method
    // for (int i = 0; i < size; i++)
    // {
    //     int tempSize = i;
    //     bool loop = true;
    //     while (loop)
    //     {
    //         for (int j = i; j <= tempSize; j++)
    //         {
    //             sum += arr[j];
    //         }
    //         tempSize++;
    //         if (tempSize == size)
    //             loop = false;
    //     }
    // }

    // second method
    int curr = 0;
    for (int i = 0; i < size; i++)
    {
        curr = 0;
        for (int j = i; j < size; j++)
        {
            curr += arr[j];
            cout << "current : " << curr << endl;
            sum += curr;
        }
    }

    cout << "Sum of all sub arrays = " << sum;

    return 0;
};