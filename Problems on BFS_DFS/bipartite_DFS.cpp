class Solution {
public:
    bool dfs(int node, int color, vector<vector<int>> &adj, vector<int>& visited){
        visited[node]=color;
        for(auto it: adj[node]){
            if(visited[it]==-1){
                if(dfs(it, !color, adj, visited)==false){
                    return false;
                }
            }
            else if(color==visited[it]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        int color=0;
        vector<int> visited(n,-1);
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                if(dfs(i, color, adj, visited)==false){
                    return false;
                }
            }
        }
        return true;        
    }
};
