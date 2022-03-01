#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // int b[n];
    // for (int i = 0; i < n; i++)
    // {
    //     b[i] = a[i];
    // }
    if (y == 1)
    {
        //right shift

        for (int j = 0; j < x; j++)
        {
            for (int i = n; i > 0; i--)
            {
                a[i] = a[i - 1];
            }
            a[0] = a[n];
            // for (int i = 0; i < n; i++)
            // {
            //     cout << a[i] << " ";
            // }
            // cout << endl;
        }

        for (int i = 0; i < n - 1; i++)
        {
            cout << a[i] << " ";
        }
        cout << a[n - 1];
        cout << endl;
    }
    else if (y == 0)
    {
        /* code */

        for (int j = 0; j < x; j++)
        {
            int last = a[0];
            for (int i = 0; i < n - 1; i++)
            {
                a[i] = a[i + 1];
            }
            a[n - 1] = last;
            // for (int i = 0; i < n; i++)
            // {
            //     cout << a[i] << " ";
            // }
            // cout << endl;
        }

        for (int i = 0; i < n - 1; i++)
        {
            cout << a[i] << " ";
        }
        cout << a[n - 1];

        cout << endl;
    }
}