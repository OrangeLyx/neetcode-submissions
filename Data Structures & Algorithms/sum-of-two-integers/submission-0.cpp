class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int sum = a ^ b;              // 不带进位的和
            unsigned carry = (unsigned)(a & b) << 1;  // 进位
            a = sum;
            b = carry;
        }
        return a;
    }
};
