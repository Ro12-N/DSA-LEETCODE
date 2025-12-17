class Solution {
public:
long long dp[1001][501][3];
long long solve(int i,vector<int>&prices,int c,int k){
    if(i>=prices.size()){
        if(c==0) return 0;
        return INT_MIN;
    }
    if(dp[i][k][c]!=INT_MIN) return dp[i][k][c];
    long long skip;
    skip=solve(i+1,prices,c,k);
    long long take=INT_MIN;
    if(k>0){
        //sell
        if(c==1)
        take=prices[i]+solve(i+1,prices,0,k-1);
        //buy
        else if(c==2)
        take=-prices[i]+solve(i+1,prices,0,k-1);
        //start
        else take=max(-prices[i]+solve(i+1,prices,1,k),prices[i]+solve(i+1,prices,2,k));
    }
    return dp[i][k][c] = max(take,skip);
}
    long long maximumProfit(vector<int>& prices, int k) {
       for(int i=0;i<1001;i++){
        for(int j=0;j<501;j++){
            for(int k=0;k<3;k++){
                dp[i][j][k]=INT_MIN;
            }
        }
       }
        return solve(0,prices,0,k);
        
    }
};

// Time Complexity: O(n*k)
// Space Complexity: O(n*k) for dp array

//bottom up approach

// class Solution {
// public:
//     long long maximumProfit(vector<int>& prices, int k) {
//         int n = prices.size();
//         static long long dp[1001][501][3];

//         // base case
//         for (int j = 0; j <= k; j++) {
//             dp[n][j][0] = 0;
//             dp[n][j][1] = INT_MIN;
//             dp[n][j][2] = INT_MIN;
//         }

//         for (int i = n - 1; i >= 0; i--) {
//             for (int j = 0; j <= k; j++) {

//                 // skip
//                 dp[i][j][0] = dp[i + 1][j][0];
//                 dp[i][j][1] = dp[i + 1][j][1];
//                 dp[i][j][2] = dp[i + 1][j][2];

//                 if (j > 0) {
//                     // sell
//                         dp[i][j][1] = max(
//                             dp[i][j][1],
//                             prices[i] + dp[i + 1][j - 1][0]
//                         );

//                     // buy
//                         dp[i][j][2] = max(
//                             dp[i][j][2],
//                             -prices[i] + dp[i + 1][j - 1][0]
//                         );
//                 }

//                 // transition to neutral
//                     dp[i][j][0] = max(dp[i][j][0], -prices[i] + dp[i + 1][j][1]);

//                     dp[i][j][0] = max(dp[i][j][0], prices[i] + dp[i + 1][j][2]);
//             }
//         }

//         return dp[0][k][0];
//     }
// };

//Time Complexity: O(n*k)
//Space Complexity: O(n*k)