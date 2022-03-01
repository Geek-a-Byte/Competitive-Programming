#include <iostream>
#include <queue>
using namespace std;
int n, e;
//n er value 0 diye initialize kora karon globally assign kora nai kono man
vector<vector<int>
> adj;

int mark[10000];

void initAdj()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }
}

int main()
{
    //cout << mark[0];
    int t;
    cin >> t;
    int e;
    cin >> e;
    //initAdj();
    for (int j = 0; j < t; j++)
    {
        initAdj();
        //initMark();
        int x, y;
        for (int i = 1; i <= e; i++)
        {
            //int x, y;
            cin >> x >> y;
            adj[x][y] = 1;
            adj[y][x] = 1;
        }
        int count = 0;
        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj.size(); j++)
            {
                if (adj[i][j])
                    count++;
            }
        }
        cout << count / 2 << endl;
    }
    return 0;
}

//sentinal value -> null value
// 4 3
// 0 1
// 0 2
// 1 3
