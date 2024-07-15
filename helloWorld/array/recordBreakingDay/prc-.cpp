// Input : size = 6, arr = {1,2,3,1,4,2}
// Output : 3
// Have to find total of record breaking day. Conditions :-
// 1. Have to be higher than the previous all days.
// 2. Have to be higher than the next day.

#include <iostream>
using namespace std;

int main()
{
    int size = 15, days = 0;
    int arr[size] = {3, 2, 3, 1, 4, 2};
    int max = 0;

    for (int i = 0; i < size - 1; i++)
    {
        if (i == size - 1)
        {
            if (arr[i] > max)
            {
                days++;
                break;
            }
            else
                break;
        }
        if (arr[i] > max)
        {
            max = arr[i];
            if (arr[i] > arr[i + 1])
            {
                days++;
            }
        }
    }

    cout << days;
    return 0;
}