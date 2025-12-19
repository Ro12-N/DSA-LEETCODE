class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int, vector<pair<int,int>>> mp;
        
        for (auto &i : meetings) {
            int p = i[0], q = i[1], t = i[2];
            mp[p].push_back({q, t});
            mp[q].push_back({p, t});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int> ans(n, INT_MAX);

        pq.push({0, 0});
        pq.push({0, firstPerson});
        ans[0] = 0;
        ans[firstPerson] = 0;

        while (!pq.empty()) {
            auto [t, u] = pq.top();
            pq.pop();

            if (t > ans[u]) continue;

            for (auto [v, nt] : mp[u]) {
                if (nt >= t && ans[v] > nt) {
                    ans[v] = nt;
                    pq.push({nt, v});
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (ans[i] != INT_MAX)
                res.push_back(i);
        }

        return res;
    }
};

// Time Complexity: O(M log M)
// Space Complexity: O(N + M)