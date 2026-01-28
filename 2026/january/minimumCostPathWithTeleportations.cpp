class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<vector<int>>> dist(
            m, vector<vector<int>>(n, vector<int>(k+1, INT_MAX))
        );

        vector<array<int,3>> cells;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cells.push_back({grid[i][j], i, j});
        sort(cells.begin(), cells.end());

        vector<int> ptr(k+1, 0);

        priority_queue<
            tuple<int,int,int,int>,
            vector<tuple<int,int,int,int>>,
            greater<>
        > pq;

        dist[0][0][0] = 0;
        pq.push({0, 0, 0, 0});

        int dirs[2][2] = {{1,0}, {0,1}};

        while (!pq.empty()) {
            auto [cost, i, j, t] = pq.top();
            pq.pop();

            if (i == m-1 && j == n-1) return cost;
            if (cost > dist[i][j][t]) continue;

            for (auto &d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni < m && nj < n) {
                    int ncost = cost + grid[ni][nj];
                    if (dist[ni][nj][t] > ncost) {
                        dist[ni][nj][t] = ncost;
                        pq.push({ncost, ni, nj, t});
                    }
                }
            }

            if (t < k) {
                while (ptr[t] < cells.size() &&
                       cells[ptr[t]][0] <= grid[i][j]) {

                    int x = cells[ptr[t]][1];
                    int y = cells[ptr[t]][2];

                    if (dist[x][y][t+1] > cost) {
                        dist[x][y][t+1] = cost;
                        pq.push({cost, x, y, t+1});
                    }
                    ptr[t]++;
                }
            }
        }

        return -1;
    }
};
// Time Complexity: O((m * n + k * m * n) log(m * n))
// Space Complexity: O(m * n * k)