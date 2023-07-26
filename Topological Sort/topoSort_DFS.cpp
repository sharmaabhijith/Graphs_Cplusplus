#include<stack>
void dfs(int node, vector<int> adj[], vector<int>& visited, stack<int>& st){
    visited[node]=1;
    for(auto it: adj[node]){
        if(!visited[it]){
            dfs(it, adj, visited, st);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    // Write your code here!
    vector<int> adj[nodes];
    for(int i=0;i<edges;i++){
        int a = graph[i][0];
        int b = graph[i][1];
        adj[a].push_back(b);
    }
    vector<int> visited(nodes,0);
    stack<int> st;
    for(int i=0;i<nodes;i++){
        if(!visited[i]){
            dfs(i,adj,visited,st);
        }
    }
    vector<int> ans;
    for(int i=0;i<nodes;i++){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
