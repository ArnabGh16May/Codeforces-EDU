/*
    Author: Arnab Ghosh
    Created: 25-07-22 20:31
*/
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debugg.cpp"
#else
#define debug(x)
#endif
using namespace std;
typedef long long ll;

//inbuilt sqrt() function can be used. This is the implementation of that.
long double root2(long double x) {
	long double l = 0, r = x;
	while(r - l > 1e-6) {
		long double m = (l + r) / 2.0;
		if(m * m <= x) l = m;
		else r = m;
	}	
	
	return r;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    cout << setprecision(15) << fixed;
    long double c;
    cin >> c;
    long double l = 0, r = c;
    for(int i = 0; i < 100; i++) {
    	long double m = (r + l) / 2.0;
    	if(m * m + root2(m) <= c) l = m;
    	else r = m;
	}
	
	cout << r << "\n";
    
}
