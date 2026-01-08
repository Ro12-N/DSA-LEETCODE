class Solution {
public:
int n,m;
int dp[501][501];
int solve(int i,int j,vector<int>&a,vector<int>&b){
    if(i==m||j==n) return -1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    int take=(a[i]*b[j])+max(0,solve(i+1,j+1,a,b));
    int si=solve(i+1,j,a,b);
    int sj=solve(i,j+1,a,b);
    return dp[i][j]= max({take,si,sj});
}
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m=nums1.size();
        n=nums2.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,nums1,nums2);
    }
};

// Time Complexity: O(M*N) where M and N are the sizes of nums1 and nums2 respectively
// Space Complexity: O(M*N)