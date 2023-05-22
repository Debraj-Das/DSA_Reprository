/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t = 1;
    	cin >> t;
    while (t--)
        solve();

    return 0;
}

class Solution
{
public:
    int romanToInt(string s)
    {
        map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int arr[s.length()];
        int ans = 0, prev = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            arr[i] = m[s[i]];
            if (arr[i] >= prev)
                ans += arr[i];
            else
                ans -= arr[i];
            prev = arr[i];
        }
        return ans;
    }
};

void solve()
{
    string s;
    cin >> s;
    Solution ob;
    cout << ob.romanToInt(s) << el;

    return;
}


// Topper Solution
int romanToInt(string s) {

        int len = s.size();
        int solution_value = 0;

        for (int i = 0; i<len; i++){
            
            switch (s[i]){
                case 'I':
                    if (s[i+1] == 'V'){
                        solution_value+=4;
                        i++;
                    }else if (s[i+1] == 'X'){
                        solution_value+=9;
                        i++;
                    }else{
                        solution_value+=1;
                    }                       
                    break;
            
                case 'V':
                    solution_value+=5;
                    break;
            
                case 'X':
                    if (s[i+1] == 'L'){
                        solution_value+=40;
                        i++;
                    }else if (s[i+1] == 'C'){
                        solution_value+=90;
                        i++;
                    }else{
                        solution_value+=10;
                    } 
                    break;
            
                case 'L':
                    solution_value+=50;
                    break;

                case 'C':
                    if (s[i+1] == 'D'){
                        solution_value+=400;
                        i++;
                    }else if (s[i+1] == 'M'){
                        solution_value+=900;
                        i++;
                    }else{
                        solution_value+=100;
                    }
                    break;

                case 'D':
                    solution_value+=500;
                    break;

                case 'M':
                    solution_value+=1000;
                    break;
                                                                                         
            }//switch
        }//for (int i = 0; i<len; i++)

        return solution_value;
    }