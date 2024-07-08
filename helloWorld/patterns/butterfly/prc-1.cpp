// Input : 4
// Output :
// *      *
// **    **
// ***  ***
// ********
// ********
// ***  ***
// **    **
// *      *

#include <iostream>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
#endif

    int n, left, right;
    scanf("%d", &n);
    left = 1;
    right = n * 2;
    for (int i = 1; i <= n * 2; i++)
    {
        for (int j = 1; j <= n * 2; j++)
        {
            if (j <= left || j >= right)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        if (i >= n)
        {
            right++;
            left--;
        }
        else
        {
            right--;
            left++;
        }
        cout << endl;
    }
};
