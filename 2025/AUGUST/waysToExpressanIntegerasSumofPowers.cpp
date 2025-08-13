class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>> dp;
    vector<int> powers;

    int solve(int n, int idx) {
        if (n == 0) return 1;
        if (idx >= powers.size() || n < 0) return 0;
        
        if (dp[n][idx] != -1) return dp[n][idx];

        int take = solve(n - powers[idx], idx + 1) % mod;
      
        int skip = solve(n, idx + 1) % mod;

        return dp[n][idx] = (take + skip) % mod;
    }

    int numberOfWays(int n, int x) {
        for (int i = 1; pow(i, x) <= n; i++) {
            powers.push_back((int)pow(i, x));
        }
        dp.assign(n + 1, vector<int>(powers.size(), -1));
        return solve(n, 0);
    }
};
