class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0,k=0,l=0;
        while(j<version1.size() || l<version2.size()){
            while(j < version1.size() && version1[j] != '.')j++;
            while(l < version2.size() && version2[l] != '.')l++;
            string s1 = (i < version1.size()) ? version1.substr(i, j - i) : "";
            string s2 = (k < version2.size()) ? version2.substr(k, l - k) : "";
            int num1 = s1.empty() ? 0 : stoi(s1);
            int num2 = s2.empty() ? 0 : stoi(s2);
            if(num1>num2)return 1;
            else if(num1<num2) return -1;
            i=j+1,k=l+1;
            j++,l++;
        }
        return 0;
    }
};