#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    map<string, int> mp;
    for (int i = 0; i < q; i++)
    {
        int n;
        cin >> n;
        string val;
        int num;
        if (n == 1)
        {
            cin >> val;
            cin >> num;
            mp[val] += num;
            //cout << mp[val] + num << endl;
        }
        if (n == 2)
        {
            cin >> val;
            mp.erase(val);
        }
        if (n == 3)
        {
            cin >> val;
            cout << mp[val] << endl;
        }
    }
}