class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i=0;
        int j=0;
        int carry=0;
        string ans="";
        while(i<a.size()||j<b.size()||carry){
             int curr=carry;
             if(i<a.size()){
                curr+=(a[i]-'0');
                i++;
             }
             if(j<b.size()){
                curr+=(b[j]-'0');
                j++;
             }
             ans+=(curr%2)+'0';
             carry=curr/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// TC: O(max(a.size(),b.size()))
// SC: O(max(a.size(),b.size()))