// Input : 9
// Output :

//     *       *
//   *   *   *   *
// *       *       *

#include <iostream>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int row = 1; row <= 3; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            if ((row + col) % 4 == 0 || (row == 2 && col % 4 == 0))
                cout << "*" << " ";
            else
                cout << "  ";
        }
        cout << endl;
    }
};