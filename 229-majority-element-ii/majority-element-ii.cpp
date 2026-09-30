class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a = 0 , b = 1 , ca = 0, cb = 0 ;
        for (int x : nums ){
            if (x == a )
            ca++;
            else if (x == b )
            cb++;
            else if (ca == 0)
            a = x , ca = 1 ;
            else if (cb == 0 )
            b = x , cb = 1 ;
            else 
            ca--, cb--;
        }
        ca = cb = 0;
        for(int x : nums){
            if(x == a ) ca++;
            else if (x == b )cb++;
        }
        vector<int> ans;
        if(ca > nums.size() / 3)
        ans.push_back(a);

        if(cb > nums.size() / 3 )
        ans.push_back(b);
        return ans;
    }
};