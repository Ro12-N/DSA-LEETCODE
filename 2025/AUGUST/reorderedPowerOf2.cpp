class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<string>st;
        long long ans=1;
        for(int i=0;i<32;i++){
            string curr=to_string(ans);
            ans*=2;
            sort(curr.begin(),curr.end());
            st.insert(curr);
        }
        string curr=to_string(n);
        sort(curr.begin(),curr.end());
        return st.count(curr);
    }
};