#include "PriorityQueueMin.h"
#define INF INT_MAX

int cost[101][101];
int dis[101];
int parent[101];
int explored[101];

int n, e, source;

void init()
{
    //O(n)
    for (int i = 1; i < 101; i++)
    {
        dis[i] = INF;
        parent[i] = -1;
    }
}

void input()
{
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        cost[u][v] = w;
    }
    cin >> source;
}

void sssp()
{
    dis[source] = 0;///O(1)
    PriorityQueueMin p;
    Node node(source, dis[source]);
    p.push(node);
    while (p.size() != 0)
    {
        Node cur = p.top();
        p.pop();

        int king = cur.id;
        if (explored[king] == 1)
        {
            continue;
        }
        explored[king] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (cost[king][i] != 0 && explored[i] != 1 && dis[i] > cost[king][i] + dis[king])
            {
                //relaxation
                dis[i] = dis[king] + cost[king][i];
                parent[i] = king;
                Node x(i, dis[i]);
                p.push(x);
            }
        }
    }
}

void showDist(int i)
{
    cout << "Distance of " << i << " from source " << source << " is :" << dis[i] << endl;
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
        cout << i << " ";
        return;
    }
    else
    {
        showPath(parent[i]);
        cout << " -> " << i << " ";
    }
    ///i=4
    //i=4 showpath(2)  cout<<4
    //i=2 showPath(3)  cout<<2
}

void showPathOfAll()
{
    for (int i = 1; i <= n; i++)
    {
        cout << "Path of " << i << ": ";
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
}
