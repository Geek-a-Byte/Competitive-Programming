#include <bits/stdc++.h>
using namespace std;
vector<int> prime_arr;

void prime_factors(int s)
{
    for (int i = 2; i <= sqrt(s); i++)
    {
        if (s % i == 0)
        {
            prime_arr.push_back(i);
        }
    }
    for (int i = 0; i < prime_arr.size(); i++)
    {
        cout << prime_arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    int s, t;
    for (int i = 1; i <= T; i++)
    {
        cin >> s >> t;
        prime_factors(s);
    }
}