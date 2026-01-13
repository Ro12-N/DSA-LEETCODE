class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        for(int i=1;i<points.size();i++){
            int a=points[i-1][0];
            int b=points[i-1][1];
            int c=points[i][0];
            int d=points[i][1];
             int p=abs(a-c);
             int q=abs(b-d);
             ans+=min(p,q)+abs(p-q);
        }
        return ans;
    }
};

// https://leetcode.com/problems/minimum-time-visiting-all-points/description/
// Tc:O(n)
// Sc:O(1)