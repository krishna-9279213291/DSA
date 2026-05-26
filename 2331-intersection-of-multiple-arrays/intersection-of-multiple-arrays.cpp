class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> freq(1001, 0);
        vector<int> ans;

        // Count frequency of each number
        for (auto &arr : nums) {
            for (int x : arr) {
                freq[x]++;
            }
        }

        // Check which numbers are present in all arrays
        for (int i = 1; i <= 1000; i++) {
            if (freq[i] == nums.size()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};