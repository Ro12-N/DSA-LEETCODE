class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>st;
        for(auto i:nums){
            while(!st.empty()){
                int a=st.back();
                int g=gcd(i,a);
                if(g==1) break;
                st.pop_back();
               long long b=  (1LL*a * i) / g;
               i=b;
            }
            st.push_back(i);
        }
        return st;
    }
};