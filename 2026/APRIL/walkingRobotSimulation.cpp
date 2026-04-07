class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string>st;
        for(auto v:obstacles){
            string key=to_string(v[0])+"_"+to_string(v[1]);
            st.insert(key);
        }
        int maxd=0;
        int x=0;
        int y=0;
        pair<int,int>dir={0,1};
        for(int i=0;i<commands.size();i++){
            if(commands[i]==-2){
                dir={-dir.second,dir.first};
            }
            else if(commands[i]==-1){
                dir={dir.second,-dir.first};
            }
            else{
                for(int j=0;j<commands[i];j++){
                    int newx=x+dir.first;
                    int newy=y+dir.second;
                    string newkey=to_string(newx)+"_"+to_string(newy);
                    if(st.find(newkey)!=st.end()){
                        break;
                    }
                    x=newx;
                    y=newy;
                }
            }
            maxd=max(maxd,x*x+y*y);
        }
        return maxd;
    }
};
// TIME: O(n*m) where n is the number of commands and m is the number of obstacles, since we need to check for each command if the new position is an obstacle
// SPACE: O(m) since we are using a set to store the obstacles, which can take up to O(m) space in the worst case where all obstacles are unique.