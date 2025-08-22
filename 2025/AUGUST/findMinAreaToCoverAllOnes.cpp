class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
         int n=grid.size();
         int m=grid[0].size();
         int a=n;
         int b=-1;
         int c=m;
         int d=-1;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    a=min(a,i);
                    b=max(b,i);
                    c=min(c,j);
                    d=max(d,j);
                }
            }
         }
         return (b-a+1)*(d-c+1);
    }
};