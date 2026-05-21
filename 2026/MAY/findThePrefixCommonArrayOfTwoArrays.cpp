class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
         vector<int>freq(51,0);
         vector<int>ans;
         int cnt=0;
         for(int i=0;i<n;i++){
            if(++freq[A[i]]==2) cnt++;
            if(++freq[B[i]]==2) cnt++;
            ans.push_back(cnt);
         }
         return ans;
    }
};
// TC : O(n) where n is the size of the input arrays A and B
// SC : O(1) as we are using only constant extra space to store the frequency