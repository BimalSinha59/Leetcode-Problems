class Solution {
public:
    double getLowerArea(double ycord, const vector<vector<int>>& squares) {
        double area = 0;
        for (const auto& sq : squares) {
            double bcord = sq[1];
            double side = sq[2];
            double tcord = bcord + side;
            if (tcord <= ycord) {
                area += side * side;
            } else if (bcord < ycord) {
                area += (ycord - bcord) * side;
            }
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double minY = 1e9, maxY = -1e9;
        double totalArea = 0;
        for (const auto& sq : squares) {
            double y = sq[1];
            double l = sq[2];
            minY = min(minY, y);
            maxY = max(maxY, y + l);
            totalArea += l * l;
        }
        double low = minY, high = maxY;
        for (int i = 0; i < 100; ++i) {
            double mid = low + (high - low) / 2.0;
            if (getLowerArea(mid, squares) * 2.0 >= totalArea) {
                high = mid;
            } else {
                low = mid;
            }
        }

        return low;
    }
};