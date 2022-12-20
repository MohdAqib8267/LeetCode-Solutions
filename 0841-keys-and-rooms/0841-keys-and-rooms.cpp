class Solution {
public:
    void DFS(int src,vector<int>adj[],vector<bool>& vis,int n){
        if(vis[src]==true){
            return;
        }
        vis[src]=true;
        for(auto x:adj[src]){
            DFS(x,adj,vis,n);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<rooms[i].size();j++){
                adj[i].push_back(rooms[i][j]);
            }
        }
        vector<bool>vis(n,false);
        DFS(0,adj,vis,n);
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                return false;
            }
        }
        return true;
    }
};