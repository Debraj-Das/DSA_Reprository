/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define el '\n'
#define sp ' '

#define f(i, a, b) for (int i = a; i < (b); i++)
#define fr(i, a, b) for (int i = a; i >= (b); i--)

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define eif(cds, a, b) ((cds) ? (a) : (b))

#define pii pair<int, int>
#define ff first
#define ss second

#define vi vector<int>
#define pb push_back

#define si set<int>

inline int exp(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1)
            x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}

inline void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin>>t ;
    while(t--) solve();

    return 0;
}

inline void solve()
{
    int n ;
    cin>>n ;
    int b[n][n] ;
    f(i,0,n)
    {
        f(j,0,n)
        {
            cin>>b[i][j] ;
        }
    }

    // a[i][j] = 1 unhappy 
    // a[i][j] = 2 happy
    // a[i][j] = 3 super happy

    // calculate the no of combinations for which all the children are happy or alleast one is super happy

    int a[n];
    f(i,0,n)
    {
        a[i] = i ;
    }

    int ans = 0 , sum , i ;

    do
    {
        sum = 0 ;
        for(i = 0 ; i < n ; i++)
        {
            if(b[i][a[i]] == 3)
            break;
            sum += b[i][a[i]] ;
        }
        if((i < n) or (sum == 2*n)) ans++ ;
    }
    while(next_permutation(a,a+n)) ;

    cout<<ans<<el ;

    return;
}
