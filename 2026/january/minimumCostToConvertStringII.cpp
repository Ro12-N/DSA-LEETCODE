class Solution {
public:
    string sourceStr;
    string targetStr;
    set<int> validLengths;
    vector<long long> dp;
    unordered_map<string, vector<pair<string,long long>>> adj;
    unordered_map<string, unordered_map<string,long long>> dijkstraMemo;
    const long long INF = 1e15;

    long long dij(string s, string e) {
        if(dijkstraMemo[s].count(e)) return dijkstraMemo[s][e];

        unordered_map<string,long long> dist;
        priority_queue<pair<long long,string>, vector<pair<long long,string>>, greater<>> pq;
        dist[s] = 0;
        pq.push({0, s});

        while(!pq.empty()) {
            long long d = pq.top().first;
            string node = pq.top().second;
            pq.pop();

            if(node == e) break;

            for(auto &edge : adj[node]) {
                string nextNode = edge.first;
                long long cost = edge.second;
                if(!dist.count(nextNode) || d + cost < dist[nextNode]) {
                    dist[nextNode] = d + cost;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        long long ans = dist.count(e) ? dist[e] : INF;
        return dijkstraMemo[s][e] = ans;
    }

    long long solve(int idx) {
        if(idx >= sourceStr.size()) return 0;
        if(dp[idx] != -1) return dp[idx];

        long long minCost = INF;

        if(sourceStr[idx] == targetStr[idx])
            minCost = solve(idx + 1);

        for(auto &len : validLengths) {
            if(idx + len > sourceStr.size()) break;

            string srcSub = sourceStr.substr(idx, len);
            string tgtSub = targetStr.substr(idx, len);

            if(!adj.count(srcSub)) continue;

            long long pathCost = dij(srcSub, tgtSub);
            if(pathCost == INF) continue;

            minCost = min(minCost, pathCost + solve(idx + len));
        }

        return dp[idx] = minCost;
    }

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        sourceStr = source;
        targetStr = target;

        dp.assign(source.size() + 1, -1);

        for(int i = 0; i < original.size(); i++) {
            adj[original[i]].push_back({changed[i], cost[i]});
            validLengths.insert(original[i].size());
        }

        long long ans = solve(0);
        return ans == INF ? -1 : ans;
    }
};
// Time Complexity: O(n * m^2 * log k) where n is the length of source string, m is the number of unique substrings and k is the average number of edges per node.
// Space Complexity: O(m^2)