class Solution {
public:
bool solve(string word,vector<int>&v){
    for(auto i:word){
        if(v[i-'a']==1) return false;
    }
    return true;
}
    int canBeTypedWords(string text, string brokenLetters) {
        int cnt=0;
        vector<int>v(26,0);
        for(auto i:brokenLetters){
            v[i-'a']++;
        }
        stringstream st(text);
        string word;
        int ans=0;
        while(st>>word){
            ans+=solve(word,v);
        }
        return ans;
    }
};