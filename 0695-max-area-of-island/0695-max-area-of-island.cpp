class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,int &area,int n,int m){
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]==0){
            return;
        }
        area++;
        grid[i][j]=0;
        dfs(i+1,j,grid,area,n,m);
        dfs(i,j+1,grid,area,n,m);
        dfs(i-1,j,grid,area,n,m);
        dfs(i,j-1,grid,area,n,m);
        
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int maxArea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int area=0;
                    dfs(i,j,grid,area,n,m);
                    maxArea=max(area,maxArea);
                }
            }
        }
        return maxArea;
    }
};