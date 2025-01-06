class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        vector<int> ones;
        for(int i=0; i<n; i++) {
            if(boxes[i] == '1') ones.push_back(i);
        }

        vector<int> res(n);
        for(int i=0; i<n; i++) {
            int ans=0;
            for(int j=0; j<ones.size(); j++) {
                ans += abs(i-ones[j]);
            }
            res[i] = ans;
        }
        
        return res;
    }
};