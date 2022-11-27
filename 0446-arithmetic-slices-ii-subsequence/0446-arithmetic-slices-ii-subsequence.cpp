class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        
        vector<unordered_map<long,long>>dp(n);
        
        long ans=0;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                
                long diff=(long)nums[i]-(long)nums[j];
                 
                //check kreynge ki kya ye diff jth element pr phle b aaya hai
                ans = ans + dp[j][diff];
                
                //store in map--> jitne diff phle aa chuke
                dp[i][diff] = dp[i][diff]+dp[j][diff];
                
                //ek jo ab aaya
                dp[i][diff]++;
                
            }
        }
        return ans;
    }
};