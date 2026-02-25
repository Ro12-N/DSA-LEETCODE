class Solution {
public:
    bool hasAllCodes(string s, int k) {
      if(s.size()<k) return false;
      unordered_set<string>st;
       string curr="";
       int j=0;
      for(int i=0;i<s.size();i++){
          curr=s[i]+curr;
          if(i-j+1>k){
            j++;
            curr.pop_back();
          }
        
          if(i-j+1==k){
            st.insert(curr);
          }
      }
      return st.size()==pow(2,k);

    
    }
};
// TC: O(n) where n is the length of the input string s, since we iterate through the string once.
// SC: O(2^k) in the worst case, since we can have at