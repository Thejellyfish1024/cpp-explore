// Input : (2,5), (8, 65)
// Output : 101, 101
// Decimal to other numbers

// binary - 5 = 101
// octal - 65 = 101
// hexa - 257 = 101

#include <bits/stdc++.h>
using namespace std;

string convertDecimalToOthers(int n, int base)
{
    string convertVal;
    int x = 1;
    while (n > 0)
    {
        int remainder = n % base;
        if (base == 16 && remainder > 9)
        {
            char alphaRemainder = remainder - 10 + 'A';
            convertVal = alphaRemainder + convertVal;
        }
        else
        {
            if (convertVal.size() < 1)
            {
                convertVal = to_string(remainder);
            }
            else
            {
                convertVal = to_string(remainder) + convertVal;
            }
        }
        n /= base;
    }

    return convertVal.size() > 0 ? convertVal : "0";
}

int main()
{
    // base number for conversion(binary(2), octal(8) or hexadecimal(16));
    int n, base;

    scanf("%d", &base);
    cin >> n;
    cout << convertDecimalToOthers(n, base);
    return 0;
};