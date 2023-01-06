class Solution {
public:
    //dp solution gives TLE
//     int solve(int i,int coins,vector<int>& costs,vector<vector<int>>& dp){
//         if(i>=costs.size()){
//             return 0;
//         }
      
//         if(dp[i][coins]!=-1){
//             return dp[i][coins];
//         }
//         //take
//         int take=0;
//         if(coins>=costs[i]){
//             take=1+solve(i+1,coins-costs[i],costs,dp);
//         }
//         int not_take=solve(i+1,coins,costs,dp);
//         return dp[i][coins]=max(take,not_take);
        
//     }
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        // vector<vector<int>>dp(n+1,vector<int>(coins+1,-1));
        // return solve(0,coins,costs,dp);
        
        //Greedy solution
        sort(costs.begin(),costs.end());
        int count=0;
        int total=coins;
        for(int i=0;i<n;i++){
            if(costs[i]<=total){
                count++;
                total -= costs[i];
            }
        }
        return count;
    }
};