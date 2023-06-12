#include "Segment.hpp"
#include "./Header/debug.hpp"
#include <iostream>
using namespace std;

template <typename T>
T merge(T a, T b)
{
    return a + b;
}

void solve();

int main()
{
    int i = 0 ;
    time(15)
    {
        i++;
        solve();
    }
    cout << "Correct Case : "<<i<<endl;

    return 0;
}

void solve()
{
    int n = getRandomNumber(1, 1000);
    vector<int> v = RandomVector(n, 1, 10000000);
    SegmentTree<int, merge> st(v);
    int q = getRandomNumber(10, 200), l, r, ans;
    while (q--)
    {
        l = getRandomNumber(0, n - 1);
        r = getRandomNumber(l, n - 1);
        ans = 0;
        for (int i = l; i <= r; i++)
            ans += v[i];
        if (ans != st.getValue(l, r))
        {
            cout << "Wrong Answer\n";
            cout << "Correct Answer : " << ans << endl;
            cout << "Your Answer : " << st.getValue(l, r) << endl;
            cout << "Array : ";
            for (int i = 0; i < n; i++)
                cout << v[i] << " ";
            cout << endl;
            cout << "Query : " << l << " " << r << endl;
            exit(0);
        }
        if(q%10==0)
        {
            int index = getRandomNumber(0, n - 1);
            int value = getRandomNumber(1, 10000000);
            v[index] = value;
            st.update(index, value);
        }
    }
    return;
}
