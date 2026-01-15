class Solution {
public:
    bool solve(double m, vector<vector<int>>& squares, double t) {
        double btarea = 0.0;

        for (auto &i : squares) {
            double y = i[1];
            double l = i[2];

            if (m <= y) {
                continue;   
            }
            else if (m >= y + l) {
                btarea += l * l;   
            }
            else {
                btarea += l * (m - y);  
            }
        }
        return btarea >= t / 2.0;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double totalarea = 0.0;
        double low = 1e18;
        double high = -1e18;

        for (auto &i : squares) {
            double y = i[1];
            double l = i[2];
            totalarea += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        while (high - low > 1e-5) {
            double mid = low + (high - low) / 2.0;

            if (solve(mid, squares, totalarea))
                high = mid;
            else
                low = mid;
        }
        return low;
    }
};

// https://leetcode.com/problems/separate-the-squares/description/
// Tc:O(nlog(maxY)) 
// Sc:O(1)