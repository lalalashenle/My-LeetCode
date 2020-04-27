/// Source : https://leetcode-cn.com/problems/design-a-stack-with-increment-operation/
/// Author : lalalashenle
/// Time   : 2020-04-27

#include <iostream>
#include <vector>

using namespace std;

class CustomStack {
   public:
    int test[1001] = {0};
    int curLen = 0;
    int maxLen = 0;
    CustomStack(int maxSize) { maxLen = maxSize; }

    void push(int x) {
        if (curLen < maxLen) {
            test[curLen] = x;
            curLen++;
        }
    }

    int pop() {
        if (curLen == 0)
            return -1;
        int ret = test[curLen - 1];
        curLen--;
        return ret;
    }

    void increment(int k, int val) {
        int index = 0;
        while (index < k && index < curLen) {
            test[index] += val;
            index++;
        }
    }
};

int main() {
    CustomStack customStack(3);  // 栈是空的 []
    customStack.push(1);         // 栈变为 [1]
    customStack.push(2);         // 栈变为 [1, 2]
    customStack.pop();    // 返回 2 --> 返回栈顶值 2，栈变为 [1]
    customStack.push(2);  // 栈变为 [1, 2]
    customStack.push(3);  // 栈变为 [1, 2, 3]
    customStack.push(4);  // 栈仍然是 [1, 2, 3]，不能添加其他元素使栈大小变为 4
    customStack.increment(5, 100);  // 栈变为 [101, 102, 103]
    customStack.increment(2, 100);  // 栈变为 [201, 202, 103]
    customStack.pop();  // 返回 103 --> 返回栈顶值 103，栈变为 [201, 202]
    customStack.pop();  // 返回 202 --> 返回栈顶值 202，栈变为 [201]
    customStack.pop();  // 返回 201 --> 返回栈顶值 201，栈变为 []
    customStack.pop();  // 返回 -1 --> 栈为空，返回 -1
    system("pause");
}
