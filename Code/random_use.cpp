#include <bits/stdc++.h>
#include "Header/Random.hpp"

using namespace std;

int main()
{
    long long n  , i = 0 , nagative = 0 ;
    time(5)
    {
        i++;
        n = randomInt(-2000 , 2000);
        if(n < 0)
            nagative++ ;
    }
    cout << (i) <<"  nagative number "<< nagative << endl;
    cout<< (nagative*100.00) /i << endl;

    return 0;
}