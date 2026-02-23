class Solution {
public:
    int binaryGap(int n) {
        int a=-1;
        int ans=0;
        for(int i=0;i<32;i++){
            if(n &(1<<i)){
               if(a!=-1) ans=max(ans,i-a);
                a=i;
            }
        }
        return ans;
    }
};
// TC: O(1) since we are iterating through a fixed number of bits (32 bits for an integer).
// SC: O(1) since we are using a constant amount of space to store the