/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define el '\n'
#define f(i,a,b) for(int i = a; i < b; i++)
#define fr(i,a,b) for(int i = a; i >= b; i--)
#define vi vector<int>
void solve() ;

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
#endif

    int t = 1;
//	cin >> t;
    while (t--) solve();

    return 0;
}


// Memorization Method after Recursion step
int dp[1000][1000];

int Profit(int wt[], int val[], int n, int w)
{
    // Base Condition
    if(n == 0 || w == 0)
        return 0;
    
    // Memorization Optimization
    if(dp[n][w] != -1)
        return dp[n][w];
    
    // Choice Diagram to find the maximum profit and Memorization to dp array
    if(wt[n - 1] <= w)
        return dp[n][w] = max(val[n - 1] + Profit(wt, val, n - 1, w - wt[n - 1]), Profit(wt, val, n - 1, w));
    else
        return dp[n][w] = Profit(wt, val, n - 1, w);
}

void solve()
{
    int n, w;
    cin >> n >> w;
    int wt[n], val[n];
    f(i, 0, n) cin >> wt[i];
    f(i, 0, n) cin >> val[i];
    memset(dp, -1, sizeof(dp));
    cout<<Profit(wt, val, n, w )<<el;
    
    return ;
}


// Tabulation Method after Recursion step

int knapsack(int wt[], int val[], int n, int w)
{
    int dp[n + 1][w + 1];
    
    // Base Condition to initialize the dp array
    f(i, 0, n + 1)
        dp[i][0] = 0;
    f(i, 0, w + 1)
        dp[0][i] = 0;
    
    // Choice Diagram to find the maximum profit using previous calculated values
    f(i, 1, n + 1)
    {
        f(j, 1, w + 1)
        {
            if(wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j]; 
        }
    }
    
    return dp[n][w];
}

