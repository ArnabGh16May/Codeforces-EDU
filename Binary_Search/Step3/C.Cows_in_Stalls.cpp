/*
    Author: Arnab Ghosh
    Created: 02-08-22 09:48
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
    ll n, k;
    cin >> n >> k;
    vector<ll> stalls(n);
    for(ll &i: stalls) {
    	cin >> i;
	}
	
	auto possible = [&](ll d) {
		ll allocatedCows = 1, start = stalls[0];
		for(ll i = 0; i < n; i++) {
			if(stalls[i] - start >= d) {
				allocatedCows++;
				start = stalls[i];
			}
		}
		
		return allocatedCows >= k;
	};
	
	ll l = 0, r = stalls[n - 1] - stalls[0];
	while(l <= r) {
		ll d = (l + r) >> 1ll;
		if(possible(d)) l = d + 1;
		else r = d - 1;
	}
	cout << r << '\n';
}
