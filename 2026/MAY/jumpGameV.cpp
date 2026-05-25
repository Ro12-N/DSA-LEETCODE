class Solution {
public:
int n;
vector<int>dp;

int solve(vector<int>&arr,int i,int d){
    if(dp[i]!=-1) return dp[i];
    int res=1;
    for(int j=i-1;j>=max(0,i-d);j--){
        if(arr[j]>=arr[i]) break;
        res=max(res,1+solve(arr,j,d));
    }
    for(int j=i+1;j<=min(n-1,i+d);j++){
        if(arr[j]>=arr[i]) break;
        res=max(res,1+solve(arr,j,d));

    }
    return dp[i]= res;
}
    int maxJumps(vector<int>& arr, int d) {
        n=arr.size();
        dp.resize(n+1,-1);
        int ans=1;
        for(int i=0;i<n;i++){
            ans=max(ans,solve(arr,i,d));
        }
        return ans;
    }
};
// TC : O(n*d) where n is the size of the input array arr and d is the maximum distance we can jump as we are traversing the array once and for each element we are checking at most d elements on both sides
// SC : O(n) as we are using a dp array of size n to store the results of the subproblems and the recursion stack can go up to n in the worst case.