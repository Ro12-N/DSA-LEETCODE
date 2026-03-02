class Solution {
public:
    int minPartitions(string n) {
        int maxi=0;
        for(auto i:n){
            maxi=max(maxi,(i-'0'));
        }
        return maxi;
    }
};
//TC: O(n) where n is the length of the string n
//SC: O(1) since we are using only a constant amount of space to store