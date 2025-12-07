class Solution {
public:
    int countOdds(int low, int high) {
        if(low==high) return low%2;
        if(low%2 &&high%2) return 2+(high-low-1)/2;
        return low%2+high%2+(high-low)/2;
    }
};