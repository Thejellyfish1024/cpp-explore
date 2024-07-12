// Input : 2, 101
// Output : 5
// Binary, Octal, Hexadecimal to decimal

// 101 = 1*2^2 + 0*2^1 + 1*2^0 = 5 (binary to decimal)
// 101 = 1*8^2 + 0*8^1 + 1*8^0 = 65 (octal to decimal)
// 101 = 1*16^2 + 0*16^1 + 1*16^0 = 257 (hexadecimal to decimal)

#include <bits/stdc++.h>
using namespace std;

int convertNumberToDecimal(int n, int base, string n2)
{
    int convertVal = 0;
    int x = 1;
    if (base == 16)
    {
        for (int i = n2.size() - 1; i >= 0; i--)
        {
            if (n2[i] >= '0' && n2[i] <= '9')
            {
                convertVal += x * (n2[i] - '0');
                x *= base;
            }
            else if (n2[i] >= 'A' && n2[i] <= 'F')
            {
                convertVal += x * (n2[i] - 'A' + 10);
                x *= base;
            }
        }
    }
    else
    {
        while (n > 0)
        {
            int lastDigit = n % 10;
            convertVal += lastDigit * x;
            x = x * base;
            n = n / 10;
        }
    }

    return convertVal;
}

int main()
{
    // base number for conversion(binary(2), octal(8) or hexadecimal(16));
    int n, base;
    string n2;

    scanf("%d", &base);
    if (base == 16)
    {
        cin >> n2;
        cout << convertNumberToDecimal(0, base, n2);
    }
    else
    {
        cin >> n;
        cout << convertNumberToDecimal(n, base, "");
    }
    return 0;
};