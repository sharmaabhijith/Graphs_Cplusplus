class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool> &visited){
        // Mark the city visited
        visited[node]=true;
        for (int col=0;col<isConnected[node].size();col++){
            // 1. ignore self loop col!=node
            // 2. See if there is a path between each city and node city
            // 3. Only perform DFS, if it has not been traversed yet
            if(col!=node && isConnected[node][col]==1 && visited[col]==false){
                dfs(col, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int numcity = isConnected.size();
        vector<bool> visited(numcity, false);
        int countprv = 0;
        // Iterate through each city and check if it has been traversed through DFS. 
        // If DFS couldn't find the city through traversal, then there is a break between the cities and it belongs to other province. 
        for(int i=0;i<numcity;i++){
            if(!visited[i]){
                // Indicates city that couldn't be traversed through DFS
                countprv++;
                dfs(i, isConnected, visited);
            }
        }
        
        return countprv;
    }
};
