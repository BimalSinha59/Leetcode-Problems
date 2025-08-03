class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();
        int ans=0;
        int i=0,j=1;
        while(j<n){
            if(weight[i]>weight[j]){
                ans++;
                i=j+1;
                j=i+1;
            }
            else{
                i++;
                j++;
            }
        }
        return ans;
    }
};