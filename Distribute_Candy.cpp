/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define f(a, b) for (int i = a; i < b; i++)
#define fr(a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
void solve();

#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
 const char* comma = strchr (names + 1, ',');
 cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();

    int t = 1;
    //	cin >> t;
    while (t--)
        solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

// int min_require_candy(int arr[], int n)
// {
//     int no = 2 * n - 1;
//     f(0, n - 1) if (arr[i] == arr[i + 1]) no--;
//     return no;
// }

void increase(int arr[], int candy[], int n, int a, int b)
{
    if (arr[a] < arr[b])
    {
        candy[a] = 1 ;
        f(a + 1, b) candy[i] = (arr[i - 1] < arr[i]) ? candy[i - 1] + 1 : candy[i - 1];
    }
    else if (arr[a] > arr[b])
    {
        candy[b] = 1 ;
        fr(b - 1, a + 1) candy[i] = (arr[i] > arr[i+1]) ? candy[i + 1] + 1 : candy[i + 1];

        if (a == 0)
            candy[a] = (arr[a + 1] < arr[a]) ? candy[a + 1] + 1 : candy[a + 1];
        else if (a == (n - 1))
            candy[a] = (arr[a - 1] < arr[a]) ? candy[a - 1] + 1 : candy[a - 1];
        else
        {
            int right = (arr[a + 1] < arr[a]) ? candy[a + 1] + 1 : candy[a + 1];
            int left = (arr[a - 1] < arr[a]) ? candy[a - 1] + 1 : candy[a - 1];
            candy[a] = max(right, left);
        }
    }
    return ;
}

int min_require_candy(int arr[], int n)
{
    int points = 0;
    int candy[n] ;
    f(0, n)
    {
        bool check = (i == 0 or arr[i] < arr[i - 1]) and (i == (n - 1) or arr[i] < arr[i + 1]);
        check = check or ((i == 0 or arr[i] > arr[i - 1]) and (i == (n - 1) or arr[i] > arr[i + 1])) ;
        // bug(check);
        if (check)
        {
            increase(arr, candy, n, points, i);
            points = i;
        }
    }
    // Below part for the print need candy for every childs
    f(0,n)
    cout<<candy[i]<<' ';
    cout<<el;

    points = 0 ;
    f(0,n) points += candy[i] ;
    return points ;
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    f(0, n) cin >> arr[i];
    cout << min_require_candy(arr, n) << el;

    return;
}