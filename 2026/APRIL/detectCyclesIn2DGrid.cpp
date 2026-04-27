class Solution {
public:
    bool dfs(int x, int y, int px, int py,
             vector<vector<char>>& grid,
             vector<vector<int>>& vis) {

        vis[x][y] = 1;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        for(auto &d : dirs) {
            int nx = x + d[0];
            int ny = y + d[1];

            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny] == grid[x][y]) {

                if(!vis[nx][ny]) {
                    if(dfs(nx, ny, x, y, grid, vis)) return true;
                }
                else if(nx != px || ny != py) {
                    return true;
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j]) {
                    if(dfs(i, j, -1, -1, grid, vis))
                        return true;
                }
            }
        }
        return false;
    }
};
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)