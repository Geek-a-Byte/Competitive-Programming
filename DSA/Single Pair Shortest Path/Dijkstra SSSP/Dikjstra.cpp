#include "PriorityQueueMin.h"
#define INF INT_MAX;

int cost[101][101]; // weightage between two nodes
int dis[101];       //shortest distance from source of all nodes
int parent[101];    //parent of all nodes
int explored[101];  //a mark for all nodes whether they are explored or not

int n, e, s;

void init()
{

    //make all nodes' distance from the source infinite
    //make all nodes' parent -1
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        dis[i] = INF;
    }
}

void input()
{
    //take input of :
    //no of nodes
    //no of edges
    //edges and cost
    //source
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        cost[u][v] = w; //directed bole khali cost[u][v]
        //undirected hole cost[u][v]
        //and cost[v][u]
    }
    cin >> s;
}

void sssp()
{
    //follow the steps of the algo
    //make the distance of the source 0
    //take a priorityminqueue obj
    // take a node with parameterized constructor
    // where it takes source, dis[source]
    // and then push it to queue
    dis[s] = 0;
    PriorityQueueMin p;
    Node a(s, dis[s]);
    p.push(a);
    while (p.size() != 0)
    {
        Node curr = p.top();
        p.pop();
        int king = curr.id; // first value mane koto number index
        if (explored[king] == 1)
        {
            continue;
        }
        explored[king] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (cost[king][i] != 0 && explored[i] != 1 && dis[i] > dis[king] + cost[king][i])
            {
                dis[i] = dis[king] + cost[king][i];
                Node b(i, dis[i]);
                p.push(b);
                parent[i] = king;
            }
        }
    }
}

void showDist(int i)
{
    cout << "Min distance from source to " << i << " is " << dis[i] << endl;
}

void showDistforall()
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
        cout << " -> " << i;
    }
}

void showPathforall()
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
    input();
    init();
    sssp();
    showDistforall();
    showPathforall();
}