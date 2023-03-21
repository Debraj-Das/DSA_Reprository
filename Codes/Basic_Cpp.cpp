/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

/*
    This Code used for the Basic practise for the C++ language
    like -> general practise of other laguege
    some part practise part of the C++ language

    Predure oriented programming parts
*    1. C++ Basic -> Builden data type , input/output , operation
*    2. Condition statement -> Branching , looping
*    3. Function and Library(basic library)
*    4. Structure and Class , enum
    Objective oriented programming parts
*    5. OOPs ideas and philosopy and basic analogy
*    6. Inheritance and Friend , static , Inner class
*    7. Overloading and polymorphism
    some Advence part
*    9. Constants , preprocessor , Directives
*   10. Template and STL Librarys

*/

#include <bits/stdc++.h>
using namespace std;
void solve();

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
        solve(); // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}
 
bool compare(int a , int b) // This used of the 
{
    return a > b ;
}
// its lambda function is [](int a , int b) {return a<b;}

void solve()
{
    // int n;
    // cin >> n;
    // vector<vector<int>>v(n,vector<int>(n,0));   // decleartion and filled the 2D vector by Zeroes
    // cout << (typeid(string).name() == typeid(int).name()) << endl; // This is for check the data type is same or not

    // cout<<sizeof(int64_t)<<endl; // This is use for the long long int
    
    vector<int> arr = {4 , 6 , 2 , 8 , 10};
    sort(arr.begin() , arr.end() , [](int a, int b) {return a < b;});
    for(auto x: arr)
    cout<< x <<' '; 
    cout<<endl;
    return;
}