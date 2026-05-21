class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),[](vector<int>& a, vector<int>& b) { 
            return a[1] > b[1]; 
        });
        int ans = 0;
        for (auto& it : boxTypes) {
            int mini = min(it[0], truckSize);
            ans += mini * it[1];
            truckSize -= mini;
            if (truckSize <= 0) {
                break;
            }
        }
        return ans;
    }
};