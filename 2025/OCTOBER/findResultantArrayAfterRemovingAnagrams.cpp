class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<int>s1(26,0);
        for(int i=0;i<words[0].size();i++){
            s1[words[0][i]-'a']++;
        }
        vector<string>res;
        res.push_back(words[0]);
        for(int i=1;i<words.size();i++){
            string p=words[i];
                    vector<int>s2(26,0);

            for(auto j:p){
                s2[j-'a']++;
            }
            if(s1!=s2){
                res.push_back(p);
                s1=s2;
            }
        }
        return res;
    }
};