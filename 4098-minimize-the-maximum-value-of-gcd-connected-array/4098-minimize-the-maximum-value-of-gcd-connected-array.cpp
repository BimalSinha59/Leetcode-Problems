class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if (value == 1) {
            return -1;
        }
        int min_factor = -1;
        for (int i = 2; i * i <= value; i++) {
            if (value % i == 0) {
                min_factor = i;
                break;
            }
        }
        if (min_factor == -1) {
            min_factor = value;
        }
        int left_value = value - min_factor;
        int leftIdx = 2 * index;
        if (index > 0 && left_value < leftIdx) {
            return -1;
        }

        int right = n - index - 1;
        if (right == 0) {
            return value;
        }

        return 2LL * (right - 1) + value + min_factor;
    }
};