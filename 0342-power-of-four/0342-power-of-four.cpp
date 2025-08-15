class Solution {
public:
    bool isPowerOfFour(int n) {
        for(int i=0; i<16; i++){
            int ans = pow(4, i);
            if(ans==n) return true;
        }
        return false;
        
    }
};