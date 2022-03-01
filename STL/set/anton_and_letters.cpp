#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    set<char> s1;
    for (auto x : s)
    {
        if (x == ' ' || x == '{' || x == '}' || x == ',')
        {
            continue;
        }
        if (x >= 97 && x <= 122)
        {
            s1.insert(x);
        }
    }
    cout << s1.size();
}