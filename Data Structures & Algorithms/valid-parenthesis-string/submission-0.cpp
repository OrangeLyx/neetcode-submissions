class Solution {
public:
 bool checkValidString(string s) {
    int n = s.length();
    int balance = 0; // balance 用来表示当前的括号平衡度


    for (int i = 0; i < n; i++) {
        char ch = s[i]; 
        if (ch == '(' || ch == '*') { // 如果当前字符是左括号，或者 '*'（即可被解锁）
            balance++; // 括号平衡度加一
        } else { // 当前字符是右括号
            balance--; // 括号平衡度减一，表示匹配了一个左括号
            if (balance < 0) {
                return false; // 如果出现右括号却没有匹配的左括号，则返回 false
            }
        }
    }

    balance = 0; // 重新初始化括号平衡度

    for (int i = n - 1; i >= 0; i--) {
        char ch = s[i]; // 获取字符串 s 的第 i 个字符（从末尾开始）
        if (ch == ')' || ch == '*') { // 如果当前字符是右括号，或者 '*'（即可被解锁）
            balance++; // 括号平衡度加一
        } else { // 当前字符是左括号
            balance--; // 括号平衡度减一，表示匹配了一个右括号
            if (balance < 0) {
                return false; // 如果出现左括号却没有匹配的右括号，则返回 false
            }
        }
    }

    return true; 
}
};