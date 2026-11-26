class segmentTree {
    vector<int> seg;

public:

    segmentTree(int n) {
        seg.resize(4*n + 1, 0);
    }

    void build(int idx, int low, int high, vector<int> &sum) {
        if(low == high) {
            seg[idx] = sum[low];
            return;
        }

        int mid = (low + high) >> 1;
        build(2*idx + 1, low, mid, sum);
        build(2*idx + 2, mid + 1, high, sum);

        seg[idx] = max(seg[2*idx + 1], seg[2*idx + 2]);
    }

    int query(int idx, int low, int high, int l, int r) {
        if(l > high || low > r) return 0;
        if(low >= l && high <= r) return seg[idx];

        int mid = (low + high) >> 1;
        int left = query(2*idx + 1, low, mid, l, r);
        int right = query(2*idx + 2, mid + 1, high, l, r);

        return max(left, right); 
    }
};

class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<pair<int,int>> v;
        for(int i = 0; i < nums1.size(); i++) v.emplace_back(nums1[i], nums2[i]);
        ranges::sort(v, greater{});

        int maxY = -1;
        vector<int> x, y, sum;
        for(int i = 0; i < nums1.size(); i++) {
            if(v[i].second > maxY) {
                maxY = v[i].second;
                x.push_back(v[i].first); y.push_back(v[i].second);
                sum.push_back(x.back() + y.back());
            }
        }

        segmentTree sg(sum.size());
        sg.build(0, 0, sum.size() - 1, sum);

        auto bisect_right = [&] (int st, int end, int xi) -> int {
            int ans = -1;
            while(st <= end) {
                int mid = st + (end - st)/2;

                if(x[mid] >= xi) {
                    st = mid + 1;
                    ans = mid;
                }
                else end = mid - 1;
            }
            return ans;
        };

        vector<int> ans(queries.size());
        for(int i = 0; i < queries.size(); i++) {
            int xi = queries[i][0], yi = queries[i][1];

            int curr = bisect_right(0, x.size() - 1, xi);
            if(curr == -1) {
                ans[i] = curr;
                continue;
            }

            int nxt = lower_bound(begin(y), end(y), yi) - y.begin();
            if(nxt == y.size() || nxt > curr) {
                ans[i] = -1;
                continue;
            }

            ans[i] = sg.query(0, 0, sum.size() - 1, nxt, curr);
        }

        return ans;
    }
};