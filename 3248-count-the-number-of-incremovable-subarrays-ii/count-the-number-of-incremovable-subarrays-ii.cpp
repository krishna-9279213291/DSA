class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();

        int i = 0 ; 
        while(i<n-1 && nums[i] < nums[i+1])i++;
        int j = n-1; 
        while(j>0 && nums[j-1] < nums[j])j--;

        if(j <= i)return (1LL*n*(n+1))/2;

        long long ans = i + (n - j) + 2;

        if(nums[n-1] <= nums[0] ){
            return ans ;
        }     
                
        int t = 0;
        ans = (n-j+1);       

        while(j < n && t <= i){

            while(j < n && nums[j] <= nums[t])j++;
            ans += (n-j+1);
            t++;

        }

        ans += (i - t + 1);

        return ans;

    }
};