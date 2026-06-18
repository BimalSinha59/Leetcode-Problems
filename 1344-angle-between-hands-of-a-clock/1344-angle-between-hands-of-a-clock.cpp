class Solution {
public:
    double angleClock(int hour, int minutes) {
        double one_min_ang = 180 / 30.0;
        double diff = abs(hour * 5.0 - minutes);
        double rem = minutes / 12.0;
        double angle = diff * one_min_ang;
        if (hour * 5 >= minutes) {
            angle += rem * one_min_ang;
        } else {
            angle -= rem * one_min_ang;
        }
        angle = min(angle, 360 - angle);
        return abs(angle);
    }
};