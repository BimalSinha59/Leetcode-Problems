class Solution {
public:
    int countFourPersonGroups(vector<int>& seats) {
        seats.push_back(10);
        int count = 0;
        for (int i = 1; i < seats.size(); i++) {

            int diff = seats[i] - seats[i - 1] - 1;
            if (diff == 8) {
                count = 2;
            } else if ((diff == 4) &&
                       (seats[i - 1] + 1 == 2 || seats[i - 1] + 1 == 4 ||
                        seats[i - 1] + 1 == 6)) {
                count = 1;
            } else if (diff > 4) {
                count = 1;
            }
        }

        return count;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        reservedSeats.push_back({1, 1});
        reservedSeats.push_back({n, 1});
        sort(reservedSeats.begin(), reservedSeats.end());
        int ans = 0;
        int last_row = -1;
        int m = reservedSeats.size();
        int i = 0;
        while (i < m) {
            vector<int> seats;
            seats.push_back(1);
            seats.push_back(reservedSeats[i][1]);

            i++;
            while (i < m && reservedSeats[i][0] == reservedSeats[i - 1][0]) {
                seats.push_back(reservedSeats[i][1]);
                i++;
            }
            ans += countFourPersonGroups(seats);

            if (last_row != -1) {
                ans += (reservedSeats[i - 1][0] - last_row - 1) * 2;
            }
            last_row = reservedSeats[i - 1][0];
        }
        return ans;
    }
};