#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a;
        vector<int> b;
        //vector<int>::iterator itr;
        int input, fixed;
        for (int j = 0; j < n; j++)
        {
            cin >> input;
            a.push_back(input);
        }

        for (auto it = a.begin(); it != a.end(); it++)
        {
            if (*it == a[x - 1])
            {
                fixed = a[x - 1];
                a.erase(it);
            }
        }

        reverse(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            // if (i == x - 1)
            // {
            //     cout << fixed << " ";
            // }
            // else
            // {
            cout << a[i] << " ";
            //}
        }
        cout << endl;
    }
}