class Solution {
public:
void mark(int m, int n, vector<vector<int>>& grid){
    for(int i=m-1;i>=0;i--){
        if(grid[i][n]==-1 || grid[i][n]==-2) break;
        else grid[i][n]=1;
    }
    for(int i=m+1;i<grid.size();i++){
        if(grid[i][n]==-1 || grid[i][n]==-2) break;
        else grid[i][n]=1;
    }
    for(int i=n-1;i>=0;i--){
        if(grid[m][i]==-1 || grid[m][i]==-2) break;
        else grid[m][i]=1;
    }
    for(int i=n+1;i<grid[0].size();i++){
        if(grid[m][i]==-1 || grid[m][i]==-2) break;
        else grid[m][i]=1;
    }
}
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m,vector<int>(n,0));
        for(auto i:guards){
            grid[i[0]][i[1]]=-1;
        }
        for(auto i:walls){
            grid[i[0]][i[1]]=-2;
        }
         for(auto i:guards){
            mark(i[0],i[1],grid);
         }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) cnt++;
            }
        }
        return cnt;
    }
};