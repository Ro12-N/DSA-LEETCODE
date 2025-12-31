class Solution {
public:
    bool canCross(int r, int c, int mid, vector<vector<int>>& cells) {
        vector<vector<int>> grid(r + 1, vector<int>(c + 1, 0));

        for (int i = 0; i <= mid; i++) {
            grid[cells[i][0]][cells[i][1]] = 1;
        }

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(r + 1, vector<bool>(c + 1, false));

        for (int j = 1; j <= c; j++) {
            if (grid[1][j] == 0) {
                q.push({1, j});
                vis[1][j] = true;
            }
        }

        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == r) return true;

            for (auto &d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx >= 1 && nx <= r && ny >= 1 && ny <= c &&
                    !vis[nx][ny] && grid[nx][ny] == 0) {
                    
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int s = 0, e = cells.size() - 1;
        int ans = 0;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (canCross(row, col, mid, cells)) {
                ans = mid + 1;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
};

//Time Complexity: O(row * col * log(row * col))
//Space Complexity: O(row * col)
