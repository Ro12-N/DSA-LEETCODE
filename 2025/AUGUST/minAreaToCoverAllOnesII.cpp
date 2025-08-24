class Solution {
public:

long long solve(vector<vector<int>>&grid,int sr,int er,int sc,int ec){
    int a=INT_MAX;
    int b=0;
    int c=INT_MAX;
    int d=0;
    for(int i=sr;i<er;i++){
        for(int j=sc;j<ec;j++){
            if(grid[i][j]){
                a=min(a,i);
                b=max(b,i);
                c=min(c,j);
                d=max(d,j);

            }
        }
    }
    if(a==INT_MAX) return 0;
    return 1LL*(b-a+1)*(d-c+1);
}
void rotate(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
         vector<vector<int>> rotated(m, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rotated[j][n - 1 - i] = grid[i][j];
        }
       }
       grid=rotated;
    }


long long pro(vector<vector<int>>&grid){
      int n = grid.size();
        int m = grid[0].size();
    int res=INT_MAX;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            int t=solve(grid,0,i,0,m);
            int d=solve(grid,i,n,0,j);
            int o=solve(grid,i,n,j,m);
            res=min(res,(t+d+o));

              t=solve(grid,0,i,0,j);
             d=solve(grid,0,i,j,m);
             o=solve(grid,i,n,0,m);
              res=min(res,(t+d+o));
        }
    }

    for(int i=1;i<n;i++){
        for(int j=i+1;j<n;j++){
            int t=solve(grid,0,i,0,m);
            int d=solve(grid,i,j,0,m);
            int o=solve(grid,j,n,0,m);
            res=min(res,(t+d+o));
        }
    }


    return res;
}
    int minimumSum(vector<vector<int>>& grid) {
        long long res=pro(grid);
         rotate(grid);
     res=min(res,pro(grid));
        return res;
    }
};