class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false ;
        }
        int revN = 0 ;
        int dup = x ;
        while ( x != 0){
            int ld = x % 10;
            x = x / 10;
            
            if ( revN > INT_MAX / 10 || (revN == INT_MAX / 10 && ld > 7)){
                return 0;
            }
             if ( revN < INT_MIN / 10 || (revN == INT_MIN / 10 && ld < -8)){
                return 0;
            }

            revN = (revN * 10) + ld;
            
            
            
            
        
    }
        if (dup == revN){
                return true ;
            }else {
                return false ;
            }
            
    }
};