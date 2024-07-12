// Input : 2, 101
// Output : 5
// Binary, Octal, Hexadecimal to decimal

// 101 = 1*2^2 + 0*2^1 + 1*2^0 = 5 (binary to decimal)
// 101 = 1*8^2 + 0*8^1 + 1*8^0 = 65 (octal to decimal)
// 101 = 1*16^2 + 0*16^1 + 1*16^0 = 257 (hexadecimal to decimal)

#include <iostream>
#include <math.h>
using namespace std;

int convertNumberToDecimal(int n, int base)
{
    int convertVal = 0;
    int x = 1;
    // int A, B, C, D, E, F;
    // if(base == 16){
    //     A = 10;
    //     B = 11;
    //     C = 12;
    //     D = 13;
    //     E = 14;
    //     F = 15;
    // }
    while (n > 0)
    {
        int lastDigit = n % 10;
        convertVal += lastDigit * x;
        // cout<< convertVal<<endl;
        x = x * base;
        n = n / 10;
    }
    return convertVal;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../../../input.txt", "r", stdin);
    //     freopen("../../../output.txt", "w", stdout);
    // #endif
    int n, base;
    // select number base for conversion(binary(2), octal(8) or hexadecimal(16));

    scanf("%d", &base);
    scanf("%d", &n);
    cout << convertNumberToDecimal(n, base);
    return 0;
};