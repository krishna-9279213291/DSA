class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();

        vector<int> diff(n);
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            sum += diff[i];
        }

        // If all differences can be reduced to zero
        if (sum <= k) return 0;

        // Binary search for the maximum difference level
        int low = 0, high = 100000;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long required = 0;

            for (int d : diff) {
                if (d > mid) {
                    required += d - mid;
                }
            }

            if (required <= k)
                high = mid;
            else
                low = mid + 1;
        }

        int level = low;
        long long remaining = k;

        // Reduce all differences greater than level
        for (int i = 0; i < n; i++) {
            if (diff[i] > level) {
                remaining -= diff[i] - level;
                diff[i] = level;
            }
        }

        // Distribute remaining operations
        // by reducing some differences from level to level - 1
        for (int i = 0; i < n && remaining > 0; i++) {
            if (diff[i] == level && level > 0) {
                diff[i]--;
                remaining--;
            }
        }

        long long ans = 0;

        for (int d : diff) {
            ans += 1LL * d * d;
        }

        return ans;
    }
};