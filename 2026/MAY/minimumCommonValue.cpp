class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        while(i<nums1.size() &&j<nums2.size()){
            if(nums1[i]==nums2[j]) return nums1[i];
            else if(nums1[i]>nums2[j]) j++;
            else i++;
        }
        return -1;
    }
};
// TC : O(n) where n is the size of the smaller input array between nums1 and nums2
// SC : O(1) as we are using only constant extra space to store the pointers