/// Source : https://leetcode-cn.com/problems/implement-stack-using-queues/
/// Author : lalalashenle
/// Time   : 2020-03-1

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 单队列。遍历过程中先压后推，实现队列转身。
class MyStack {
private:
    queue<int> memo;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        memo.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int n = memo.size();
        for (int i = 0; i < n - 1; i++) {
            memo.push(memo.front());
            memo.pop();
        }
        memo.pop();
    }

    /** Get the top element. */
    int top() {
        int n = memo.size();
        for (int i = 0; i < n - 1; i++) {
            memo.push(memo.front());
            memo.pop();
        }
        int res = memo.front();
        memo.push(res);
        memo.pop();
        return res;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return memo.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {


    return 0;
}
