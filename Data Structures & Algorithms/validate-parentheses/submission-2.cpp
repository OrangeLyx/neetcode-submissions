class Solution {
    private: unordered_map<char,char> mp={{')','('},{']','['},{'}','{'}};
public:
    bool isValid(string s) {
        
        if(s.length()%2){
            return false;
        }
        stack<char> st;
        for(char c:s){
            if(!mp.count(c)){
                st.push(c);
            }else{
                if(st.empty()|| st.top()!=mp[c]) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
