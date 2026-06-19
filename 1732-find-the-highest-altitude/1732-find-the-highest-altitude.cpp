class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int netGain = 0;
        int highestAlt = 0;
        for (int i = 0; i < gain.size(); i++) {
            netGain += gain[i];
            highestAlt = max(highestAlt, netGain);
        }
        return highestAlt;
    }
};