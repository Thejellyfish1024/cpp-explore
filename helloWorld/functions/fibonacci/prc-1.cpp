// Input : 5
// Output : 0,1,1,2,3

#include <iostream>
#include <math.h>
using namespace std;

void fibo(int first, int second, int num, int count)
{
    if (count == num)
        return;
    if (count == 1)
    {
        cout << first << " " << second << " ";
    }
    else
    {
        cout << second<<" ";
    }
    return fibo(second, first + second, num, ++count);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    fibo(0, 1, n, 1);

    return 0;
};