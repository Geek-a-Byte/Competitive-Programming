#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int l = s.size(), c = 0, i;
    sort(s.begin(), s.end());

    for (i = 0; i < l - 1; i++)
    {
        if (s[i] != s[i + 1])
            c++;
    }

    if (c % 2 != 0)
    {
        printf("CHAT WITH HER!");
    }
    else
    {
        printf("IGNORE HIM!");
    }
}