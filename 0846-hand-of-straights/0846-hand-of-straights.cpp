class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }

        unordered_map<int, int> card_freq;
        for (int card : hand) {
            card_freq[card]++;
        }

        for (int card : hand) {
            int start_card = card;
            while (card_freq[start_card - 1]) {
                start_card--;
            }

            while (start_card <= card) {
                while (card_freq[start_card]) {
                    for (int i = start_card; i < start_card + groupSize; i++) {
                        if (!card_freq[i]) {
                            return false;
                        }
                        card_freq[i]--;
                    }
                }
                start_card++;
            }
        }

        return true;
    }
};