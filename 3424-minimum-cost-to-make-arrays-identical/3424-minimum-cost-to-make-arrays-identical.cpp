class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {

       int n=arr.size();
        long long ans1=0;
        for(int i=0; i<n; i++){
            int x=abs(arr[i]-brr[i]);
            ans1+=x;
        }
       
            long long ans=0;
           
            sort(arr.begin(),arr.end());
            sort(brr.begin(),brr.end());
            for(int i=0; i<n; i++){
                int x=abs(arr[i]-brr[i]);
                ans+=x;
            }
            ans+=k;
            return min(ans1,ans);
    
        
    }
};