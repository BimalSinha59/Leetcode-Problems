class Solution {
public:
    bool canEat(vector<int> &piles, int h , int k){
        int n = piles.size();
        long long int totalH = 0;
        for(int i=0; i<n; i++){
            totalH=totalH+ceil((piles[i])/(double)k);
        }

        if(totalH<=h){
            return true;
        }
        
        return false;
        
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1; 
        int e = *max_element(piles.begin(), piles.end());

        int ans = 0;
        while(s<=e){
            int mid = s+(e-s)/2;
            int k = mid;
            if(canEat(piles, h, k )){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;   
    }
};