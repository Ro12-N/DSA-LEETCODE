class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans="";
        for(int i=0;i<nums.size();i++){
            ans+=((1-(nums[i][i]-'0'))+'0');
        }
        return ans;
    }
};
//TC: O(n) where n is the length of the input vector nums
//SC: O(n) where n is the length of the input vector nums since we are using a string ans to store the result which can have at most n characters.