class SGTree {
	vector<int> seg;
    public:
	SGTree(int n) {
		seg.resize(4 * n + 1);
	}

	void build(int ind, int low, int high, vector<int>& nums) {
		if (low == high) {
			seg[ind] = nums[low];
			return;
		}

		int mid = (low + high) / 2;
		build(2 * ind + 1, low, mid, nums);
		build(2 * ind + 2, mid + 1, high, nums);
		seg[ind] = seg[2 * ind + 1]+seg[2 * ind + 2];
	}

	int query(int ind, int low, int high, int l, int r) {
		// no overlap
		// l r low high or low high l r
		if (r < low || high < l) return 0;

		// complete overlap
		// [l low high r]
		if (low >= l && high <= r) return seg[ind];

		int mid = (low + high) >> 1;
		int left = query(2 * ind + 1, low, mid, l, r);
		int right = query(2 * ind + 2, mid + 1, high, l, r);
		return left+right;
	}
	void update(int ind, int low, int high, int i, int val) {
		if (low == high) {
			seg[ind] = val;
			return;
		}

		int mid = (low + high) >> 1;
		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
		else update(2 * ind + 2, mid + 1, high, i, val);
		seg[ind] = seg[2 * ind + 1]+seg[2 * ind + 2];
	}
};

class NumArray {
public:
    SGTree* sg;
    int n;
    NumArray(vector<int>& nums) {
        n=nums.size();
        sg=new SGTree(n);
        sg->build(0,0,n-1,nums);
    }
    void update(int index, int val) {
       sg->update(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return sg->query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */