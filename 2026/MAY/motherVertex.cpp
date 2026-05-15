class Solution {
public:

    void dfs(int node,
             vector<int> adj[],
             vector<int>& vis) {

        vis[node] = 1;

        for(auto it : adj[node]) {

            if(!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }

    int findMotherVertex(int V, vector<vector<int>>& edges) {

        vector<int> adj[V];

        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        vector<int> vis(V, 0);

        int ans = 0;

        for(int i = 0; i < V; i++) {

            if(!vis[i]) {
                dfs(i, adj, vis);
                ans = i;
            }
        }


        fill(vis.begin(), vis.end(), 0);

        dfs(ans, adj, vis);

        for(int i = 0; i < V; i++) {

            if(!vis[i]) {
                return -1;
            }
        }

        return ans;
    }
};
// TC : O(V + E) where V is the number of vertices and E is the number of edges in the graph. This is because we perform a DFS traversal of the graph.
// SC : O(V) due to the visited array and the recursion stack used in DFS.