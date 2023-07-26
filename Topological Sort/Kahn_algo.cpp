#include<queue>
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    // convert edge list to adjacency list
    vector<int> adj[nodes];
    for(int i=0;i<edges;i++){
        int a = graph[i][0];
        int b = graph[i][1];
        adj[a].push_back(b);
    }
    // Create indegree list to keep count of each node's indegree count
    vector<int> indegree(nodes,0);
    queue<int> q;
    vector<int> ans(nodes);
    for(int i=0;i<nodes;i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    for(int i=0;i<nodes;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        // Node transfer from queue to array
        ans.push_back(node);
        q.pop();
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return ans;
}
