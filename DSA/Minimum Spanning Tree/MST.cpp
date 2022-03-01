#include "PriorityQueueMin.h"
#define INF INT_MAX

int n,e;
int explored[101];
int parent[101];
int cost[101][101];
int key[101];




void init(){
    for(int i=1;i<=100;i++)
    {
        key[i]=INF;
    }

}

void input(){
    cin>>n>>e;
    for (int i=0;i<e; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        cost[x][y]=z;
        cost[y][x]=z;
    }

}

void mst(int root){
    parent[root]=-1;
    key[root]=0;
    PriorityQueueMin pq;

    Node n1(root,0);
    pq.push(n1);

    while(pq.size()!=0){
        Node m=pq.top();
        m.print();
        pq.pop();
        int  king =m.id;
        if(explored[king]==1)   continue;
        explored[king]=1;

        for(int i=1;i<=n;i++)
        {
            if(cost[king][i]!=0 && explored[i]!=1 && key[i]>cost[king][i])
            {
                Node temp(i,cost[king][i]);
                pq.push(temp);
                parent[i]=king;
                key[i]=cost[king][i];
            }
        }
    }
}

int mstCost(int n){
    if(n==0)    return 0;
    if(parent[n]==-1)   return mstCost(n-1);
    return cost[n][parent[n]] + mstCost(n-1);

}

void showEdges(){
    for(int i=1; i<=n; i++){
        int j = parent[i];
        if(j==-1)   continue;
        cout<<i<<" "<<j<<": "<<cost[i][j]<<endl;
    }
}

int main()
{
    freopen("mstinput.txt","r",stdin);
    init();
    input();

    mst(1);
    int cost = mstCost(n);
    showEdges();
    cout<<"Total cost: "<<cost;
}
