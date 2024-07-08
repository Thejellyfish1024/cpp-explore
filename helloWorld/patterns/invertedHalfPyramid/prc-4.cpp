// Input : 5
// Output :
// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15

#include <iostream>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
#endif

    int n, val = 1, row = 1, col = 1;
    scanf("%d", &n);
    while (n > 0)
    {
        cout << val<<" ";
        val++;
        if (row == col)
        {
            col = 1;
            row++;
            cout << endl;
            n--;
        }
        else col++;
        
    }
};
