#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int a[25][25];
void clear()
{
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
        {
            if (i == j)
                a[i][j] = 0;
            else
                a[i][j] = INF;
        }
}
int main()
{
    int t = 1;
    while (1)
    {
        clear();
        int n, m;
        cin >> n >> m;
        if (n == 0)
            break;
        string names[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> names[i];
        }

        for (int l = 0; l < m; l++)
        {
            int i, j, k;
            cin >> i >> j >> k;
            a[i][j] = k;
            a[j][i] = k;
        }

        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
                }
            }
        }
        //you need to determine the node/house to which it takes the minimum distance from every other node
        int minima = INF;
        int index;
        for (int i = 1; i <= n; i++)
        {
            int sum = 0;
            for (int j = 1; j <= n; j++)
            {
                sum += a[i][j];
            }

            if (minima > sum)
            {
                minima = sum;
                index = i;
            }
        }

        cout << "Case #" << t << " : " << names[index] << endl;
        t++;
    }
}