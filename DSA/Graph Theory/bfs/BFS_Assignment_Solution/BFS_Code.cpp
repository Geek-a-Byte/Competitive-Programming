#include<iostream>
#include<queue>
using namespace std;

int n,e;
int adj[100][100];
int mark[100];
int dis[100];
int parent[100];

void initAdj(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            adj[i][j] = 0;
        }
    }
}

void initMark(){
    for(int i=0; i<n; i++)  mark[i] = 0;
}

void initDis(){
    for(int i=0; i<n; i++)  dis[i] = 0;
}

void initParent(){
    for(int i=0; i<n; i++)  parent[i] = -1;
}

void printDisForAll(){
    for(int i=0; i<n; i++){
        cout<<"Distance of "<<i<<" from source is "<<dis[i]<<endl;
    }
    cout<<endl;
}

void printParentTree(int element){
    if(element==-1) return;
    printParentTree(parent[element]);
    cout<<element<<" ";
}

void printParentTreeForAll(){
    for(int i=0; i<n; i++){
        cout<<"Parent tree for "<<i<<" is: ";
        printParentTree(i);
        cout<<endl;
    }
}

void bfs(int start){
    initMark();
    initDis();
    initParent();

    queue <int> q;
    q.push(start);
    mark[start] = 1;

    cout<<endl<<"Exploration order: ";

    while(q.size()!=0){       ///while(!q.empty()) this condition can be applied also
        int king = q.front();
        q.pop();
        cout<<king<< " ";

        ///Finds the children of king
        for(int i=0; i<n; i++){
            if(adj[king][i]==1){
                int child = i;

                ///Finds the unmarked children of king
                if(mark[child]==0){
                    q.push(child);
                    mark[child] = 1;
                    dis[child] = dis[king] + 1;
                    parent[child] = king;
                }
            }
        }///For loop ends

    }///While Loop ends
    cout<<endl<<endl;
}


int main(){
    cin>>n>>e;
    initAdj();

    for(int i=1; i<=e; i++){
        int x,y;
        cin>>x>>y;
        adj[x][y] = 1;
    }

    int start;
    cin>>start;

    bfs(start);
    printDisForAll();
    printParentTreeForAll();

    return 0;
}
/*
4 3

0 1
0 2
1 3
*/
