using ll = long long;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& op) {
        ll len = 1;
        if(len == k) return 'a';
        int i = 0;
        while(i < op.size()){
            len *= 2;
            if(k <= len) break;
            i++;
        }
        ll cnt = 0;
        while(i >= 0 && k > 1){
            if(op[i] == 1 && k > len / 2){
                cnt++;
            }
            len /= 2;
            i--;
            if(k > len) k -= len;
        }

        return (cnt % 26) + 'a';
    }
};