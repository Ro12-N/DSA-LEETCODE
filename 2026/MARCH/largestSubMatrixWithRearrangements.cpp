class Solution {
public:
int solve(vector<int>curr){
    int n=curr.size();
    vector<int>ns(n,n);
    vector<int>ps(n,-1);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && curr[st.top()]>curr[i]){
            int idx=st.top();
            st.pop();
            ns[idx]=i;
        }
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && curr[st.top()]>curr[i]){
            int idx=st.top();
            st.pop();
            ps[idx]=i;
        }
        st.push(i);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,curr[i]*(ns[i]-ps[i]-1));
    }
    return ans;
}
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>curr(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            int cnt=0;
            for(int i=0;i<n;i++){
                if(matrix[i][j]==1) cnt++;
                else cnt=0;
                curr[i][j]=cnt;
            }
        }
        int res=0;
        for(auto &i:curr){
           sort(i.begin(),i.end());
           res=max(res,solve(i));
        }


        return res;
    }
};
// TC: O(n*m*log(m)) where n is number of rows and m is number of columns
// SC: O(n*m) for the curr matrix and O(m) for the stack and the ns and ps arrays.