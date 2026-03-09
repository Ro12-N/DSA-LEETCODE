class Solution {
public:
int dp[201][201][2];
 int M;
int solve(int z,int o,int l,bool last){
    if(z==0 &&o==0) return 1;
    if(dp[z][o][last]!=-1) return dp[z][o][last];
    int res=0;
    if(last==true){
        for(int i=1;i<=min(l,o);i++){
            res=(res+solve(z,o-i,l,false))%M;
        }
    }else{
        for(int i=1;i<=min(l,z);i++){
            res=(res+solve(z-i,o,l,true))%M;
        }
    }
    return dp[z][o][last]= res;
}
    int numberOfStableArrays(int zero, int one, int limit) {
         M=1e9+7;
        memset(dp,-1,sizeof(dp));
      int startzero=solve(zero,one,limit,false)%M;
      int startone=solve(zero,one,limit,true)%M; 
      return (startzero+startone)  %M;
    }
};
//TC: O(zero*one*limit) where zero is the number of zeros, one is the number of ones and limit is the maximum length of consecutive zeros or ones allowed in the binary array.
//SC: O(zero*one*limit) where zero is the number of zeros, one is the number of ones and limit is the maximum length of consecutive zeros or ones allowed in the binary array. This is because we are using a 3D dp array to store the results of subproblems, which has dimensions [zero+1][one+1][2].