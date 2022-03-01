#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define optimize() ios_base::sync_with_stdio(0);
int main()
{
    int c[20][20];
    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.length();
    int n = s2.length();

    for (int i = 0; i <= m; i++)
    {

        c[i][0] = 0;
    }

    for (int j = 0; j <= n; j++)
    {

        c[0][j] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (s1[i - 1] == s2[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
            }

            else
            {
                if (c[i - 1][j] > c[i][j - 1])
                {
                    c[i][j] = c[i - 1][j];
                }
                else
                {
                    c[i][j] = c[i][j - 1];
                }
            }
        }
    }

    int l = c[m][n];
    char L[l + 1];
    L[l] = '\0';

    int i = m;
    int j = n;

    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            L[l - 1] = s1[i - 1];
            i--;
            j--;
            l--;
        }

        else
        {
            if (c[i - 1][j] >= c[i][j - 1])
            {
                i--;
            }

            else
            {
                j--;
            }
        }
    }

    cout << L << endl;
}