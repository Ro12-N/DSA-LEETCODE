class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,int>>v(26,{-1,-1});
        int ans=0;
        for(int i=0;i<s.size();i++){
            char curr=s[i]-'a';
            if(v[curr].first==-1) v[curr].first=i;
            v[curr].second=i;
        }
        for(int i=0;i<s.size();i++){
            if(v[s[i]-'a'].first!=-1){
                int k=v[s[i]-'a'].second;
                int j=i+1;
                unordered_set<char>st;
                while(j<k){
                    st.insert(s[j++]);
                }
                ans+=st.size();
                v[s[i]-'a'].first=-1;
            }
        }
        return ans;
    }
};