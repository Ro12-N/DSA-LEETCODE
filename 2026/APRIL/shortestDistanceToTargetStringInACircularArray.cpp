class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans=INT_MAX;
        int n=words.size();
        for(int i=0;i<words.size();i++){
            if(words[i]==target){
               int dist = min(abs(startIndex - i), n - abs(startIndex - i));
                ans = min(ans, dist);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
// Time Complexity: O(n) where n is the number of words in the array
// Space Complexity: O(1)