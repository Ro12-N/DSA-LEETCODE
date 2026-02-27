class Solution {
public:
    int numSteps(string s) {
        int c=0;
        int n=s.size();
        int cnt=0;
        for(int i=n-1;i>0;i--){
            int bit=(s[i]-'0')+c;
            if(bit%2){
                cnt+=2;
                c=1;
            }else{
                cnt+=1;
            }
        }
        return cnt+c;
    }
};
// TC: O(n) where n is the length of the input string, since we need to iterate through the string once.
// SC: O(1) since we are using only a constant amount of extra space 