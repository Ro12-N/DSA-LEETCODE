class Solution {
public:
    #define p pair<double, int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<p> pq;

        for (int i = 0; i < n; i++) {
            double currpr = (double)classes[i][0] / classes[i][1];
            double newpr = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
            double delta = newpr - currpr;
            pq.push({delta, i});
        }

        while (extraStudents--) {
            auto [delta, idx] = pq.top();
            pq.pop();

            classes[idx][0]++;
            classes[idx][1]++;

            double currpr = (double)classes[idx][0] / classes[idx][1];
            double newpr = (double)(classes[idx][0] + 1) / (classes[idx][1] + 1);
            delta = newpr - currpr;
            pq.push({delta, idx});
        }

        double ans = 0.0;
        for (int i = 0; i < n; i++) {
            ans += (double)classes[i][0] / classes[i][1];
        }

        return ans / n;
    }
};
