#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define N 10000007
int a[N];

void sieve()
{
    for (int i = 2; i <= sqrt(N); i++)
    {
        if (a[i] == 0)
        {
            for (int j = i + i; j <= N; j += i)
            {
                if (a[j] == 0)
                    a[j] = i;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (a[i] == 0)
            a[i] = i;
    }
}

int NOD(int n)
{
    int nod = 1;
    while (n > 1)
    {
        int cnt = 0;
        int f = a[n];
        while (n % f == 0)
        {
            n /= f;
            cnt++;
        }
        nod *= (cnt + 1);
    }
    return nod;
}

signed main()
{
    sieve();
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        cout << NOD(x) << endl;
    }
}