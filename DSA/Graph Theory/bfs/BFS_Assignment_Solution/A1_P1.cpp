#include<iostream>
#include<queue>
using namespace std;

int adj[105][105];
int mark[105];
int n,m;

void input(){
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
}

///If all the vertices of the graph are visited, the function returns true, otherwise returns false
bool isAllVerticesVisited(){
    for(int i=0; i<n; i++){
        if(mark[i]==0)  return false;
    }
    return true;
}


///Returns a the number of a vertex which is not visited
int nextUnVisitedVertex(){
    for(int i=0; i<n; i++){
        if(mark[i]==0)  return i;
    }
    return -1;
}

///Marks all the vertices of the graph which can be reached from "start" vertex
void bfs(int start){
    queue<int> q;
    q.push(start);
    mark[start] = 1;

    while(q.size()!=0){
        int parent = q.front();
        q.pop();

        for(int i=0; i<n; i++){
            if(adj[parent][i]==1 && mark[i]==0){
                int child = i;
                q.push(child);
                mark[child] = 1;
            }
        }

    }
}


int findTotalComponent(){
    int component = 0;

    ///The process continues until all the vertices are visited
    while(isAllVerticesVisited()==false){
        int unVisitedVertex = nextUnVisitedVertex();
        bfs(unVisitedVertex);
        component++;
    }

    return component;
}


int main(){
    input();
    int component = findTotalComponent();
    cout<<component;
}
