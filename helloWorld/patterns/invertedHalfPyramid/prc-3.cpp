// Input : 5
// Output :
// 1
// 22
// 333
// 4444
// 55555

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
        cout << val;
        
        if (row == col)
        {
            col = 1;
            val++;
            row++;
            cout << endl;
            n--;
        }
        else col++;
        
    }
};
