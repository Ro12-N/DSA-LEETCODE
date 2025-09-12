class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char,int>mp;
        for(auto i:s){
            char ch=tolower(i);
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                   mp[i]++;
            }
        }
        int idx=0;
        string ans="AEIOUaeiou";
        for(int i=0;i<s.size();i++){
             char ch=tolower(s[i]);
             if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                    while(mp[ans[idx]]==0){
                        idx++;
                    }
                    s[i]=ans[idx];
                    mp[ans[idx]]--;
             }
        }
        return s;
    }
};