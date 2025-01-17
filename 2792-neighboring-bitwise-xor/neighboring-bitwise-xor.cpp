class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();

        int prv = 1, cur;
        for(int i=0; i<n-1; i++) {
            cur = derived[i];
            if(cur == 1) {
                if(prv == 1) {
                    prv = 0;
                }
                else {
                    prv = 1;
                }
            }
            else {
                if(prv == 1) {
                    prv = 1;
                }
                else {
                    prv = 0;
                }
            }
        }

        return ((prv ^ 1) == derived[n-1]);
    }
};