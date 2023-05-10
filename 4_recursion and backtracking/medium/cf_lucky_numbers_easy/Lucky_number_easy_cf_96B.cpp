// https://www.youtube.com/watch?v=rrd7MJk4Pko&ab_channel=NaziaShehnaz
#include <bits/stdc++.h>
using namespace std;

#define int long long int

signed main()
{
    vector<int> vv;//5*1e6

    for (int i = 2; i <= 10; i += 2) {
        string s;
        for (int j = 1; j <= i / 2; j++) {
            s += '4';
        }
        for (int j = 1; j <= i / 2; j++) {
            s += '7';
        }
        do {
            vv.push_back(stoll(s));
        } while (next_permutation(s.begin(),s.end()));
    }

    sort(vv.begin(), vv.end());
    int n; 
    cin >> n;
    cout << *(lower_bound(vv.begin(), vv.end(), n));

}
