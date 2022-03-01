#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> a;
    while (t--)
    {

        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for (auto i : a)
    {
        cout << i << " ";
    }
}