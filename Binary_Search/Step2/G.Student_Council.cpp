/*
    Author: Arnab Ghosh
    Created:26-07-22 13:38
*/
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debugg.cpp"
#else
#define debug(x)
#endif
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
	long long k, n, tot = 0;	
    cin >> k >> n;
    vector<long long> a(n);
    for(long long i = 0; i < n; i++) {
    	cin >> a[i];
    	tot += a[i];
	}
	
	auto possible = [&](long long m) {
		long long total = 0;
		for(long long i = 0; i < n; i++) {
			total += min(m, a[i]);
		}
		return (m * k <= total);
	};
	
	long long l = 0, r = tot / k;
	while(l <= r) {
		long long m = (l + r) >> 1ll;
		if(possible(m)) l = m + 1;
		else r = m - 1;
	}
	cout << r << "\n";
}
