class Solution {
public:
typedef tuple<int,int,int> T;
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
        priority_queue<T>pq;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vis[0][0]=true;
        pq.push({health-grid[0][0],0,0});
        while(!pq.empty()){
            auto [curr,i,j]=pq.top();
            pq.pop();
            if(i==n-1 && j==m-1 && curr>0) return true;
            for(auto d:dir){
                int i_=i+d[0];
                int j_=j+d[1];
                if(i_>=0 && j_>=0 && i_<n && j_<m && !vis[i_][j_]){
                    vis[i_][j_]=true;
                    pq.push({curr-grid[i_][j_],i_,j_});
                }
            }
        }
        return false;
    }
};
// Time Complexity: O(n*m*log(n*m)) where n is the number of rows and m is the number of columns in the grid. This is because we are using a priority queue to explore the grid, and in the worst case, we may need to explore all cells in the grid, and each insertion into the priority queue takes logarithmic time.
// Space Complexity: O(n*m) for the visited array and the priority queue, where n is the number of rows and m is the number of columns in the grid.