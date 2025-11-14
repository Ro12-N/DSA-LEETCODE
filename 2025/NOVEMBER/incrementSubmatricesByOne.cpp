class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        for(auto i:queries){
            int r1=i[0];
            int c1=i[1];
            int r2=i[2];
            int c2=i[3];
            for(int j=r1;j<=r2;j++){
                ans[j][c1]+=1;
                if(c2+1<n) ans[j][c2+1]-=1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                ans[i][j]+=ans[i][j-1];
            }
        }
        return ans;
    }
};

//tc : O(q + n^2) where q is the number of queries
//sc : O(1) ignoring the space required for the answer matrix