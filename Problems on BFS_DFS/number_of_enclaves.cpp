void dfs(int row, int col, vector<vector<int>> &Matrix, int N, int  M, 
vector<vector<int>>& visited){
    visited[row][col]=1;
    int drow[]={-1,0,1,0};
    int dcol[]={0,-1,0,1};
    for(int i=0;i<4;i++){
        int nrow=row+drow[i];
        int ncol=col+dcol[i];
        if(nrow>=0 && nrow<N && ncol>=0 && ncol<M
        && Matrix[nrow][ncol]==0 && !visited[nrow][ncol]){
            dfs(nrow, ncol, Matrix, N, M, visited);
        }
    }
}


int matrixTraps(int N,int M,vector<vector<int>> &Matrix)
{
    vector<vector<int>> visited (N, vector<int>(M,0));
    int count=0;
    for(int i=0;i<N;i++){
        if(!visited[i][0] && Matrix[i][0]==0){
            dfs(i, 0, Matrix, N, M, visited);
        }
        if(!visited[i][M-1] && Matrix[i][M-1]==0){
            dfs(i, M-1, Matrix, N, M, visited);
        }
    }
    for(int i=0;i<M;i++){
        if(!visited[0][i] && Matrix[0][i]==0){
            dfs(0, i, Matrix, N, M, visited);
        }
        if(!visited[N-1][i] && Matrix[N-1][i]==0){
            dfs(N-1, i, Matrix, N, M, visited);
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(Matrix[i][j]==0 && !visited[i][j]){
                count++;
            }
        }
    }
    return count;  
}
