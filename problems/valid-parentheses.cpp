/************************************************************
* problem id : 20
* problem title : Valid Parentheses
* problem link : https://leetcode.com/problems/valid-parentheses/description/
************************************************************/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int size = s.size();

        if(size==0)
            return true;
        for(int i=0; i<size; i++) {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                st.push(s[i]);
            else {
                if(s[i]==')') {
                    if(st.empty() || st.top()!='(')
                        return false;
                    else
                        st.pop();
                }
                if(s[i]==']') {
                    if(st.empty() || st.top()!='[')
                        return false;
                    else
                        st.pop();
                }
                if(s[i]=='}') {
                    if(st.empty() || st.top()!='{')
                        return false;
                    else
                        st.pop();
                }
            }
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};
