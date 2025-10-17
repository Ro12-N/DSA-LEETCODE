class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int>freq(100001,0);
        for(auto i:nums){
            int m=(value+(i%value))%value;
              freq[m]++;
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i%value]==0) return i;
            freq[i%value]--;
        }
        return -1;
    }
};