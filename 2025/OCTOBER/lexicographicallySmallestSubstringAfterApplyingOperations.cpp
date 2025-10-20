class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string>st;
        string ans=s;
        st.insert(s);
        queue<string>q;
        q.push(s);
        while(!q.empty()){
            string curr=q.front();
            q.pop();
            if(curr<ans){
                ans=curr;
            }
            string temp=curr;
            for(int i=1;i<curr.size();i+=2){
                temp[i]=(temp[i]-'0'+a)%10 +'0';
            }
            if(!st.count(temp)) {
                st.insert(temp);
                q.push(temp);
            }
            reverse(curr.begin(),curr.end());
            reverse(curr.begin(),curr.begin()+b);
            reverse(curr.begin()+b,curr.end());
            if(!st.count(curr)) {
                st.insert(curr);
                q.push(curr);
            }
        }
        return ans;

    }
};