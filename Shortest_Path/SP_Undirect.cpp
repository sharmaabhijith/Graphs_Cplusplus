vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
    // Write your code here.
    int m=edges.size();
    vector<int> dis(n, INT_MAX);
    vector<int> adj[n];
    queue<int> q;
    //Create adjacency list from edges 
    for(int i=0;i<m;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    //Create queue and push elements
    q.push(src);
    dis[src]=0;
    while(!q.empty()){
        int node=q.front();
        //cout<<node<<" ";
        q.pop();
        for(auto it: adj[node]){
            // greedy distance check
            if(dis[node]+1<dis[it]){
                dis[it]=dis[node]+1;
                q.push(it);
            }
        } 
    }
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        if(dis[i]!=INT_MAX){
            ans[i]=dis[i];
        }
    }
    return ans;
}
