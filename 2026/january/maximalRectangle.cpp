class Solution {
public:
int n,m;
int solve(vector<int>curr){
    vector<int>ns(m,m);
    vector<int>ps(m,-1);
    vector<int>st;
    for(int i=0;i<m;i++){
      
      while(!st.empty() &&curr[st.back()]>curr[i]){
           int idx=st.back();
           st.pop_back();
           ns[idx]=i;
      }


      st.push_back(i);
    }
     for(int i=m-1;i>=0;i--){
      
      while(!st.empty() &&curr[st.back()]>curr[i]){
           int idx=st.back();
           st.pop_back();
           ps[idx]=i;
      }


      st.push_back(i);
    }
    int ans=0;
    for(int i=0;i<m;i++){
       ans=max(ans,curr[i]*(ns[i]-ps[i]-1));
    }
    return ans;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
         n=matrix.size();
         m=matrix[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(matrix[j][i]=='1') cnt++;
                else cnt=0;
                ans[j][i]=cnt;
            }
        }
        int res=0;
        for(auto i:ans){
            res=max(res,solve(i));
        }
        return res;
    }
};
// https://leetcode.com/problems/maximal-rectangle/description/
//Tc:O(n*m)
//Sc:O(m)