class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int xor_sum = 0;

        for (int x : derived) {
            xor_sum ^= x;
        }
        return xor_sum == 0;
    }
};
