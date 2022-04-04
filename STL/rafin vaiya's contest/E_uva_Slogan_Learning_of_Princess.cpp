#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, string> mp;
    string s1, s2;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        getline(cin, s1);
        getline(cin, s2);
        mp[s1] = s2;
    }
    int m;
    cin >> m;
    cin.ignore();
    for (int i = 1; i <= m; i++)
    {
        getline(cin, s1);
        cout << mp[s1] << endl;
    }
}