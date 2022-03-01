#include <bits/stdc++.h>
using namespace std;

#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define endl "\n"
#define IO read write
#define ll long long int
void fileOJ()
{
#ifndef ONLINE_JUDGE
    IO
#endif
}

int main()
{
    FIO;
    fileOJ();
    string s;
    cin >> s;
    int c = 1;
    int mx = c;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            c++;
            mx = max(c, mx);
        }
        else
        {
            c = 1;
        }
    }
    cout << mx;
}