class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>rowsum(n,vector<int>(m,0));
        vector<vector<int>>colsum(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            rowsum[i][0]=grid[i][0];
            for(int j=1;j<m;j++){
                rowsum[i][j]=rowsum[i][j-1]+grid[i][j];
            }
        }
        for(int j=0;j<m;j++){
            colsum[0][j]=grid[0][j];
            for(int i=1;i<n;i++){
              colsum[i][j]=colsum[i-1][j]+grid[i][j];
            }
        }
        for(int s=min(m,n);s>=2;s--){

            for(int i=0;i+s-1<n;i++){
                for(int j=0;j+s-1<m;j++){
                  int target=rowsum[i][j+s-1]-((j>0)?rowsum[i][j-1]:0);
                  bool f=false;
                  for(int k=i+1;k<i+s;k++){
                    int currsum=rowsum[k][j+s-1]-(j>0?rowsum[k][j-1]:0);
                     if(currsum!=target){
                        f=true;
                        break;
                     }
                  }
                  if(f) continue;


                 for(int k=j;k<j+s;k++){
                    int currsum=colsum[i+s-1][k]-(i>0?colsum[i-1][k]:0);
                     if(currsum!=target){
                        f=true;
                        break;
                     }
                 }
                  if(f) continue;
                  int dia=0;
                int antidia=0;
                for(int k=0;k<s;k++){
                    dia+=grid[i+k][j+k];
                    antidia+=grid[i+k][j+s-1-k];
                }
                if(dia!=antidia || dia!=target) continue;
                return s;
                }
                
                
            }
        }
        return 1;

    }
};
// https://leetcode.com/problems/largest-magic-square/description/
// Tc:O(min(n,m)^3) 
// Sc:O(n*m)o;