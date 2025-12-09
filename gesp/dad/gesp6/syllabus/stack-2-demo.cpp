#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (const string& s : tokens) {
        if (s == "+" || s == "-" || s == "*" || s == "/") {
            int b = st.top();
            st.pop();  // 栈顶是右操作数
            int a = st.top();
            st.pop();  // 次顶是左操作数
            if (s == "+")
                st.push(a + b);
            else if (s == "-")
                st.push(a - b);
            else if (s == "*")
                st.push(a * b);
            else if (s == "/")
                st.push(a / b);
        } else {
            st.push(stoi(s));  // 字符串转整数入栈
        }
    }
    return st.top();
}

int main() {
    vector<string> tokens = {"4", "13", "5", "/", "+"};  // 4 + (13 / 5)
    cout << "Result: " << evalRPN(tokens) << endl;       // Output: 6
    return 0;
}