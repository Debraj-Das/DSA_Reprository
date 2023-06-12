#include <bits/stdc++.h>

template <typename T , T (*merge)(T , T)>
class SegmentTree
{
protected:
    std::vector<T> tree;
    int n;
    // T merge(T, T);

    // Build the segment tree
    void build(std::vector<T> &arr)
    {
        for (int i = 0; i < n; i++)
            tree[n + i - 1] = arr[i];
        for (int i = n - 2; i >= 0; i--)
            tree[i] = merge(tree[2 * i + 1], tree[2 * i + 2]);
    }

public:
    // Constructor of Segment Tree Class with default value of the node as def = 0
    SegmentTree(std::vector<T> arr)
    {
        n = arr.size();
        this->tree.resize(2 * n - 1);
        build(arr);
    }
    SegmentTree(T arr[], int n)
    {
        this->n = n;
        this->tree.resize(2 * n - 1);
        std::vector<T> v(arr, arr + n);
        build(v);
    }

    // Update the value of the index-th element to value
    void update(int index, T value)
    {
        index += n - 1;
        tree[index] = value;
        while (index > 0)
        {
            index = (index - 1) / 2;
            tree[index] = merge(tree[2 * index + 1], tree[2 * index + 2]);
        }
        return;
    }

    // Get the value of the function over the range [lo, hi]
    T getValue(int lo, int hi)
    {
        lo += n, hi += n;
        T res = 0;
        while (lo <= hi)
        {
            if (lo % 2 == 1)
            {
                res = merge(res, tree[lo - 1]);
                lo++;
            }
            if (hi % 2 == 0)
            {
                res = merge(res, tree[hi - 1]);
                hi--;
            }
            lo /= 2, hi /= 2;
        }
        return res;
    }
    // Get the value of the index-th element
    T getValue(int index) { return getValue(index, index); }
    // Get the value of whole array value
    T getValue() { return getValue(0, n - 1); }

    // Print the segment tree
    void print()
    {
        std::cout << "NO of elements in tree : " << n << '\n';
        std::cout << "Size of tree : "
                  << this->tree.size() << '\n';
        std::cout << "Tree: \n\t";
        for (auto x : tree)
            std::cout << x << " ";
        std::cout << std::endl;
    }
};

/*
! Instructions to use Segment Tree Class
* Data type of the segment tree is T
T = int , double or any other data type

~ merge function is used to merge two nodes to create parent node
* So Define merge function according to the query
e.g: sum Query
    merge(a,b) { return a+b;}
e.g: min Query
    merge(a,b) { return min(a,b);}

~ Public functions of Segment Tree Class
* Constructor of Segment tree
    SegmentTree(std::vector<T> arr)
    SegmentTree(T arr[], int n)

* Update the value of the index-th element to value
    void update(int index, T value)

* Get the value of the function over the range [lo, hi]
    T getValue(int lo, int hi)
* Get the value of the index-th element
    T getValue(int index)
* Get the value of whole array value
    T getValue()

* Print the segment tree
    void print()

*/

#include "./Header/debug.hpp"
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

