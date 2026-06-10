class SegmentTree{
public:
    struct Node {
        int mn;
        int mx;
    };
    int n;
    vector<Node>tree;

    SegmentTree(vector<int>&nums){
        n=nums.size();
        tree.resize(4*n);
        build(0,0,n-1,nums);
    }

    Node merge(Node a,Node b){
        return {min(a.mn,b.mn),max(a.mx,b.mx)};
    }

    void build(int idx,int l,int r,vector<int>&nums){
        if(l==r){
            tree[idx]={nums[l],nums[r]};
            return;
        }

        int mid=l+(r-l)/2;

        build(2*idx+1,l,mid,nums);
        build(2*idx+2,mid+1,r,nums);

        tree[idx]=merge(tree[2*idx+1],tree[2*idx+2]);
    }

    Node query(int idx,int l,int r,int ql,int qr){
        if(qr<l || ql>r){
            return {INT_MAX,INT_MIN};
        }

        if(ql<=l && r<=qr){
            return tree[idx];
        }

        int mid=l+(r-l)/2;

        return merge(query(2*idx+1,l,mid,ql,qr),query(2*idx+2,mid+1,r,ql,qr));
    }
    long long get(int l,int r){
        Node ans=query(0,0,n-1,l,r);
        return 1LL*(ans.mx-ans.mn);
    }
};
class Solution {
public:
    using T=tuple<long long,int,int>;
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        SegmentTree seg(nums);

        priority_queue<T>pq;

        for (int l=0;l<n;l++) {
            pq.push({seg.get(l,n-1),l,n-1});
        }

        long long ans=0;
        while(k-- && !pq.empty()){
            auto[val,l,r]=pq.top();
            pq.pop();
            ans+=val;
            if(r-1>=l) {
                pq.push({seg.get(l,r-1),l,r-1});
            }
        }
        return ans;
    }
};