#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    string s;

    getchar();
    for (int j = 1; j <= t; j++)
    {
        map<char, int> mp;
        int arr[26] = {0};
        getline(cin, s);
        for (auto x : s)
        {
            char c = tolower(x);
            if (c >= 97 && c <= 122)
            {
                arr[c - 97]++;
                mp[c] = arr[c - 97];
            }
        }
        int max = arr[0];
        for (auto i : arr)
        {
            if (i > max)
            {
                max = i;
            }
        }
        map<char, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second == max)
            {
                cout << it->first;
            }
        }
        cout << endl;
    }
}