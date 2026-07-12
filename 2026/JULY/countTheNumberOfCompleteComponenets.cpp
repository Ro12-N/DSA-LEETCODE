class Solution {
public:
void dfs(int src,unordered_map<int,vector<int>>&mp,vector<bool>&vis,int &chk,int &cnt){  
     vis[src]=true;
     chk++;
      cnt+=mp[src].size();
     for(auto i:mp[src]){
        if(!vis[i]){
            dfs(i,mp,vis,chk,cnt);
        }
     }
      
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>mp;
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        int ans=0;
       vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int cnt=0;
                int ed=0;
                dfs(i,mp,vis,ed,cnt);
                ans+=((ed*(ed-1))==cnt);
            }
        }
        return ans;
    }
};
// Time Complexity: O(n + e) where n is the number of nodes and e is the number of edges in the graph
// Space Complexity: O(n + e) for storing the adjacency list and the visited array