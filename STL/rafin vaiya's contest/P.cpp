//unsolved 
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    string s;
    getchar();
    multimap<char, int> mp;
    //map<char, int>::key_compare mycomp = mp.key_comp();
    vector<char> v;
    while (t--)
    {
        getline(cin, s);
        for (auto x : s)
        {
            if (x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z')
            {
                v.push_back(toupper(x));
                if (x >= 97 && x <= 122)
                {
                    mp[x - 32]++;
                }
                else
                {
                    mp[x]++;
                }
            }
        }
    }
    //char h = mp.rbegin()->first;
    sort(v.begin(), v.end());

    int i = 0;
    for (auto it : mp)
    {
        cout << v[i] << " ";
        cout << it.second << endl;
        i++;
    }
}
