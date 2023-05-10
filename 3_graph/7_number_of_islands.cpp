// same as cses counting rooms

class Solution {
  public:
    // up, down, left, right, all 4 diagonals
    vector<pair<int,int>>moves={{-1,0},{+1,0},{0,-1},{0,+1},{-1,+1},{+1,+1},{-1,-1},{+1,-1}};
    bool visited[505][505];
    
    bool boundaryCheck(int i,int j, vector<vector<char>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        if(i<0 or i>=rows or j<0 or j>=cols) return false;
        return true;
    }
    void dfs(int i, int j, vector<vector<char>>& grid)
    {
        visited[i][j] = 1;
        for (auto k : moves)
        {
            int nx=i+k.first;
            int ny=j+k.second;
            if (boundaryCheck(nx,ny,grid) and !visited[nx][ny])
            {
                dfs(nx, ny, grid);
            }
        }
    }
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // code here
        int rows = grid.size();
        int cols = grid[0].size();
        int cnt=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                char c= grid[i][j];
                if(c=='0')
                {
                    visited[i][j]=1;
                }
                if(c=='1')
                {
                    visited[i][j]=0;
                }
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++){
                if (!visited[i][j])
                {
                    dfs(i,j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

