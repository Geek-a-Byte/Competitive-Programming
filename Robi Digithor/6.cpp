#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    long long int d, sum, sum5;

    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        sum = 0;
        sum5 = 0;
        cin >> d;
        cout << "Case " << i << ": ";

        for (long long int j = 5; j <= d; j = j + 5)
        {
            sum5 += j;
        }
        sum = ((d * (d + 1)) / 2) - sum5;
        cout << sum << endl;
    }
}