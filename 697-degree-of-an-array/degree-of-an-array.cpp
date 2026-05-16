class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        unordered_map<int, int> count;
        unordered_map<int, int> firstIndex;
        unordered_map<int, int> lastIndex;

        // Store frequency and first/last occurrence
        for (int i = 0; i < nums.size(); i++) {
            
            if (firstIndex.find(nums[i]) == firstIndex.end()) {
                firstIndex[nums[i]] = i;
            }

            lastIndex[nums[i]] = i;
            count[nums[i]]++;
        }

        // Find degree of array
        int degree = 0;

        for (auto it : count) {
            degree = max(degree, it.second);
        }

        // Find minimum length subarray
        int ans = nums.size();

        for (auto it : count) {
            
            int num = it.first;
            int freq = it.second;

            if (freq == degree) {
                ans = min(ans, lastIndex[num] - firstIndex[num] + 1);
            }
        }

        return ans;
    }
};