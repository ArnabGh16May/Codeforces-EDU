/*
    Author:    Arnab Ghosh
    Created:   05.08.2022 08:51:15
*/
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debugg.h"
#else 
#define debug(x)
#endif
using namespace std;
typedef long long ll;

long long n, k;
long long smaller(vector<vector<long long>> a, long long m) {
	long long cnt = 0;
	for(ll i = 0; i < n; i++) {
		if(a[i][0] < m) cnt += min(m - a[i][0], a[i][1] - a[i][0] + 1);
	}
	return cnt;
}
     
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
   	cin >> n >> k;
   	vector<vector<long long>> seg(n);
   	long long mn = INT_MAX, mx = INT_MIN;
	for(ll i = 0; i < n; i++) {
		long long l, r;
		cin >> l >> r;
		seg[i].push_back(l);
		seg[i].push_back(r);
		mn = min(mn, l);
		mx = max(mx, r);
	}
	long long l = mn, r = mx;
	while(l <= r) {
		long long m = (l + r) >> 1ll;
		if(smaller(seg, m) <= k) {
			 l = m + 1;
		}
		else r = m - 1;
	}
	cout << r << '\n';

}