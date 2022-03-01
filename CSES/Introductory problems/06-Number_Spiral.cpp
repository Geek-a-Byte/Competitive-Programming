#include <iostream>
#define int long long int
using namespace std;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
        {
            if (a % 2 == 1)
            {
                // a is odd
                cout << (a - 1) * (a - 1) + b << endl;
            }
            else
            {
                cout << a * a - b + 1 << endl;
            }
        }
        else if (a == b)
        {
            cout << a * a - (a - 1) << endl;
        }
        else
        {
            if (b % 2 == 1)
            {
                cout << b * b - a + 1 << endl;
            }
            else
            {
                cout << (b - 1) * (b - 1) + a << endl;
            }
        }
    }
}