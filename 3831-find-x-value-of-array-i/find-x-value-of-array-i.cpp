class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);

        // dp[r] = number of subarrays ending at previous index
        // having product % k == r
        vector<long long> dp(k, 0);

        for (int num : nums) {
            int val = num % k;

            vector<long long> cur(k, 0);

            // Start a new subarray with just nums[i]
            cur[val]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newRemainder = (r * val) % k;
                    cur[newRemainder] += dp[r];
                }
            }

            // Add current subarrays to final answer
            for (int r = 0; r < k; r++) {
                result[r] += cur[r];
            }

            dp = cur;
        }

        return result;
    }
};