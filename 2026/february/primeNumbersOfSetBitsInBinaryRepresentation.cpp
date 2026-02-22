class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int>st={2,3,5,7,11,13,17,19,23,29,31};
        int ans=0;
        for(int i=left;i<=right;i++){
            int curr=__builtin_popcount(i);
            if(st.count(curr)) ans++;
        }
        return ans;
    }
};
// TC: O(n log n) where n is the number of integers between left and right, due to counting set bits for each integer.
// SC: O(1) for the unordered_set and constant space used in counting set bits