class Solution {
  public:
    // Function to find the number of islands.
    void dfs(pair<int, int> index, vector<vector<bool>>& visited, vector<vector<char>>& grid){
        int row=index.first;
        int col=index.second;
        visited[row][col]=true;
        
        int n=grid.size();
        int m=grid[0].size();
        
        for(int delrow = -1; delrow<=1;delrow++) {
            for(int delcol = -1; delcol <= 1; delcol++) {
                int nrow = row + delrow; 
                int ncol = col + delcol; 
                  // neighbour row and column is valid, and is an unvisited land
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                  && grid[nrow][ncol] == '1' && !visited[nrow][ncol]) {
                      dfs(make_pair(nrow,ncol), visited, grid);
                  }
              }
          }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int numisl=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited (n, vector<bool> (m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' and visited[i][j]==false){
                    numisl++;
                    dfs(make_pair(i,j), visited, grid);
                }
            }
        }
        return numisl;
    }
