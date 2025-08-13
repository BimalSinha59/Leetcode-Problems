class Solution {
public:
    bool isPowerOfThree(int n) {
        for(int i=0; i<(31*(1/log2(3))); i++){
            int ans = pow(3, i);
            if(ans==n) return true;
        }
        return false;
        
    }
};