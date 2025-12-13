class Solution {
public:
bool chk(string &s){
    if(s.empty()) return false;
    for(auto i:s){
        if(!isalnum(i) &&i!='_') return false;
    }
    return true;
}
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string>o={"electronics", "grocery", "pharmacy", "restaurant"};
        unordered_set<string>st(o.begin(),o.end());
        vector<string>ans;
        unordered_map<string,vector<string>>mp;
        int n=code.size();
        for(int i=0;i<n;i++){
            if(isActive[i] &&chk(code[i]) &&st.count(businessLine[i])){
                mp[businessLine[i]].push_back(code[i]);
            }
        }
        for(auto i:o){
             if(!mp[i].empty()){
                sort(mp[i].begin(),mp[i].end());
                ans.insert(ans.end(),mp[i].begin(),mp[i].end());
             }
        }

        return ans;
    }
};