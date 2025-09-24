#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {10, 20, 30};
    v.push_back(40); // add element
    v[1] = 25;       // modify
    for (int x : v)
        cout << x << " ";
    return 0;
}
