#include <iostream>
#include <queue>
using namespace std;
int n, e;
//n er value 0 diye initialize kora karon globally assign kora nai kono man
int adj[100][100] = {0};

int mark[100] = {0};
int dis[100] = {0};

// void initAdj()
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             adj[i][j] = 0;
//         }
//     }
// }

void printDis()
{
    for (int i = 0; i < n; i++)
    {
        cout << "distance"
             << " of  " << i << " is " << dis[i] << endl;
    }
}

void bfs(int start)
{
    //initMark();
    queue<int> q;
    q.push(start);
    mark[start] = 1;
    while (!q.empty())
    {
        int king = q.front();
        cout << king << " ";
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (adj[king][i])
            {
                int child = i;
                if (!mark[child])
                {
                    q.push(child);
                    dis[child] = dis[king] + 1;
                    mark[child] = 1;
                }
            }
        }
    }
}

int main()
{
    //cout << mark[0];
    cin >> n >> e;
    //initAdj();
    for (int i = 1; i <= e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x][y] = 1;
    }
    int start;
    cin >> start;
    bfs(start);
    printDis();
    return 0;
}

//sentinal value -> null value
// 4 3
// 0 1
// 0 2
// 1 3
