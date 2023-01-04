class Solution {
public:
    int solve(int num,vector<int>& dp){
       if(num==2){
           return 1;
       }
        if(num==3){
            return 1;
        }
        if(num==1){
            return INT_MAX;
        }
        if(dp[num]!=-1){
            return dp[num];
        }
        return dp[num]=1+min(solve(num-2,dp),solve(num-3,dp));
        
        
    }
    int minimumRounds(vector<int>& tasks) {
        int n=tasks.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[tasks[i]]++;
            
        }
        vector<int>freq;
        int mx=0;
        for(auto it:mp){
            freq.push_back(it.second);
            mx=max(mx,it.second);
        }
        int m=freq.size();
        int count=0;
        vector<int>dp(100005,-1);
        for(int i=0;i<m;i++){
            if(freq[i]==1){
                return -1;
            }
            int cnt_per_element=solve(freq[i],dp);
            if(cnt_per_element==INT_MAX){
                return -1;
            }
            count=count+cnt_per_element;
        }
        return count;
    }
};