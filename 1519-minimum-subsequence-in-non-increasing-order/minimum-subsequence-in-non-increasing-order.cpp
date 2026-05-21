class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        
        // Step 1: Sort array in descending order
        sort(nums.begin(), nums.end(), greater<int>());
        
        // Step 2: Find total sum
        int total = 0;
        for(int num : nums) {
            total += num;
        }
        
        // Step 3: Pick largest elements until
        // subsequence sum > remaining sum
        vector<int> ans;
        int currSum = 0;
        
        for(int num : nums) {
            ans.push_back(num);
            currSum += num;
            
            if(currSum > total - currSum) {
                break;
            }
        }
        
        return ans;
    }
};