#include <bits/stdc++.h>
using namespace std;

int isprime(int n)
{
    if (n <= 1)
    {
        return 0;
    }
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int t;
    cin >> t;
    string s;
    for (int j = 1; j <= t; j++)
    {
        int flag = 0;
        vector<char> s1;
        int count[125] = {0};
        cin >> s;

        for (auto x : s)
        {
            s1.push_back(x);
        }
        sort(s1.begin(), s1.end());
        for (auto i : s1)
        {
            if (i >= 'a' && i <= 'z' || i >= 'A' && i <= 'Z' || i >= '0' && i <= '9')
                count[i]++;
        }
        cout << "Case " << j
             << ": ";
        for (int i = 0; i < 125; i++)
        {
            if (isprime(count[i]))
            {
                flag = 1;
                printf("%c", i);
            }
        }
        if (flag == 0)
        {
            cout << "empty";
        }
        cout << endl;
    }
}