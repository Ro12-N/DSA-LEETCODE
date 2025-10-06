class Solution {
public:
int n,m;
vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
void solve(queue<pair<int,int>>&q,vector<vector<int>>&h,vector<vector<bool>>&oc){
    while(!q.empty()){
        auto [i,j]=q.front();
        q.pop();
        for(auto d:dir){
            int ni=i+d[0];
            int nj=j+d[1];
            if(ni>=0 &&nj>=0 &&ni<n &&nj<m &&!oc[ni][nj] && h[ni][nj]>=h[i][j]){
                oc[ni][nj]=true;
                q.push({ni,nj});
            }
        }
    }
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        vector<vector<bool>>pac(n,vector<bool>(m,false));
        vector<vector<bool>>at(n,vector<bool>(m,false));
        queue<pair<int,int>>p;
        queue<pair<int,int>>a;
        for(int j=0;j<m;j++){
            pac[0][j]=true;
            at[n-1][j]=true;
            p.push({0,j});
            a.push({n-1,j});
        }
        for(int i=0;i<n;i++){
            pac[i][0]=true;
            at[i][m-1]=true;
            p.push({i,0});
            a.push({i,m-1});
        }
        solve(p,heights,pac);
        solve(a,heights,at);
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j]&&at[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;

    }
};