// Input : 5
// Output :
//     * * * * *
//    * * * * *
//   * * * * *
//  * * * * *
// * * * * *


#include <iostream>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
#endif

    int n, space;
    scanf("%d", &n);
    space = n-1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= n; j++)
        {
            cout << "*";
        }
        cout << endl;
        space--;
    }
};