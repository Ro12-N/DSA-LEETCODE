class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0;
        int mini=INT_MAX;
        int cnt=0;
        long long sum=0;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]<0){
                    cnt++;
                }
                 mini=min(mini,abs(matrix[i][j]));
                sum+=abs(matrix[i][j]);
            }
        }
        if(cnt%2==1) sum-=2*mini;
        return sum;
    }
};
// Time Complexity: O(n*m) where n is the number of rows and m is the number of columns in the matrix.
// Space Complexity: O(1) as we are using only a constant amount of extra space