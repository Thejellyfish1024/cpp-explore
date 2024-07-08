#include <iostream>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    switch (n)
    {
    case 5:
        cout << "n is 5";
        break;
    case 3:
        cout << "n is 3";
        break;

    default:
        cout << "hello";
        break;
    }
};
