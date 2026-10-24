class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(1<n) {
            if(n%2==0)
                n/=2;
            else
                return false;
        }
        return n==1?true:false;
    }
};