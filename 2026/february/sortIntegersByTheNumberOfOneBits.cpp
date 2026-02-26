class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
       sort(arr.begin(),arr.end(),[](int &a,int &b){
          if(__builtin_popcount(a)==__builtin_popcount(b)) return a<b;
          return __builtin_popcount(a)<__builtin_popcount(b);
       });
        return arr;
    }
};
// TC: O(n log n) where n is the number of elements in the input array, due to the sorting step.    
// SC: O(1) if we ignore the space used by the sorting algorithm, otherwise O(n) due to the space used by the sorting algorithm.