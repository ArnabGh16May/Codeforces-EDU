/*
    Author: Arnab Ghosh
    Created: 02-08-22 08:53
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
    ll n, k, tot = 0, maxx = INT_MIN;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll &i: a) {
    	cin >> i;
    	tot += i;
    	maxx = max(maxx, i);
	}
	
	auto segments = [&](ll m) {
		ll seg = 1, sum = 0;
		for(ll i = 0; i < n; i++) {
			if(sum + a[i] <= m) {
				sum += a[i];
			}else if(a[i] <= m) {
				seg++;
				sum = a[i];
			}
		}
		return seg;
	};
	
	ll l = maxx, r = tot, ans = -1;
	while(l <= r) {
		ll m = (l + r) >> 1ll;
		if(segments(m) == k) r = m - 1;
		else if(segments(m) > k) l = m + 1;
		else r = m - 1;
	}
	cout << l << '\n';
}
