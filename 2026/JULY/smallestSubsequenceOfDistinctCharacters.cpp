class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>lastidx(26,0);
        for(int i=0;i<s.size();i++){
            lastidx[s[i]-'a']=i;
        }
        stack<char>st;
        vector<int>vis(26,0);
        for(int i=0;i<s.size();i++){
            if(vis[s[i]-'a']) continue;
            while(!st.empty() && st.top()>s[i] && i<lastidx[st.top()-'a']){
                vis[st.top()-'a']=0;
                st.pop();
            }

            st.push(s[i]);
            vis[s[i]-'a']=1;
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};
// Time Complexity: O(n) where n is the length of the input string s. This is because we are iterating through the string once to build the last index array and then again to construct the smallest subsequence.
// Space Complexity: O(1) since we are using a constant amount of extra space for the last index array and the visited array, which have a fixed size of 26 (the number of lowercase letters). The stack can also hold at most 26 characters.