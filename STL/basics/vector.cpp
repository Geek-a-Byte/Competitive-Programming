#include <bits/stdc++.h>
using namespace std;
int main()
{
    // vector<int> a[100];
    // a[0].push_back(1);
    // a[0][1] = 100;
    // cout << a[0][1] << endl;
    // cout << "hi it works";

    // vector<vector<int>> a(100);
    // a[0].push_back(1);
    // a[0][1] = 100;
    // cout << a[0][1] << endl;
    // cout << "hi it works";
    // vector<int> a;
    // for (int i = 1; i <= 5; i++)
    //     a.push_back(i);
    // for (auto x : a)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    //begin() – Returns an iterator pointing to the first element in the vector
    //end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
    // for (auto i = a.begin(); i != a.end(); ++i)
    //     cout << *i << " ";
    // cout << endl;

    //     for (auto i = a.cbegin(); i != a.cend(); ++i)
    //     cout << *i << " ";
    int n;
    cin >> n;
    map<string, long long int> mp;

    string name;
    long long int number;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> number;
        mp[name] = number;
    }
    string query;

    while (cin >> query)
    {

        if (mp[query] != 0)
        {

            cout << query << "=" << mp[query] << endl;
        }
        else
        {
            cout << "Not found" << endl;
        }
    }
    return 0;
}