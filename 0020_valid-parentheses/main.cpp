/// Source : https://leetcode-cn.com/problems/valid-parentheses/
/// Author : lalalashenle
/// Time   : 2020-02-28

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>

using namespace std;

// 栈
class Solution {
public:
    bool isValid(string s) {
        stack<char> Stack;

        if(s.length() == 1)
            return false;

        int i = 0;
        while (s[i] != NULL) {
            switch (s[i]) {
                case '(':
                    Stack.push(s[i]);
                    break;
                case '{':
                    Stack.push(s[i]);
                    break;
                case '[':
                    Stack.push(s[i]);
                    break;
                case ')':
                    if(Stack.empty())
                        return false;
                    if (Stack.top() != '(')
                        return false;
                    Stack.pop();
                    break;
                case '}':
                    if(Stack.empty())
                        return false;
                    if (Stack.top() != '{')
                        return false;
                    Stack.pop();
                    break;
                case ']':
                    if(Stack.empty())
                        return false;
                    if (Stack.top() != '[')
                        return false;
                    Stack.pop();
                    break;
                default:
                    break;
            }
            i++;
        }
        if (!Stack.empty())
            return false;
        return true;

    }
};

int main() {
    Solution test;
    string s = "{[]}";

    cout << test.isValid(s);

    return 0;
}
