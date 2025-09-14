class Solution {
public:
unordered_set<string>exact;
unordered_map<string,string>cap;
unordered_map<string,string>vow;
string toLower(string &s){
    string ans="";
    for(auto i:s){
        char ch=tolower(i);
        ans+=ch;
    }
    return ans;
}
string tovow(string &s){
    string ans="";
    for(auto i:s){
        if(i=='a'||i=='e'||i=='u'||i=='i'||i=='o'){
            ans+='*';
        }else ans+=i;
    }
    return ans;
}
string solve(string &q){
     if(exact.count(q)){
        return q;
     }
     string l=toLower(q);
     if(cap.count(l)){
        return cap[l];
     }
     string c=tovow(l);
     if(vow.count(c)){
        return vow[c];
     }
    return "";
}
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        exact.clear();
        cap.clear();
        vow.clear();
        for(auto i:wordlist){
            exact.insert(i);
            string curr=toLower(i);
            if(!cap.count(curr)){
                cap[curr]=i;
            }
            string res=tovow(curr);
            if(!vow.count(res)){
                vow[res]=i;
            }
        }
        vector<string>ans;
        for(auto i:queries){
            ans.push_back(solve(i));
        }
        return ans;
    }
};