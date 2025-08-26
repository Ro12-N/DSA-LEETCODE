class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        unordered_map<int,vector<int>>mp;
        int m=mat[0].size();
        int n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int>ans;
        for(int i=0;i<m+n-1;i++){
            if(i%2==0){
                   reverse(mp[i].begin(),mp[i].end());
            }
            ans.insert(ans.end(),mp[i].begin(),mp[i].end());
        }
     return ans;

    }
};