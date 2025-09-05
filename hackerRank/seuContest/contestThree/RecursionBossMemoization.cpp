#include <bits/stdc++.h>
using namespace std;

void numberOfSteps(int n, int &count)
{
    count++;
    int length = to_string(n).length();
    if (length == 1)
        return;

    multiset<int> set;
    int temp = n;
    for (int i = 1; i <= length; i++)
    {
        set.insert(temp % 10);
        temp /= 10;
    }
    numberOfSteps(n - (*--set.end()), count);
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num, count = 0;
    cin >> num;
    numberOfSteps(num, count);
    cout << count;
    return 0;
}
