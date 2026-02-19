class Solution {
public:
    bool hasAlternatingBits(int n) {
       long x= (n ^ (n>>1));
       return (x &(x+1))==0;
    }
};

// TC: O(1) since the operations are constant time.
// SC: O(1) since we are using a constant amount of space.