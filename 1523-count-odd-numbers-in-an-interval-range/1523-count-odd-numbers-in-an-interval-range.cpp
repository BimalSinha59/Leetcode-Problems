class Solution {
public:
    int countOdds(int low, int high) {
        int diff=high-low;
        int ans;
        if(diff&1){
            ans=diff/2+1;
        }
        else if(low&1 && high&1){
            ans=diff/2+1;
        }
        else{
            ans=diff/2;
        }
        return ans;
    }
};