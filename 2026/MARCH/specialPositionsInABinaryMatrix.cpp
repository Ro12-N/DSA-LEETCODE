class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>r(n);
        vector<int>c(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                r[i]+=mat[i][j];
                c[j]+=mat[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1 && r[i]==1 &&c[j]==1) ans++;
            }
        }
        return ans;
    }
};
//TC: O(n*m) where n is the number of rows and m is the number of columns in the matrix
//SC: O(n+m) since we are using two additional arrays of size n and m