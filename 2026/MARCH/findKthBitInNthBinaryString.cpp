class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1) return '0';
        int len=(1<<n)-1;
        if(k<ceil(len/2.0)){
            return findKthBit(n-1,k);
        }else if(k==ceil(len/2.0)) return '1';
        else {
            char d=findKthBit(n-1,(len-(k-1)));
            return (d=='1')?'0':'1';
        }
    }
};
//TC: O(n) where n is the value of n
//SC: O(n) since we are using recursion and the maximum depth of the recursion is n