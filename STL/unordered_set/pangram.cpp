#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    if (n < 26)
    {
        cout << "NO";
    }
    else
    {
        unordered_set<char> s1;
        for (auto x : s)
        {
            if (x >= 97 && x <= 122)
            {
                s1.insert(x);
            }
        }

        if (s1.size() == 26)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
}