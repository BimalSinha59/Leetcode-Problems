class Solution {
public:
    bool isPossible(vector<int>& target) {
        int sum=0;
        //int n=target.size();
        priority_queue<int>pq;
        for(int &it:target){
            pq.push(it);
            sum+=it;
        }

        while(pq.top()!=1){
            int tope=pq.top();
            pq.pop();
            sum-=tope;
            if(sum<=0 || sum>=tope){
                return false;
            }
            tope=tope%sum;
            sum+=tope;
            if(tope>0){
                pq.push(tope);
            }
            else{
                pq.push(sum);
            }
        }
        return true;
    }
};