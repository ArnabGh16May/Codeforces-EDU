/*
    Author: Arnab Ghosh
    Created:01-08-22 18:36
*/
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debugg.cpp"
#else
#define debug(x)
#endif
using namespace std;
typedef long double ld;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
	cout << setprecision(10) << fixed;
    int n;
    cin >> n;
    vector<ld> x(n), v(n);
    for(int i = 0; i < n; i++) {
    	cin >> x[i];
    	cin >> v[i];
	}
    
    auto good = [&](long double t) {
    	ld left = INT_MIN, right = INT_MAX;
		for(int i = 0; i < n; i++) {
			left = max(left, x[i] - t * v[i]);
			right = min(right, x[i] + t * v[i]);
		}
		
		return left >= right;
	};
	
    ld l = 0.0, r = ld(1e9);
    for(int i = 0; i < 200; i++) {
    	ld t = (l + r) / 2.0;
    	if(good(t)) l = t;
    	else r = t;
	}
	
	cout << r << '\n';
    
}
