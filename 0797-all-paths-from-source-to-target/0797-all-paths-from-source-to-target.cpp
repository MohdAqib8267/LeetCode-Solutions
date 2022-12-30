class Solution {
public:
    void DFS(int src,int target,vector<vector<int>>& adj,vector<int>& path,vector<vector<int>>& ans){
        path.push_back(src);
        if(src==target){
            ans.push_back(path);
            return;
        }
        for(auto it:adj[src]){
            DFS(it,target,adj,path,ans);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj;
        for(int i=0;i<n;i++){
            adj.push_back(graph[i]);
        }
        //DFS
        vector<vector<int>>ans;
        vector<int>path;
         DFS(0,n-1,adj,path,ans);
        return ans;
    }
};