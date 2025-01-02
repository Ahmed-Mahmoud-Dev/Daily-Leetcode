class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), ones = 0, zeros = 0;
        for(int i=0; i<n; i++) {
            ones += s[i] == '1';
        }
        
        int res = 0;
        for(int i=0; i<n-1; i++) {
            if(s[i] == '0') {
                zeros++;
            }
            else {
                ones--;
            }
            
            res = max(res, ones+zeros);
        }
        
        return res;
    }
};