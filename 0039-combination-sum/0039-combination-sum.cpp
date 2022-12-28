class Solution {
public:
    void solve(int i,int target,vector<int>& temp,vector<int>& candi,vector<vector<int>>& ans){
        if(i>=candi.size()){
            return;
        }
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0){
            return;
        }
        //2 cases- take,not take
        temp.push_back(candi[i]);
        solve(i,target-candi[i],temp,candi,ans);
        temp.pop_back();
        solve(i+1,target,temp,candi,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
         solve(0,target,temp,candidates,ans);
        return ans;
    }
};