class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int side=0;
        int n=bottomLeft.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int topx=min(topRight[i][0],topRight[j][0]);
                int botx=max(bottomLeft[i][0],bottomLeft[j][0]);
                int s=topx-botx;

                int boty=max(bottomLeft[i][1],bottomLeft[j][1]);
                int topy=min(topRight[i][1],topRight[j][1]);
                int a=topy-boty;

                int f=min(s,a);
                ans=max(ans,f);
            }
        }
        return 1LL*ans*ans;
    }
};
// https://leetcode.com/problems/find-the-largest-area-of-a-square-inside-two-rectangles/description/
// Tc:O(n^2)
// Sc:O(1)