class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t result = 0;
        
        for (int i = 0; i < 32; i++) {
            result <<= 1;        // 给下一位腾位置
            result |= (n & 1);   // 把 n 的最低位放进来
            n >>= 1;             // 去掉 n 的最低位
        }
        
        return result;
    }
};
