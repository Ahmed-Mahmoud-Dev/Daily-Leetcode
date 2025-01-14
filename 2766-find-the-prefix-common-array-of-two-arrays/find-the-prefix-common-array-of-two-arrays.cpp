class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> a, b;

        int n = A.size(), cur=0;
        vector<int> res(n);
        for(int i=0; i<n; i++) {
            cur += (a.find(B[i]) != a.end() && b.find(B[i]) == b.end()) + (b.find(A[i]) != b.end() && a.find(A[i]) == a.end());
            cur += (A[i] == B[i]);
            res[i] = cur;

            a.insert(A[i]), b.insert(B[i]);
        }

        return res;
    }
};