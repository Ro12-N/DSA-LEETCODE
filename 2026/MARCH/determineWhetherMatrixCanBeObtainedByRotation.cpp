class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        for(int k=0;k<4;k++){
            if(mat==target) return true;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    swap(mat[i][j],mat[j][i]);
                }
                reverse(mat[i].begin(),mat[i].end());
            }
        }
        return false;
    }
};
// TC : O(n^2) where n is the size of the matrix. We are iterating through all the elements of the matrix to rotate it.
// SC: O(1) as we are rotating the matrix in place without using any extra space.