class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>> q;
        int onecount;
        int dm=INT_MAX;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans (n, vector<int>(m,INT_MAX));
        vector<vector<bool>> vis (n, vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }   
        }

        int drow[]={1,0,-1,0};
        int dcol[]={0,-1,0,1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int d=q.front().second;
            q.pop();
            ans[row][col]=d;
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                && !vis[nrow][ncol] && mat[nrow][ncol]==1){
                    vis[nrow][ncol]=true;
                    q.push({{nrow,ncol},d+1});
                }
            }
        }
    return ans;
    }
};
