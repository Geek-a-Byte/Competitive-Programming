#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

int explored[101] = {0};
int parent[101];
int cost[101][101];
int key[101];
int n, e;

class Node
{

public:
    int id, key;

    Node(int i, int k)
    {
        id = i;
        key = k;
    }

    void print()
    {
        cout << "Id: " << id << " || Key: " << key << endl;
    }
};

void init()
{
    for (int i = 1; i <= 100; i++)
    {
        key[i] = INF;
    }
}
//sub graph er khetre edge nao thakte pare karon edge 0 hobe jeta faka set oitao main graph er ongsho
//spanning subgraph main graph er shob vertex and
//edge is equal or subset of main graph) na hoile
//spanning tree(tree hoite hobe shob vertex connected thakte hobe) o hobe na
//main graph er onekgula spanning tree er min total cost jar shetai min spanning tree

//prim's algo:

//unexplored node er moddhe jar value shob cheye choto take min node dhorbo
//then min node ke explore korbo
//tokhon min er neighbour ke explore korbo
//trpor min node er shathe neighbour er edge er weight ja ta value te insert hobe neighbour
//jodi kono node er kono neighbour na thake , tokhon oi neighbour hobe visited
//next unexplored node er moddhe jar value shob cheye choto take min node dhorbo
//then abar neighbour ke explore korbo
//trpor jodi oi neighbour node er value weight er theke beshi hoy then weight ta value hishebe set hobe notun
//tai parent change hobe
//not sure : jodi kono node er kono child ee unexplored na thake tokhon oitake min node dhorbo na

void input()
{
    cin >> n >> e;
    for (int i = 1; i <= e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        cost[u][v] = w;
        cost[v][u] = w;
    }
}

bool operator<(const Node &child, const Node &parent)
{
    if (parent.key < child.key)
    {
        return true;
    }
    return false;
}

void mst(int root)
{
    //root er kono parent nai
    parent[root] = -1;
    key[root] = 0;
    priority_queue<Node> pq;
    Node n1(root, 0);
    pq.push(n1);

    while (!pq.empty())
    {
        Node p = pq.top();
        pq.pop();

        int king = p.id;
        if (explored[king] == 1)
        {
            continue;
        }

        explored[king] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (cost[king][i] != 0 && explored[i] != 1 && key[i] > cost[king][i])
            {
                parent[i] = king;
                key[i] = cost[king][i];
                Node temp(i, key[i]);
                pq.push(temp);
            }
        }
    }
}

int mstCost()
{
}

void showEdges()
{
    for (int i = 1; i <= n; i++)
    {
        int j = parent[i];
        if (j == -1)
            continue;
        cout << i << " " << j << ": " << cost[i][j] << endl;
    }
}

int main()
{
    freopen("mstinput.txt", "r", stdin);
    init();
    input();

    mst(1);
    int cost = mstCost();
    showEdges();
    cout << "Total cost: " << cost;
}

// !focus on what should be done rather than what can be done.