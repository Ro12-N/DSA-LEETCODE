class Solution {
public:
    int n, m;
    bool solve(vector<vector<long long>>& v, int threshold, int s) {
        if (s == 0) return true;
        for (int i = 0; i + s - 1 < n; i++) {
            for (int j = 0; j + s - 1 < m; j++) {
                long long ts = 0;
                for (int k = i; k < i + s; k++) {
                    ts += v[k][j + s - 1] - (j > 0 ? v[k][j - 1] : 0);
                }
                if (ts <= threshold) return true;
            }
        }
        return false;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        n = mat.size();
        m = mat[0].size();

        vector<vector<long long>> v(n, vector<long long>(m, 0));

        for (int i = 0; i < n; i++) {
            v[i][0] = mat[i][0];
            for (int j = 1; j < m; j++) {
                v[i][j] = v[i][j - 1] + mat[i][j];
            }
        }

        int low = 0, high = min(n, m), ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (solve(v, threshold, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
// https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description/
// Tc:O(n*m*log(min(n,m)))  
// Sc:O(n*m)