class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long maxDiagSq = 0; 
        int ans = 0;
        
        for (auto &dim : dimensions) {
            long long a = dim[0], b = dim[1];
            long long diagSq = a*a + b*b;
            int area = a * b;
            
            if (diagSq > maxDiagSq) {
                maxDiagSq = diagSq;
                ans = area;
            } else if (diagSq == maxDiagSq) {
                ans = max(ans, area);
            }
        }
        return ans;
    }
};
