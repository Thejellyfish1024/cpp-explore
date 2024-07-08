// Input : 5
// Output  :
// *****
// ****
// ***
// **
// *

#include <iostream>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
#endif

    int row, count = 0;
    scanf("%d", &row);
    while (row > 0)
    {
        count++;
        cout << "*";
        if (count % row == 0)
        {
            cout << endl;
            row--;
            count = 0;
        }

        if (row == 0)
            break;
    }
};
