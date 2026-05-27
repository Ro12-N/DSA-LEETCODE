class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        vector<int>dp(n,0);
        dp[0]=1;
        int cnt=0;
        for(int j=1;j<n;j++){
            if(j-minJump>=0) cnt+=dp[j-minJump];
            if(j-maxJump-1>=0) cnt-=dp[j-maxJump-1];
            if(cnt>0 && s[j]=='0') dp[j]=1;
        }
        return dp[n-1]>0;
    }
};
// TC : O(n) where n is the size of the input string s as we are traversing the string once and for each character we are performing constant time operations
// SC : O(n) as we are using a dp array of size n to store the results of the subproblems and the cnt variable takes O(1) space.