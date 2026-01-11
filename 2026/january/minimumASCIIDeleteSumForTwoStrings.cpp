class Solution {
public:
    int n, m;
    int dp[1001][1001];

    int solve(int i, int j, string &s1, string &s2) {
        if (i == n && j == m) return 0;

        if (i == n) {
            int sum = 0;
            for (int k = j; k < m; k++) sum += s2[k];
            return sum;
        }

        if (j == m) {
            int sum = 0;
            for (int k = i; k < n; k++) sum += s1[k];
            return sum;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = solve(i + 1, j + 1, s1, s2);

        int deli = s1[i] + solve(i + 1, j, s1, s2);
        int delj = s2[j] + solve(i, j + 1, s1, s2);

        return dp[i][j] = min(deli, delj);
    }

    int minimumDeleteSum(string s1, string s2) {
        n = s1.size();
        m = s2.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s1, s2);
    }
};

// Time Complexity: O(n*m)
// Space Complexity: O(n*m)
