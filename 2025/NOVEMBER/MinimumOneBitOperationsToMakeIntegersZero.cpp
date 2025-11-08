class Solution {
public:
    int minimumOneBitOperations(int n) {
        vector<long long>dp(31,0);
        dp[0]=1;
        for(int i=1;i<31;i++){
            dp[i]=2*dp[i-1]+1;
        }
        int ans=0;
        bool sign =1;
        for(int i=30;i>=0;i--){
            int val=((1<<i) &n);
            if(val){
                if(sign) ans+=dp[i];
                else ans-=dp[i];
            sign=!sign;

            }
        }
        return ans;

    }
};