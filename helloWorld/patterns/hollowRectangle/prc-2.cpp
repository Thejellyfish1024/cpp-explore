// Input : 5, 5
// Output  :
// *****
// *   *
// *   *
// *   *
// *****
// same problem solution with one loops

#include <iostream>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
#endif

    int col, row, total, r = 1, c = 1;
    scanf("%d\n", &col);
    scanf("%d", &row);
    total = col * row;
    for (int i = 1; i <= total; i++)
    {
        if (r == 1 || r == row || c == 1 || c == col)
        {
            cout << "*";
        }
        else
            cout << " ";

        c++;
        if (i % col == 0 && i != total)
        {
            cout << endl;
            r++;
            c = 1;
        }
    }
};
