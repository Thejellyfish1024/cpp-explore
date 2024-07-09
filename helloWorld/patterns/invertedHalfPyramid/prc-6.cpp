// Input : 5
// Output :
// 1
// 0 1
// 1 0 1
// 0 1 0 1
// 1 0 1 0 1

// #include <iostream>
// using namespace std;
// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("../../../input.txt", "r", stdin);
//     freopen("../../../output.txt", "w", stdout);
// #endif

//     int n, col, val = 1;
//     scanf("%d", &n);
//     col = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= col; j++)
//         {
//             cout << val << " ";
//             if (val == 1)
//                 val = 0;
//             else
//                 val = 1;
//         }
//         cout << endl;
//         col++;
//         if (i % 2 != 0)
//             val = 0;
//         else
//             val = 1;
//     }
// };

// another method

#include <iostream>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
#endif

    int n, col;
    scanf("%d", &n);
    col = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if ((i + j) % 2 == 0)
                cout << 1 << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
        col++;
    }
};