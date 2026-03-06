class Solution {
public:
    int minOperations(string s) {
        
        int p=0,q=0;
        int a=1,b=0;
        for(auto i:s){
            int curr=i-'0';
            if(curr!=a) p++;
            if(curr!=b) q++;
            a=1-a;
            b=1-b;
        }
        return min(p,q);
    }
};
//TC: O(n) where n is the length of the input string s
//SC: O(1) since we are using only a constant amount of extra space