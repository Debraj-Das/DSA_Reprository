#include <bits/stdc++.h>
using namespace std;

auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class MyQueue
{
private:
    stack<int> pushs;
    stack<int> pops;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        pushs.push(x);
    }

    int pop()
    {
        if (pops.empty())
        {
            while (!pushs.empty())
            {
                pops.push(pushs.top());
                pushs.pop();
            }
        }
        int res = pops.top();
        pops.pop();
        return res;
    }

    int peek()
    {
        if (pops.empty())
        {
            while (!pushs.empty())
            {
                pops.push(pushs.top());
                pushs.pop();
            }
        }
        return pops.top();
    }

    bool empty()
    {
        return pushs.empty() and pops.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    return 0;
}
