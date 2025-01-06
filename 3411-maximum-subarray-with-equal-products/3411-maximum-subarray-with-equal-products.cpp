class Solution {
public:
    long long prod(vector<int> &arr){
        int m=arr.size();
        long long mul=1;
        for(int i=0; i<m; i++ ){
            mul*=arr[i];
        }
        return mul;
    }
long long Gcd(vector<int> &arr){
    int m=arr.size();
    long long gcdn=0;
    for(int i=0; i<m; i++){
        gcdn=__gcd(gcdn,(long long)arr[i]);
    }
    return gcdn;
}
long long Lcm(vector<int> &arr){
    int m=arr.size();
    long long lcmn=1;
    for(int i=0; i<m; i++){
        lcmn=lcm(lcmn,(long long)arr[i]);
    }
    return lcmn;
}
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        // int pmul[n];
        // int pgcd[n];
        // int plcm[n];
        // pmul[0]=nums[0];
        // pgcd[0]=__gcd(nums[0],nums[1]);
        // plcm[0]=1;
        // for(int i=1; i<n; i++){
        //     pmul[i]=nums[i]*pmul[i-1];
        //     pgcd[i]=__gcd(nums[i],pgcd[i-1]);
        //     plcm[i]=pmul[i]/pgcd[i];
        // }
        int ans=0;
        for(int i=0; i<n; i++){
            vector<int> arr;
            for(int j=i; j<n; j++){
                arr.push_back(nums[j]);
                long long x=prod(arr),y=Gcd(arr),z=Lcm(arr);
                if(x==y*z){
                    int temp=arr.size();
                    ans=max(ans,temp);
                }
            }
        }
        return ans;
    }
};