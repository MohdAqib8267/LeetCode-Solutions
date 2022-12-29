class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
          int n = weights.size();
        //optimize search bounds
        int l=0,r=0,ans;
        for(int x:weights){
            l=max(l,x),r+=x;
        }
        ans =r;
        while(l<r){
            //can I ship all stuff in time if the capcity is "mid"?
            int mid = (l+r)/2,d=1,cur = 0;
            for(int i = 0;i<n;i++){
                if(cur+weights[i]<=mid)cur+=weights[i];
                else {
                    d++;
                    cur = weights[i];
                }
            }
            if(d<=days){
                ans = mid;
                r = mid;
            }
            else l = mid+1;
        }
        return ans;
    }
};