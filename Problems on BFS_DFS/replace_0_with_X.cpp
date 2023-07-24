#include<vector>
void dfs(int row, int col, char** arr, int n, int  m, vector<vector<int>>& visited){
    visited[row][col]=1;
    int drow[]={-1,0,1,0};
    int dcol[]={0,-1,0,1};
    for(int i=0;i<4;i++){
        int nrow=row+drow[i];
        int ncol=col+dcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
        && arr[nrow][ncol]=='O' && !visited[nrow][ncol]){
            dfs(nrow, ncol, arr, n, m, visited);
        }
    }
}

void replaceOWithX(char** arr, int n, int  m)
{
    //Write your code here
    vector<vector<int>> visited (n, vector<int>(m,0));
    for(int i=0;i<n;i++){
        if(!visited[i][0] && arr[i][0]=='O'){
            dfs(i, 0, arr, n, m, visited);
        }
        if(!visited[i][m-1] && arr[i][m-1]=='O'){
            dfs(i, m-1, arr, n, m, visited);
        }
    }
    for(int i=0;i<m;i++){
        if(!visited[0][i] && arr[0][i]=='O'){
            dfs(0, i, arr, n, m, visited);
        }
        if(!visited[n-1][i] && arr[n-1][i]=='O'){
            dfs(n-1, i, arr, n, m, visited);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='O' && !visited[i][j]){
                arr[i][j]='X';
            }
        }
    }  
}
