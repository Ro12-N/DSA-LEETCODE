class Solution {
public:
int n,m;
vector<vector<pair<long long,long long>>>dp;
pair<long long,long long>solve(vector<vector<int>>&grid,int i,int j){
    if(i==n-1 &&j==m-1){
        return {grid[i][j],grid[i][j]};
    }
    if(dp[i][j]!=make_pair(LLONG_MIN,LLONG_MAX)) return dp[i][j];
    long long mx=LLONG_MIN;
    long long mn=LLONG_MAX;
    if(i+1<n){
        auto [dmx,dmn]=solve(grid,i+1,j);
        mx=max({mx,dmx*grid[i][j],dmn*grid[i][j]});
        mn=min({mn,dmx*grid[i][j],dmn*grid[i][j]});
    }
    if(j+1<m){
        auto [rmx,rmn]=solve(grid,i,j+1);
        mx=max({mx,rmx*grid[i][j],rmn*grid[i][j]});
        mn=min({mn,rmx*grid[i][j],rmn*grid[i][j]});
    }
    return dp[i][j]= {mx,mn};
}
    int maxProductPath(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
    dp=vector<vector<pair<long long,long long>>>(n,vector<pair<long long,long long>>(m,{LLONG_MIN,LLONG_MAX}));
        auto [pos,neg]=solve(grid,0,0);
        const int mod=1e9+7;
        return pos<0?-1:(pos)%mod;
    }
};
// TC : O(n*m) where n and m are the dimensions of the grid. We are visiting each cell of the grid once.
// SC: O(n*m) for the dp array and O(n+m) for the recursion stack. The dp array stores the maximum and minimum product for each cell, and the recursion stack can go as deep as n+m in the worst case.


// Tabulation approach
// Bottom-up approach where we fill the dp table iteratively starting from the bottom-right corner of the grid. We calculate the maximum and minimum product for each cell based on the values from the right and down cells. Finally, we return the maximum product from the top-left cell of the dp table.
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
vector<vector<pair<long long,long long>>>dp(n,vector<pair<long long,long long>>(m));
        dp[n-1][m-1]={grid[n-1][m-1],grid[n-1][m-1]};
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 &&j==m-1) continue;
                long long mx=LLONG_MIN;
                long long mn=LLONG_MAX;
                if(i+1<n){
                    auto [dmx,dmn]=dp[i+1][j];
        mx=max({mx,dmx*grid[i][j],dmn*grid[i][j]});
        mn=min({mn,dmx*grid[i][j],dmn*grid[i][j]});
                }
                if(j+1<m){
                   auto [rmx,rmn]=dp[i][j+1];
        mx=max({mx,rmx*grid[i][j],rmn*grid[i][j]});
        mn=min({mn,rmx*grid[i][j],rmn*grid[i][j]});  
                }
                dp[i][j]={mx,mn};

            }
        }
        const int mod=1e9+7;
        return dp[0][0].first<0?-1:(dp[0][0].first%mod);

          
    }
};
// TC : O(n*m) where n and m are the dimensions of the grid. We are filling each cell of the dp table once.
// SC: O(n*m) for the dp array. The dp array stores the maximum and minimum product for each cell.