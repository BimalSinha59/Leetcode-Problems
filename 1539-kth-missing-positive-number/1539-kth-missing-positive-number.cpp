class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int idx=-1;
        int s=0,e=n-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(arr[mid]-(mid+1)<k){
                idx=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        if(idx==-1){
            return k;
        }
        int temp=arr[idx]-(idx+1);
        int diff=k-temp;
        return arr[idx]+diff;
    }
};