class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = shifts.size(), sz = s.size();
        vector<int> partial(sz+1);
        for(int i=0; i<n; i++) {
            int l = shifts[i][0], r = shifts[i][1], direction = shifts[i][2];
            if(direction == 0) {
                partial[l] += 25, partial[r+1] += 1;
            }
            else {
                partial[l] += 1, partial[r+1] += 25;
            }
        }

        for(int i=1; i<sz; i++) {
            partial[i] += partial[i-1];
        }

        string res = {};
        for(int i=0; i<sz; i++) {
            res.push_back((char)(((s[i]-'a') + partial[i])%26 + 'a'));
        }

        return res;
    }
};