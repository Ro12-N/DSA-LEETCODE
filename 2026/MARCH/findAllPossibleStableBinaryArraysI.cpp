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



//Bottom up approach
class Solution {
public:
int dp[201][201][2];
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,0,sizeof(dp));
        int m=1e9+7;
        dp[0][0][0]=1;
        dp[0][0][1]=1;
        for(int o=0;o<=one;o++){
            for(int z=0;z<=zero;z++){
                if(o==0 &&z==0) continue;
                int res=0;
                for(int len=1;len<=min(limit,o);len++){
                    res=(res+dp[z][o-len][0])%m;
                }
                dp[z][o][1]=res;
                res=0;
                for(int len=1;len<=min(limit,z);len++){
                    res=(res+dp[z-len][o][1])%m;
                }
                dp[z][o][0]=res;

            }
        }
        int a=dp[zero][one][0];
        int b=dp[zero][one][1];
        return (a+b)%m;
    }
};

//TC: O(zero*one*limit) where zero is the number of zeros, one is the number of ones and limit is the maximum length of consecutive zeros or ones allowed in the binary array.
//SC: O(zero*one*limit) where zero is the number of zeros, one is the number of ones and limit is the maximum length of consecutive zeros or ones allowed in the binary array. This is because we are using a 3D dp array to store the results of subproblems, which has dimensions [zero+1][one+1][2].