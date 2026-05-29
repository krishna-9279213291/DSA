class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;

        // Step 2: Find minimum absolute difference
        int mini = INT_MAX;

        for(int i = 1; i < arr.size(); i++) {
            mini = min(mini, arr[i] - arr[i - 1]);
        }

        // Step 3: Store all pairs having minimum difference
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] - arr[i - 1] == mini) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }

        return ans;
    }
};