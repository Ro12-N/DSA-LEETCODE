class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       vector<vector<int>>ans(n,vector<int>(m,1));
       long long sf=1,pf=1;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[i][j]=pf;
            pf=(pf*grid[i][j])%12345;

        }
       } 
       for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            ans[i][j]=(ans[i][j]*sf)%12345;
            sf=(sf*grid[i][j])%12345;
        }
       }
       return ans;
    }
};
// TC: O(n*m) where n and m are the dimensions of the grid. We are iterating through each cell of the grid twice, once for calculating the prefix product and once for calculating the suffix product.
// SC: O(n*m) for the ans matrix. We are storing the product of all elements except the current one for each cell in the ans matrix.