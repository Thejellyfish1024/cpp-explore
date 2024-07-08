// same problem of practice-1 but with one loop.

#include <iostream>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
#endif

    int col, row;
    scanf("%d\n", &col);
    scanf("%d", &row);
    // cin >> row >> col;
    for (int i = 1; i <= row * col; i++)
    {

        cout << "*";
        if (i % col == 0 && i != row * col)
            cout << endl;
    }
};