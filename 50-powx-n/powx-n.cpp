class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;
        
        // Negative power
        if (power < 0) {
            x = 1 / x;
            power = -power;
        }
        
        double ans = 1.0;
        
        while (power > 0) {
            
            // If power is odd
            if (power % 2 == 1) {
                ans *= x;
            }
            
            x *= x;       // Square the base
            power /= 2;   // Divide power by 2
        }
        
        return ans;
    }
};