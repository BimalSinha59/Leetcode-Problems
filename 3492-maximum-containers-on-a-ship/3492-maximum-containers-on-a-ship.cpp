class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int totalC=n*n;
        int ans=maxWeight/w;
        return min(totalC,ans);
        
    }
};