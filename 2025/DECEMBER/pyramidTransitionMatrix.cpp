class Solution {
public:
unordered_map<string,bool>dp;
   bool solve(string curr,int idx,unordered_map<string,vector<char>>&mp,string next){
    if(curr.size()==1) return true;
    string key=curr+"_"+to_string(idx)+"_"+next;
    if(dp.count(key)) return dp[key];
        if(idx==curr.size()-1){
           return solve(next,0,mp,"");
        }
        string pair=curr.substr(idx,2);
        if(!mp.count(pair)) return false;
        for(auto i:mp[pair]){
            next.push_back(i);
            if(solve(curr,idx+1,mp,next)) return true;
            next.pop_back();
        }
        return  dp[key]=false;
   }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,vector<char>>mp;
        for(auto i:allowed){
            string curr=i.substr(0,2);
            mp[curr].push_back(i[2]);
        }
        return solve(bottom,0,mp,"");
    }
};

// Time Complexity: O(N^M) where N is number of allowed transitions and M is the height of the pyramid
// Space Complexity: O(N^M) for the recursion stack and dp map