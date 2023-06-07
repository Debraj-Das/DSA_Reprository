#include <bits/stdc++.h>
#include "./Header/debug.hpp"
using namespace std;


int main()
{
	int n = 1;
	time(1)
	{
		// code here
		vector<int> v = RandomVector(getRandomNumber(5, 10), 1, 50);
		cout << n << ") ";
		for (int i : v)
			cout << i << " ";
		cout << endl;
		n++;
	}
	return 0;
}