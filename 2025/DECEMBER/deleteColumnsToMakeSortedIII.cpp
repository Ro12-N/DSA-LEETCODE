class Solution {
public:
bool solve(vector<string> &strs,int i,int j){
    int n=strs.size();
    int m=strs[0].size();
   for(int k=0;k<n;k++){
      if(strs[k][j]>strs[k][i]) return false;
   }
  return true;
}
    int minDeletionSize(vector<string>& strs) {
        int n=strs[0].size();
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(strs[0][j]<=strs[0][i])
                     if(solve(strs,i,j))
                    dp[i]=max(dp[i],dp[j]+1);
            }
        }
        return n- *max_element(dp.begin(),dp.end());
    }
};
// Time Complexity: O(N^2 * M)
// Space Complexity: O(N)