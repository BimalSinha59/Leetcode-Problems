class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total_waviness = 0;
        for (int i = num1; i <= num2; i++) {
            string num = to_string(i);
            int waviness = 0;
            for (int j = 1; j < num.size() - 1; j++) {
                if ((num[j] > num[j - 1] && num[j] > num[j + 1]) ||
                    (num[j] < num[j - 1] && num[j] < num[j + 1])) {
                    waviness++;
                }
            }
            total_waviness += waviness;
        }
        return total_waviness;
    }
};