#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a;
    int size;
    int n;
    while (scanf("%d", &n) != EOF)
    {
        a.push_back(n);
        size = a.size();
        sort(a.begin(), a.end());
        if (size % 2 == 1)
        {
            cout << a[(size / 2)] << endl;
        }
        else
        {
            cout << (a[(size / 2)] + a[(size / 2) - 1]) / 2 << endl;
        }
    }
}