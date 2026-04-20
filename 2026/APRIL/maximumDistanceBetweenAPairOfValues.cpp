class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        int i=0,j=0;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                ans=max(ans,j-i);
                j++;
            }else i++;
        }
        return ans;
    }
};
// Time Complexity: O(m+n) where m and n are the sizes of nums1 and nums2 respectively
// Space Complexity: O(1)