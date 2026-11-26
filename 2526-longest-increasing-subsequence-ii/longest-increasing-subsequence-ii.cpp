const int N = 1e5+1;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        int t[2*N + 2]; memset(t, 0, sizeof(t));

        auto upd = [&](int p, int v) {
            p += N;
            t[p] = v;
            for(; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
        };

        auto qry = [&](int l, int r) {
            l+=N, r+=N;
            int ret = 0;
            for(; l<r; l>>=1, r>>=1) {
                if (l&1) ret = max(ret, t[l++]);
                if (r&1) ret = max(ret, t[--r]);
            }
            return ret;
        };

        //upd(nums[0], 1);

        for (int i=0; i<n; ++i) {
            int curr = nums[i];
            int best = 1 + qry(max(0, curr - k), curr);
            upd(curr, best);
        }
        int ans = qry(0, N+1);

        return ans;
    }
};