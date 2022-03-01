#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    map<string, string> mp;
    string s1, s2;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2;
        mp[s1] = s2;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> s1;
        if (mp.find(s1) != mp.end())
            cout << mp[s1] << endl;
        else
        {
            char c1 = s1[s1.size() - 1];
            char c2 = s1[s1.size() - 2];

            if (c1 == 'y' && (c2 != 'a' && c2 != 'e' && c2 != 'i' && c2 != 'o' && c2 != 'u'))
            {
                s1.resize(s1.size() - 1);
                cout << s1 << "ies" << endl;
            }
            else if (c1 == 'o' || c1 == 's' || c1 == 'x' || (c1 == 'h' && (c2 == 'c' || c2 == 's')))
                cout << s1 << "es" << endl;
            else
                cout << s1 << "s" << endl;
        }
    }
}