class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        
        int start = 0;
        for(char c : s)
            if(c == '0') start++;

        vector<int> dist(n + 1, -1);
        vector<set<int>> remaining(2);

        for(int i = 0; i <= n; i++)
            remaining[i % 2].insert(i);

        queue<int> q;
        q.push(start);
        dist[start] = 0;
        remaining[start % 2].erase(start);

        while(!q.empty()) {
            int m = q.front();
            q.pop();

            if(m == 0) return dist[m];

            int minZeros = max(0, k - (n - m));
            int maxZeros = min(m, k);

            int lnode = m + k - 2 * maxZeros;
            int rnode = m + k - 2 * minZeros;

            auto &st = remaining[lnode % 2];

            auto it = st.lower_bound(lnode);
            while(it != st.end() && *it <= rnode) {
                int next = *it;
                dist[next] = dist[m] + 1;
                q.push(next);
                it = st.erase(it);
            }
        }

        return -1;
    }
};
// TC: O(n) where n is the length of the input string, since in the worst case we might need to visit each possible number of zeros in the string.
// SC: O(n) since we are using a queue to store the states and a vector to store the distances, both of which can grow up to the size of n