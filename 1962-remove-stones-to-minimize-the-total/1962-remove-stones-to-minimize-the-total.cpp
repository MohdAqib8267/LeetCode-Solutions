class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n=piles.size();
        
        //maxheap
        priority_queue<int,vector<int>>pq;
        
        for(int i=0;i<n;i++){
            pq.push(piles[i]);
        }
        
        while(!pq.empty() and k--){
            int temp=pq.top();
            pq.pop();
            if(temp%2 == 0){
                pq.push(temp/2);
            }
            else{
                pq.push((temp/2)+1);
            }
        }
        int ans=0;
        while(!pq.empty()){
            ans=ans+pq.top();
            pq.pop();
        }
        return ans;
    }
};