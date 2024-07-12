// Input : 17
// Output : not prime

#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    if (isPrime(n))
        cout << "Prime";
    else
        cout << "Not Prime";

    return 0;
};