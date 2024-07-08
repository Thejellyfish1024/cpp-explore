// Input : 5
// Output  :
//     *
//    **
//   ***
//  ****
// *****

#include <iostream>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
#endif

    int row, total, r = 1, c;
    scanf("%d", &row);
    c = row;
    total = row * row;
    for (int i = 1; i <= total; i++)
    {
        if (c > r)
        {
            cout << " ";
        }
        else
            cout << "*";
        c--;
        if (i % row == 0 && i != total)
        {
            cout << endl;
            r++;
            c = row;
        }
    }
};
