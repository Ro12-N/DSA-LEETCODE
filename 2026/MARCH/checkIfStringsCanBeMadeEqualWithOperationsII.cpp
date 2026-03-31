class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int>e(26,0);
        vector<int>o(26,0);
        for(int i=0;i<s1.size();i++){
            if(i%2==0){
               e[s1[i]-'a']++;
               e[s2[i]-'a']--;
            }else{
              o[s1[i]-'a']++;
              o[s2[i]-'a']--;
            }
        }
        for(int i=0;i<26;i++){
            if(e[i]!=0||o[i]!=0) return false;
        }
        return true;
    }
};
// TC : O(n)
// SC : o(1)