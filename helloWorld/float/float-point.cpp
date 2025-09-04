#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float n = 63.3588;
    cout << fixed << setprecision(6)<< n <<endl;
    cout << min(5, 3) << " " << max(5, 3) << endl;
    int a = 10, b = 20;
    swap(a, b);
    cout << a << " "<< b;
    return 0;
}