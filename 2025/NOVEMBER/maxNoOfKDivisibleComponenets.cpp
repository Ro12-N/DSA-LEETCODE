class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int,vector<int>>mp; 
        for(auto i:edges){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        queue<int>q;
        vector<int>nbr(n);
        for(int i=0;i<n;i++){
            nbr[i]=mp[i].size();
            if(nbr[i]==1) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            nbr[front]--;
            if(values[front]%k==0) cnt++;
            for(auto v:mp[front]){
                if(nbr[v]!=0){
                    values[v]+=(values[front]%k);
                    if(--nbr[v]==1) q.push(v);
                }
            }
        }
        return cnt==0?1:cnt;
    }
};