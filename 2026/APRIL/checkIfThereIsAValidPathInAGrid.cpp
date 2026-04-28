class Solution {
public:
int m,n;
bool dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&vis,unordered_map<int,vector<vector<int>>>&mp){
    if(i==n-1 &&j==m-1) return true;
    vis[i][j]=true;
    for(auto &d:mp[grid[i][j]]){
        int ni=i+d[0];
        int nj=j+d[1];
        if(ni<0||nj<0||ni>=n||nj>=m||vis[ni][nj]) continue;
        for(auto &nxt:mp[grid[ni][nj]]){
            if(ni+nxt[0]==i && nj+nxt[1]==j){
                if(dfs(grid,ni,nj,vis,mp))return true;
            }
        }
    }
    return false;

}
    bool hasValidPath(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
        unordered_map<int,vector<vector<int>>>mp={
            {1,{{0,-1},{0,1}}},
            {2,{{-1,0},{1,0}}},
            {3,{{0,-1},{1,0}}},
            {4,{{0,1},{1,0}}},
             {5,{{0,-1},{-1,0}}},
              {6,{{-1,0},{0,1}}}

        };
        vector<vector<int>>vis(n,vector<int>(m,0));
        return dfs(grid,0,0,vis,mp);

    }
};
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)