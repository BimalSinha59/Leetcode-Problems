class Fancy {
public:
    vector<int> seq, mul, add;
    const int mod=1e9+7;
    Fancy() {
        mul.push_back(1);
        add.push_back(0);
    }
    int quickmul(int x, int y) {
        int ret = 1;
        int cur = x;
        while (y) {
            if (y & 1) {
                ret = 1LL*ret * cur % mod;
            }
            cur = 1LL*cur * cur % mod;
            y >>= 1;
        }
        return ret;
    }
    int inv(int x) { 
        return quickmul(x, mod - 2); 
    }

    void append(int val) {
        seq.push_back(val);
        mul.push_back(mul.back());
        add.push_back(add.back());
    }
    
    void addAll(int inc) {
        add.back() = (add.back() + inc) % mod;
    }
    
    void multAll(int m) {
        mul.back() = 1LL*mul.back() * m % mod;
        add.back() = 1LL*add.back() * m % mod;
    }
    
    int getIndex(int idx) {
        if (idx >= seq.size()) {
            return -1;
        }
        int ao = 1LL*inv(mul[idx]) * mul.back() % mod;
        int bo = (add.back() - 1LL*add[idx] * ao % mod + mod) % mod;
        int ans = (1LL*ao * seq[idx] % mod + bo) % mod;
        return ans;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */