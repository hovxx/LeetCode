/**************************************************************
* problem id : 155
* problem title : Min Stack
* problem link : https://leetcode.com/problems/min-stack/description/
***************************************************************/

class MinStack {
public:
    void push(int x) {
        s1.push(x);
        if(s2.empty())
            s1.push(x);
        else {
            if(x<=s1.top())
                s2.push(x);
        }
    }

    void pop() {
        if(s1.top()==getMin())
            s2.pop();
        s1.pop();
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return s2.top();
    }

private:
    stack<int> s1;
    stack<int> s2;
};
