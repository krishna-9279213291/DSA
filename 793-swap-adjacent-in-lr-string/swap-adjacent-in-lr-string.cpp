class Solution {
public:
    bool canTransform(string s, string r) {
        int n=s.length();
        int i=0,j=0;
        while(i<n || j<n){
            while(s[i]=='X') i++;
            while(r[j]=='X') j++;
            if(i==n && j!=n || i!=n && j==n ){
                return 0;
            }
            if(s[i]!=r[j]){
                return 0;
            }
            else{
                if(s[i]=='L' && j>i || s[i]=='R' && j<i){
                    return 0;
                }
                i++;j++;
            }
        }
        return 1;
    }
};