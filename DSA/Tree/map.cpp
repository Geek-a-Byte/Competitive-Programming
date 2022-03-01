#include <bits/stdc++.h>
using namespace std;

int main()
{
    //Case 1:

    // map<int, pair<int, int>> mp;
    // int dist = 5;
    // int level = 0;
    // mp[dist] = {2, 3};
    // mp[level] = {4, 5};

    // cout << mp[dist].first << endl;
    // cout << mp[dist].second << endl;
    // for (auto it : mp)
    // {
    //     cout << it.first << endl;
    //     //cout << it.second << endl; ->error
    //     cout << it.second.first << endl;
    //     cout << it.second.second << endl
    //          << endl;
    // }

    //Case 2:

    // map<pair<int, int>, int> mp1;
    // int x, y, z;
    // while (cin >> x >> y >> z)
    // {
    //     mp1[{x, y}] = z;
    // }
    // cout << mp1[{2, 3}] << endl;
    // //cout << mp1[{2, 3}].first << endl;->error
    // //cout << mp1[{2, 3}].second << endl;->error
    // for (auto it : mp1)
    // {
    //     cout << it.first.first << endl;
    //     cout << it.first.second << endl;
    //     cout << it.second << endl;
    // }

    //Case 3:
    // map<pair<int, int>, pair<int, int>> mp2;
    // int w, x, y, z;
    // while (cin >> w >> x >> y >> z)
    // {
    //     mp2[{w, x}] = {y, z};
    // }
    // cout << mp2[{2, 3}].first << endl;
    // cout << mp2[{2, 3}].second << endl;
    // for (auto it : mp2)
    // {
    //     cout << it.first.first << endl;
    //     cout << it.first.second << endl;
    //     cout << it.second.first << endl;
    //     cout << it.second.second << endl;
    // }

    //Case 4:
    map<int, int> mp3;
    int x, y;
    while (cin >> x >> y)
    {
        mp3[x] = y;
    }
    cout << mp3[x] << endl;
    for (auto it : mp3)
    {
        cout << it.first << endl;
        cout << it.second << endl;
    }
}