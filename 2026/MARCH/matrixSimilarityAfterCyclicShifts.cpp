class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        k=k%m;
        if(k==0) return true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sh=0;
                if(i%2){
                    sh=(j-k+m)%m;

                }else{
                  sh=(j+k)%m;
                }
                if(mat[i][j]!=mat[i][sh]) return false;
            }
        }


        return true;
    }
};
// Time Complexity: O(n * m)
// Space Complexity: O(1)