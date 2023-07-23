bool detectcycle(int src, vector<vector<int>>& adj, int visited[]){
    queue<pair<int,int>> q;
    visited[src]=1;
    q.push({src,-1});

    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it]=1;
                q.push({it,node});
            }
            else{
                if(it!=parent){
                    return true;
                }
            }
            
        }
    }
    return false;

}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    int src=1;
    int visited[n+1]={0};
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    for(int i=src;i<=n;i++){
        if(!visited[i]){
            if(detectcycle(i, adj, visited)){
                return "Yes";
            }
        }
    }
    return "No";
}
