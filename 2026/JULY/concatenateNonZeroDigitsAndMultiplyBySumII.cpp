class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        vector<long long> val(n, 0);
        vector<int> sum(n, 0), nz(n, 0);
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        int currSum = 0;
        long long currVal=0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            if (d != 0) {
                currVal = (currVal * 10 + d) % MOD;
                currSum += d;
                cnt++;
            }
            val[i] = currVal;
            sum[i] = currSum;
            nz[i] = cnt;
        }

        vector<int> res;
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int digitSum = sum[r] - (l ? sum[l - 1] : 0);
            int cntDigits = nz[r] - (l ? nz[l - 1] : 0);
            long long right = val[r];
            long long left = (l ? val[l - 1] : 0);

            long long number = (right - (left * pow10[cntDigits]) % MOD + MOD) % MOD;

            res.push_back((number * digitSum) % MOD);
        }

        return res;
    }
};
// Time Complexity: O(n + q) where n is the length of the string and q is the number of queries
// space Complexity: O(n) for storing val, sum, nz, and pow10 arrays