class Solution {
public:
    string getHappyString(int n, int k) {
        string result;
        int count = 0;
        generate(n, "", count, k, result);
        return result;
    }

private:
    void generate(int n, string curr, int &count, int k, string &result) {
        if (curr.size() == n) {
            count++;
            if (count == k) result = curr;
            return;
        }

        for (char c : {'a', 'b', 'c'}) {
            if (curr.empty() || curr.back() != c) {
                generate(n, curr + c, count, k, result);
                if (!result.empty()) return;
            }
        }
    }
};

// Time Complexity: O(3^n) in the worst case, but it will be much less due to the happy string constraint.
// Space Complexity: O(n) for the recursion stack.