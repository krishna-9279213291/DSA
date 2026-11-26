class Solution {
public:
    vector<int> LPS(string& s){
        int n = s.size();
        vector<int> lps(n, 0);
        int i = 1, prev = 0;
        while(i < n){
            if(s[i] == s[prev]){
                prev++;
                lps[i] = prev;
                i++;
            }else{
                if(prev > 0){
                    prev = lps[prev-1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    vector <int> search(string p, string t)
    {
        string ns = p + "#" + t;
        vector<int> lps = LPS(ns);
        vector<int> ans;
        int n = p.size();
        for(int i=n+1; i<lps.size(); i++){
            ans.push_back(i-n-lps[i]);
        }
        return ans;
    }
    int minValidStrings(vector<string>& w, string t) {
        int n = w.size();
        vector<vector<int>> arr(n);
        for(int i=0; i<n; i++){
            arr[i] = search(w[i], t);
        }
        int m = t.size();
        vector<int> dp(m+1, 1e9);
        dp[0] = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dp[i+1] = min(dp[i+1], dp[arr[j][i]] + 1);
            }
        }
        if(dp[m] == 1e9) return -1;
        return dp[m];
    }
};