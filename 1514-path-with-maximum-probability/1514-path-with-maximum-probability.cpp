class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<double,int>> graph[n];
        vector<double> prob(n,0);
        prob[start]=1;
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({succProb[i],edges[i][1]});
            graph[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }
        priority_queue<pair<double,int>> pq;
        pq.push({1,start});
        while(!pq.empty()){
            auto i=pq.top();
            pq.pop();
            double p=i.first;
            int u=i.second;
            for(auto it:graph[u]){
                if(prob[it.second]<p*it.first){
                    prob[it.second]=p*it.first;
                    pq.push({prob[it.second],it.second});
                }
            }
            
        }
        
        return prob[end];
    }
};