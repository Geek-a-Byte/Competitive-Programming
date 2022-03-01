#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, string> mp;
    string s1, s2, s3, l;

    while (getline(cin, l))
    {
        if (l[0] == '\0')
            break;
        stringstream ss(l);
        ss >> s1;
        ss >> s2;
        mp[s2] = s1;
    }

    while (cin >> s3)
    {
        if (mp.find(s3) != mp.end())
            cout << mp[s3] << endl;
        else
            cout << "eh" << endl;
    }
}
