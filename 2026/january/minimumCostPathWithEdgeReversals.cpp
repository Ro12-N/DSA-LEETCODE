class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<vector<int>>>mp;
        for(auto i:edges){
            int s=i[0];
            int e=i[1];
            int v=i[2];
            mp[s].push_back({e,v});
            mp[e].push_back({s,2*v});
        }
        vector<int>dist(n,INT_MAX);
        dist[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto [dt,curr]=pq.top();
            pq.pop();
            if(curr==n-1) return dt;
            if(dt>dist[curr]) continue;
            for(auto j:mp[curr]){
                int w=j[1];
                int nxt=j[0];
                if(dt+w<dist[nxt]){
                    dist[nxt]=dt+w;
                    pq.push({dist[nxt],nxt});
                }
            }
        }
        return dist[n-1]==INT_MAX?-1:dist[n-1];
    }
};
// Time Complexity: O((n + e) log n) where n is number of nodes and e is number of edges
// Space Complexity: O(n + e)here sorting is done in place.