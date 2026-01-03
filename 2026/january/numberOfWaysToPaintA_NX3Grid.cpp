class Solution {
public:
vector<string>rows;
int mod=1e9+7;
int N;
vector<vector<int>>dp;
int color(int prev,int remain){
    if(remain==0) return 1;
    if(dp[prev][remain]!=-1) return dp[prev][remain];
    string prevstring=rows[prev];
    int ways=0;
    for(int i=0;i<rows.size();i++){
        if(i==prev)continue;
        string curr=rows[i];
        bool notfound=true;
        for(int j=0;j<3;j++){
            if(prevstring[j]==curr[j]){
                notfound=false;
                break;
            }
        }
        if(notfound) ways=(ways+color(i,remain-1))%mod;
    }
    return dp[prev][remain]= ways;
}
void solve(string temp){
    if(temp.size()==3){
        rows.push_back(temp);
        return;
    }
    for(auto ch:{'G','Y','R'}){
        if(!temp.empty() && temp.back()==ch) continue;
        solve(temp+ch);
    }
}
    int numOfWays(int n) {
        string temp="";
        solve(temp);
        int K=rows.size();
        dp.assign(K+1,vector<int>(n+1,-1));
        int res=0;
        N=n;
        for(int i=0;i<K;i++){
            res=(res+color(i,n-1))%mod;
        }
        return res;
    }
};
