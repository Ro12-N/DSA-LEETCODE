class Solution {
public:
void solve(int src,unordered_map<int,vector<vector<int>>>&mp,vector<bool>&vis,int &ans){
     vis[src]=true;
     for(auto i:mp[src]){
        int nxt=i[0];
        int c=i[1];
        ans=min(ans,c);
        if(!vis[nxt]){
            solve(nxt,mp,vis,ans);
        }
     }
}
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<vector<int>>>mp;
        for(auto i:roads){
            mp[i[0]].push_back({i[1],i[2]});
            mp[i[1]].push_back({i[0],i[2]});
        }
        int ans=INT_MAX;
        vector<bool>vis(n,false);
        solve(1,mp,vis,ans);
        return ans;
    }
};
// Time Complexity: O(n+e) where n is the number of nodes and e is the number of edges in the graph. This is because we are performing a depth-first search (DFS) traversal of the graph, which visits each node and edge once.
// Space Complexity: O(n+e) where n is the number of nodes and e is the number of edges in the graph. This is because we are using an adjacency list to represent the graph, which requires O(n+e) space, and a visited array of size n to keep track of visited nodes during the DFS traversal.