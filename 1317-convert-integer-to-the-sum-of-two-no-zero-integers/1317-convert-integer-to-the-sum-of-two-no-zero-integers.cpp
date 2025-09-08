class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int num=n;
        if(num<10){
            return {1,num-1};
        }
        string s;
        while(n>9){
            int dig=n%10;
            if(dig==0){
                s.push_back('8');
            }
            else{
                int x=dig-2;
                if(x<=0){
                    x=3;
                }
                s.push_back(x+'0');
            }
            n/=10;
        }
        reverse(s.begin(),s.end());
        int a=stoi(s);
        cout<<s;
        return {a,num-a};
    }
};