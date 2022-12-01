class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
          vector<long> pref (nums.begin(), nums.end());
    
    for (int i = 1; i < n; i++) {
      pref[i] += pref[i-1];
    }
        long ind=-1;
        long diff=INT_MAX;
        long sum=pref[n-1];
        for(int i=0;i<n;i++){
            long pre=pref[i]/(i+1);
            
            long suff= i==n-1 ? 0 : (sum-pref[i])/(n-i-1);
           
            
            long chk=abs(pre-suff);
           
            if(diff>chk){
                diff=chk;
                ind=i;
            }
           
        }
        return ind;
    }
};