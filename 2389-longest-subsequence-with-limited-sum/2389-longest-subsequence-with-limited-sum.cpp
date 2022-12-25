class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<int>ans;
        sort(nums.begin(),nums.end());
        
       for(int i=0;i<m;i++){
           int sum=0;
           int j=0;
           while(j<n and sum+nums[j]<=queries[i]){
               sum=sum+nums[j];
               j++;
           }
           ans.push_back(j);
       }
        return ans;
    }
};