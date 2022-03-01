#include <bits/stdc++.h>
using namespace std;
#define max 10000
const int INF = 0x3f3f3f3f;
int a[max][max];
int b[max];
int p[max][max];
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    while (cin >> n)
    {

        string blank;
        getline(cin, blank); //reads the rest of the line after reading n
        getline(cin, blank); //reads the next blank line after reading
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                p[i][j] = j;
                cin >> a[i][j];
                if (a[i][j] == -1)
                {
                    a[i][j] = INF;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    int len = a[i][k] + a[k][j] + b[k];

                    if (len < a[i][j])
                    {
                        a[i][j] = len;
                        p[i][j] = p[i][k];
                    }
                    else if (len == a[i][j])
                    {
                        if (p[i][j] > p[i][k])
                        {
                            p[i][j] = p[i][k];
                        }
                    }
                }
            }
        }
        int x, y;
        while (cin >> x >> y)
        {
            int total_dist = a[x][y];
            cout << "From " << x << " to " << y << " : " << endl;
            cout << "Path: " << x << "-->";

            while (1)
            {
                /* code */

                x = p[x][y];
                if (x == y)
                {
                    break;
                }
                cout << x << "-->";
            }
            cout << y;
            cout << endl;
            cout << "Total cost : " << total_dist << endl
                 << endl;
        }
    }
}