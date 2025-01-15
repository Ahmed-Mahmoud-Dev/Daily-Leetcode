class Solution {
public:
    int minimizeXor(int num1, int num2) {
        const int size = 30;
        bitset<size> n1(num1);
        int setBits = __builtin_popcount(num2);

        if(setBits >= n1.count()) {
            setBits -= n1.count();
            for(int i=0; i<size && setBits; i++) {
                if(!n1.test(i)) {
                    n1.set(i);
                    setBits--;
                }
            }
        }
        else {
            for(int i=size-1; i>=0; i--) {
                if(n1.test(i)) {
                    if(setBits) {
                        setBits--;
                    }
                    else {
                        n1.reset(i);
                    }
                }
            }
        }

        return n1.to_ulong();
    }
};