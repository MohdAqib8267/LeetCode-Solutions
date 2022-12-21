class Solution {
public:
    bool DFS(int src,vector<int>adj[], vector<int>& col,vector<bool>& vis,int curr){
       
        vis[src]=true;
        col[src]=curr;
        for(auto e:adj[src]){
          if(!vis[e]){
              if(DFS(e,adj,col,vis, curr xor 1)==false){
                  return false;
              }
          }
            else if(vis[e] and col[e]==curr){
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];
        for(auto x:dislikes){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int>col(n+1,-1);
        vector<bool>vis(n+1,false);
       for(int i=1;i<=n;i++){
           if(!vis[i]){
               if(DFS(i,adj,col,vis,0)==false){
                   return false;
               } 
           }
       }
        return true;
    }
};