// Input : 5
// Output :
//         *
//       * * *
//     * * * * *
//   * * * * * * *
// * * * * * * * * *
// * * * * * * * * *
//   * * * * * * *
//     * * * * *
//       * * *
//         *

#include <iostream>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
#endif

    int n, space, star = 1;
    scanf("%d", &n);
    space = n - 1;
    for (int i = 1; i <= n * 2; i++)
    {
        for (int j = 1; j <= space; j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= star; j++)
        {
            cout << "*"<<" ";
        }
        cout << endl;
        if (i == n)
            continue;
        else if (i < n)
        {
            star += 2;
            space--;
        }
        else
        {
            star -= 2;
            space++;
        }
    }
};