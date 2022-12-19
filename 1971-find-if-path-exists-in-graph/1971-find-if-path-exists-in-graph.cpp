class Solution {
public:
    void DFS(int source,int destination,int n,vector<int>& vis,vector<int> adj[]){
        if(vis[source]==true){
            return;
        }
        vis[source]=true;
        for(auto x:adj[source]){
            DFS(x,destination,n,vis,adj);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
       vector<int>adj[n];
        for(auto x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int>vis(n,0);
        DFS(source,destination,n,vis,adj);
        
        if(vis[destination]==1){
            return true;
        }
        return false;
    }
};