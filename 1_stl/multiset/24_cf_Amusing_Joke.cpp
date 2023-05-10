#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    if (s3.size() > s1.size() + s2.size())
    {
        cout << "NO";
    }
    else
    {
        multiset<char> m1, m2;
        for (auto x : s1)
        {
            m1.insert(x);
        }
        for (auto x : s2)
        {
            m1.insert(x);
        }
        for (auto x : s3)
        {
            m2.insert(x);
        }
        if (m1 == m2)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
}