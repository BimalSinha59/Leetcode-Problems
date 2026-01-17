class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
                                    
        int n = bottomLeft.size();
        int largestSide = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int iscTopx = min(topRight[i][0], topRight[j][0]);
                int iscBotx = max(bottomLeft[i][0], bottomLeft[j][0]);
                int width = iscTopx - iscBotx;
                int iscTopy = min(topRight[i][1], topRight[j][1]);
                int iscBoty = max(bottomLeft[i][1], bottomLeft[j][1]);
                int hight = iscTopy - iscBoty;
                int side = min(width, hight);
                largestSide = max(largestSide, side);
            }
        }
        return 1LL * largestSide * largestSide;
    }
};