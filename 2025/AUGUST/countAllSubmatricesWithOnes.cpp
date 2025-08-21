class Solution {
public:
int solve(vector<int>&curr){
    int a=0;
    int b=0;
    for(auto i:curr){
        if(i) a++;
        else a=0;
        b+=a;
    }
    return b;
}
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>curr(m,1);
            for(int j=i;j<n;j++){
                for(int k=0;k<m;k++){
                    curr[k]=curr[k]&mat[j][k];
                }
                ans+=solve(curr);
            }
        }
        return ans;
    }
};