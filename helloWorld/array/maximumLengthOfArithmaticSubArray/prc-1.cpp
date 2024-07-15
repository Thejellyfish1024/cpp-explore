// Input : size = 10 , arr = {9, 7, 5, 4, 5, 6, 7, 1}
// Output : 5
// Have to find the length of the maximum length of the sub-array which have the similar difference.

#include <iostream>
using namespace std;

int main()
{
    int size = 10, maxLength = 2;
    int arr[size] = {9, 7, 5, 4, 5, 6, 7, 1};
    int currDif = abs(arr[0] - arr[1]), currLength = 2;
    for (int i = 1; i < size - 1; i++)
    {
        if (abs(arr[i] - arr[i + 1]) == currDif)
        {
            currLength++;
        }
        else
        {
            currDif = arr[i] - arr[i + 1];
            currLength = 2;
        }
        if (currLength > maxLength)
            maxLength = currLength;
    }

    cout << maxLength;
    return 0;
}