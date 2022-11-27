class Solution {
public:
   void comb(int idx,int k,vector<int>& ip,vector<int>& op,vector<vector<int>>& ans){
        if(k==0){
            ans.push_back(op);
            return;
        }
        if(idx>=ip.size()){
            return;
        }
        op.push_back(ip[idx]);
        comb(idx+1,k-1,ip,op,ans);
        op.pop_back();
        comb(idx+1,k,ip,op,ans);
    }
    vector<vector<int>> combine(int n, int k) {
          vector<vector<int>> ans;
        vector<int> op;
        vector<int> ip;
        for(int i=1; i<=n; i++)
            ip.push_back(i);
        comb(0,k,ip,op,ans);
        return ans;
    }
};