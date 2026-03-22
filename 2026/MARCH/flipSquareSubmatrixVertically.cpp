class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
         for(int i=0;i<k/2;i++){
            for(int j=0;j<k;j++){
                swap(grid[i+x][y+j],grid[x-i+k-1][y+j]);
            }
         }
         return grid;
        
    }
};
// TC : O(k^2) where k is the size of the submatrix. We are iterating through all the elements of the submatrix to reverse it.
// SC: O(1) as we are reversing the submatrix in place without using any extra space.