class Solution {
public:
    struct Event {
        int y, type, l, r;
        bool operator<(const Event& other) const {
            return y < other.y;
        }
    };

    vector<int> xs;
    vector<int> cnt;
    vector<long long> seg;

    void pull(int idx, int l, int r){
        if(cnt[idx] > 0){
            seg[idx] = xs[r] - xs[l];
        } else if(r - l == 1){
            seg[idx] = 0;
        } else {
            seg[idx] = seg[idx*2] + seg[idx*2+1];
        }
    }

    void update(int idx, int l, int r, int ql, int qr, int val){
        if(qr <= l || r <= ql) return;
        if(ql <= l && r <= qr){
            cnt[idx] += val;
            pull(idx,l,r);
            return;
        }
        int mid = (l+r)/2;
        update(idx*2, l, mid, ql, qr, val);
        update(idx*2+1, mid, r, ql, qr, val);
        pull(idx,l,r);
    }

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;

        for(auto &s: squares){
            int x = s[0], y = s[1], l = s[2];
            events.push_back({y, 1, x, x+l});
            events.push_back({y+l, -1, x, x+l});
            xs.push_back(x);
            xs.push_back(x+l);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        sort(events.begin(), events.end());

        int m = xs.size();
        cnt.assign(4*m,0);
        seg.assign(4*m,0);

        auto getId = [&](int x){
            return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        };

        vector<tuple<int,int,long long>> areas;
        long long total = 0;

        int prev_y = events[0].y;

        for(auto &e: events){
            if(e.y > prev_y){
                long long w = seg[1];
                int h = e.y - prev_y;
                if(w > 0){
                    areas.push_back({prev_y, h, w});
                    total += w * h;
                }
            }

            int L = getId(e.l);
            int R = getId(e.r);
            update(1,0,m-1,L,R,e.type);

            prev_y = e.y;
        }

        double half = total / 2.0;
        double acc = 0;

        for(auto &[y,h,w]: areas){
            if(acc + 1.0*h*w >= half){
                return y + (half - acc) / w;
            }
            acc += 1.0*h*w;
        }
        return 0.0;
    }
};
