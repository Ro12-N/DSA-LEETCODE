class Solution {
public:
    int mirrorDistance(int n) {
        int rev=0;
        int curr=n;
        while(curr){
            rev=rev*10+curr%10;
            curr/=10;
        }
        return abs(rev-n);
    }
};
// Time Complexity: O(log n) where n is the input integer
// Space Complexity: O(1)