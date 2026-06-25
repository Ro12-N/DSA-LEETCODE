class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> v(26, 0);
        for (char c : text)
            v[c - 'a']++;

        int ans = INT_MAX;
        for (char c:string("balloon")) {
            int val = v[c - 'a'];
            if (c == 'l' || c == 'o')
                val /= 2;

            ans = min(ans, val);
        }

        return ans==INT_MAX?0:ans;
    }
};
// TC : O(n) since we are traversing the string once
// SC : O(1) since we are using constant space