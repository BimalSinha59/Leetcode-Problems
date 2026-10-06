class Solution {
public:
    bool canFinish(vector<int>& piles, int speed, int h) {
        long long hours = 0;
        for (int pile : piles) {
            hours += ceil((double)pile / speed);
            if (hours > h) {
                return false;
            }
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int min_k = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canFinish(piles, mid, h)) {
                min_k = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return min_k;
    }
};