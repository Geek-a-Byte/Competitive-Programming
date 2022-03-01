#include<iostream>
#include<queue>
#include<string>
using namespace std;

int n, nextIndex;
int adj[55][55];
int mark[55];
int dis[55];
int parent[55];
string stringIntMapping[55];

///Sets -1 as the parent of all vertices
void initParent(){
    for(int i=0; i<n; i++){
        parent[i] = -1;
    }
}

/*
We keep all the file/folder names in a string array
We consider the index as the vertex number for an file/folder name
findIndex function returns the index for a file if the file/folder name is present in the array, else returns 0
*/
int findIndex(string key){
    for(int i=0; i<n; i++){
        if(stringIntMapping[i]==key){
            return i;
        }
    }
    return -1;
}


///assigns the next unassigned index for a file/folder name in the array and returns the assigned index
int assignIndex(string key){
    stringIntMapping[nextIndex] = key;
    nextIndex++;
    return nextIndex-1;
}


void input(){
    cin>>n;
    int i;

    for(i=1; i<=n-1; i++){
        string x,y;
        cin>>x>>y;

        int xIndex = findIndex(x);
        int yIndex = findIndex(y);

        if(xIndex==-1){
            xIndex = assignIndex(x);
        }

        if(yIndex==-1){
            yIndex = assignIndex(y);
        }

        adj[xIndex][yIndex] = 1;
    }
}


void bfs(){
    initParent();
    queue<int> q;
    int start = findIndex("c");
    mark[start] = 1;
    dis[start] = 2;
    q.push(start);


    while(q.size()!=0){
        int king = q.front();
        q.pop();

        for(int i=0; i<n; i++){
            if(adj[king][i]==1 && mark[i]==0){
                int child = i;
                dis[child] = dis[king] + 2;
                parent[child] = king;
                mark[child] = 1;
                q.push(child);
            }
        }
    }
}

///Prints the absolute path for a file/folder name
void printPath(int key){
    if(key==-1){
        return;
    }

    printPath(parent[key]);

    if(stringIntMapping[key]=="c"){
        cout<<"c:";
    }
    else{
        cout<<"\\"<<stringIntMapping[key];
    }
}

void runQuery(){
    int q;
    cin>>q;

    for(int i=1; i<=q; i++){
        string x;
        cin>>x;
        int index = findIndex(x);

        if(index==-1){
            cout<<"File Not Found"<<endl<<"-1";
        }
        else{
            cout<<"Absolute path for "<<x<<": ";
            printPath(index);
            cout<<endl<<"Number of mouse clicks required for opening "<<x<<": "<<dis[index];
        }

        cout<<endl<<endl;
    }
}

int main(){
    input();
    bfs();
    runQuery();
}

/*

6
c cse19
codes bfs.cpp
c a.jpg
c codes
cse19 dsalgo
3
bfs.cpp
cse19
koushik.jpg
*/
