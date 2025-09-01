class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double, int>> pq;
        for (int i = 0; i < n; i++) {
            double s = classes[i][0];
            double t = classes[i][1];
            double gain = ((s + 1) / (t + 1)) - (s / t);
            pq.push({gain, i});
        }
        for (int i = 0; i < extraStudents; i++) {
            int idx = pq.top().second;
            pq.pop();
            classes[idx][0]++;
            classes[idx][1]++;
            double s = classes[idx][0];
            double t = classes[idx][1];
            double newGain = ((s + 1) / (t + 1)) - (s / t);
            pq.push({newGain, idx});
        }
        double sum = 0;
        for (auto it : classes) {
            double pss = it[0];
            double tls = it[1];
            sum += (pss / tls);
        }
        return sum / n;
    }
};