#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch); // push opening bracket
        } else {
            if (st.empty()) return false; // no matching opening

            char top = st.top();
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')) {
                st.pop(); // matched
            } else {
                return false; // mismatch
            }
        }
    }

    return st.empty(); // all brackets matched
}

int main() {
    string input;
    cout << "Enter bracket expression: ";
    cin >> input;

    if (isValid(input))
        cout << "Valid\n";
    else
        cout << "Invalid\n";

    return 0;
}
