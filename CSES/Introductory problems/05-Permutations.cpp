#include <bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
    int x;
    cin >> x;
    vector<int> v;
    int flag = 0;
    int cnt = 0;
    if (x % 2 == 1)
    {
        for (int i = 1; cnt <= ceil(x / 2); i += 2, cnt++)
            v.push_back(i);
        for (int i = 2; i <= x; i += 2)
        {
            if (v[v.size() - 1] - i == 1)
            {
                flag = 1;
                break;
            }
            else
            {
                v.push_back(i);
            }
        }
        if (flag == 1)
            cout << "NO SOLUTION";
        else
        {
            for (auto i : v)
                cout << i << " ";
        }
    }
    else
    {
        for (int i = 2; cnt < ceil(x / 2); i += 2, cnt++)
            v.push_back(i);
        for (int i = 1; i <= x; i += 2)
        {
            if (v[v.size() - 1] - i == 1)
            {
                flag = 1;
                break;
            }
            else
            {
                v.push_back(i);
            }
        }
        if (flag == 1)
            cout << "NO SOLUTION";
        else
        {
            for (auto i : v)
                cout << i << " ";
        }
    }