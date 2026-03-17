class Solution {
public:
 set<int>st;

void add(int sum){
    st.insert(sum);
    if(st.size()>3){
        st.erase(st.begin());
    }
}
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        st.clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                add(grid[i][j]);
        for(int side=1;i-side>=0 &&i+side<n &&j+side<m &&j-side>=0   ;side++){
                  int sum=0;
                  for(int k=0;k<=side-1;k++){
                        sum+=grid[i-side+k][j+k];  
                        sum+=grid[i+side-k][j-k];
                        sum+=grid[i-k][j-side+k];
                        sum+=grid[i+k][j+side-k];
                  }
                  add(sum);

                }
            }
        } 
        return vector<int>(st.rbegin(),st.rend()); 
    }
};
// Time Complexity: O(n*m*min(n,m)^2) where n and m are the dimensions of the grid, due to the nested loops and the calculation of rhombus sums.
// Space Complexity: O(1) for the set storing the sums, as it will contain at most 3 elements.


// Optimized version using prefix sums to calculate rhombus sums in O(1) time after O(n*m) preprocessing.
class Solution {
public:
 set<int>st;

void add(int sum){
    st.insert(sum);
    if(st.size()>3){
        st.erase(st.begin());
    }
}
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        st.clear();
        vector<vector<int>>dp1(n,vector<int>(m,0));
        vector<vector<int>>dp2(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp1[i][j]=grid[i][j];
                dp2[i][j]=grid[i][j];
                if(i-1>=0 &&j-1>=0){
                    dp1[i][j]+=dp1[i-1][j-1];
                }
                if(i-1>=0 &&j+1<m){
                    dp2[i][j]+=dp2[i-1][j+1];
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                add(grid[i][j]);
        for(int side=1;i-side>=0 &&i+side<n &&j+side<m &&j-side>=0   ;side++){
                  int sum=0;
                   int tr=i-side,tc=j;
                   int br=i+side,bc=j;
                   int lr=i,lc=j-side;
                   int rr=i,rc=j+side;

                   sum+=dp1[rr][rc];
                   if(tr-1>=0 &&tc-1>=0){
                    sum-=dp1[tr-1][tc-1];
                   }
                   sum+=dp2[br][bc];
                   if(rr-1>=0 &&rc+1<m){
                    sum-=dp2[rr-1][rc+1];
                   }
                   sum+=dp2[lr][lc];
                   if(tr-1 >=0 &&tc+1<m){
                    sum-=dp2[tr-1][tc+1];
                   }
                   sum+=dp1[br][bc];
                   if(lr-1>=0 &&lc-1>=0){
                    sum-=dp1[lr-1][lc-1];
                   }
                   sum-=(grid[tr][tc]+grid[br][bc]+grid[lr][lc]+grid[rr][rc]);
                  add(sum);

                }
            }
        } 
        return vector<int>(st.rbegin(),st.rend()); 
    }
};
// TC: O(n*m) for preprocessing the prefix sums and O(n*m*min(n,m)) for calculating the rhombus sums, but the sum calculation is O(1) due to prefix sums.
// SC: O(n*m) for the prefix sum arrays, and O(1) for the set storing the sums, as it will contain at most 3 elements.