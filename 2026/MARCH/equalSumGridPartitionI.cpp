class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        long long ts=0;
        vector<long long>r(n,0);
        vector<long long>c(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ts+=grid[i][j];
                r[i]+=grid[i][j];
                c[j]+=grid[i][j];
            }
        }
        long long rs=0;
        long long cs=0;
        for(int i=0;i<n;i++){
            rs+=r[i];
            if(rs*2==ts) return true;
        }
        for(int j=0;j<m;j++){
            cs+=c[j];
            if(cs*2==ts) return true;
        }
        return false;
    }
};