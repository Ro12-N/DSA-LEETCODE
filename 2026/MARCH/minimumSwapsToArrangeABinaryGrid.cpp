class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>z(n,0);
        for(int i=0;i<n;i++){
            int cnt=0;
            int j=n-1;
            while(j>=0 &&grid[i][j]==0) {
                cnt++;
                j--;
            }
            z[i]=cnt;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int need=n-i-1;
            int j=i;
            while(j<n &&z[j]<need){
                j++;
            }
            if(j==n) return -1;
            ans+=j-i;
            while(j>i){
                swap(z[j],z[j-1]);
                j--;
            }

        }
        return ans;
    }
};
//TC: O(n^2) where n is the size of the grid
//SC: O(n) since we are using an additional vector to store the count of trailing