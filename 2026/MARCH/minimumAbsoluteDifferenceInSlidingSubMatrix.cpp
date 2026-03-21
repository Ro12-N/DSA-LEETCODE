class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>ans(m-k+1,vector<int>(n-k+1,0));
        for(int i=0;i<=m-k;i++){
            for(int j=0;j<=n-k;j++){
                  set<int>st;
                for(int p=i;p<i+k;p++){
                    for(int q=j;q<j+k;q++){
                        st.insert(grid[p][q]);
                    }
                }
                if(st.size()==1){
                    continue;
                }
                int mini=INT_MAX;
                auto prev=st.begin();
                auto curr=next(prev);
                while(curr!=st.end()){
                    mini=min(mini,*curr-*prev);
                    prev=curr;
                    curr++;
                }
                ans[i][j]=mini;

            }
        }
        return ans;

    }
};
// TC : O((m−k)×(n−k)×k2×logk) where m is number of rows and n is number of columns and k is the size of the submatrix. We are iterating through all the submatrices of size k*k and for each submatrix we are calculating the minimum absolute difference.
// SC: O((m-k+1)*(n-k+1)) as we are using an extra 2D vector to store the answer for each submatrix of size k*k.