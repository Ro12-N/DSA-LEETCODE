class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> minX(n+1, INT_MAX), maxX(n+1, INT_MIN);
        vector<int> minY(n+1, INT_MAX), maxY(n+1, INT_MIN);

        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            minX[y] = min(minX[y], x);
            maxX[y] = max(maxX[y], x);
            minY[x] = min(minY[x], y);
            maxY[x] = max(maxY[x], y);
        }

        int ans = 0;
        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            if (x == 1 || x == n || y == 1 || y == n) continue;

            if (minX[y] < x && x < maxX[y] &&
                minY[x] < y && y < maxY[x]) {
                ans++;
            }
        }
        return ans;
    }
};
