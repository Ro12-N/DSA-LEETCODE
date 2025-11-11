class Solution {
public:
int dp[601][101][101];
pair<int,int> solve(string s){
    int one=0;
    int zero=0;
    for(auto i:s){
        if(i=='1') one++;
        else zero++;
    }
    return {zero,one};
}
int solve(vector<pair<int,int>>&ans,int idx,int m,int n){
     if(idx>=ans.size()) return 0;
     if(dp[idx][m][n]!=-1) return dp[idx][m][n];
     int a=ans[idx].first;
     int b=ans[idx].second;
     int take=0;
     if(a<=m &&b<=n){
        take=1+solve(ans,idx+1,m-a,n-b);
     }
     return dp[idx][m][n] =max(take,solve(ans,idx+1,m,n));
}
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>ans;
        for(auto i:strs){
            ans.push_back(solve(i));
        }
        memset(dp,-1,sizeof(dp));
        return solve(ans,0,m,n);

    }
};