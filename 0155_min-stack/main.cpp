/// Source : https://leetcode-cn.com/problems/min-stack/
/// Author : lalalashenle
/// Time   : 2020-02-25

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;


class MinStack {
private:
    int a[1000000] = {0};
    int length = 0;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        a[length] = x;
        length++;
    }

    void pop() {
        length--;
    }

    int top() {
        return a[length-1];
    }

    int getMin() {
        if(length == 0)
            return 0;
        int res = INT_MAX;
        for(int i = 0; i < length; i++)
            if(res > a[i])
                res = a[i];
        return res;
    }
};

int main() {
    MinStack minStack;
    minStack.push(0);
    minStack.push(1);
    minStack.push(0);
    minStack.getMin();
    minStack.pop();
    minStack.getMin();

    return 0;
}
