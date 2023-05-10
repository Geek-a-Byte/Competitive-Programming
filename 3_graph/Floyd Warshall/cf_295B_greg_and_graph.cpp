#include <bits/stdc++.h>
using namespace std;

int a[500][500];
int rmv[500];
int vis[500];
long long int ans[500];
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> rmv[i];
    }

    //the nodes are added to intermediate vertext list in the opposite sequence they are being removed
    //so the loop will execute in reverse order

    int cur; // the remaining current node

    for (int i = n - 1; i >= 0; i--)
    {
        cur = rmv[i];
        cur--;

        vis[cur] = 1;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                a[j][k] = min(a[j][k], a[j][cur] + a[cur][k]);
            }
        }

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                //check if both j and k remains in the graph after removing nodes
                if (vis[j] && vis[k])
                {
                    ans[i] = ans[i] + a[j][k];
                }
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << ans[n - 1];
}