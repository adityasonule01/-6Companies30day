
class Solution {
public:
    bool isset(int x, int bit) {
        return (x & (1 << bit)) != 0;
    }

    void setbit(int &x, int bit) {
        x |= (1 << bit);
    }

    void unsetbit(int &x, int bit) {
        x &= ~(1 << bit);
    }

 
    int minimizeXor(int num1, int num2) {
        int x = num1;

        int reqsetbitcount = __builtin_popcount(num2);
        int currsetbitcount = __builtin_popcount(x);

        int bit = 0;
        if (currsetbitcount < reqsetbitcount) {
           
            while (currsetbitcount < reqsetbitcount) {
                if (!isset(x, bit)) {
                    setbit(x, bit);
                    currsetbitcount++;
                }
                bit++;
            }
        } else if (currsetbitcount > reqsetbitcount) {
         
            while (currsetbitcount > reqsetbitcount) {
                if (isset(x, bit)) {
                    unsetbit(x, bit);
                    currsetbitcount--;
                }
                bit++;
            }
        }
        return x;
    }
};


