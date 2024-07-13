// Input : 10, 11
// Output : 101

#include <bits/stdc++.h>
using namespace std;

string addTwoBinaryNumbers(int n1, int n2)
{
    string sum = "";
    int carry = 0;
    string num1 = to_string(n1);
    string num2 = to_string(n2);
    if (num1.size() != num2.size())
    {
        if (num1.size() > num2.size())
        {
            while (num1.size() != num2.size())
            {
                num2 = '0' + num2;
            }
        }
        else
        {
            while (num1.size() != num2.size())
            {
                num1 = '0' + num1;
            }
        }
    }

    for (int i = num1.size() - 1; i >= 0; i--)
    {
        int currentSum = (num1[i] - '0') + (num2[i] - '0') + carry;
        if (currentSum == 3)
        {
            sum = '1'+ sum;
            carry = 1;
        }
        else if (currentSum == 2)
        {
            sum = '0'+ sum;
            carry = 1;
        }
        else if (currentSum == 1)
        {
            sum = '1'+ sum;
            carry = 0;
        }
        else
        {
            sum = '0'+ sum;
            carry = 0;
        }
    }

    if(carry == 1){
      sum = '1'+sum;
    }

    return sum;
}

int main()
{
    // base number for conversion(binary(2), octal(8) or hexadecimal(16));
    int n1, n2;

    cin >> n1;
    cin >> n2;
    cout << addTwoBinaryNumbers(n1, n2);
    return 0;
};