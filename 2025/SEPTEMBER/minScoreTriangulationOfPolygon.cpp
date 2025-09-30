class Solution {
public:
int dp[51][51];
int solve(vector<int>&v,int i,int j){
     if(j-i+1<3) return 0;
     if(dp[i][j]!=-1) return dp[i][j];
     int ans=INT_MAX;
    for(int k=i+1;k<j;k++){
        int wt=v[i]*v[j]*v[k]+solve(v,i,k)+solve(v,k,j);
        ans=min(ans,wt);
    }
    return dp[i][j]= ans;
}
    int minScoreTriangulation(vector<int>& values) {
         int n=values.size();
         memset(dp,-1,sizeof(dp));
         return solve(values,0,n-1);
    }
};