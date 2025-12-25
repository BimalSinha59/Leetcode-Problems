class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int psum=0;
        int ans=0;
        for(int &g:gain){
            psum+=g;
            ans=max(ans,psum);
        }
        return ans;
    }
};