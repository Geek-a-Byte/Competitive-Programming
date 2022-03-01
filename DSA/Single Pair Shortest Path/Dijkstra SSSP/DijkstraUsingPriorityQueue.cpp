#include <bits/stdc++.h>
using namespace std;
int cost[101][101];
int dis[101];
int parent[101];
int explored[101];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
int n, e, source;

void init()
{
    for (int i = 1; i <= 100; i++)
    {
        dis[i] = INT_MAX;
        parent[i] = -1;
    }
}

void input()
{
    cin >> n >> e;
    int x, y, c;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y >> c;
        cost[x][y] = c;
    }
    cin >> source;
}

void sssp()
{
    dis[source] = 0;
    p.push(make_pair(0, source));
    while (!p.empty())
    {
        pair<int, int> pa = p.top();
        p.pop();
        int king = pa.second;
        int v = pa.first;
        if (explored[king] == 1)
            continue;
        explored[king] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (cost[king][i] != 0 && explored[i] != 1 && dis[i] > dis[king] + cost[king][i])
            {
                dis[i] = dis[king] + cost[king][i];
                parent[i] = king;
                p.push(make_pair(dis[i], i));
            }
        }
    }
}

void showDist(int i)
{
    cout << "Distance of " << i << " from source is: " << dis[i] << endl;
}

void showDistOfAll()
{
    for (int i = 1; i <= n; i++)
    {
        showDist(i);
    }
}

void showPath(int i)
{
    if (parent[i] == -1)
    {
        cout << i;
        return;
    }

    else
    {
        showPath(parent[i]);
        cout << "->" << i;
    }
}

void showPathOfAll()
{
    for (int i = 1; i <= n; i++)
    {
        cout << "path of " << i << ":";
        showPath(i);
        cout << endl;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    init();
    input();
    sssp();
    showDistOfAll();
    showPathOfAll();
    return 0;
}