class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 1; i--) {
            int idx = i % n;

            // Remove elements smaller than or equal to current
            while (!st.empty() && st.top() <= nums[idx]) {
                st.pop();
            }

            // Next greater element
            if (!st.empty()) {
                ans[idx] = st.top();
            }

            // Current element becomes candidate
            st.push(nums[idx]);
        }

        return ans;
    }
};