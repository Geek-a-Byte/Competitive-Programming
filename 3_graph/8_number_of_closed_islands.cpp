//User function Template for C++

class Solution {
    public:
         // up, down, left, right, all 4 diagonals
    vector<pair<int,int>>moves={{-1,0},{+1,0},{0,-1},{0,+1}};
    bool visited[505][505];
    
    bool cornerCellCheck(int i, int j, vector<vector<int>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        if((i==0 or j==0 or i==rows-1 or j==cols-1) and grid[i][j]==1)
        {
            return true;
        }
        return false;
    }
    bool boundaryCheck(int i,int j, vector<vector<int>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        if(i<0 or i>=rows or j<0 or j>=cols) return false;
        return true;
    }
    void dfs(int i, int j, vector<vector<int>>& grid, bool& hasCornerCell)
    {
        if(cornerCellCheck(i,j,grid))
        {
            hasCornerCell=true;
        }
        visited[i][j] = 1;
        for (auto k : moves)
        {
            int nx=i+k.first;
            int ny=j+k.second;
            
            if (boundaryCheck(nx,ny,grid) and !visited[nx][ny] and grid[nx][ny]==1)
            {
                dfs(nx, ny, grid, hasCornerCell);
            }
        }
    }
    int closedIslands(vector<vector<int>>& grid, int N, int M) {
        // Code here
        int rows = N;
        int cols = M;
        int cnt=0;
        for (int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++){
                
                visited[i][j]=false;
            }
        }
     
        for (int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++){
                
                if (!visited[i][j] and grid[i][j]==1)
                {
                    bool hasCornerCell=false;
                    dfs(i,j, grid, hasCornerCell);
                    // cout<<hasCornerCell<<endl;
                    if(!hasCornerCell) cnt++;
                }
            }
        }
        return cnt;
    }
 
};