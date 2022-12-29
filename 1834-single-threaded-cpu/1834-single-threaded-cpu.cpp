class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        using pp=pair<int,pair<int,int>>;
        vector<pp>v;
        vector<int>res;
        
        for(int i=0;i<tasks.size();i++){
            v.push_back({tasks[i][0],{tasks[i][1],i}});
        }
        sort(v.begin(),v.end());
        int i=0;
        long long curr_time=v[i].first;
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        while(i<n || !pq.empty()){
            //available tasks at current time
            while(i<n and curr_time>=v[i].first){
                pq.push({v[i].second.first,{v[i].second.second,v[i].first}});
                i++;
            }
            curr_time=curr_time+pq.top().first;
            res.push_back(pq.top().second.first);
            pq.pop();
            if(i<n and curr_time<v[i].first and pq.empty()){
                curr_time=v[i].first;
            }
        }
        return res;
    }
};